#include "v8.h"
#include "node.h"
#include "nan.h"

using namespace v8;
using namespace node;

namespace {

NAN_METHOD(Set) {
  Nan::HandleScope();

  Local<Function> fn = Local<Function>::Cast(info[0]);
  Local<String> name = info[1]->ToString();
  fn->SetName(name);

  info.GetReturnValue().SetUndefined();
}

void Initialize(Handle<Object> target) {
  Nan::HandleScope();
  Nan::SetMethod(target, "set", Set);
}

} // anonymous namespace

NODE_MODULE(binding, Initialize);
