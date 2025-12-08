# Minilib.Common.Assert

Defined in minilib-common@0.7.2

Assert functions.

## Values

### namespace Minilib.Common.Assert

#### assert_eq_lazy

Type: `[a : Std::Eq] Std::Lazy Std::String -> a -> a -> Std::Lazy b -> b`

`assert_eq_lazy(errmsg, lhs, rhs, lazy_func)` asserts that two values are equal.
If the assertion failed, prints a message to the stderr and aborts the program.
If the assertion succeeded, calls a lazy function.
For example, instead of
`assert_eq(|_| "error", a, b);; ...` in an IO monad, you can write
`assert_eq_lazy(|_| "error", a, b) $ |_| ...`.

#### assert_lazy

Type: `Std::Lazy Std::String -> Std::Bool -> Std::Lazy a -> a`

`assert_lazy(errmsg, value, lazy_func)` asserts that a condition (boolean value) is true.
If the assertion failed, prints a message to the stderr and aborts the program.
If the assertion succeeded, calls a lazy function.

For example, instead of
`assert(|_| "error", a == b);; ...` in an IO monad, you can write
`assert_lazy(|_| "error", a == b) $ |_| ...`.

## Types and aliases

## Traits and aliases

## Trait implementations