# Minilib.Common.IORef

Defined in minilib-common@0.11.4

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

#### act

Type: `[m : Minilib.Monad.IO::MonadIO] (a -> Std::IO (b, a)) -> Minilib.Common.IORef::IORef a -> m b`

Performs an action to a mutable reference.

##### Parameters

- `f`: a function which receives a value and returns an `IO (b, a)`, where `b` is a result and `a` is a new value.
- `ioref`: a mutable reference

#### borrow_ptr_io

Type: `(Std::Ptr -> Std::IO b) -> Minilib.Common.IORef::IORef a -> Std::IO b`

Borrows a pointer to `ioref_t` (the internal structure).

The borrowed pointer to `ioref_t` can be stored in a structure in a foreign language,
and can be used to restore `IORef a` by calling `IORef::from_ptr`.

In this situation, you need to manage the reference count of `ioref_t`.
Call `minilib_ioref_ref()` and `minilib_ioref_unref()` from foreign language,
or call `ioref.ref` and `ioref.unref` from Fix language.

##### Parameters

- `f`: a function which receives a pointer and returns an IO monad.
- `ioref`: a mutable reference

#### from_ptr

Type: `[m : Minilib.Monad.IO::MonadIO] Std::Ptr -> m (Minilib.Common.IORef::IORef a)`

Creates a mutable reference from a pointer to `ioref_t` (the internal structure).

NOTE: `IORef a` must be of the same type, otherwise undefined behavior occurs.

##### Parameters

- `ptr`: a pointer to `ioref_t`

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

#### ref

Type: `[m : Minilib.Monad.IO::MonadIO] Minilib.Common.IORef::IORef a -> m ()`

Increments the reference count of `ioref_t` (the internal structure).

##### Parameters

- `ioref`: a mutable reference

#### set

Type: `[m : Minilib.Monad.IO::MonadIO] a -> Minilib.Common.IORef::IORef a -> m ()`

Sets the value of a mutable reference.

##### Parameters

- `a`: a value
- `ioref`: a mutable reference

#### unref

Type: `[m : Minilib.Monad.IO::MonadIO] Minilib.Common.IORef::IORef a -> m ()`

Decrements the reference count of `ioref_t` (the internal structure).

##### Parameters

- `ioref`: a mutable reference

## Types and aliases

### namespace Minilib.Common.IORef

#### IORef

Defined as: `type IORef a = unbox struct { ...fields... }`

A mutable reference whose value can be changed using the IO monad.

##### field `dtor`

Type: `Std::FFI::Destructor Std::Ptr`

A pointer to `ioref_t` (the internal structure).

## Traits and aliases

## Trait implementations