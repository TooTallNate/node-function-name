if (Object.getOwnPropertyDescriptor(Function.prototype, 'name').configurable) {
  module.exports = function (fn, name) {
    var descriptor = Object.getOwnPropertyDescriptor(fn, 'name');
    descriptor.value = name;
    Object.defineProperty(fn, 'name', descriptor);
  };
} else {
  module.exports = require('bindings')('binding').set;
}
module.exports(module.exports, 'set function name');
