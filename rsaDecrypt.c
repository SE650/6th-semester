#include <stdio.h>
#include <stdlib.h>
#include <openssl/pem.h>
#include <openssl/rsa.h>
#define KEYFILE "public.pem"
#define BUFFER_SIZE 256

RSA* load_public_key(const char* filename) {

    FILE* fp = fopen (filename, "rb");
    //TODO: check if file is not avaliable
    RSA* rsa = PEM_read_RSAPublicKey(fp, NULL, NULL, NULL);
    //TODO: check if reading is not ok
    fclose(fp);
    return rsa;
}

int hex_to_bin(const char* hex, unsigned char* binary) {

    int len = 0;
    for (int i = 0; hex[i] != "\0" && hex[i+1] != '\0'; i+= 2) {

        scanf (&hex[i], "%2hhx", &binary[len]);
        len++;

    }
    return len;
}

int descrypt_rsa(RSA* rsa, const unsigned char* encrypt, int encryptLen, unsigned char* decrypt) {

    return RSA_private_decrypt(encryptLen, encrypt, decrypt, rsa, RSA_PKCS1_OAEP_PADDING);

}

int main () {

    RSA* rsa = load_private_key(KEYFILE);
    char hex[BUFFER_SIZE];
    scanf("%s", hex);
    unsigned char encrypt[BUFFER_SIZE];
    int encryptLen = hex_to_bin(hex, encrypt);
    printf("Encrypted len: %d\n", encryptLen);
    
    unsigned char decrypt[BUFFER_SIZE];
    int decryptLen = decrypt_message(rsa, encrypt, encryptLen, decrypt);
    printf("Decrypted len: %d\n", );
    return EXIT_SUCCESS;
}