#include <stdio.h>

int isPrime(int n){
    if(n < 2) return 0;
    if(n != 2 && n % 2 == 0) return 0;

    for (int i = 3; i * i <= n; i += 2) {
        if(n % i == 0) return 0;
    }

    return 1;
}

int mdc(int n1, int n2, int resto) { 
    while(n2!=0){ 
        resto = n1%n2; 
        n1 = n2; 
        n2 = resto; 
    } 

    return n1;
}

/* Valor do bloco ASCII não pode ser maior que p*q, para isso deve-se evitar primos p ou q menores que 10. (ex.: p=7 e q=5, n=35, a maioria dos blocos ASCII possuem valores maiores que N e isso n pode ocorrer no algoritmo RSA) */

int chavePublica(int p, int q, int e){
    int flag = 0;

    if( mdc(e, (p-1)*(q-1), 0) && isPrime(q) && isPrime(p) && p > 10 && q > 10){
        return 1;
    }else{
        if(!mdc(e, (p-1)*(q-1), 0)){
            //o expoente e não é relativamente primo a (p-1)(q-1)
            return 2;
        }else if(!isPrime(q)){
            //q não é primo
            return 3;
        }else if(!isPrime(p)){
            //p não é primo
            return 4;
        }else if(p < 10 || q < 10){
            //Valor do bloco ASCII não pode ser maior que p*q
            return 5;
        }
    }

}