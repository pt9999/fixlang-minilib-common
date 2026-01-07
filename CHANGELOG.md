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
