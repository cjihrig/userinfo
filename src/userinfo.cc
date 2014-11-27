#include <nan.h>
#include "userinfo.h"


using namespace v8;


void Init(Handle<Object> exports) {
  exports->Set(
    NanNew("whoami"),
    NanNew<FunctionTemplate>(WhoAmI)->GetFunction()
  );
}


NODE_MODULE(userinfo, Init)
