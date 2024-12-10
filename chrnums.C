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
