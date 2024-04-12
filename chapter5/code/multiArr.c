#include <stdio.h>

char *month_name(int);

int main() {
    // int days[3][3] = {
    //     {1, 2, 3},
    //     {1 , 2}
    // };
    // printf("%c\n", days[2][2]);
    char *p = month_name(2);
    printf("%s\n", p);

    return 0;
}

/* month_name:  return name of n-th month */
char *month_name(int n) {
    static char *name[] = {
        "Illegal month",
        "January", "February", "March",
        "April", "May", "June",
        "July", "August", "September",
        "October", "November", "December"
    };
    name[2] = "Chunk";
    // printf("%s\n", name[2]);
    return (n < 1 || n > 12) ? name[0] : name[n];
}
