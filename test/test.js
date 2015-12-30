var setFunctionName = require('../');
var assert = require('assert');

function foo () {
  return foo.name;
}
var fn = foo;

assert.equal(fn, foo);
assert.equal(fn(), 'foo');

setFunctionName(fn, 'bar');
assert.equal(fn, foo);
assert.equal(fn(), 'bar');

setFunctionName(fn, 'baz');
assert.equal(fn, foo);
assert.equal(fn(), 'baz');
