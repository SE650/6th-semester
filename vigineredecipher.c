//KEY IS faithful for vtext.txt

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXN 1024

char* vigenere_decrypt(char* a, char* k) {

int a_length = strlen(a);
int k_length = strlen(k);

char* decipher = (char*) malloc(sizeof(char)*(a_length + 1));
memset(decipher, '\0', sizeof(char) * (a_length + 1));

char * key_ptr = k;

    for(int i = 0; i <= a_length; i++) {

        if(isalpha(a[i])){

            int shift = tolower(*key_ptr) - 'a';
            
            if(islower(a[i])) {
                decipher[i] = 'a' + (a[i] - 'a' - shift + 26) % 26;
            } else /*if (isupper(a[i]))*/{
                decipher[i] = 'A' + (a[i] - 'A' - shift + 26) % 26;
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
            decipher[i] = a[i];
        }
    }
    decipher[a_length] = '\0';
    return decipher;
    }

    int read_cipher(char* filename, char* str) {
        FILE *fp = fopen(filename, "r");
        if(fp == NULL) {
            printf("Error opening the file!");
            return EXIT_FAILURE;
        }
    
        if (fgets(str, MAXN, fp) == NULL) {
            printf("Error reading from file.");
            return EXIT_FAILURE;
        }
    
        fclose(fp);
        return EXIT_SUCCESS;
    }
    
    void save_results(char* filename, char* text) {
        FILE *fp = fopen(filename, "wb");
        fprintf(fp, "%s", text);
        fclose(fp);
    }

int main () {
    char filename[MAXN];
    printf("Name of the file: ");
    scanf("%s", filename);
    char str[MAXN];
    read_cipher(filename, str);


    char key [MAXN];
    printf("Type in the key: ");
    scanf("%s", key);

    char* decipher = vigenere_decrypt(str, key);
    printf("%s", decipher);
    save_results("plaintext.txt", decipher);
    free(decipher);

    return (EXIT_SUCCESS);
}
