/*
 * Dictionary implementation using trie data structure
 *
 *  Created on: Aug 8th, 2022
 *      Author: SathvikPN (based on a template)
 */

/* header files */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

/* the trie node data structure */
struct s_trie_node
{
	char * translation; /* NULL if node not a word */

	/* pointer array to child nodes */
	struct s_trie_node * children[UCHAR_MAX+1];
};

/* pointer to the root node of the trie structure */
static struct s_trie_node * proot = NULL;

/* helper functions for trie structure */

/* allocate new node on the heap
   output: pointer to new node (must be freed) */
struct s_trie_node * new_node(void);

/* delete node and all its children
   input: pointer to node to delete
   postcondition: node and children are freed */
void delete_node(struct s_trie_node * pnode);

/* add word to trie, with translation
   input: word and translation
   output: non-zero if new node added, zero otherwise
   postcondition: word exists in trie */
int add_word(const char * word, char * translation);

/* read dictionary file into trie structure */
unsigned int load_dictionary(const char * filename);

/* search trie structure for word and return translations
   input: word to search
   output: translation, or NULL if not found */
char * lookup_word(const char * word);

/* maximum number of characters for word to search */
#define WORD_MAX 256

/* maximum number of characters in line */
#ifndef LINE_MAX
#define LINE_MAX 2048
#endif

/* main function */
int main(int argc, char * argv[]) {
	char word[WORD_MAX], * translation;
	int len;

	if (argc <= 1)
		return 0; /* no dictionary specified */

	/* load dictionary */
	proot = new_node();
	int src_language_words = load_dictionary(argv[1]);
    printf("[%d] unique source language words are available for translation\n", src_language_words);

	do {
		printf("Enter word to translate: ");
		fflush(stdout);
		if (!fgets(word, WORD_MAX, stdin))
			abort();

		/* strip trailing newline */
		len = strlen(word);
		if (len > 0 && word[len-1] == '\n') {
			word[len-1] = '\0';
			--len;
		}

		/* exit on empty string */
		if (len == 0)
			break;

		/* lookup word */
		translation = lookup_word(word);

		if (translation)
			printf("%s -> %s\n", word, translation);
		else
			printf("\"%s\" not found\n", word);
	} while (1);

	/* clean up trie structure */
	delete_node(proot);

	return 0;
}

/* allocate new node on the heap
   output: pointer to new node (must be freed) */
struct s_trie_node * new_node(void) {
	/* TODO: allocate a new node on the heap, and
	   initialize all fields to default values */
    struct s_trie_node * pnode = (struct s_trie_node*)malloc(sizeof(struct s_trie_node));
    pnode->translation = NULL;
    for(int i=0; i<=UCHAR_MAX; i++)
        pnode->children[i] = NULL;
    return pnode;
}

/* delete node and all its children
   input: pointer to node to delete
   postcondition: node and children are freed */
void delete_node(struct s_trie_node * pnode) {
	/* TODO: delete node and all its children
	   Be sure to free non-null translations!
	   Hint: use recursion
	 */
    if (!pnode)
        return;
    if(pnode->translation)
        free(pnode->translation);
    for(int i=0; i<=UCHAR_MAX; i++)
        delete_node(pnode->children[i]);
    free(pnode);
}

/* add word to trie, with translation
   input: word and translation
   output: non-zero if new node added, zero otherwise
   postcondition: word exists in trie */
int add_word(const char * word, char * translation) {
	/* TODO: add word to trie structure
	   If word exists, append translation to existing
	   string
	   Be sure to store a copy of translation, since
	   the string is reused by load_dictionary()
	 */
    if(!proot)
        proot = new_node();
    struct s_trie_node *pnode = proot;
    int len = strlen(word);
    unsigned char c; /* unsigned ==> 0-255 */
    int is_new_word=0; /* zero if word already exist and only translation is added */
    for(int i=0; i<len; i++)
    {
        c = word[i];
        if(pnode->children[c] == NULL)
        {
            is_new_word = 1;
            pnode->children[c] = new_node();
        }
            
        pnode = pnode->children[c];
    }
    /* No previous translations exist */
    if(!pnode->translation)
    {
        char *pstring = (char *)malloc(sizeof(char)*(strlen(translation)+1)); /* +1 for null character */
        pnode->translation = strcpy(pstring, translation);
    }

    else /* previous translation exist. append this translation */
    {
        char *old_translation = pnode->translation;
        int oldlen = strlen(old_translation);
        int newlen = strlen(translation);
        pnode->translation = (char*)malloc(sizeof(char)*(oldlen + 1 + newlen + 1));
        /* {abc\0} {pq\0} ==> {abc,pq\0}  (oldlen=3 AND newlen=2)*/
        strcpy(pnode->translation, old_translation);
        strcpy(pnode->translation + oldlen, ","); /* offset from &(pnode->translation[0])*/
        strcpy(pnode->translation + oldlen + 1, translation);
    }
    return is_new_word;
}

/* delimiter for dictionary */
#define DELIMS "\t"

/* read dictionary file into trie structure */
unsigned int load_dictionary(const char * filename) {
	FILE * pfile;
	char line[LINE_MAX], * word, * translation;
	unsigned int icount = 0;

	/* ensure file can be opened */
	if ( !(pfile = fopen(filename,"r")) )
		return icount;

	/* read lines */
	while ( (fgets(line, LINE_MAX, pfile)) ) {
		/* strip trailing newline */
		int len = strlen(line);
		if (len > 0 && line[len-1] == '\n') {
			line[len-1] = '\0';
			--len;
		}

		if (len == 0 || line[0] == '#')
			continue; /* ignore comment/empty lines */

		/* separate word and translation */
		word = line + strspn(line, DELIMS);
		if ( !word[0] )
			continue; /* no word in line */
		translation = word + strcspn(word, DELIMS);
		*translation++ = '\0';
		translation += strspn(translation, DELIMS);

		/* add word to trie */
		if (add_word(word, translation))
			icount++;
	}

	/* finish */
	fclose(pfile);
	return icount;
}

/* search trie structure for word and return translations
   input: word to search
   output: translation, or NULL if not found */
char * lookup_word(const char * word) {
	/* TODO: search trie structure for word
	   return NULL if word is not found */
    struct s_trie_node *pnode = proot;
    for(int i=0; i<strlen(word); i++)
    {
        if(pnode->children[word[i]] == NULL)
            return NULL;
        pnode = pnode->children[word[i]];
    }
        
    return pnode->translation;
}

