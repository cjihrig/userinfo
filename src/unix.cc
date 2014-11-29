#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <pwd.h>
#include <sys/types.h>
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


NAN_METHOD(GetHomeDirectory) {
  NanScope();

  /* Only support looking up the current user for Windows compatibility
  if (!args[0]->IsString()) {
    NanThrowTypeError("username must be string");
    NanReturnUndefined();
  }

  NanUtf8String arg0(args[0]);
  char* name = *arg0;
  */

  char* buf = (char*) malloc(sizeof(char) * BUFSIZ);

  if (buf == NULL) {
    NanThrowError("out of memory");
    NanReturnUndefined();
  }

  int r = getlogin_r(buf, BUFSIZ);

  if (r != 0) {
    strerror_r(r, buf, BUFSIZ);
    NanThrowError(buf);
    free(buf);
    NanReturnUndefined();
  }

  struct passwd* pw = getpwnam((const char*) buf);

  if (pw == NULL) {
    strerror_r(errno, buf, BUFSIZ);
    NanThrowError(buf);
    free(buf);
    NanReturnUndefined();
  }

  free(buf);
  NanReturnValue(NanNew(pw->pw_dir));
}
