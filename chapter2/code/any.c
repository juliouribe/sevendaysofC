#include <string.h>
#include <stdio.h>

int any(char[], char[]);

int main(){
    printf("%d\n", any("banana", "boy"));
    return 0;
}

int any(char s1[], char s2[]){
    for(int i = 0; i < strlen(s1); i++){
        for (int j = 0; j < strlen(s2); j++){
            if (s1[i] == s2[j])
                return i;
        }
    }
    return -1;
}

