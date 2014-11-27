#include <lmcons.h>
#include <nan.h>


using namespace v8;


NAN_METHOD(WhoAmI) {
  NanScope();
  DWORD size = UNLEN + 1;
  char buf[UNLEN + 1];
  DWORD r = GetUserName(buf, &size);

  if (r == 0) {
    FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM, NULL, GetLastError(),
                  MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
                  buf, UNLEN + 1, NULL);
    NanThrowError(buf);
    NanReturnUndefined();
  }

  NanReturnValue(NanNew(buf));
}
