#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

void test_int_format(const char *format, int input) {
    int printf_ret;
    int ft_printf_ret;

    printf("Testing: Format = \"%s\" | Input = %d\n", format, input);
    
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
    // Basic test cases for %d format with different integer values
    int positive = 1234;
    int negative = -1234;
    int zero = 0;

    // Basic integer print
    test_int_format("%d", positive);
    test_int_format("%d", negative);
    test_int_format("%d", zero);

    // Width: Print with various widths
    test_int_format("%10d", positive);  // Width of 10
    test_int_format("%5d", negative);   // Width of 5
    test_int_format("%20d", zero);      // Width of 20

    // Precision: Print with varying precision
    test_int_format("%.5d", positive);  // Precision of 5 digits
    test_int_format("%.3d", negative);  // Precision of 3 digits
    test_int_format("%.1d", zero);      // Precision of 1 digit

    // Zero-padding: Print with zero-padding
    test_int_format("%010d", positive); // Zero-padded, width 10
    test_int_format("%05d", negative);  // Zero-padded, width 5
    test_int_format("%020d", zero);     // Zero-padded, width 20

    // Left alignment: Ensure left-aligned integers
    test_int_format("%-10d", positive); // Left-aligned, width 10
    test_int_format("%-5d", negative);  // Left-aligned, width 5
    test_int_format("%-20d", zero);     // Left-aligned, width 20

    // Space flag: Print signed integers with a space for positive numbers
    test_int_format("% 10d", positive);  // Space before positive number
    test_int_format("% 10d", negative);  // Space before negative number (should not affect)
    
    // Plus flag: Print signed integers with explicit plus for positive numbers
    test_int_format("%+10d", positive);  // Explicit plus for positive number
    test_int_format("%+10d", negative);  // Explicit plus for negative number (should show the sign)

    // Negative values with different flags
    test_int_format("%+10d", negative);  // Print negative with the plus flag
    test_int_format("% 10d", negative);  // Print negative with the space flag
    test_int_format("%-10d", negative);  // Left-aligned negative integer

    // Edge cases
    test_int_format("%d", INT_MAX);  // Maximum integer value
    test_int_format("%d", INT_MIN);  // Minimum integer value
    test_int_format("%d", 2147483647); // Another test for INT_MAX on 32-bit systems
    test_int_format("%d", -2147483648); // Another test for INT_MIN on 32-bit systems

    // Test with minimum width and no padding
    test_int_format("%1d", positive);  // Just the number (width 1)
    
    // Combination of flags
    test_int_format("%-+10d", positive);  // Left-aligned, plus sign, width 10
    test_int_format("% 010d", negative);  // Zero-padded, space flag, width 10
    test_int_format("%010.5d", positive); // Zero-padded, width 10, precision 5
    test_int_format("% 5.3d", negative);  // Space flag, width 5, precision 3

    return 0;
}
