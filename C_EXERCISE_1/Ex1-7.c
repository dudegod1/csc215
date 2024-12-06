#include <stdio.h>

main() /* Replace multiple blanks with a single blank */
{
    int c, prev_char; // c: current character, prev_char: previous character
    prev_char = 0;    // Initialize previous character to 0
    
    while ((c = getchar()) != EOF) {
        if (c != ' ' || prev_char != ' ') {
            putchar(c);
        }
        prev_char = c; //update previous character

    }
}
