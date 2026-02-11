# Minilib.Monad.Error

Defined in minilib-common@0.12.1

This module defines the `MonadError` trait, which can report errors.

Monads that implement `MonadError` can throw errors via the `error` function.

It also provides functions like `catch` and `finally` to help with exception handling.

Example:
```
read_file: Path -> IOFail String;
read_file = |path| (
    let handle = *open_file(path, "r");
    do {
        println("reading file: " + path).lift;;
        read_string(handle)
    }
    .catch(|errmsg| pure("Error: " + errmsg))
    .finally(close_file(handle).lift)
);
```

## Values

### namespace Minilib.Monad.Error

#### finally

Type: `[m : Minilib.Monad.Error::MonadError] m () -> m a -> m a`

Returns a monad which performs `body` first, then `cleanup`,
regardless of whether `body` throws an error.

If `cleanup` throws an error, that error takes precedence over an error thrown by `body`.

##### Parameters

- `cleanup`: a cleanup
- `body`: a body

#### from_result_t

Type: `[m : Minilib.Monad.Error::MonadError] Std::Result Std::ErrMsg a -> m a`

Synonym of `lift_result`.

#### lift_result

Type: `[m : Minilib.Monad.Error::MonadError] Std::Result Std::ErrMsg a -> m a`

Lifts an operation result to a monad.

#### to_result_t

Type: `[m : Minilib.Monad.Error::MonadError] m a -> m (Std::Result Std::ErrMsg a)`

Converts to an operation result.

### namespace Minilib.Monad.Error::MonadErrorIF

#### catch

Type: `[m : Minilib.Monad.Error::MonadErrorIF] (Std::ErrMsg -> m a) -> m a -> m a`

`ma.catch(handler)` catches any error that is thrown during the computation of `ma`.

#### error

Type: `[m : Minilib.Monad.Error::MonadErrorIF] Std::ErrMsg -> m a`

`error(e)` throws an error.

## Types and aliases

## Traits and aliases

### namespace Minilib.Monad.Error

#### trait `MonadError = Std::Monad + Minilib.Monad.Error::MonadErrorIF`

Kind: `*->*`

A trait for the interface of monads which can report errors.

#### trait `[m : *->*] m : MonadErrorIF`

A trait for monads which can report errors.

##### method `error`

Type: `Std::String -> m a`

`error(e)` throws an error.

##### method `catch`

Type: `(Std::String -> m a) -> m a -> m a`

`ma.catch(handler)` catches any error that is thrown during the computation of `ma`.

## Trait implementations

### impl `Std::IO::IOFail : Minilib.Monad.Error::MonadErrorIF`

### impl `Std::Result Std::String : Minilib.Monad.Error::MonadErrorIF`