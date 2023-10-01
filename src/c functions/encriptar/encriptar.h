#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <gmp.h>

void expMod(mpz_t result, const mpz_t base, const mpz_t expoente, const mpz_t mod) {
    mpz_powm(result, base, expoente, mod);
}

int encriptar(char message[], int n, int e){
    int i, arrSize;

    mpz_t asciiNum, n_mpz, e_mpz, result;

    mpz_init(asciiNum);
    mpz_init(n_mpz);
    mpz_init(e_mpz);
    mpz_init(result);


    // Converter os valores normais para GMP
    mpz_set_ui(n_mpz, (unsigned int)n);
    mpz_set_ui(e_mpz, (unsigned int)e);

    arrSize = strlen(message);

    // Tamanho máximo para o array de valores encriptados
    int maxEncryptedValues = 3000;

    if (arrSize > maxEncryptedValues) {
        printf("Erro: A mensagem é muito longa para encriptar.\n");
        return 1;
    }

    // Array para armazenar os valores encriptados
    mpz_t encryptedValues[maxEncryptedValues];

    printf("Mensagem encriptada: ");
    for (i = 0; i < arrSize; i++) {
        // Pré-codificação:
        int asciiValue = (int)message[i];
        mpz_set_ui(asciiNum, asciiValue);
        mpz_init(encryptedValues[i]);
        expMod(encryptedValues[i], asciiNum, e_mpz, n_mpz);

        gmp_printf("%Zd ", encryptedValues[i]);
    }
    printf("\n");

    // Não há necessidade de salvar os valores encriptados em um arquivo

    mpz_clear(asciiNum);
    mpz_clear(n_mpz);
    mpz_clear(e_mpz);
    mpz_clear(result);

}