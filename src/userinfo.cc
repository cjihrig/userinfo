#include <nan.h>
#include "userinfo.h"


using namespace v8;


void Init(Local<Object> exports) {
  exports->Set(
    Nan::New("whoami").ToLocalChecked(),
    Nan::New<FunctionTemplate>(WhoAmI)->GetFunction()
  );

  exports->Set(
    Nan::New("getHomeDirectory").ToLocalChecked(),
    Nan::New<FunctionTemplate>(GetHomeDirectory)->GetFunction()
  );
}


NODE_MODULE(userinfo, Init)
