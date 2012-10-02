node-function-name
==================
### Set the "name" property of `Function` objects

Very simple module. Sets the, usually immutable, `name` property of `Function`
objects. This functionality is exposed internally to V8, but not exposed to
JavaScript, so this native module is required.

Note that unfortunately _only_ String values are allowed.

Installation
------------

Install with `npm`:

``` bash
$ npm install function-name
```


Example
-------

``` js
var set = require('function-name');

function test () {
}

console.log(test.name);
// "test"

// change the "name" property to 'foo'
set(test, 'foo');

console.log(test.name);
// "foo"

// spaces, and even usually illegal UTF8 chars, are allowed
set(test, '   ☃   ');

console.log(test.name);
// "   ☃   "
```

That's it!
