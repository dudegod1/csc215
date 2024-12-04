#include <stdio.h> //I/O library for input/output functions like printf()

int main(argc, argv) // main func definition with arguments
int argc; // argument count, including the program name
char *argv[]; // array of strings holding command line arguments
{
        int i; // declares loop counter var
        int total; // var to store cumulative total 
        total = 0; // initializes total to 0
        
        // Loop through each command-line argument starting from index 1 (skipping the program name)
        for (i = 1; i < argc; i++) { 
            int num; // declares var to store converted int
            num = atoi(argv[i]); // converts current argument (string) to int

            // checks if conversion failed
            if (num == 0) {
			    printf("Ruh Roh! %s is not a number", argv[i]);
			    return 1;
		    }

                total += num;
        }
        

        printf("%d", total);
        return 0;
}
