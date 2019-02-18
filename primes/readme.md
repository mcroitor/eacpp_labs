# Prime numbers generator
__Attention__: generator creates a cache file, where it stores precalculated prime numbers. This speed up calculations but uses RAM.

## How to compile
Download or clone this repository. After this just type:
```bash
make
```
It will create a folder _bin_ with binary _primes_.

## How to use
```bash
primes [<bottom_number>] <top_number>
```
This will print all prime numbers from __bottom_number__ to __top_number__.
Default value of _bottom_number_ parameter is 1.

__Attention__: big range printing will slow calculations. From this, if you want to do some analysis, use cache file, it is simple (huge, may be) text.

__But you always can continue to calculate prime numbers!__

## HOWTO

* store primes number top to N number?
```bash
primes N N
```
and read __prime_numbers.txt__ file after that!

* store a range of prime numbers between N and M into a file?
```bash
primes N M > result.txt
```

* analyze prime numbers without generating?
It is simple. This project has precalculated cache (prime numbers)[url=http://github.com/mcroitor/eacpp_labs/primes/prime_numbers.txt] -- prime numbers from [1, 100000000] range.