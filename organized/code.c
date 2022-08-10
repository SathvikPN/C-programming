#define DEBUG 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

struct word {
    char* data;
};

struct sentence {
    struct word* data;
    int word_count;//denotes number of words in a sentence
};

struct paragraph {
    struct sentence* data  ;
    int sentence_count;//denotes number of sentences in a paragraph
};

struct document {
    struct paragraph* data;
    int paragraph_count;//denotes number of paragraphs in a document
};

void print_word(struct word w) {
    printf("%s", w.data);
}

void print_sentence(struct sentence sen) {
    for(int i = 0; i < sen.word_count; i++) {
        print_word(sen.data[i]);
        if (i != sen.word_count - 1) {
            printf(" ");
        }
    }
}

void print_paragraph(struct paragraph para) {
    for(int i = 0; i < para.sentence_count; i++){
        print_sentence(para.data[i]);
        printf(".");
    }
}

void print_document(struct document doc) {
    for(int i = 0; i < doc.paragraph_count; i++) {
        print_paragraph(doc.data[i]);
        if (i != doc.paragraph_count - 1)
            printf("\n");
    }
}


char** split_string(char* text, char delim)
{
    assert(text!=NULL);
    char **result = malloc(1);
    int len;
    char *token = strtok(text, &delim);
    while(token)
    {
        len++;
        result = realloc(result, len*sizeof(char*));
        result[len-1] = token;
        token = strtok(NULL, &delim);
    }

    /* terminate array of strings with a NULL */
    len++;
    result = realloc(result, len*sizeof(char*));
    result[len-1] = NULL;
    return result;
}

#if DEBUG
void print_array_string(char **arr)
{
    int i=0;
    while(arr)
    {
        printf("[%s] ", arr[i]);
    }
    puts("");
}
#endif

struct document get_document(char* text) {
    struct document doc;
    struct paragraph *para;
    int npara = 0;
    char** paragraphs = split_string(text, '\n'); /* array of sentence-strings */
    while(paragraphs[npara]!=NULL)
        npara++;

    doc.paragraph_count = npara;
    doc.data = (struct paragraph*) malloc(npara * sizeof(struct paragraph));
    

    for(int i=0; i < npara; i++)
    {
        char **sentences = split_string(paragraphs[i], '.');
        print_array_string(sentences);
        int nsen = 0;
        while(sentences[nsen]!=NULL)
            nsen++;
        doc.data[i].sentence_count = nsen;
        doc.data[i].data = (struct sentence*) malloc(nsen * sizeof(struct sentence));
        // doc.data[i].data[nsen].word_count = 0;

        for(int j=0; j<nsen; j++)
        {
            char **words = split_string(sentences[j], ' ');
            int nwords = 0;
            while(words[nwords])
                nwords++;
            doc.data[i].data[j].word_count = nwords;
            doc.data[i].data[j].data = (struct word*)malloc((nwords)*sizeof(struct word));
            for (int k=0; k<nwords; k++)
                doc.data[i].data[j].data[k].data = words[k];
        }
    }
#if DEBUG
    for(int i=0; i<doc.paragraph_count; i++)
    {
        print_paragraph(doc.data[i]);
    }
#endif 

    return doc;
}

struct word kth_word_in_mth_sentence_of_nth_paragraph(struct document Doc, int k, int m, int n) {
    return Doc.data[n-1].data[m-1].data[k-1];
}

struct sentence kth_sentence_in_mth_paragraph(struct document Doc, int k, int m) { 
    return Doc.data[m-1].data[k-1];
}

struct paragraph kth_paragraph(struct document Doc, int k) {
    return Doc.data[k-1];
}

char* get_input_text() {	
    int paragraph_count;
    scanf("%d", &paragraph_count);

    char p[MAX_PARAGRAPHS][MAX_CHARACTERS], doc[MAX_CHARACTERS];
    memset(doc, 0, sizeof(doc));
    getchar();
    for (int i = 0; i < paragraph_count; i++) {
        scanf("%[^\n]%*c", p[i]);
        strcat(doc, p[i]);
        if (i != paragraph_count - 1)
            strcat(doc, "\n");
    }

    char* returnDoc = (char*)malloc((strlen (doc)+1) * (sizeof(char)));
    strcpy(returnDoc, doc);
    return returnDoc;
}

int main() 
{
    char* text = get_input_text();
    struct document Doc = get_document(text);

    int q;
    scanf("%d", &q);

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 3){
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            struct word w = kth_word_in_mth_sentence_of_nth_paragraph(Doc, k, m, n);
            print_word(w);
        }

        else if (type == 2) {
            int k, m;
            scanf("%d %d", &k, &m);
            struct sentence sen= kth_sentence_in_mth_paragraph(Doc, k, m);
            print_sentence(sen);
        }

        else{
            int k;
            scanf("%d", &k);
            struct paragraph para = kth_paragraph(Doc, k);
            print_paragraph(para);
        }
        printf("\n");
    }     
}

/*

SAMPLE INPUT:
2
Learning C is fun.
Learning pointers is more fun.It is good to have pointers.
3
1 2
2 1 1
3 1 1 1


SAMPLE OUTPUT:
Learning pointers is more fun.It is good to have pointers.
Learning C is fun
Learning
*/