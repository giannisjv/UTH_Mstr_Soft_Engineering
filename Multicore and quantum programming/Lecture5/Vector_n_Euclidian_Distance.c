#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>
#include <math.h>
#include "Par_Functions.h"
#include "Sequen_Functions.h"

#define N 200000000

int main(int argc, char const *argv[]){
/* 
VIDRAS IOANNIS

-CPU AMD Ryzen 4600H (mobile) 3Ghz
-12 Cores
-RAM 32GB 3200 M/T
-Fedora 41 workstation
 */


    int *A = malloc(N * sizeof(int));   // Malloc for dynamic Array A in size of int 4 bytes
    int *B = malloc(N * sizeof(int));   // Malloc for dynamic Array B in size of int 4 bytes


    int i;
    // Metrics 
    srand(time(NULL));
    double tot_vect, Par_tot_vect;
    double tot_eu, Par_tot_eu;
    double tot_manh, Par_tot_Manh;
    double tot_wei, Par_tot_wei;
    // Metrics
    //part 1 variables
    double V_angle, Par_V_angle;

    // part 2 variables
    double Eu_dist, Par_Eu_dist;
    double Manh_dist, Par_Manh_dist;

    // part 3 variables  
    double weights, Par_wei;

    for(i=0; i<N; i++){
        A[i] = rand() % 10;             // Random Numbers from 0 to 9
        B[i] = rand() % 10;
    }
/*
       for(i=0; i<N; i++){
        printf("\nA: %d  B: %d", A[i], B[i]);     
    }
*/
#pragma omp 

    printf("\n#########################################################################################\n");
    printf("Vector Angle");
    printf("\n#########################################################################################\n");
    // Sequential
    Seq_vectors(N, A, B, &V_angle, &tot_vect);
    printf("\nV_angle: %2.4f time_took: %2.6f",V_angle, tot_vect);

    // Parallel 
    vectors(N, A, B, &Par_V_angle, &Par_tot_vect);
    printf("\nParallel V_angle: %2.4f, Time took: %2.6f\n",Par_V_angle, Par_tot_vect);

    // Part 2
    // Euclidean distance
    
    printf("\n#########################################################################################\n");
    printf("Euclidean Distance");
    printf("\n#########################################################################################\n");

    // Sequential
    Seq_Eucli_Dista(N, A, B, &Eu_dist, &tot_eu); 
    printf("\nEuclidean Distance: %2.4f, time took %2.6f", Eu_dist, tot_eu);

    // Parallel
    eu_distance(N, A, B, &Par_Eu_dist, &Par_tot_eu);
    printf("\nPar Euclidean Distance: %2.4f, time took %2.6f\n", Par_Eu_dist, Par_tot_eu);


    // Manhattan distance 
    printf("\n#########################################################################################\n");
    printf("Manhattan Distance");
    printf("\n#########################################################################################\n");

    //Sequentian
    Seq_manhattan(N, A, B, &Manh_dist, &tot_manh);
    printf("\nManhattan Distance: %2.4f time took %2.6f", Manh_dist, tot_manh);

    // Parallel
    ManhattanDist(N, A, B, &Par_Manh_dist, &Par_tot_Manh);
    printf("\nPar Manhattan Distance: %2.4f time took %2.6f\n", Par_Manh_dist, Par_tot_Manh);

    // Part 3

    printf("\n#########################################################################################\n");
    printf("Weights");
    printf("\n#########################################################################################\n");

    // Sequential
    Seq_Weights(N, A, B, &weights, &tot_wei);
    printf("\nWeights: %2.5f Time took %2.5f\n", weights, tot_wei);

    // Parallel
    Par_weights(N, A, B, &Par_wei, &Par_tot_wei);
    printf("Par Weights: %2.5f Time took %2.5f\n", Par_wei, Par_tot_wei);

    free(A);
    free(B);

    return 0;
}
