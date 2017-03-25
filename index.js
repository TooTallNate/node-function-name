module.exports = function (fn, name) {
  var descriptor = Object.getOwnPropertyDescriptor(fn, 'name');
  descriptor.value = name;
  Object.defineProperty(fn, 'name', descriptor);
};
module.exports(module.exports, 'set function name');
