#include <stdio.h>
#define EOF -1

int main () {
    int newln, blank, tab, c;
    newln=0;
    blank=0;
    tab=0;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {       // Check if the character is a blank (space)
            blank++;
        } else if (c == '\t') { // Check if the character is a tab
            tab++;
        } else if (c == '\n') { // Check if the character is a newline
            newln++;
        }
    }

    // Print the counts of blanks, tabs, and newlines
    printf("Blanks: %d\n", blank);
    printf("Tabs: %d\n", tab);
    printf("Newlines: %d\n", newln);

    return 0; // Exit the program successfully
}

