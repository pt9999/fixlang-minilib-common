# Minilib.Text.StringEx

Defined in minilib-common@0.9.0

String utility functions.

Features:
- Array U8 -> String conversion
- Search, replace, split, comparison of String
- Format

## Values

### namespace Minilib.Text.StringEx

#### byte_to_string

Type: `Std::U8 -> Std::String`

Deprecated: Please use `Std::String::from_U8`.

Converts a byte (a character) to a string of length 1.

Example:
```
0x41_U8.byte_to_string
==> "A"
```

#### find_byte

Type: `Std::U8 -> Std::String -> Std::Option Std::I64`

Searches for the specified byte from the beginning of a string.
If found, returns the index of that byte.

##### Parameters

* `c` - a byte (a character)
* `str` - a string

Example:
```
"aaa/bbb/ccc".find_byte('/')
==> some(3)
"aaa".find_byte('/')
==> none()
```

#### find_last_byte

Type: `Std::U8 -> Std::String -> Std::Option Std::I64`

Searches for the specified byte from the end of a string.
If found, returns the index of that byte.

##### Parameters

* `c` - a byte (a character)
* `str` - a string

Example:
```
"aaa/bbb/ccc".find_last_byte('/')
==> some(7)
"aaa".find_last_byte('/')
==> none()
```

#### replace_all

Type: `Std::String -> Std::String -> Std::String -> Std::String`

`input.replace_all(from, to)` replaces all occurrences of `from` in the input string with `to`.
If `from` is empty, returns the input string unchanged.

##### Parameters

* `from` - a string to be searched
* `to` - a string to replace with
* `input` - a string to be replaced

Returns the modified string.
If `from` is empty, returns the input string unchanged.
If `from` is not found, returns the input string unchanged.
If `to` is empty, removes all occurrences of `from` from the input string.
If `input` is empty, returns an empty string.

Example:
```
"foo1:11,foo2:22,Foo3:33".replace_all("foo", "piyo")
==> "piyo1:11,piyo2:22,Foo3:33"
"foo1:11,foo2:22,Foo3:33".replace_all("foo", "")
==> "1:11,2:22,Foo3:33"
"foo1:11,foo2:22,Foo3:33".replace_all("", "piyo")
==> "foo1:11,foo2:22,Foo3:33"
```

#### replace_suffix

Type: `Std::String -> Std::String -> Std::String -> Std::Result Std::ErrMsg Std::String`

`str.replace_suffix(from, to)` replaces `from` at the end of `str` with `to`.
if `str` does not end with `from`, an error occurs.

##### Parameters

* `from` - a string to be searched
* `to` - a string to replace with
* `str` - a string to be replaced

Returns `ok(str)` if the replacement is successful.
Returns `err("suffix does not match: str")` if the replacement fails.

Example:
```
"test.txt".replace_suffix(".txt", ".tmp")
 ==> ok("test.tmp")
"test.jpg".replace_suffix(".txt", ".tmp")
 ==> err("suffix does not match: test.jpg")
```

#### split_by

Type: `(Std::U8 -> Std::Bool) -> Std::String -> Std::Iterator::DynIterator Std::String`

Splits a string by a function that checks whether a character is a delimiter or not.
The result will not contain any empty string.

##### Parameters

* `is_delim` - a function that checks whether a character is a delimiter or not
* `str` - a string to be split

Returns a dynamic iterator of strings.

Example:
```
"  aa bb  12 ".split_by(Character::is_space).to_array
==>  ["aa", "bb", "12"]
```

#### split_ex

Type: `Std::String -> Std::String -> Std::Iterator::DynIterator Std::String`

Deprecated: Please use `Std::String::split`.

Same as Std::String::split, except that `"foo".split_ex(",")` returns a singleton iterator of "foo".

Example:
```
"foo,bar,baz".split_ex(",").to_array
==> ["foo", "bar", "baz"]
"foo".split_ex(",").to_array
==> ["foo"]
```

#### split_first

Type: `Std::String -> Std::String -> (Std::String, Std::String)`

`str.split_first(delim)` splits the string `str` into two parts at the first occurence of the delimiter `delim`.
Returns `(left, right)` where `left` is the left part of the delimiter, and
`right` is the right part of the delimiter.
Returns `(str, "")` if the delimiter is not found.

##### Parameters

* `delim` - a string to be searched
* `str` - a string to be split

Returns a tuple of two strings.
If `delim` is empty, returns `(str, "")`.
If `delim` is not found, returns `(str, "")`.
If `str` is empty, returns `("", "")`.

Example:
```
"aaa/bbb/ccc".split_first("/")
==> ("aaa", "bbb/ccc")
"aaa/bbb/ccc".split_first("bb")
==> ("aaa/", "b/ccc")
"aaa/bbb/ccc".split_first("!")
==> ("aaa/bbb/ccc", "")
```

#### subarray

