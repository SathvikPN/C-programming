#include<stdio.h>
#include<string.h>
void eval(char);
int string_length(char*);
int main()
{
    char line[100];

    /* line scanner */
    scanf("%[^\n]%*c", line); 

    printf("[%s]\n", line);
    printf("string_length: %d\n", string_length(line));
    for (int i=0; i<string_length(line); i++)
        eval(line[i]);
}

int string_length(char *line)
{
    int length=0;
    for(char *c=line; *c!='\0'; c++ )
        length++;
    return length;
}

void eval(char c)
{
    printf("%c : ", c);
    if (c>='A' && c<='Z')   
    {
        puts("Upper-case");
    }

    else if (c>='a' && c<='z')
    {
        puts("lower-case");
    }

    else if (c>='0' && c<='9')  
    {
        puts("digit");
    }

    else if (c==' ' || c=='\t' || c=='\n')
    {
        puts("white space");
    }
    
    else
    {
        puts("NOT {letter,digit,whitespace}");
    }
    
    
    
    
}
