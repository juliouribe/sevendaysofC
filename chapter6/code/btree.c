#include <stdio.h>

struct tnode {
    int val;
    struct tnode *left;
    struct tnode *right;
};

void add(struct tnode *p, struct tnode *c);
void printTree(struct tnode *p);

int main() {
    struct tnode head = {5};
    struct tnode a1 = {2};
    struct tnode a2 = {3};
    struct tnode c1 = {9};
    struct tnode b1 = {1};
    struct tnode b2 = {7};
    struct tnode c2 = {2};
    struct tnode d1 = {4};
    struct tnode d2 = {5};
    struct tnode arr[] = {a1,a2, c1, b1, b2, c2, d1,d2};
    struct tnode *a = &head;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        struct tnode *b = &arr[i];
        add(a, b);
    }
    // printf("%d\n", head.val);
    // printf("%d\n", head.left->val);
    // printf("%d\n", head.right->val);
    // printf("%d\n", head.right->left->left->val);
    printTree(a);
    return 0;
}

void add(struct tnode *p, struct tnode *c){
    /*
    Compare against head value, if larger add to the right
    if smaller add to the left
    */
    if (c->val < p->val)
        if (p->left == (void *)0)
            p->left = c;
        else
            add(p->left, c);
    else
        if (p->right == (void *)0)
            p->right = c;
        else
            add(p->right, c);
}

void printTree(struct tnode *p) {
    if (p != (void *)0) {
        printf("%d\n", p->val);
        printTree(p->left);
        printTree(p->right);
    }
}
