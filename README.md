node-function-name
==================
### Set the "name" property of `Function` objects
[![Build Status](https://travis-ci.org/TooTallNate/node-function-name.svg?branch=master)](http://travis-ci.org/TooTallNate/node-function-name)

Very simple module. Sets the non-writable `name` property of `Function`
objects. In older versions of node, this functionality is exposed internally to
V8, but not exposed to JavaScript, so a  native module is required. In newer
versions of node, function names can be redefined with `Object.defineProperty`,
which this module uses.

Note that unfortunately _only_ String values are allowed.

> **NOTE: For users of node prior to `iojs@3.0.0`**, you'll need to use an
alternate version of this module, `function-name@native`, which provides a C++
implementation.

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
  throw new Error('blah');
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

// the newly set "name" also appears in stack traces!
test();
// Error: blah
//     at    ☃    (/Users/nrajlich/node-function-name/t.js:4:9)
//     at Object.<anonymous> (/Users/nrajlich/node-function-name/t.js:23:1)
//     at Module._compile (module.js:449:26)
//     at Object.Module._extensions..js (module.js:467:10)
//     at Module.load (module.js:356:32)
//     at Function.Module._load (module.js:312:12)
//     at Module.runMain (module.js:492:10)
//     at process.startup.processNextTick.process._tickCallback (node.js:244:9)
```

That's it!
