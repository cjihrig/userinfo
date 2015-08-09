#ifndef _USERINFO_SRC_USERINFO_H_
#define _USERINFO_SRC_USERINFO_H_


#include <nan.h>


using namespace v8;


void WhoAmI(const Nan::FunctionCallbackInfo<Value>& info);
void GetHomeDirectory(const Nan::FunctionCallbackInfo<Value>& info);
void Init(Local<Object> exports);


#endif
