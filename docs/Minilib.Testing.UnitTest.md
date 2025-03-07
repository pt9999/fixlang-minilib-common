# Minilib.Testing.UnitTest

Defined in minilib-common@0.6.0

Unit Test Framework

## Values

### namespace Minilib.Testing.UnitTest

#### _TEST_VERBOSE

Type: `Std::Bool`

If _TEST_VERBOSE is true, the results of all testcases will be printed.
If _TEST_VERBOSE is false, the results of only failed testcases will be printed.

If the environment variable `TEST_VERBOSE` is set to non-empty string, _TEST_VERBOSE becomes true.
For example, running the `TEST_VERBOSE=1 fix test` command at a shell prompt will report all testcases.

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

#### make_test

Type: `Std::String -> Std::Lazy (Std::IO::IOFail ()) -> Minilib.Testing.UnitTest::TestCase`

Creates a named test case from a lazy `IOFail ()`.

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

### namespace Minilib.Testing.UnitTest::TestCase

#### empty

Type: `Minilib.Testing.UnitTest::TestCase`

A test case where the number of successes and number of failures are both equal to 0.
Can be used as a placeholder at the end of an array of test cases.

### namespace Minilib.Testing.UnitTest::TestSuite

#### run

Type: `Minilib.Testing.UnitTest::TestSuite -> Std::IO ()`

## Types and aliases

### namespace Minilib.Testing.UnitTest

#### TestCase

Defined as: `type TestCase = Std::Lazy (Std::IO::IOFail (Std::I64, Std::I64))`

TestCase is a type that counts the number of successful and failed tests.

#### TestSuite

Defined as: `type TestSuite = Std::Array (Std::String, Std::IO ())`

## Traits and aliases

## Trait implementations