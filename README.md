# base
A simple tool to convert a number between the decimal, binary and hexadecimal
number systems. The program uses 32-bit unsigned integers and is designed to
work properly with numbers in the interval [0, 4294967295], the behavior of the
program is undefined when using numbers outside the interval or with improperly
formatted numbers.

### How to run
On Linux, compile with `gcc base.c -o base` then pipe input to the program.

### Formatting examples
* Decimal numbers: `123456789`
* Binary numbers: `b10101`, `B10101`
* Hexadecimal numbers: `0x1289ABEF`, `0X1289abef`, `0x1289abEF`

### Example usage

```
$ echo "10" | ./base
Dec: 10
Bin: 1010
Hex: 0xA
```

```
$ echo "b1110" | ./base
Dec: 14
Bin: 1110
Hex: 0xE
```

```
$ echo "0xFFFFFFFF" | ./base
Dec: 4294967295
Bin: 11111111111111111111111111111111
Hex: 0xFFFFFFFF
```

