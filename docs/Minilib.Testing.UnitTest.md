# Minilib.Testing.UnitTest

Defined in minilib-common@0.8.1

Unit Test Framework

## Values

### namespace Minilib.Testing.UnitTest

#### assert_equal

Type: `[a : Std::Eq, a : Std::ToString] Std::String -> a -> a -> Std::IO::IOFail ()`

Verifies that two values are equal. If the values are different, the test will fail with the specified message.

#### assert_not_equal

Type: `[a : Std::Eq, a : Std::ToString] Std::String -> a -> a -> Std::IO::IOFail ()`

Verifies that two values are not equal. If the values are equal, the test will fail with the specified message.

#### assert_true

Type: `Std::String -> Std::Bool -> Std::IO::IOFail ()`

Verifies that the boolean value is true. If the boolean value is false, the test will fail with the specified message.

#### make_table_test

Type: `[a : Std::ToString] Std::String -> Std::Array a -> (a -> Std::IO::IOFail ()) -> Minilib.Testing.UnitTest::TestCase`

Creates a set of test cases from parameters and a lazy `IOFail ()`.

##### Parameters

- `test_name`: the name of the test case.
- `params`: an array of parameters to be passed to the test case.
- `body`: a lazy `IOFail ()` that will be executed when the test case is run.

Returns an aggregated test case.

#### make_test

Type: `Std::String -> Std::Lazy (Std::IO::IOFail ()) -> Minilib.Testing.UnitTest::TestCase`

Creates a named test case from a lazy `IOFail ()`.

##### Parameters

- `test_name`: the name of the test case.
- `body`: a lazy `IOFail ()` that will be executed when the test case is run.

Returns a test case that will execute the `body` when run.
The test case will print the name of the test case and the result (success or failure) to `stderr`.

#### run_test_driver

Type: `Std::Array Minilib.Testing.UnitTest::TestCase -> Std::IO ()`

Executes all test cases. This function:
- Sets `stdout` and `stderr` to be unbuffered for immediate output.
- Runs all test cases.
- Prints a summary of the results, including the number of passed and failed tests.
- If any test case fails or an error occurs, prints the error message and aborts the program.
- If all test cases passed, returns `pure()`.

#### run_tests

Type: `Std::Array Minilib.Testing.UnitTest::TestCase -> Minilib.Testing.UnitTest::TestCase`

Executes all test cases and treat the results as one test case.
It is used to run all test cases in a single test case.

##### Parameters

- `tests`: an array of test cases.

Returns a test case that will execute all test cases.

### namespace Minilib.Testing.UnitTest::TestCase

#### empty

Type: `Minilib.Testing.UnitTest::TestCase`

A test case where the number of successes and number of failures are both equal to 0.
Can be used as a placeholder at the end of an array of test cases.

### namespace Minilib.Testing.UnitTest::TestSuite

#### run

Type: `Minilib.Testing.UnitTest::TestSuite -> Std::IO ()`

Run a test suite.

##### Parameters

- `testsuite`: a test suite.

## Types and aliases

### namespace Minilib.Testing.UnitTest

#### TestCase

Defined as: `type TestCase = Std::Lazy (Std::IO::IOFail (Std::I64, Std::I64))`

TestCase is a type that counts the number of successful and failed tests.

#### TestSuite

Defined as: `type TestSuite = Std::Array (Std::String, Std::IO ())`

## Traits and aliases

## Trait implementations