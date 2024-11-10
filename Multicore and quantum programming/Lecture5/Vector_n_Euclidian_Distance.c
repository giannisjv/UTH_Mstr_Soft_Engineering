#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>
#include <math.h>
#define N 5

int main(int argc, char const *argv[])
{
    int *A = malloc(N * sizeof(int));   // Malloc for dynamic Array A in size of int 4 bytes
    int *B = malloc(N * sizeof(int));   // Malloc for dynamic Array B in size of int 4 bytes

    int i;
    srand(time(NULL));
    double sumA, sumB, cosA, cosB, V_angle, magA, magB, cosine;
    sumA = sumB = 0.0;

    for(i=0; i<N; i++){
        A[i] = rand() % 10;             // Random Numbers from 0 to 9
        B[i] = rand() % 10;
    }

       for(i=0; i<N; i++){
        printf("\nA: %d  B: %d", A[i], B[i]);     
    }

    for(i=0; i<N; i++){
        sumA += A[i] * A[i];            //
        sumB += B[i] * B[i];
    }
    printf("\nA: %2.5f  B: %2.5f", sumA, sumB);  
    magA = sumA * 0.5;                  // Finding the sqrt of sumA (Vector magnitude)
    magB = sumB * 0.5;                  // Finding the sqrt of sumB (Vector magnitude)
    printf("\nA: %2.5f  B: %2.5f", magA, magB); 
    cosine = ((sumA * sumB) / (magA * magB));
    printf("\ncosine %2.5f",cosine);
    V_angle = magA * magB * cos(cosine);

    printf("\n%2.10f\n",V_angle);



    free(A);
    free(B);

    return 0;
}
