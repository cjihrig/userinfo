#ifndef _USERINFO_SRC_USERINFO_H_
#define _USERINFO_SRC_USERINFO_H_


#include <nan.h>


using namespace v8;


NAN_METHOD(WhoAmI);
NAN_METHOD(GetHomeDirectory);
void Init(Handle<Object> exports);


#endif
