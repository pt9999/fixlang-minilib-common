# Minilib.Common.IteratorEx

Defined in minilib-common@0.11.4

Extensions for `Std::Iterator`.

## Values

### namespace Minilib.Common.IteratorEx

#### drop

Type: `[i : Std::Iterator] Std::I64 -> i -> i`

Drop the first `n` elements of an iterator.

##### Parameters

* `n` - The number of elements to be dropped.
* `iter` - The iterator to be taken from.

#### drop_while

Type: `[i : Std::Iterator, Std::Iterator::Item i = a] (a -> Std::Bool) -> i -> i`

Drop elements from an iterator while a predicate holds.

##### Parameters

* `predicate` - The predicate function to be applied to each element of the iterator.
* `iter` - The iterator to be taken from.

#### get_last

Type: `[iter : Std::Iterator] iter -> Std::Option (Std::Iterator::Item iter)`

Get the last element of an iterator.

If the iterator is empty, this function returns `none`.

Time complexity: `O(n)`

##### Parameters

* `iter` - The iterator.

#### repeat

Type: `a -> Std::Iterator::MapIterator Std::Iterator::CountUpIterator Std::I64 a`

Create an iterator that generates the same element infinitely.

##### Parameters

* `a` - A value of type `a`.

#### scan

Type: `[i : Std::Iterator, Std::Iterator::Item i = a] s -> (a -> s -> s) -> i -> Minilib.Common.IteratorEx::ScanIterator i s a`

Create an iterator that generates the inclusive scan of an iterator.

Conceptually, `[a0, a1, a2, ...].to_iter.scan(s, op) = [s1, s2, ...].to_iter` such that
`s0 = s, s1 = op(a0,s0), s2 = op(a1,s1), ...`.

##### Parameters

* `state` - The initial state.
* `op` - The function to be called on the pair of an element and the current state.
* `iter` - The iterator to be scaned.

#### scan_ex

Type: `[i : Std::Iterator, Std::Iterator::Item i = a] s -> (a -> s -> s) -> i -> Std::Iterator::ConsIterator (Minilib.Common.IteratorEx::ScanIterator i s a) s`

Create an iterator that generates the exclusive scan of an iterator.

Conceptually, `[a0, a1, a2, ...].to_iter.scan_ex(s, op) = [s0, s1, s2, ...].to_iter` such that
`s0 = s, s1 = op(a0,s0), s2 = op(a1,s1), ...`.

##### Parameters

* `state` - The initial state.
* `op` - The function to be called on the pair of an element and the current state.
* `iter` - The iterator to be scaned.

#### tails

Type: `[i : Std::Iterator] i -> Minilib.Common.IteratorEx::TailsIterator i`

Creates an iterator that yields a tail starting from each element.

Conceptually, `[a1, a2, ..., an].to_iter.tails = [t1, t2, ..., tn, nil].to_iter` such that
`t1 = [a1, a2, ..., an].to_iter, t2 = [a2, a3, ..., an].to_iter, ..., tn = [an].to_iter, nil = [].to_iter`.

##### Parameters

* `iter` - An iterator.

#### transpose

Type: `[i : Std::Iterator, i2 : Std::Iterator, Std::Iterator::Item i2 = i] i2 -> Minilib.Common.IteratorEx::TransposeIterator i`

Transposes an iterator of iterators.

Conceptually, `[a1, a2, ..., an].to_iter.transpose = [b1, b2, ..., bm].to_iter` where
`a1 = [a11, a12, ..., a1m].to_iter, ..., an = [an1, an2, ..., anm].to_iter` then
`b1 = [a11, a21, ..., an1].to_iter, ..., bm = [a1m, a2m, ..., anm].to_iter`.

##### Parameters

* `iter_iter` - An iterator of iterators. It must be a finite iterator.

## Types and aliases

### namespace Minilib.Common.IteratorEx

#### ScanIterator

Defined as: `type ScanIterator i s a = unbox struct { ...fields... }`

##### field `state`

Type: `s`

##### field `op`

Type: `a -> s -> s`

##### field `iter`

Type: `i`

#### TailsIterator

Defined as: `type TailsIterator i = unbox struct { ...fields... }`

##### field `opt_iter`

Type: `Std::Option i`

#### TransposeIterator

Defined as: `type TransposeIterator i = unbox struct { ...fields... }`

##### field `iters`

Type: `Std::Array i`

## Traits and aliases

## Trait implementations

### impl `[i : Std::Iterator] Minilib.Common.IteratorEx::ScanIterator i s a : Std::Iterator`

### impl `[i : Std::Iterator] Minilib.Common.IteratorEx::TailsIterator i : Std::Iterator`

### impl `[i : Std::Iterator] Minilib.Common.IteratorEx::TransposeIterator i : Std::Iterator`