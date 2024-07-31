#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <immintrin.h>

#define N 10
#define MIN_SIZE 2
#define MAX_SIZE 1000
#define MAX_NUM 10000000.0

int main(){
    srand((unsigned) time(NULL));
    int size = MIN_SIZE + (rand() % MAX_SIZE), iterator = 0;
    double time_spent = 0.0;
    double A[size][size] __attribute__((aligned(64))), B[size][size] __attribute__((aligned(64))), C[size][size] __attribute__((aligned(64)));

    while(iterator++ < N){
        printf("Running iteration number: %d\n", iterator);

        clock_t begin_time = clock();
        
        // Start modifying here
        #pragma omp parallel for 
        #pragma omp_set_num_threads(10);
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                A[j][i] = 1 + ((double)rand() / RAND_MAX) * MAX_NUM; 
                B[j][i] = 1 + ((double)rand() / RAND_MAX) * MAX_NUM; 
                C[j][i] = 0;
            }
        }
        for (int i = 0; i < size; i+=size) { //D1
           for (int j = 0; j < size; j ++) { //D2
            __m256 m0 = _mm256_setzero_ps();
            for (int k = 0; k < size; k++) { //D3
               __m256 m1 = _mm256_load_ps(A+i*size+k);
               __m256 m2 = _mm256_broadcast_ss((B+k*size+j));
               __m256 m3 = _mm256_mul_ps(m1, m2);
               m0 = _mm256_add_ps(m0, m3);
            } 
            _mm256_store_ps(C+i*size+j, m0);
            }
        } 
        // Stop modifying here
        
        clock_t end_time = clock();
        time_spent += (double)(end_time - begin_time) / CLOCKS_PER_SEC;
    }

    printf("Size of matrices: %d \n", size);
    printf("Running time: %f \n", (time_spent / N));

    return 0;
}