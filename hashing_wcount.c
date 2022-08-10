/* hash-table with chaining that stores frequency of words in file */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG 1

#define INPUT_FILE "book.txt"

#define MAX_BUCKETS 1000
#define MULTIPLIER 31
#define MAX_LEN    1024

struct wordrec {
    char *word;
    unsigned long count;
    struct wordrec* next;
};

struct wordrec* hashtable[MAX_BUCKETS]; /* HASH-table: Array of wordrec */

unsigned long hashstring(const char* word); /* produce hash value for word */

struct wordrec* walloc(const char* word); /* allocates new node */
struct wordrec* lookup(const char* word); /*return pointer to wrecord if exist. else NULL */
struct wordrec* update_hashtable(const char* word); /* if word exist, increment its counter. else makes new wrecord */
void process_table(struct wordrec** hashtable, int hashtable_array_len);
void cleartable(); /* reclaims memory */

int main()
{
    FILE* fp = fopen(INPUT_FILE, "r");
    if(!fp)
    {
        puts("Unable to open file");
        exit(1);
    }
    char word[MAX_LEN]; 

    /* set zero for all hash-array elements */
    memset(hashtable, 0, sizeof(hashtable));

    /* read word-strings from file */
    while(fscanf(fp, "%s", word) == 1)
        update_hashtable(word);

    fclose(fp);

#if DEBUG
    struct wordrec *pwr;
    for(int i=0; i<MAX_BUCKETS; i++)
    {
        pwr = hashtable[i];
        if(pwr)
            printf("[%s (%ld)]", pwr->word, pwr->count);
    }
    puts("");
#endif
    process_table(hashtable, MAX_BUCKETS);
    cleartable();
    return 0; 
}


/* Definitions ------------------------------------------------------------------------------- */

/* produce hash value for passed string word */
unsigned long hashstring(const char* word)
{
    unsigned long hash = 0;
    while(*word)
    {
        hash = (hash * MULTIPLIER) + (*word);
        word++;
    }

    return (hash % MAX_BUCKETS);
}

/* allocates and initialise new word-record */
struct wordrec* walloc(const char* word)
{
    struct wordrec *pwr = (struct wordrec *)malloc(sizeof(struct wordrec));
    pwr->word = strdup(word);
    pwr->count = 1;
    pwr->next = NULL;
    return pwr;
}

/* Returns pointer to wrecord if exist. else NULL */
struct wordrec* lookup(const char* word)
{
    unsigned long hash = hashstring(word);
    struct wordrec *pwr = hashtable[hash];
    while(pwr)
    {
        /* BUGFIX: comparing strings pwr->word == word which checks if address of starting char of both strings are same */
        if(!strcmp(pwr->word, word))
            return pwr;
        pwr = pwr->next;
    }
    return NULL;
}

/* if word exist, increment its counter. else makes new wrecord */
struct wordrec* update_hashtable(const char* word)
{
    unsigned long hash = hashstring(word);
    struct wordrec *pwr = hashtable[hash];
    
    if(!pwr)
    {
        hashtable[hash] = walloc(word);
        return hashtable[hash];
    }

    while(1)
    {
        /* BUGFIX: comparing strings pwr->word == word which checks if address of starting char of both strings are same */
        int difference = strcmp(pwr->word, word);
        if(!difference)
        {
            pwr->count++;
            return pwr;
        }

        /* else: this is not the suitable wrecord */
        if(!pwr->next)
        {
            pwr->next = walloc(word);
            return pwr->next;
        }

        /* next wrecord exist */
        pwr = pwr->next;
    }

    return NULL; /* This return signals failure */
}

/* some processing on loaded hashtable */
void process_table(struct wordrec** hashtable, int hashtable_array_len)
{
    #define INPUT_MAX 256
    char input_word[INPUT_MAX];
    puts("   INPUT FORMAT: {word}{enter}");
    puts("RESPONSE FORMAT: [word](count)");
    puts("------------------------------------------");
    do
    {
        printf("Enter word to lookup: ");
        fflush(stdout);
        if(!fgets(input_word, INPUT_MAX, stdin))
            abort(); /* failed to read stdin */
        
        unsigned int len = strlen(input_word);
        
        /* remove trailing newline character */
        if(len>0 && input_word[len-1] == '\n')
        {
            input_word[len-1] = '\0';
            --len;
        }

        /* PROCESSING ------------------------------------*/
        if(len==0)
        {
            puts("------------------------------------");
            puts("USER ended the program.");
            return;
        }
        
        struct wordrec *pwr = lookup(input_word);
        if(pwr)
            printf("[%s](%ld)\n", pwr->word, pwr->count);
        else
            printf("[%s](0)\n", input_word);
    } while (1);
    
}

/* reclaim hashtable memory */
void cleartable()
{
    /* https://stackoverflow.com/questions/33170802/c-does-freeing-an-array-of-pointers-also-free-what-theyre-pointing-to#33170941 */
    /* only dynamically allocated malloc data at heap can be freed dynamically */
    /* code data is automatically reclaimed when program terminates and cannot be dynamically reclaimed */
    for(int i=0; i<MAX_BUCKETS; i++)
    {
        struct wordrec *pwr = hashtable[i];
        struct wordrec *p_del_rec;
        while(pwr)
        {
            p_del_rec = pwr;
            pwr = pwr->next;
            free(p_del_rec);
        }
    }
    return;
}