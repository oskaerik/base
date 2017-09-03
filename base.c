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

/* Returns decimal value of binary number */
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

/* Returns decimal value of hexadecimal number */
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

/* Main function */
int main() {
    // Get valid input
    int size = 64;
    int input[64] = {0};
    get_input(input, size);

    // Check base and get decimal value
    int decimal = 0;
    if (input[0] == 'b' || input[0] == 'B') {
        decimal = bin_input(input, size);
        printf("binary: %d\n", decimal);
    } else if (input[0] == '0' && (input[1] == 'x' || input[1] == 'X')) {
        decimal = hex_input(input, size);
        printf("hex: %d\n", decimal);
    } else {
        printf("dec\n");
    }
    return 0;
}

