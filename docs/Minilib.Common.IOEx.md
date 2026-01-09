# Minilib.Common.IOEx

Defined in minilib-common@0.8.2

Extensions for `Std::IO`.

## Values

### namespace Minilib.Common.IOEx

#### fflush

Type: `Std::IO::IOHandle -> Std::IO::IOFail ()`

Flushes a file stream.
For details, see Linux manual page for [fflush()](https://man7.org/linux/man-pages/man3/fflush.3.html).

NOTE: `Std::IO::flush` may be a better choice.

#### set_unbuffered_mode

Type: `Std::IO::IOHandle -> Std::IO ()`

Sets IOHandle to unbuffered mode.
For detials, see Linux manual page for [setbuf()](https://man7.org/linux/man-pages/man3/setbuf.3.html).

NOTE: When a fix program is invoked by `run_with_stream()`,
      then the stdout and stderr becomes not a TTY but a file stream.
      So the stdout becomes block-buffered. The stderr also seems to be block-buffered.

## Types and aliases

## Traits and aliases

## Trait implementations