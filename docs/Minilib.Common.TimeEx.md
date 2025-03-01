# Minilib.Common.TimeEx

Defined in minilib-common@0.5.2

Timing module, such as sleep for a while, and measuring execution time.

## Values

### namespace Minilib.Common.TimeEx

#### _repeat_io

Type: `Std::IO a -> Std::I64 -> Std::IO a`

#### consumed_realtime_while_io

Type: `Std::IO a -> Std::IO (a, Std::F64)`

Get wall-clock time elapsed while executing an I/O action.

#### measure_time

Type: `Std::F64 -> (() -> a) -> Std::IO (Std::F64, a)`

Measures wall-clock time per a function call.
Specifically, It calls the function many times until the specified time limit (in second) passes
and measures the total time.
Returns the measured time per loop (in second) and the IO operation result.
NOTE: The measured time per loop has a overhead about 0.1~1.0 usec.

#### measure_time_io

Type: `Std::F64 -> Std::IO a -> Std::IO (Std::F64, a)`

Measures wall-clock time per an IO operation.
Specifically, It performs an IO operation many times until the specified time limit (in second) passes
and measures the total time.
Returns the measured time per loop (in second) and the IO operation result.
NOTE: The measured time per loop has a overhead about 0.1~1.0 usec.

#### notimeit

Type: `[a : Std::ToString] Std::String -> (() -> a) -> Std::IO a`

Same interface as `timeit()` but does not measure time.

#### timeit

Type: `[a : Std::ToString] Std::String -> (() -> a) -> Std::IO a`

Measures wall-clock time per a function call.
Specifically, It calls the function many times and measures the total time.
It then prints the function result and measured time per loop.
NOTE: The measured time per loop has a overhead about 0.1~1.0 usec.

#### timeit_io

Type: `[a : Std::ToString] Std::String -> Std::IO a -> Std::IO a`

Measures wall-clock time per an IO operation.
Specifically, It performs an IO operation many times and measures the total time.
It then prints the IO operation result and measured time per loop.
NOTE: The measured time per loop has a overhead about 0.1~1.0 usec.

#### usleep

Type: `Std::U32 -> Std::IO::IOFail ()`

Sleeps for specified micro-seconds.
For details, see Linux manual page for [usleep()](https://man7.org/linux/man-pages/man3/usleep.3.html).

## Types and aliases

## Traits and aliases

## Trait implementations