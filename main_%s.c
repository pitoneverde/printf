#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ft_printf.h"  // Include your ft_printf header here

void test_ft_printf(char *format, char *str) {
    int printf_return;
    int ft_printf_return;

    // Capture the return value of printf
    printf_return = printf(format, str);
    
    // Capture the return value of ft_printf
    ft_printf_return = ft_printf(format, str);

    // Output both results along with their return values
    printf("\n\nTesting: Format = \"%s\" | Input = \"%s\"\n", format, str);
    printf("printf returned: %d\n", printf_return);
    printf("ft_printf returned: %d\n", ft_printf_return);

    // Check if the return values match
    if (printf_return == ft_printf_return) {
        printf("Return values match: %d\n", printf_return);
    } else {
        printf("Mismatch in return values!\n");
    }

    // Check if the printed outputs are the same (using external comparison method)
    // This can be done by capturing stdout, but for now it's commented
    // You may implement your own comparison function if you want to automate this
}

int main(void) {
    // Test cases with various combinations of flags and edge cases

    // 1. Basic %s tests
    test_ft_printf("%s\n", "Hello, World!");      // Regular string
    test_ft_printf("%s\n", "");                    // Empty string
    test_ft_printf("%s\n", NULL);                  // NULL string (should print (null))

    // 2. Precision cases
    test_ft_printf("%.5s\n", "Hello, World!");     // Precision: truncate to 5 chars
    test_ft_printf("%.3s\n", "Hi there!");         // Precision: truncate to 3 chars
    test_ft_printf("%.0s\n", "Test");              // Precision 0: should print nothing

    // 3. Width cases
    test_ft_printf("%10s\n", "Hello");             // Width: pad with spaces before
    test_ft_printf("%-10s\n", "Hello");            // Left-alignment, pad with spaces after
    test_ft_printf("%15s\n", "Hello, World!");     // Width > string length
    test_ft_printf("%-15s\n", "Hello, World!");    // Left-alignment with large width

    // 4. Width and Precision combination
    test_ft_printf("%10.5s\n", "Hello, World!");   // Width with precision: truncate string
    test_ft_printf("%.5s\n", "Hello, World!");     // Precision and width
    test_ft_printf("%-10.5s\n", "Hello, World!");  // Left-alignment with precision

    // 5. Zero Padding (although this is less common with %s, we'll test it)
    test_ft_printf("%010s\n", "Hello");            // Zero padding (should pad with spaces, not zeros)

    // 6. Space Padding (single space for non-negative values)
    test_ft_printf("% 10s\n", "Hello");            // Space padding before string
    test_ft_printf("%- 10s\n", "Hello");           // Space padding after string with left-alignment

    // 7. Plus Flag (shouldn't be applied to %s, but we'll test for robustness)
    test_ft_printf("%+10s\n", "Hello");            // Plus flag should not affect %s

    // 8. Multiple flags combined
    test_ft_printf("%-10.5s\n", "Hello, World!");  // Left alignment and precision
    test_ft_printf("%10.3s\n", "Hello, World!");   // Width and precision combined
    test_ft_printf("% 10.5s\n", "Hello, World!");  // Space padding with width and precision
    test_ft_printf("%- 10.5s\n", "Hello, World!"); // Left-aligned with space padding and precision

    // 9. Edge cases
    test_ft_printf("%5s\n", "Short");              // Short string, width larger than string
    test_ft_printf("%-5s\n", "Short");             // Left-aligned short string
    test_ft_printf("%50s\n", "This is a long string that will be padded");  // Very long string
    test_ft_printf("%50.10s\n", "This is a long string that will be truncated"); // Long string with precision
    test_ft_printf("%5.3s\n", "Hi");               // Precision truncates the string

    return 0;
}
