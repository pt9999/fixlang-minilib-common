# `module Minilib.Common.Common`

Common functions such as `id` and `flip`.

# Types and aliases

# Traits and aliases

# Trait implementations

# Values

## `namespace Minilib.Common.Common`

### `apply : a -> (a -> b) -> b`

`apply(a, f)` is equal to `f(a)`.
You can write it as `apply(a) $ f`, `a.apply $ f` or `f.apply(a)`.

### `compose2 : (a -> b -> c) -> (c -> d) -> a -> b -> d`

`compose2` composes a two-argument function with a one-argument function.

### `const : a -> b -> a`

`const` is a constant function. It returns its first argument ignoring its second argument.
ie. `const(a,b)` returns `a`.
Note that `const(id)(a,b)` returns `b`, since `const(id)(a,b) = const(id,a)(b) = id(b) = b`.

### `curry : ((a, b) -> c) -> a -> b -> c`

`curry` converts an uncurried function to a curried function.

### `flip : (a -> b -> c) -> b -> a -> c`

`flip(f)` swaps the first argument and the second argument.

### `id : a -> a`

`id` is an identity function.

### `pair : a -> b -> (a, b)`

`pair(a,b)` returns `(a, b)`.

### `swap : (a, b) -> (b, a)`

`swap` is a function that swaps the first component and the second component of `Tuple2`.
ie. `(a,b).swap` returns `(b, a)`.

### `uncurry : (a -> b -> c) -> (a, b) -> c`

`uncurry` converts a curried function to an uncurried function.