# Hexdumper

This is a C implementation of an xxd-style hex dumper that displays offsets, hexadecimal bytes, and printable ASCII.

## Build

You can compile the Hexdumper.c file with the following commands:

### Linux - gcc

``` gcc -Wall -Wextra Hexdumper.c -o hexdumper ```

### MacOS/Windows - clang

``` clang -Wall -Wextra Hexdumper.c -o hexdumper```

## Usage

To use the hexdumper, type the file name as the argument after ```./hexdumper```

Example:

```./hexdumper test.txt```

Or, you can also type the text by yourself:

```./hexdumper echo Hello World!```


