/* count words, lines, characters of files passed as parameter */
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

/* globals nwords, nlines, ncharacters */
unsigned long int nw=0, nl=0, nc=0;

void process_file(char* filename);

int main(int argc, char *argv[])
{
    int nfiles = --argc; /*ignore the name of the program itself*/
    unsigned long int twords, tlines, tcharacters;
    twords = tlines = tcharacters = 0;

    if (nfiles>0)
    {
        printf("%6s %6s %6s    %s", "words", "lines","chars", "files");

        puts("");
    }
    /* Process each files */
    for(int argidx=1; argidx<=nfiles; argidx++)
    {
        /* updates global variables nw, nl, nc */
        process_file(argv[argidx]);
        
        /* Log and reset globals */
        twords+=nw;
        tlines+=nl;
        tcharacters+=nc;
        nw = nl = nc = 0;
    }

    if (nfiles>0)
    {
        puts("");
        printf("%6ld %6ld %6ld    total\n", twords, tlines, tcharacters);
    }
}


void process_file(char *filename)
{
    FILE *fp = NULL;
    fp = fopen(filename, "r");
    if (fp==NULL)
    {
        printf("[Unable to open]: %s \nEXIT\n", filename);
        exit(1);
    }

    /* processing */
    nw = nl = nc = 0;
    char c;
    int flag_in=0; /* is fp inside a word */
    while((c=getc(fp))!=EOF)
    {
        /* character count */
        nc++;

        /* lines count */
        if (c=='\n')
            nl++;

        /* words count */
        if (!flag_in && !isspace(c))
        {
            flag_in = 1;
            continue;
        }

        if (flag_in && isspace(c))
        {
            nw++;
            flag_in = 0;
        }
    }
    /* last line */
    nl++; 
    if (flag_in && (c==EOF))
        nw++;

    /* display */
    printf("%6ld %6ld %6ld    %s\n", nw, nl, nc, filename);
    fclose(fp);
    return;
}