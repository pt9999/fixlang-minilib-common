# Minilib.Common.IORef

Defined in minilib-common@0.9.0

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

Type: `Minilib.Common.IORef::IORef a -> Std::IO a`

Gets the value of a mutable reference.

##### Parameters

- `ioref`: a mutable reference

#### make

Type: `a -> Std::IO (Minilib.Common.IORef::IORef a)`

Creates a mutable reference with the specified initial value.

##### Parameters

- `a`: an initial value

#### mod

Type: `(a -> a) -> Minilib.Common.IORef::IORef a -> Std::IO ()`

Modifies the value of a mutable reference.

##### Parameters

- `f`: a function for modifying the value
- `ioref`: a mutable reference

#### put

Type: `a -> Minilib.Common.IORef::IORef a -> Std::IO ()`

`put` is a synonym of `set`.

#### set

Type: `a -> Minilib.Common.IORef::IORef a -> Std::IO ()`

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