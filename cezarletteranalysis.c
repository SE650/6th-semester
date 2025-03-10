#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 1000
#define ALPHA_LENGTH 26
#define COMMON_COUNT 10

char* cezar_decipher(char* str, int key){
    int length = strlen(str);
    char* plaintext = (char*) malloc (sizeof(char) * (length + 1));
    for (int i = 0; i < length; i++) {
        if (str [i] >= 'a' && str[i] <= 'z') {
            plaintext[i]= ((str[i] - 'a') - key + 26) % 26 + 'a';
        }
        else if (str [i] >= 'A' && str[i] <= 'Z') {
            plaintext[i]= ((str[i] - 'A') - key + 26) % 26 + 'A';
        } 
        else if(str [i] >= '0' && str [i] <= '9') {
            plaintext[i] = ((str[i] - '0') - key + 10) % 10 + '0';
        }
        else {
            plaintext[i] = str[i];
        }
    }
    return plaintext;
}

int* count_frequencies(char* cypher){
    int* frequency = (int*) malloc(sizeof(int) * ALPHA_LENGTH);
    memset(frequency, 0 , sizeof(int) * ALPHA_LENGTH);
    int length = strlen(cypher);
    for(int i = 0; i < length; i++) {
        char letter = tolower(cypher[i]);

        if(letter >= 'a' && letter <= 'z'){
            int position = letter - 'a';
            frequency[position]++;
        }
    }
    return frequency;
}

int get_max_index(int* frequency) {
    int max_index = 0;
    for (int i = 0; i < ALPHA_LENGTH; i++) {
        if(frequency[i]>frequency[max_index]) {
            max_index = i;
        }
    }
    return max_index;
}

int main() {
    char cipher[MAXN];
    scanf("%s", cipher);

    char letters[COMMON_COUNT] = {'e', 't','a','o','i','n','s','r','h','l'};

    int most_common_letter = get_max_index(count_frequencies(cipher)) + 'a';
    for(int i = 0; i < COMMON_COUNT; i++) {
        int key = abs(most_common_letter - letters[i]);
        printf("The key is: %d\n", key);
        char* plaintext = cezar_decipher(cipher, key);
        printf("%s\n", plaintext);
        free(plaintext);

    }
    
    return EXIT_SUCCESS;

}