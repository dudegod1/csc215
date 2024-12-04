#include <stdio.h> //I/O library for input/output functions like printf()

int main(argc, argv) // main func definition with arguments
int argc; // argument counter
char *argv[]; // array of pointers to string
{
        int i; // declares loop counter var
        int total; // var to store cumulative total 
        total = 0; // initializes total to 0
        
        // Loop through each command-line argument starting from index 1 (skipping the program name)
        for (i = 1; i < argc; i++) { 
            int num; // declares var to store converted int
            char *string_check; // Declares a pointer to hold the current string argument
            string_check = argv[i]; // Points to the current command-line argument (string)

            num = atoi(argv[i]); // converts current argument (string) to int
            
            // checks if input is string 
            // num == 0 indicates failure unless the string is literally "0"
            if (num == 0 && *string_check != '0') {
                // Prints an error message if the argument is not a valid number
                printf("Ruh Roh! %s is not a number", argv[i]);
                return 1; // Exits the program with a non-zero status (indicating failure)
            }

            total += num;  // Adds the converted number to the running total
        }

        // Prints the total of all valid arguments after the loop completes
        printf("%d", total);
        return 0;  // Exits the program with a success status (0)
