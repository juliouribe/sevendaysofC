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

int main(){
    char *str1 = install("fruit", "banana")->name;
    char *str2 = install("fruit", "banana")->defn;
    char *str3 = lookup("fruit")->defn;
    struct nlist *str4 = lookup("banana");
    // printf("%s\n",str1);
    // printf("%s\n",str2);
    printf("%s\n",str3);
    printf("%d\n",str4);
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