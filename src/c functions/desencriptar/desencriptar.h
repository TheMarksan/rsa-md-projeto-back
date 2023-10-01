#include <stdio.h>
#include <gmp.h>

void expMod(mpz_t result, const mpz_t base, const mpz_t expoente, const mpz_t mod) {
    mpz_powm(result, base, expoente, mod);
}

int desencriptar(int encriptada[], int p, int q, int e, int arrSize) {
    mpz_t mpzP, mpzQ, mpzE, mpzProduct, mpzInverse, mpzN;
    mpz_init(mpzP);
    mpz_init(mpzQ);
    mpz_init(mpzE);
    mpz_init(mpzProduct);
    mpz_init(mpzInverse);
    mpz_init(mpzN);

    mpz_set_si(mpzP, p);
    mpz_set_si(mpzQ, q);
    mpz_set_si(mpzE, e);

    mpz_mul(mpzN, mpzP, mpzQ); //n = p*q
    mpz_sub_ui(mpzP, mpzP, 1); //p-1
    mpz_sub_ui(mpzQ, mpzQ, 1); //q-1
    mpz_mul(mpzProduct, mpzP, mpzQ); //product = (p-1)*(q-1)

    mpz_invert(mpzInverse, mpzE, mpzProduct); //calcular o d(inverso) de e mod product

    FILE *outputFile = fopen("desencriptado.txt", "wb"); // Abrir em modo binário
    //estou a olhar
    
    if (outputFile == NULL) {
        perror("Erro ao abrir o arquivo de saída");
        mpz_clear(mpzP);
        mpz_clear(mpzQ);
        mpz_clear(mpzE);
        mpz_clear(mpzProduct);
        mpz_clear(mpzInverse);
        mpz_clear(mpzN);
        return 1; // Return an error code
    }

    char desencriptada[arrSize];

    for (int i = 0; i < arrSize; i++) {
        mpz_t ascii, item;
        mpz_init(ascii);
        mpz_init(item);

        mpz_set_si(item, encriptada[i]);
        expMod(ascii, item, mpzInverse, mpzN);

        unsigned long int asciiValue = mpz_get_ui(ascii);
        char decryptedChar = (char)asciiValue;
        desencriptada[i] = decryptedChar;
        fwrite(&decryptedChar, sizeof(char), 1, outputFile);

        mpz_clear(ascii);
        mpz_clear(item);
    }

    fclose(outputFile);

    mpz_clear(mpzP);
    mpz_clear(mpzQ);
    mpz_clear(mpzE);
    mpz_clear(mpzProduct);
    mpz_clear(mpzInverse);
    mpz_clear(mpzN);
    return 0; 
}
