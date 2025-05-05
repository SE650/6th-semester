#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#define MAXN 1024
#define ALPHA_LENGTH 26
#define COMMON_COUNT 10

char* vigenere_decrypt(char* plaintext, char* key)
{
    int text_length = strlen(plaintext);
    int key_length = strlen(key);

    char* decipher = (char*) malloc(sizeof(char) * (text_length + 1));
    memset(decipher, '\0', sizeof(char) * (text_length + 1));

    char* key_ptr = key;
    for(int i = 0; i < text_length; i++)
    {
        if(isalpha(plaintext[i]))
        {
            int shift = tolower(*key_ptr) - 'a';


            if(islower(plaintext[i]))
            {
                decipher[i] = 'a' + (plaintext[i] - 'a' - shift + 26) % 26;
            }
            else
            {
                decipher[i] = 'A' + (plaintext[i] - 'A' - shift + 26) % 26;
            }
            key_ptr++;
            if (*key_ptr=='\0') {
                key_ptr=key;
            }
        }
        else
        {
            decipher[i] = plaintext[i];
        }
    }

    decipher[text_length] = '\0';
    return decipher;
}

int* count_frequencies(char* cipher)
{
    int* frequency = (int*) malloc(sizeof(int) * ALPHA_LENGTH);
    memset(frequency, 0, sizeof(int) * ALPHA_LENGTH);
    int length = strlen(cipher);
    for(int i = 0; i < length; i++)
    {
        int position = tolower(cipher[i]) - 'a';
        frequency[position]++;
    }

    return frequency;
}

int get_max_index(int* frequencies)
{
    int max_index = 0;
    for(int i = 0; i < ALPHA_LENGTH; i++)
    {
        if(frequencies[i] > frequencies[max_index])
        {
            max_index = i;
        }
    }
    return max_index;
}

void split_substrings(char* input, char** substring, int keyLength) {

    int len = strlen(input);
    for (int i = 0; i < keyLength; i++) {
        int idx = 0;
        for( int j = 0; j < len; j += keyLength) {
            substring[i][idx++] = input[j];
        }
        substring[i][idx] = '\0';
    }

}

int best_shift(char* substring, char* common_letters, int order_len) {

    int freq[ALPHA_LENGTH] = {0};
    int len = strlen(substring);

    for(int i = 0; i < len; i++) {
        if (substring[i] >= 'a' && substring[i] <= 'z') {
            freq[substring[i] - 'a']++;
        }
    }

    get_max_index(freq);

    for (int i = 0; i < order_len; i++) {
        int target = freq_order[i] - 'a';
        int shift = (max_index - target + 26) % 26;
        return shift;
    }
    return 0;
}

int main() {

char input[MAXN];
printf("Type in the text: ");
scanf("%[^\n]s" ,input);

int keyLength;
printf("First version: Type in the length of the unknown key: ");
scanf("%d", keyLength);

char substring[MAXN][MAXN];

int* frequencies = count_frequencies(input);
char max_letter = get_max_index(frequencies) + 'a';
char common_letters[COMMON_COUNT] = {'e', 't', 'a', 'o', 'i', 'n',
     's', 'r', 'h', 'l'};
    return 0;

}