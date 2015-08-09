#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <pwd.h>
#include <sys/types.h>
#include <nan.h>


using namespace v8;


void WhoAmI(const Nan::FunctionCallbackInfo<Value>& info) {
  char buf[BUFSIZ];
  int r = getlogin_r(buf, BUFSIZ);

  if (r != 0) {
    strerror_r(r, buf, BUFSIZ);
    Nan::ThrowError(buf);
    return;
  }

  info.GetReturnValue().Set(Nan::New(buf).ToLocalChecked());
}


void GetHomeDirectory(const Nan::FunctionCallbackInfo<Value>& info) {
  char* buf = (char*) malloc(sizeof(char) * BUFSIZ);

  if (buf == NULL) {
    Nan::ThrowError("out of memory");
    return;
  }

  int r = getlogin_r(buf, BUFSIZ);

  if (r != 0) {
    strerror_r(r, buf, BUFSIZ);
    Nan::ThrowError(buf);
    free(buf);
    return;
  }

  struct passwd* pw = getpwnam((const char*) buf);

  if (pw == NULL) {
    strerror_r(errno, buf, BUFSIZ);
    Nan::ThrowError(buf);
    free(buf);
    return;
  }

  info.GetReturnValue().Set(Nan::New(pw->pw_dir).ToLocalChecked());
  free(buf);
}
