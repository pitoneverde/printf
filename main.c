#include "ft_printf.h"
#include <stdio.h>

int main() {
    char c = 'A';
    char *str = "Hello, World!";
    void *ptr = &c;  // Just using the address of `c` as an example pointer
    unsigned int u;
    int i = 456;
    unsigned int x = 0x123ABC;

    int a;
    int b;
    a = printf("Testing format specifiers:\n");
    b = ft_printf("Testing format specifiers:\n");
    if (a != b) printf("a:%d, b:%d\n", a, b);
    a = printf("Testing format specifiers:%%\n");
    b = ft_printf("Testing format specifiers:%%\n");
    if (a != b) printf("a:%d, b:%d\n", a, b);
    a = printf("Character: %c\n", c);
    b = ft_printf("Character: %c\n", c);
    if (a != b) printf("a:%d, b:%d\n", a, b);
    a = printf("String: %s\n", str);
    b = ft_printf("String: %s\n", str);
    if (a != b) printf("a:%d, b:%d\n", a, b);
    a = printf("Pointer: %p\n", ptr);
    b = ft_printf("Pointer: %p\n", ptr);
    if (a != b) printf("a:%d, b:%d\n", a, b);
    a = printf("Unsigned int: %u\n", u);
    b = ft_printf("Unsigned int: %u\n", u);
    if (a != b) printf("a:%d, b:%d\n", a, b);
    a = printf("Signed int: %i\n", i);
    b = ft_printf("Signed int: %i\n", i);
    if (a != b) printf("a:%d, b:%d\n", a, b);
    a = printf("Hexadecimal (lowercase): %x\n", LONG_MAX);
    b = ft_printf("Hexadecimal (lowercase): %x\n", LONG_MAX);
    if (a != b) printf("a:%d, b:%d\n", a, b);
    a = printf("Hexadecimal (uppercase with #): %#X\n", x);
    b = ft_printf("Hexadecimal (uppercase with #): %#X\n", x);
    if (a != b) printf("a:%d, b:%d\n", a, b);
    a = printf("Left-justified: %-10d\n", i);
    b = ft_printf("Left-justified: %-10d\n", i);
    if (a != b) printf("a:%d, b:%d\n", a, b);
    a = printf("With width and precision (.3): %.3d\n", 1);
    b = ft_printf("With width and precision (.3): %.3d\n", 1);
    if (a != b) printf("a:%d, b:%d\n", a, b);
    a = printf("With + sign: %+d\n", i);
    b = ft_printf("With + sign: %+d\n", i);
    if (a != b) printf("a:%d, b:%d\n", a, b);
    a = printf("With space flag (positive value): % d\n", u);  // Space flag for positive number
    b = ft_printf("With space flag (positive value): % d\n", u);  // Space flag for positive number
    if (a != b) printf("a:%d, b:%d\n", a, b);
    a = printf("With space flag (positive value): % d\n", i);  // Space flag for negative number
    b = ft_printf("With space flag (positive value): % d\n", i);  // Space flag for negative number
    if (a != b) printf("a:%d, b:%d\n", a, b);
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
