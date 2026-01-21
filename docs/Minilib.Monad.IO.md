# Minilib.Monad.IO

Defined in minilib-common@0.10.1

This module defines the `MonadIO` and `MonadIOFail` traits, which can lift `IO` and `IOFail` monad.

## Values

### namespace Minilib.Monad.IO

#### emprintln

Type: `[m : Minilib.Monad.IO::MonadIO] Std::String -> m ()`

Same as `eprintln`, except that it can be automatically lifted into monads that implement MonadIO.

#### mprintln

Type: `[m : Minilib.Monad.IO::MonadIO] Std::String -> m ()`

Same as `println`, except that it can be automatically lifted into monads that implement MonadIO.

### namespace Minilib.Monad.IO::MonadIOFailIF

#### lift_iofail

Type: `[m : Minilib.Monad.IO::MonadIOFailIF] Std::IO::IOFail a -> m a`

### namespace Minilib.Monad.IO::MonadIOIF

#### lift_io

Type: `[m : Minilib.Monad.IO::MonadIOIF] Std::IO a -> m a`

## Types and aliases

## Traits and aliases

### namespace Minilib.Monad.IO

#### trait `MonadIO = Std::Monad + Minilib.Monad.IO::MonadIOIF`

Kind: `*->*`

A monadic trait which can lift IO monad.

#### trait `MonadIOFail = Std::Monad + Minilib.Monad.IO::MonadIOIF + Minilib.Monad.IO::MonadIOFailIF`

Kind: `*->*`

A monadic trait which can lift IO and IOFail monad.

#### trait `[m : *->*] m : MonadIOFailIF`

An interface of a monadic trait which can lift IOFail monad.

##### method `lift_iofail`

Type: `Std::IO::IOFail a -> m a`

#### trait `[m : *->*] m : MonadIOIF`

An interface of a monadic trait which can lift IO monad.

##### method `lift_io`

Type: `Std::IO a -> m a`

## Trait implementations

### impl `Std::IO : Minilib.Monad.IO::MonadIOIF`

### impl `Std::IO::IOFail : Minilib.Monad.IO::MonadIOFailIF`

### impl `Std::IO::IOFail : Minilib.Monad.IO::MonadIOIF`