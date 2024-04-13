#include <stdio.h>
#define MAX_LENGTH 140

struct manufacturer
{
    char company[MAX_LENGTH];
};

struct toy
{
    char name[MAX_LENGTH];
    struct manufacturer *manu;
};

struct cat
{
    char name[MAX_LENGTH];
    struct toy *favorite;
};

int main()
{
    struct manufacturer hasbro = {"Hasbro"};
    struct manufacturer *h = &hasbro;
    struct toy ball = {"ball", h};
    struct toy *b = &ball;
    struct cat jerry = {"Jerry", b};
    printf("%s\n", jerry.name);
    printf("Favorite toy is a %s\n", jerry.favorite->name);
    // printf("Favorite toy is a %s\n", (*(jerry.favorite)).name);
    // printf("Brought you by %s\n", jerry.favorite->manu->company);
    printf("Brought you by %s\n", (*((*(jerry.favorite)).manu)).company);

    return 0;
}
