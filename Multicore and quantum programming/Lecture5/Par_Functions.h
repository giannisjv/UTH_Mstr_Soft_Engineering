/* 
VIDRAS IOANNIS

-CPU AMD Ryzen 4600H (mobile) 3Ghz
-12 Cores
-RAM 32GB 3200 M/T
-Fedora 41 workstation

 */


// vectors
void vectors(int N, int *A, int *B, double *V_angle, double *tot){
    int i;
    double ab, sumA, sumB, magA, magB, cosine;
    double start = 0.0, end = 0.0;
    ab = sumA = sumB = 0.0;

start = omp_get_wtime();
#pragma omp parallel for reduction(+ : ab, sumA, sumB)
    for(i=0; i<N; i++){
        ab += A[i] * B[i];
        sumA += A[i] * A[i];
        sumB += B[i] * B[i];   
    }
    end = omp_get_wtime();

    //printf("\nA: %2.5f  B: %2.5f", sumA, sumB);  
    magA = sqrt(sumA);                  // Finding the sqrt of sumA (Vector magnitude)
    magB = sqrt(sumB);                  // Finding the sqrt of sumB (Vector magnitude)
    //printf("\nA: %2.5f  B: %2.5f Dot Prod: %2.5f", magA, magB, ab); 
    cosine = ((ab) / (magA * magB));
    //printf("\ncosine %2.5f",cosine);

    *V_angle = magA * magB * cosine;
    *tot = (end - start);

};


void eu_distance(int N, int *A, int *B, double *Eu_dist, double *tot){
    int i;
    double start, end;
    double euDist;
    
    start = omp_get_wtime();
    #pragma omp parallel for reduction(+ : euDist)
    for(i = 0; i<N; i++){
        euDist += (A[i] - B[i]) * (A[i] - B[i]);
    }
    end = omp_get_wtime();

    *Eu_dist = sqrt(euDist);
    *tot = end - start;

};


void ManhattanDist(int N, int *A, int *B, double *Man_Dist, double *tot){
    int i;
    double ManDist;
    double start, end;
    start = omp_get_wtime();
    
    #pragma omp parallel for reduction(+ : ManDist)
    for(i = 0; i<N; i++){
       ManDist += abs(A[i] - B[i]); 
    }
    end = omp_get_wtime();

    *Man_Dist = ManDist;
    *tot = end - start;

};

void Par_weights(int N, int *A, int *B, double *weight, double *tot){
    int i;
    double par3_arithm = 0.0, par3_paranom = 0.0;
    double start, end;
    
    start = omp_get_wtime();
    #pragma omp parallel for reduction(+ : par3_arithm, par3_paranom)
    for(i=0;i<N;i++){
        par3_arithm += A[i] * B[i];
        par3_paranom += B[i];
    }
    end = omp_get_wtime();

    *weight = par3_arithm / par3_paranom;
    *tot = end - start;
};


