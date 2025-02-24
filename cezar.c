#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 1000
//((str[i] - 'a') + shift) % 26 + 'a'
char* cezar_cipher(char* str, int key){
    int length = strlen(str);
    char* cipher = (char*) malloc (sizeof(char) * (length + 1));
    for (int i = 0; i < length; i++) {
        if (str [i] >= 'a' && str[i] <= 'z') {
            cipher[i]= ((str[i] - 'a') + key) % 26 + 'a';
        }
        else {
            cipher[i] = str[i];
        }
    }
    return cipher;
}

int main () {

    char str[MAXN];
    scanf("%s", str);
    int key;
    scanf("%i", &key);
    char* cipher = cezar_cipher(str, key);
    printf("%s", cipher);
    return EXIT_SUCCESS;
}