# `module Minilib.Trait.Traversable`

# Types and aliases

# Traits and aliases

## `namespace Minilib.Trait.Traversable`

### `trait [t : *->*] t : Traversable`

A trait for types which can traverse all elements with `Monad`.

#### method `sequence : [m : Std::Monad] t (m a) -> m (t a)`

`ta.sequence` performs all elements sequentially and collects the results.
Similar to Haskell's `sequence` function.

# Trait implementations

### `impl Std::Array : Minilib.Trait.Traversable::Traversable`

### `impl Std::Iterator : Minilib.Trait.Traversable::Traversable`

### `impl Std::Option : Minilib.Trait.Traversable::Traversable`

### `impl Std::Result e : Minilib.Trait.Traversable::Traversable`

### `impl Std::Tuple2 e : Minilib.Trait.Traversable::Traversable`

# Values

## `namespace Minilib.Trait.Traversable`

### `foreach_m : [m : Std::Monad, t : Minilib.Trait.Traversable::Traversable, t : Std::Functor] (a -> m ()) -> t a -> m ()`

`ta.foreach_m(f)` maps each element with `f`, then performs all elements sequentially and forgets the results.
Similar to Haskell's `mapM` function, but the results are discarded.

Example:
```
["hello", "world"].foreach_m(println);;
==> ("hello\nworld\n" is printed)
```

### `map_m : [m : Std::Monad, t : Minilib.Trait.Traversable::Traversable, t : Std::Functor] (a -> m b) -> t a -> m (t b)`

`ta.map_m(f)` maps each element with `f`, then performs all elements sequentially and collects the results.
Similar to Haskell's `mapM` function.

Example:
```
let ios = ...Array of IO operations...;
let tasks = *ios.map_m(AsyncIOTask::make);
let results = *tasks.map_m(get);
==> (tasks are created and started in parallel, then the results of tasks are collected)
```

### `traverse : [m : Std::Monad, t : Minilib.Trait.Traversable::Traversable, t : Std::Functor] (a -> m b) -> t a -> m (t b)`

`ta.traverse(f)` maps each element with `f`, then performs all elements sequentially and collects the results.
`traverse` is a synonym of `map_m`.

## `namespace Minilib.Trait.Traversable::Traversable`

### `sequence : [t : Minilib.Trait.Traversable::Traversable, m : Std::Monad] t (m a) -> m (t a)`

`ta.sequence` performs all elements sequentially and collects the results.
Similar to Haskell's `sequence` function.