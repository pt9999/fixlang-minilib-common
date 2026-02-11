# Minilib.Common.Common

Defined in minilib-common@0.12.1

Common functions such as `id` and `flip`.

## Values

### namespace Minilib.Common.Common

#### apply

Type: `a -> (a -> b) -> b`

`apply(a, f)` is equal to `f(a)`.
You can write it as `apply(a) $ f`, `a.apply $ f` or `f.apply(a)`.

##### Parameters

- `a`: a value
- `f`: a function to be applied

#### compose2

Type: `(a -> b -> c) -> (c -> d) -> a -> b -> d`

`compose2` composes a two-argument function with a one-argument function.

##### Parameters

- `f`: a two-argument function
- `g`: a one-argument function

#### const

Type: `a -> b -> a`

`const` is a constant function. It returns its first argument ignoring its second argument.
ie. `const(a,b)` returns `a`.
Note that `const(id)(a,b)` returns `b`, since `const(id)(a,b) = const(id,a)(b) = id(b) = b`.

##### Parameters

- `a`: a value to be kept

#### curry

Type: `((a, b) -> c) -> a -> b -> c`

`curry` converts an uncurried function to a curried function.

##### Parameters

- `f`: an uncurried function

#### flip

Type: `(a -> b -> c) -> b -> a -> c`

`flip(f)` swaps the first argument and the second argument.

##### Parameters

- `f`: a two-argument function

#### id

Type: `a -> a`

`id` is an identity function.

#### ifelse

Type: `Std::Bool -> a -> a -> a`

`ifelse(b, v1, v2)` returns `v1` if `b` is true, returns `v2` if `b` is false.

##### Parameters

- `b`: a condition
- `v1`: a value which will be returned when `b` is true
- `v2`: a value which will be returned when `b` is false

#### mod_if

Type: `Std::Bool -> (a -> a) -> a -> a`

`a.mod_if(b, f)` returns `f(a)` if `b` is true, returns `a` if `b` is false.

##### Parameters

- `b`: a condition
- `f`: a modifier function
- `a`: a value to be modified

#### mod_unless

Type: `Std::Bool -> (a -> a) -> a -> a`

`a.mod_unless(b, f)` returns `a` if `b` is true, returns `f(a)` if `b` is false.

##### Parameters

- `b`: a condition
- `f`: a modifier function
- `a`: a value to be modified

#### pair

Type: `a -> b -> (a, b)`

`pair(a,b)` returns `(a, b)`.

##### Parameters

- `a`: a left value
- `b`: a right value

#### swap

Type: `(a, b) -> (b, a)`

`swap` is a function that swaps the first component and the second component of `Tuple2`.
ie. `(a,b).swap` returns `(b, a)`.

##### Parameters

- `pair`: a pair

#### uncurry

Type: `(a -> b -> c) -> (a, b) -> c`

`uncurry` converts a curried function to an uncurried function.

##### Parameters

- `f`: a curried function

## Types and aliases

## Traits and aliases

## Trait implementations