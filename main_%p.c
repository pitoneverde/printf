#include "ft_printf.h"
#include <stdio.h>
#include <stdint.h>

void test_pointer_format(const char *format, void *input) {
    int printf_ret;
    int ft_printf_ret;

    printf("Testing: Format = \"%s\" | Input = %p\n", format, input);
    
    printf_ret = printf(format, input);
    ft_printf_ret = ft_printf(format, input);

    printf("printf returned: %d\n", printf_ret);
    printf("ft_printf returned: %d\n", ft_printf_ret);

    if (printf_ret != ft_printf_ret) {
        printf("Mismatch in return values!\n\n");
    } else {
        printf("Return values match: %d\n\n", printf_ret);
    }
}

int main(void) {
    // Test cases for %p format with various edge cases

    void *ptr = (void*)0x12345;  // Sample pointer
    void *null_ptr = NULL;        // Null pointer

    // Basic pointer print
    test_pointer_format("%p", ptr); // Print pointer address
    test_pointer_format("%p", null_ptr); // Print NULL pointer

    // Width (padding with spaces by default)
    test_pointer_format("%20p", ptr);  // Width greater than pointer length
    test_pointer_format("%30p", ptr);  // Wider field

    // Precision (number of hexadecimal digits after `0x`)
    test_pointer_format("%.5p", ptr);  // Limit to 5 hex digits
    test_pointer_format("%.10p", ptr); // Limit to 10 hex digits

    // Zero-padding
    test_pointer_format("%020p", ptr);  // Zero-padding with width
    test_pointer_format("%030p", ptr);  // Larger zero-padded width

    // Left alignment (ensuring the pointer is aligned to the left)
    test_pointer_format("%-20p", ptr); // Left-aligned pointer with width

    // Test edge cases for pointers:
    test_pointer_format("%p", (void*)0);   // Pointer value is 0 (should print (nil))
    test_pointer_format("%p", (void*)0x0); // Another representation of a null pointer

    // Very large address (to test wide pointer handling)
    test_pointer_format("%p", (void*)0xFFFFFFFFFFFFFFFF); // Largest pointer address on 64-bit systems

    // Minimal width for pointer (just the pointer itself)
    test_pointer_format("%1p", ptr);  // Smallest width

    // Test a pointer with precision and width combined
    test_pointer_format("%10.5p", ptr); // Width 10 with precision 5

    return 0;
}
