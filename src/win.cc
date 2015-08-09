// Need at least Vista
#if (_WIN32_WINNT < 0x0600)
#define _WIN32_WINNT _WIN32_WINNT_VISTA
#endif


#include <lmcons.h>
#include <nan.h>
#include <shlobj.h>


using namespace v8;


void WhoAmI(const Nan::FunctionCallbackInfo<Value>& info) {
  DWORD size = UNLEN + 1;
  char buf[UNLEN + 1];
  DWORD r = GetUserName(buf, &size);

  if (r == 0) {
    FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM, NULL, GetLastError(),
                  MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
                  buf, UNLEN + 1, NULL);
    Nan::ThrowError(buf);
    return;
  }

  info.GetReturnValue().Set(Nan::New(buf).ToLocalChecked());
}


void GetHomeDirectory(const Nan::FunctionCallbackInfo<Value>& info) {
  wchar_t* path;
  HRESULT hr = SHGetKnownFolderPath(FOLDERID_Profile, 0, NULL, &path);

  if (hr != S_OK) {
    char buf[BUFSIZ];
    FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM, NULL, hr,
                  MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
                  buf, UNLEN + 1, NULL);
    Nan::ThrowError(buf);
    return;
  }

  size_t len = wcslen((const wchar_t*) path);
  char* p = (char*) malloc(sizeof(char) * len + 1);

  if (p == NULL) {
    Nan::ThrowError("out of memory");
    return;
  }

  size_t r = wcstombs(p, path, len);
  p[r] = '\0';
  CoTaskMemFree(path);
  info.GetReturnValue().Set(Nan::New(p).ToLocalChecked());
}
