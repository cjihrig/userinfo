#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <nan.h>


using namespace v8;


NAN_METHOD(WhoAmI) {
  NanScope();
  char buf[BUFSIZ];
  int r = getlogin_r(buf, BUFSIZ);

  if (r != 0) {
    strerror_r(r, buf, BUFSIZ);
    NanThrowError(buf);
    NanReturnUndefined();
  }

  NanReturnValue(NanNew(buf));
}
