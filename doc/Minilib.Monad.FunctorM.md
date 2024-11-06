# `module Minilib.Monad.FunctorM`

`map_m`, `foreach_m` for Array and Iterator.

# Types and aliases

# Traits and aliases

## `namespace Minilib.Monad.FunctorM`

### `trait [f : *->*] f : FunctorM`

#### method `map_m : [m : Std::Monad] (a -> m b) -> f a -> m (f b)`

Maps a functor in a monad context.
Similar to Haskell's `mapM` function.

Example:
```
let ios = ...Array of IO operations...;
let tasks = *ios.map_m(AsyncIOTask::make);
let results = *tasks.map_m(get);
==> (tasks are created and started in parallel, then the results of tasks are collected)
```

#### method `foreach_m : [m : Std::Monad] (a -> m ()) -> f a -> m ()`

Maps a functor in a monad context ignoring the results.
Similar to Haskell's `mapM` function, but the results are discarded.

Example:
```
["hello", "world"].foreach_m(println);;
==> ("hello\nworld\n" is printed)
```

# Trait implementations

### `impl Std::Array : Minilib.Monad.FunctorM::FunctorM`

### `impl Std::Iterator : Minilib.Monad.FunctorM::FunctorM`

# Values

## `namespace Minilib.Monad.FunctorM::FunctorM`

### `foreach_m : [f : Minilib.Monad.FunctorM::FunctorM, m : Std::Monad] (a -> m ()) -> f a -> m ()`

Maps a functor in a monad context ignoring the results.
Similar to Haskell's `mapM` function, but the results are discarded.

Example:
```
["hello", "world"].foreach_m(println);;
==> ("hello\nworld\n" is printed)
```

### `map_m : [f : Minilib.Monad.FunctorM::FunctorM, m : Std::Monad] (a -> m b) -> f a -> m (f b)`

Maps a functor in a monad context.
Similar to Haskell's `mapM` function.

Example:
```
let ios = ...Array of IO operations...;
let tasks = *ios.map_m(AsyncIOTask::make);
let results = *tasks.map_m(get);
==> (tasks are created and started in parallel, then the results of tasks are collected)
```