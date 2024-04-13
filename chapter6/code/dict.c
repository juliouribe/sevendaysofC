#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define HASHSIZE 101

struct nlist { /* table entry: */
    struct nlist *next; /* next entry in chain */
    char *name; /* defined name */
    char *defn; /* replacement text */
};
static struct nlist *hashtab[HASHSIZE]; /* pointer table */ 

unsigned hash(char *s);
struct nlist *lookup(char *s);
struct nlist *install(char *name, char *defn);
int remover(char *name);

int main(){
    char *str1 = install("fruit", "banana")->name;
    printf("%s\n",str1);
    install("fruit", "banana")->name;
    printf("%d\n", remover("fruit"));
    return 0;
}

unsigned hash(char *s)
{
    unsigned hashval;
    for (hashval = 0; *s != '\0'; s++)
        hashval = *s + 31 * hashval;
    return hashval % HASHSIZE;
} 

struct nlist *lookup(char *s)
{
    struct nlist *np;
    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
        if (strcmp(s, np->name) == 0)
            return np; /* found */
    return NULL; /* not found */
} 

struct nlist *install(char *name, char *defn)
{
    struct nlist *np;
    unsigned hashval;
    if ((np = lookup(name)) == NULL) { /* not found */
        np = (struct nlist *) malloc(sizeof(*np)); 
        if (np == NULL || (np->name = strdup(name)) == NULL)
            return NULL;
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    } else /* already there */
        free((void *) np->defn); /*free previous defn */
    if ((np->defn = strdup(defn)) == NULL)
        return NULL;
    return np;
}

int remover(char *name){
    struct nlist *np;
    struct nlist *lp;
    np = hashtab[hash(name)];
    if(np != NULL && strcmp(name, np->name) == 0) {
        free((void *) np); /* found */
        return 1; 
    }
    while(np != NULL) {
        lp = np;
        np = np->next;
        if (strcmp(name, np->name) == 0) {
            lp->next = NULL;
            free((void *) np); /* found */
            return 1;
        }
    }
    return 0; /* not found */
}