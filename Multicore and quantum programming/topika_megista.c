#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

int main(int argc, char const *argv[])
{
    int i, j, w;
    float *A;
    float *B;
    int N;
    int megisto = 1; 
    float sum = 0, sum2 = 0;
    double start, S_start, end, S_end, S_time_taken, time_taken;
    srand(time(NULL));
    
    printf("Give me the N of the array!!!");
    scanf("%d",&w);
    
    for(N=10; N<=10000000;N*=100){
    printf("\n\nN: %d",N);
    A = (float *)malloc (N * sizeof(float));

    for(i=0; i<N; i++){
        A[i] = rand() % 1000000;
    }

    start = omp_get_wtime(); 
    for(i=w; i<N-w;i++){
        megisto = 1;
        for(j=0)

    }

    end = omp_get_wtime();

    time_taken = end - start;

    S_start = omp_get_wtime();
    #pragma omp single
    for(i=0; i<N; i++){
        sum2 += A[i]; 
    }
    S_end = omp_get_wtime();
    S_time_taken = S_end - S_start;
        free(A);
    printf("\nSum: %d\n", sum);
    printf("Time Took parallel: %2.6f\n",time_taken);
    printf("Time Took Sequentially: %2.6f\n",S_time_taken);
}
    return 0;
}