Type: `Std::I64 -> Std::I64 -> Std::Array a -> Std::Array a`

Deprecated: Please use `Std::Array::get_sub`.

Returns a subarray extracted from a specified range from an array.
If the specified range exceeds the array, it will be truncated to fit within the array.

Example:
```
[10, 11, 12, 13, 14].subarray(1, 2)
==> [11, 12]
[10, 11, 12, 13, 14].subarray(0, 5)
==> [10, 11, 12, 13, 14]
[10, 11, 12, 13, 14].subarray(-1, 6)
==> [10, 11, 12, 13, 14]
```

#### substring

Type: `Std::I64 -> Std::I64 -> Std::String -> Std::String`

Deprecated: Please use `Std::String::get_sub`.

Returns a substring extracted from a specified range from a string.
If the specified range exceeds the string, it will be truncated to fit within the string.

Example:
```
"abcdef".substring(2, 3)
==> "cde"
"abcdef".substring(0, 6)
==> "abcdef"
"abcdef".substring(-1, 7)
==> "abcdef"
```

#### to_lower

Type: `Std::String -> Std::String`

Converts the specified string to lowercase.

##### Parameters

* `str` - a string

Example:
```
"ABCdef123".to_lower
==> "abcdef123"
```

#### to_upper

Type: `Std::String -> Std::String`

Converts the specified string to uppercase.

##### Parameters

* `str` - a string

Example:
```
"ABCdef123".to_upper
==> "ABCDEF123"
```

### namespace Minilib.Text.StringEx::Format

#### format

Type: `[a : Minilib.Text.StringEx::Format] Std::String -> a -> Std::String`

## Types and aliases

## Traits and aliases

### namespace Minilib.Text.StringEx

#### trait `a : Format`

`args.format(str)` replaces each occurence of `{}` in the format string `str`
with each element of `args`.
Currently only supports `{}`.

##### Parameters

* `str` - a format string
* `args` - a collection of elements

Returns a formatted string.

Example:
```
["1", "2", "3"].format("foo={} bar={} baz={}")
==> "foo=1 bar=2 baz=3"
["1"].format("foo={} bar={} baz={}")
==> "foo=1 bar={} baz={}"
```

##### method `format`

Type: `Std::String -> a -> Std::String`

## Trait implementations

### impl `[a : Std::ToString, b : Std::ToString] (a, b) : Minilib.Text.StringEx::Format`

`(a, b).format(str)` replaces each occurence of `{}` in the format string `str`
with `a`, `b`.

Example:
```
(12, "abc").format("int={} str={}")
==> "int=12 str=abc"
```

### impl `[a : Std::ToString, b : Std::ToString, c : Std::ToString] (a, b, c) : Minilib.Text.StringEx::Format`

`(a, b, c).format(str)` replaces each occurence of `{}` in the format string `str`
with `a`, `b`, `c`.

Example:
```
(12, 345.678, "abc").format("int={} float={} str={}")
==> "int=12 float=345.678000 str=abc"
```

### impl `[a : Std::ToString, b : Std::ToString, c : Std::ToString, d : Std::ToString] (a, b, c, d) : Minilib.Text.StringEx::Format`

`(a, b, c, d).format(str)` replaces each occurence of `{}` in the format string `str`
with `a`, `b`, `c`, `d`.

Example:
```
(12, 345.678, "abc", some(1)).format("int={} float={} str={} option={}")
==> "int=12 float=345.678000 str=abc option=some(1)"
```

### impl `[a : Std::ToString, b : Std::ToString, c : Std::ToString, d : Std::ToString, e : Std::ToString] (a, b, c, d, e) : Minilib.Text.StringEx::Format`

`(a, b, c, d, e).format(str)` replaces each occurence of `{}` in the format string `str`
with `a`, `b`, `c`, `d`, `e`.

Example:
```
(12, 345.678, "abc", some(1), [1, 2, 3]).format("int={} float={} str={} option={} array={}")
==> "int=12 float=345.678000 str=abc option=some(1) array=[1, 2, 3]"
```

### impl `[a : Std::ToString] (a,) : Minilib.Text.StringEx::Format`

`(a, ).format(str)` replaces an occurence of `{}` in the format string `str`
with `a`.

Example:
```
(12.345, ).format("float={}")
==> "float=12.345000"
([1, 2, 3], ).format("arr={}")
==> "arr=[1, 2, 3]"
```

### impl `[a : Std::ToString] Std::Array a : Minilib.Text.StringEx::Format`

`array.format(str)` replaces each occurence of `{}` in the format string `str`
with each element of `array`.
Currently only supports `{}`.

Example:
```
[some(1), some(2), none()].format("foo={} bar={} baz={}")
==> "foo=some(1) bar=some(2) baz=none()"
[some(1)].format("foo={} bar={} baz={}")
==> "foo=some(1) bar={} baz={}"
```