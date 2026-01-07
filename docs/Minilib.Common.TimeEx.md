# Minilib.Common.TimeEx

Defined in minilib-common@0.8.0

Timing module, such as sleep for a while, and measuring execution time.

## Values

### namespace Minilib.Common.TimeEx

#### consumed_realtime_while_io

Type: `Std::IO a -> Std::IO (a, Std::F64)`

Get wall-clock time elapsed while executing an I/O action.

##### Parameters

- `io_a`: an IO monad which returns a value of type `a`.

##### Returns

- The result of the `io_a`, and the measured time.

#### measure_time

Type: `Std::F64 -> (() -> a) -> Std::IO (a, Std::F64)`

Measures wall-clock time per a function call.
Specifically, It calls the function many times until the specified time limit (in second) passes
and measures the total time.
Returns the measured time per loop (in second) and the IO operation result.
NOTE: The measured time per loop has a overhead about 0.1~1.0 usec.

Breaking change in 0.8.0: The order of the return value is now swapped.

##### Parameters

- `time_limit`: the specified time limit in seconds.
- `f`: a function to be measured.

##### Returns

- The result of the function, and the measured time.

#### measure_time_io

Type: `Std::F64 -> Std::IO a -> Std::IO (a, Std::F64)`

Measures wall-clock time per an IO operation.
Specifically, It performs an IO operation many times until the specified time limit (in second) passes
and measures the total time.
Returns the measured time per loop (in second) and the IO operation result.
NOTE: The measured time per loop has a overhead about 0.1~1.0 usec.

Breaking change in 0.8.0: The order of the return value is now swapped.

##### Parameters

- `time_limit`: the specified time limit in seconds.
- `io_a`: an IO monad which returns a value of type `a`.

##### Returns

- The result of the `io_a`, and the measured time.

#### notimeit

Type: `[a : Std::ToString] Std::String -> (() -> a) -> Std::IO a`

Same interface as `timeit()` but does not measure time.

#### sleep

Type: `Std::F64 -> Std::IO::IOFail ()`

Sleeps for specified seconds.

##### Parameters

- `seconds`: the time to sleep in seconds.

#### timeit

Type: `[a : Std::ToString] Std::String -> (() -> a) -> Std::IO a`

Measures wall-clock time per a function call.
Specifically, It calls the function many times and measures the total time.
It then prints the function result and measured time per loop.
NOTE: The measured time per loop has a overhead about 0.1~1.0 usec.
It is useful for measuring the performance of a function.

##### Parameters

- `label`: a label for the function.
- `f`: a function to be measured.

##### Returns

- The result of the function.

#### timeit_io

Type: `[a : Std::ToString] Std::String -> Std::IO a -> Std::IO a`

Measures wall-clock time per an IO operation.
Specifically, It performs an IO operation many times and measures the total time.
It then prints the IO operation result and measured time per loop.
NOTE: The measured time per loop has a overhead about 0.1~1.0 usec.

##### Parameters

- `label`: a label for the function.
- `io_a`: an IO monad which returns a value of type `a`.

##### Returns

- The result of the `io_a`.

#### usleep

Type: `Std::U32 -> Std::IO::IOFail ()`

Sleeps for specified micro-seconds.
For details, see Linux manual page for [usleep()](https://man7.org/linux/man-pages/man3/usleep.3.html).

##### Parameters

- `usec`: the time to sleep in micro-seconds.

## Types and aliases

## Traits and aliases

## Trait implementations