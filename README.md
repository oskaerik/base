# base
A simple tool to convert a number between the decimal, binary and hexadecimal number systems.

On Linux, compile with `gcc base.c -o base` then pipe input to the program.

Example usage:

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
$ echo "0xFF" | ./base
Dec: 255
Bin: 11111111
Hex: 0xFF
```

