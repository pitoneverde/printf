#include "ft_printf.h"
#include <stdio.h>

void test_char_format(const char *format, char input) {
    int printf_ret;
    int ft_printf_ret;

    printf("Testing: Format = \"%s\" | Input = \"%c\"\n", format, input);
    
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
    // Test cases for %c format with all flags

    // No flags
    test_char_format("%c", 'A');

    // Width
    test_char_format("%5c", 'A');
    test_char_format("%10c", 'A');

    // Left alignment
    test_char_format("%-5c", 'A');
    test_char_format("%-10c", 'A');

    // Zero-padding
    test_char_format("%05c", 'A');
    test_char_format("%010c", 'A');

    // Space padding
    test_char_format("% 5c", 'A');
    test_char_format("% 10c", 'A');

    // Edge case with empty width/precision
    test_char_format("%0c", 'A');  // Zero padding without width is meaningless but still tested
    test_char_format("% 0c", 'A'); // Space padding with zero doesn't make much sense

    // Testing with a single character and varying widths
    test_char_format("%2c", 'A');  // Minimal padding
    test_char_format("%3c", 'B');  // Padding should be done correctly

    // Testing padding for smaller characters
    test_char_format("%-2c", 'C'); // Left alignment should print 'C' followed by space
    test_char_format("%2c", 'D');  // Padding before 'D'

	 // Width
    test_char_format("%5c", 'A'); // Width greater than 1
    test_char_format("%10c", 'A'); // Width greater than 1

    // Left alignment
    test_char_format("%-5c", 'A'); // Left-align within width
    test_char_format("%-10c", 'A'); // Left-align with more space

    // Zero-padding
    test_char_format("%05c", 'A'); // Zero padding before char
    test_char_format("%010c", 'A'); // Zero padding with larger width

    // Space padding
    test_char_format("% 5c", 'A'); // Space padding before char
    test_char_format("% 10c", 'A'); // Space padding with more width

    // Edge case: Width 1
    test_char_format("%1c", 'A'); // No padding (just the character itself)

    // Edge case: Negative width with left alignment
    test_char_format("%-1c", 'A'); // Extreme case of left alignment with width 1

    // Edge case: Zero width and precision
    test_char_format("%0c", 'A');  // Zero padding without width (no-op for `%c`)
    test_char_format("% 0c", 'A'); // Space padding with zero (likely a no-op)

    // Edge case: Space flag with width 1
    test_char_format("% 1c", 'A'); // Space before single character (should be space)

    // Control characters
    test_char_format("%c", '\n');  // Newline character
    test_char_format("%c", '\t');  // Tab character
    test_char_format("%c", '\0');  // Null character (non-printable)
    test_char_format("%c", '\\');  // Escape character

    // Characters near boundaries
    test_char_format("%c", ' ');   // Space character
    test_char_format("%c", '~');   // Highest ASCII printable character

    return 0;
}
