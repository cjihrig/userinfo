#include <nan.h>
#include "userinfo.h"


using namespace v8;


void Init(Handle<Object> exports) {
  exports->Set(
    NanNew("whoami"),
    NanNew<FunctionTemplate>(WhoAmI)->GetFunction()
  );

  exports->Set(
    NanNew("getHomeDirectory"),
    NanNew<FunctionTemplate>(GetHomeDirectory)->GetFunction()
  );
}


NODE_MODULE(userinfo, Init)
