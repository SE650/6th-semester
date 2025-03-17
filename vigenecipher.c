#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXN 1024

char* vigenere_encrypt(char* a, char* k) {

int a_length = strlen(a);
int k_length = strlen(k);

char* cipher = (char*) malloc(sizeof(char)*(a_length + 1));
memset(cipher, '\0', sizeof(char) * (a_length + 1));

char * key_ptr = k;

    for(int i = 0; i <= a_length; i++) {

        if(isalpha(a[i])){

            int shift = tolower(*key_ptr) - 'a';
            
            if(islower(a[i])) {
                cipher[i] = 'a' + (a[i] - 'a' + shift) % 26;
            } else /*if (isupper(a[i]))*/{
                cipher[i] = 'A' + (a[i] - 'A' + shift) % 26;
            }
            key_ptr++;
            if (*key_ptr=='\0') {
                key_ptr=k;
            }
            
        } /*else if(isdigit(a[i])) {
            int shift_number = isdigit(k[i % k_length]) - '0';
            cipher[i] = '0' + (a[i] - '0' + shift_number) % 26;
        }*/
        else {
            cipher[i] = a[i];
        }
    }
    cipher[a_length] = '\0';
    return cipher;
    }

int main () {
    char textIn [MAXN];
    printf("Type in the text: ");
    scanf("%[^\n]s", textIn);
    char key [MAXN];
    printf("Type in the key: ");
    scanf("%s", key);

    char* cipher = vigenere_encrypt(textIn, key);
    printf("%s", cipher);
    free(cipher);

    return (EXIT_SUCCESS);
}