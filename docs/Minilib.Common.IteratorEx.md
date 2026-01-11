# Minilib.Common.IteratorEx

Defined in minilib-common@0.9.0

Extensions for `Std::Iterator`.

## Values

### namespace Minilib.Common.IteratorEx

#### drop

Type: `[i : Std::Iterator] Std::I64 -> i -> i`

Drop the first `n` elements of an iterator.

##### Parameters

* `n` - The number of elements to be dropped.
* `iter` - The iterator to be taken from.

#### repeat

Type: `a -> Std::Iterator::MapIterator Std::Iterator::CountUpIterator Std::I64 a`

Create an iterator that generates the same element infinitely.

##### Parameters

* `a` - A value of type `a`.

## Types and aliases

## Traits and aliases

## Trait implementations