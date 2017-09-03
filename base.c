/* Oskar Eriksson */
#include <stdio.h>

/* Returns 1 if array contains to_check, 0 if not */
int contains(int *array, int size, int to_check) {
    for (int i = 0; i < size; i++) {
        if (*(array + i) == to_check) {
            // Found match, return 1
            return 1;
        }
    }
    // No match, return 0
    return 0;
}

/* Adds valid input to an array */
void get_input(int *array, int size) {
    int valid_size = 24;
    int valid[] = {
        // 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
        48, 49, 50, 51, 52, 53, 54, 55, 56, 57,
        // A, B, C, D, E, F, X
        65, 66, 67, 68, 69, 70, 88,
        // a, b, c, d, e, f, x
        97, 98, 99, 100, 101, 102, 120
    };
    // Get input from standard in
    int current_char = 0;
    for (int i = 0; i < size; i++) {
        current_char = getchar();
        if (current_char == EOF) {
            break;
        } else if (contains(valid, valid_size, current_char)) {
            // Add char if valid, invalid remains as 0
            *(array + i) = current_char;
        }
    }
}

/* Returns decimal value of binary number from raw input */
int bin_input(int *array, int size) {
    int result = 0;
    for (int i = 0; i < size; i++) {
        if (*(array + i) == 48) {
            // Was 0, shift left
            result = result << 1;
        } else if (*(array + i) == 49) {
            // Was 1, shift left and add 1
            result = result << 1;
            result++;
        }
    }
    return result;
}

/* Returns decimal value of hexadecimal number from raw input */
int hex_input(int *array, int size) {
    int result = 0;
    int factor = 1;
    // Go through backwards, skip first two indexes
    for (int i = size - 1; i > 1; i--) {
        if (*(array + i) >= 48 && *(array + i) <= 57) {
            // Was 0-9, add value times factor, then increase factor
            result += (*(array + i) - 48) * factor;
            factor *= 16;
        } else if (*(array + i) >= 65 && *(array + i) <= 70) {
            // Was A-F, add value times factor, then increase factor
            result += (*(array + i) - 55) * factor;
            factor *= 16;
        } else if (*(array + i) >= 97 && *(array + i) <= 102) {
            // Was a-f, add value times factor, then increase factor
            result += (*(array + i) - 87) * factor;
            factor *= 16;
        }
    }
    return result;
}

/* Returns decimal value of decimal number from raw input */
int dec_input(int *array, int size) {
    int result = 0;
    int factor = 1;
    // Go through backwards, skip first two indexes
    for (int i = size - 1; i >= 0; i--) {
        if (*(array + i) >= 48 && *(array + i) <= 57) {
            // Was 0-9, add value times factor, then increase factor
            result += (*(array + i) - 48) * factor;
            factor *= 10;
        }
    }
    return result;
}

/* Prints a number in the decimal number system */
void print_dec(int number) {
    printf("Dec: %d\n", number);
}

/* Prints a number in the binary number system */
void print_bin(int number) {
    printf("Bin: ");
    int factor = 1073741824;
    int started = 0;
    while (1) {
        if (number >= factor) {
            number -= factor;
            printf("1");
            started = 1;
        } else {
            if (started) {
                printf("0");
            }
        }
        factor /= 2;
        if (factor < 1) {
            // Break when done printing
            break;
        }
    }
    printf("\n");
}

/* Prints a number in the hexadecimal number system */
void print_hex(int number) {
    printf("Hex: 0x");
    int factor = 268435456;
    int started = 0;
    int counter = 0;
    while (1) {
        counter = 0;
        while (number >= factor) {
            number -= factor;
            counter += 1;
            started = 1;
        }
        if (started) {
            if (counter > 9) {
                printf("%c", counter + 55);
            } else {
                printf("%d", counter);
            }
        }
        factor /= 16;
        if (factor < 1) {
            // Break when done printing
            break;
        }
    }
    printf("\n");
}

/* Main function */
int main() {
    // Get valid input
    int size = 64;
    int input[64] = {0};
    get_input(input, size);

    // Check base and get decimal value
    int decimal = 0;
    if (input[0] == 'b' || input[0] == 'B') {
        // Binary starts with b/B
        decimal = bin_input(input, size);
    } else if (input[0] == '0' && (input[1] == 'x' || input[1] == 'X')) {
        // Hexadecimal starts with 0x/0X
        decimal = hex_input(input, size);
    } else {
        // Presume decimal number if none of the above
        decimal = dec_input(input, size);
    }

    print_dec(decimal);
    print_bin(decimal);
    print_hex(decimal);
    return 0;
}

