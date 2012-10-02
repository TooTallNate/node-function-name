#include "v8.h"
#include "node.h"

using namespace v8;
using namespace node;

namespace {

Handle<Value> Set(const Arguments& args) {
  HandleScope scope;
  Local<Function> fn = Local<Function>::Cast(args[0]);
  Local<String> name = args[1]->ToString();
  fn->SetName(name);
  return Undefined();
}

void Initialize(Handle<Object> target) {
  HandleScope scope;
  NODE_SET_METHOD(target, "set", Set);
}

} // anonymous namespace

NODE_MODULE(binding, Initialize);
