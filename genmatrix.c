#include "main.h"
#include "genmatrix.h"


uint16_t uniform_sampling(){
    int x = rand() % Q;
}

void gen_matrix(vec *matrix, int dim){
    uint8_t i, j;
    for(i=0;i<dim;i++){
        for(j=0;j<dim;j++){
            matrix[i].entry[j] = uniform_sampling();
        }
    }
}