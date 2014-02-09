#include "v8.h"
#include "node.h"
#include "nan.h"

using namespace v8;
using namespace node;

namespace {

NAN_METHOD(Set) {
  NanScope();

  Local<Function> fn = Local<Function>::Cast(args[0]);
  Local<String> name = args[1]->ToString();
  fn->SetName(name);

  NanReturnUndefined();
}

void Initialize(Handle<Object> target) {
  NanScope();
  NODE_SET_METHOD(target, "set", Set);
}

} // anonymous namespace

NODE_MODULE(binding, Initialize);
