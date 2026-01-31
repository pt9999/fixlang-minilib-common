## 0.11.2
### Added
- Minilib.Testing.UnitTest: Added `assert_false`.
### Changed
- Minilib.Testing.UnitTest: Renamed `_TEST_VERBOSE` to `is_test_verbose` and changed to an `IO` monad.

## 0.11.1
### Added
- Minilib.Text.StringEx: Added `fill`, `get_prefix`, `get_suffix`, `pad_left`, `pad_right`.

## 0.11.0
### Added
- Minilib.Common.IORef: Added `from_ptr`, `borrow_ptr_io`, `ref`, `unref`, `act`.
- Minilib.Common.IteratorEx: Added `get_last`.
### Changed
- Minilib.Common.IORef: Major implementation changes.

## 0.10.1
### Added
- Minilib.Monad.Error: Added `finally`.

## 0.10.0
### Added
- Moved Minilib.Monad.Error, Minilib.Monad.IO from minilib-monad.
- Minilib.Monad.IO: Added `mprintln`, `emprintln`.
### Changed
- Some functions that return IO/IOFail monads now use MonadIO/MonadIOFail/MonadError.

## 0.9.1
### Added
- Minilib.Common.IteratorEx: Added `drop_while`, `scan`, `scan_ex`, `tails`, `transpose`.

## 0.9.0
## Changed
- Minilib.Text.StringEx: `starts_with` and `ends_with` are now obsolete. Use `Std::String::starts_with`, `Std::String::ends_with`.

## 0.8.0
### Added
- Added Minilib.Common.IORef. `IORef` is a mutable reference whose value can be changed using the IO monad.
- Added Minilib.Common.IteratorEx. It is an extension module for `Std::Iterator`.
- Minilib.Common.TimeEx: Added `sleep`.
### Changed
- Minilib.Text.StringEx: `format` is now a method of the new `Format` trait. `formatv` is now obsolete and has been removed.
- Minilib.Common.TimeEx: `measure_time`, `measure_time_io`: The order of the return value is now swapped.

## 0.7.1
### Added
- Minilib.Trait.Traversable: `Identity` and `Const` are now `Traversable`.

## 0.7.0
### Changed
- Minilib.Trait.Traversable: Now `foreach_m` is not a method of `Traversable` but of `Iterator`.
