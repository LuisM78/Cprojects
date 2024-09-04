#include <stdio.h>

void print_8bit_binary(unsigned char n) {
    int i;

    for (i = 7; i >= 0; i--) {
        printf("%d", (n >> i) & 1);

        if (i % 4 == 0) {
            printf(" ");
        }
    }
    printf("\n");
}

int main() {
    unsigned int a = 5;  // binary: 0000 0101
    unsigned int b = 9;  // binary: 0000 1001
    unsigned int result;
    printf("the value of a = %d \n", a);
    printf("the value of a in binary is \n");
    print_8bit_binary(a);
    printf("the value of b = %d \n", b);
    printf("the value of b in binary is \n");
    print_8bit_binary(b);
    // Bitwise AND
    result = a & b;  // binary: 0000 0001
    printf("a & b = %u\n", result);  // output: 1

    // Bitwise OR
    result = a | b;  // binary: 0000 1101
    printf("a | b = %u\n", result);  // output: 13

    // Bitwise XOR
    result = a ^ b;  // binary: 0000 1100
    printf("a ^ b = %u\n", result);  // output: 12

    // Bitwise NOT (complement)
    result = ~a;  // binary: 1111 1010 (two's complement)
    printf("~a = %u\n", result);  // output: 4294967290 (on a 32-bit system)

    // Left Shift
    result = a << 1;  // binary: 0000 1010 (shifts bits to the left by 1 position)
    printf("a << 1 = %u\n", result);  // output: 10

    // Right Shift
    result = b >> 1;  // binary: 0000 0100 (shifts bits to the right by 1 position)
    printf("b >> 1 = %u\n", result);  // output: 4

    return 0;
}


/*


Explanation:

    Bitwise AND (&):
        Each bit in the result is 1 if the corresponding bits of both operands are 1; otherwise, the bit is 0.
        a & b results in 0000 0001 (decimal 1).

    Bitwise OR (|):
        Each bit in the result is 1 if the corresponding bit of either operand is 1; otherwise, the bit is 0.
        a | b results in 0000 1101 (decimal 13).

    Bitwise XOR (^):
        Each bit in the result is 1 if the corresponding bits of the operands are different; otherwise, the bit is 0.
        a ^ b results in 0000 1100 (decimal 12).

    Bitwise NOT (~):
        Each bit in the result is the complement of the corresponding bit in the operand (flips all bits).
        ~a results in 1111 1010 (decimal 4294967290 on a 32-bit system, as it represents the two's complement).

    Left Shift (<<):
        Shifts all bits in a to the left by the number of positions specified, filling with zeros from the right.
        a << 1 results in 0000 1010 (decimal 10).

    Right Shift (>>):
        Shifts all bits in b to the right by the number of positions specified, filling with zeros from the left (for unsigned integers).
        b >> 1 results in 0000 0100 (decimal 4).

*/