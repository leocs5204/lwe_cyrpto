#include "main.h"
#include <string.h>
#include "cpucycles.h"
#include "speed_print.h"
#include "debug.h"
#include "genmatrix.h"


//#include "encryption.h"
//#include "decryption.h"


uint64_t t[NTESTS];

static int read_message(uint8_t *m){
    unsigned int i;
    
    FILE* ptr;
    char ch;
    i=0;

    //Opening file in read mode
    ptr = fopen("plaintext.txt", "r");
    
    if(NULL == ptr) {
        return -1;
    }

    printf("content of this file are :\n");

    do {
        printf("i=%d \n",i);
        ch = fgetc(ptr);
        m[i] = (uint8_t)ch;
        i++;
        printf("%c", ch);
    } while(ch != EOF);
    printf("\n\n");
    // Close the file
    fclose(ptr);

    return 0;
}



int main(){
    unsigned int i, j;
    
    int len = 0;
    int read = 0;
    uint8_t  plain_text[N/8];
    vec matrixA[K];
    vec ap;
    


    //generate random message
    if(read_message(plain_text)){
        printf("No file access, terminate the process!\n");
        return 0;
    }

    PRINTF(DEBUG_MESSAGE, "Read message in ASCII code: ");
    for(i=0;i<N/8;i++)
        PRINTF(DEBUG_MESSAGE, "%d ", plain_text[i]);

    // generate matrix A
    for(i=0;i<NTESTS;i++) {
        t[i] = cpucycles();
        gen_matrix(matrixA, K);
    }
    print_results("gen_a: ", t, NTESTS);
    for(i=0;i<K;i++) {
        PRINTF(DEBUG_MATRIX, " [");
        for(j=0;j<K;j++){
            PRINTF(DEBUG_MATRIX, " %d ", matrixA[i].entry[j]);
        }
        PRINTF(DEBUG_MATRIX, "]\n");
    }
/*
    for(i=0;i<NTESTS;i++) {
        t[i] = cpucycles();
        getnoise_eta1(&ap, seed, 0);
    }
    print_results("poly_getnoise_eta1: ", t, NTESTS);
 
    for(i=0;i<NTESTS;i++) {
        t[i] = cpucycles();
        getnoise_eta2(&ap, seed, 0);
    }
    print_results("poly_getnoise_eta2: ", t, NTESTS);

    for(i=0;i<NTESTS;i++) {
        t[i] = cpucycles();
        poly_ntt(&ap);
    }

    for(i=0;i<NTESTS;i++) {
        t[i] = cpucycles();
        gen_keypair(pk, sk);
    }
    print_results("indcpa_keypair: ", t, NTESTS);

    for(i=0;i<NTESTS;i++) {
        t[i] = cpucycles();
        encrytion(ct, key, pk, seed);
    }
    print_results("encrytion: ", t, NTESTS);

    for(i=0;i<NTESTS;i++) {
        t[i] = cpucycles();
        decryption(key, ct, sk);
    }
    print_results("decryption: ", t, NTESTS);
*/
    return 0;
}