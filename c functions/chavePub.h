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

int chavePublica(int p, int q, int e){
    int flag = 0;

    if( mdc(e, (p-1)*(q-1), 0) && isPrime(q) && isPrime(p)){
        return 1;
    }else{
        return 0;
    }

}