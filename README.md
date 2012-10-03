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
