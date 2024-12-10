#include <stdio.h>
#define MAXLINE 80

main(argc, argv)
    int argc;
    char* argv[];
{
    FILE *infp;
    int c, len;
    c = len = 0;
    char words[MAXLINE];

     if (argc != 2){
        printf("Usage: CHRNUMS <infile>\n");
        exit();
    }
    if((infp = fopen(argv[1], "r")) == NULL){
        printf("Can't open %s\n", argv[1]);
        exit();
    }else{
        infp = fopen(argv[1], "r")
        while ((c = fgetc(infp)) != EOF) {
            if (c == "\n"){
                words[len] = '\0'; /* If it's a new line, it will make that position to nUll*/
                printf("%d: %s\n", len, words);
                len = 0;
                continue;
