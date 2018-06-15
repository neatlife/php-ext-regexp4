# regexp4 Extension for PHP

a php preg_replace preg_match alternative write by c extension, for secondary choosen and better performance

c Project and documentation Please visit [Recursive Regexp Raptor (regexp4)](https://github.com/nasciiboy/recursiveregexpraptor-4)

*benchmarks* ==> [here]([https://nasciiboy.github.io/raptorVSworld/index.html)

## Build from sources

``` bash
% git clone --recursive git@github.com:neatlife/php-ext-regexp4.git
% cd php-ext-regexp4
% phpize
% ./configure
% make
% make install
```

To use the system library

``` bash
% ./configure --with-regexp4
```

## Configration

regexp4.ini:

```
extension=regexp4.so
```

## Function

* regexp4
* cpyCatch
* totCatch
* lenCatch
* gpsCatch
* putCatch
* rplCatch

detail documentation please visit: [Recursive Regexp Raptor (regexp4)](https://github.com/nasciiboy/recursiveregexpraptor-4)

## Examples

```php
$haystack = "hello";
$regexp = "l";
var_dump(regexp4($haystack, $regexp));
// int(2)
```

