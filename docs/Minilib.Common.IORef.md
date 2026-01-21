# Minilib.Common.IORef

Defined in minilib-common@0.10.1

A mutable reference whose value can be changed using the IO monad.

NOTE: `IORef` is NOT a thread-safe. If you want to require thread-safety, use `Var`.

Example:
```
let ioref = *IORef::make("hello").lift;
let str = *ioref.get;
println(str);;  // "hello"
ioref.put("world");;
let str = *ioref.get;
println(str);;  // "world"
```

## Values

### namespace Minilib.Common.IORef::IORef

#### get

Type: `[m : Minilib.Monad.IO::MonadIO] Minilib.Common.IORef::IORef a -> m a`

Gets the value of a mutable reference.

##### Parameters

- `ioref`: a mutable reference

#### make

Type: `[m : Minilib.Monad.IO::MonadIO] a -> m (Minilib.Common.IORef::IORef a)`

Creates a mutable reference with the specified initial value.

##### Parameters

- `a`: an initial value

#### mod

Type: `[m : Minilib.Monad.IO::MonadIO] (a -> a) -> Minilib.Common.IORef::IORef a -> m ()`

Modifies the value of a mutable reference.

##### Parameters

- `f`: a function for modifying the value
- `ioref`: a mutable reference

#### put

Type: `[m : Minilib.Monad.IO::MonadIO] a -> Minilib.Common.IORef::IORef a -> m ()`

`put` is a synonym of `set`.

#### set

Type: `[m : Minilib.Monad.IO::MonadIO] a -> Minilib.Common.IORef::IORef a -> m ()`

Sets the value of a mutable reference.

##### Parameters

- `a`: a value
- `ioref`: a mutable reference

## Types and aliases

### namespace Minilib.Common.IORef

#### IORef

Defined as: `type IORef a = unbox struct { ...fields... }`

A mutable reference whose value can be changed using the IO monad.

##### field `dtor`

Type: `Std::FFI::Destructor Std::Ptr`

## Traits and aliases

## Trait implementations