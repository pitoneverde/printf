#include "ft_printf.h"
#include <stdio.h>

int main() {
    char c = 'A';
    char *str = "Hello, World!";
    void *ptr = &c;  // Just using the address of `c` as an example pointer
    unsigned int u = 123;
    int i = -456;
    unsigned int x = 0x123ABC;

    printf("Testing format specifiers:\n");
    ft_printf("Testing format specifiers:\n");
    printf("Character: %c\n", c);
    ft_printf("Character: %c\n", c);
    printf("String: %s\n", str);
    ft_printf("String: %s\n", str);
    printf("Pointer: %p\n", ptr);
    ft_printf("Pointer: %p\n", ptr);
    printf("Unsigned int: %u\n", u);
    ft_printf("Unsigned int: %u\n", u);
    printf("Signed int: %i\n", i);
    ft_printf("Signed int: %i\n", i);
    printf("Hexadecimal (lowercase): %x\n", x);
    ft_printf("Hexadecimal (lowercase): %x\n", x);
    printf("Hexadecimal (uppercase with #): %#X\n", x);
    ft_printf("Hexadecimal (uppercase with #): %#X\n", x);
    // printf("Left-justified: %-10d\n", i);
    // ft_printf("Left-justified: %-10d\n", i);
    // printf("With width and precision (.0): %.0f\n", 123.456);
    // ft_printf("With width and precision (.0): %.0f\n", 123.456);
    // printf("With + sign: %+d\n", i);
    // ft_printf("With + sign: %+d\n", i);
    // printf("With space flag (positive value): % d\n", u);  // Space flag for positive number
    // ft_printf("With space flag (positive value): % d\n", u);  // Space flag for positive number
    // printf("With space flag (positive value): % d\n", i);  // Space flag for negative number
    // ft_printf("With space flag (positive value): % d\n", i);  // Space flag for negative number
	// t_flags *flags;
	// flags->left = 0;
	// flags->plus = 0;
	// flags->zero = 0;
	// flags->space = 0;
	// flags->prec = -1;
	// flags->neg = 0;
	// flags->width = 10;
	// flags->neg = 1;
	// print_num_string("123456", 0, 10, flags);
    return 0;
}
