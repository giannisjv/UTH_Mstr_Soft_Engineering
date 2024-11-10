/* 
VIDRAS IOANNIS

-CPU AMD Ryzen 4600H (mobile) 3Ghz
-12 Cores
-RAM 32GB 3200 M/T
-Fedora 41 workstation
 */


void Seq_vectors(int N, int *A, int *B, double *V_angle, double *tot){
    // vectors
    int i;
    double start, end;
    
    // Part 1 variables 
    double sumA, sumB, cosA, cosB, ab, magA, magB, cosine;
    sumA = sumB = 0.0;


    start = omp_get_wtime();
    for(i=0; i<N; i++){
        ab += A[i] * B[i];
        sumA += A[i] * A[i];
        sumB += B[i] * B[i];
        
    }
    end= omp_get_wtime();
    //printf("\nA: %2.5f  B: %2.5f", sumA, sumB);  
    magA = sqrt(sumA);                  // Finding the sqrt of sumA (Vector magnitude)
    magB = sqrt(sumB);                  // Finding the sqrt of sumB (Vector magnitude)
    //printf("\nA: %2.5f  B: %2.5f Dot Prod: %2.5f", magA, magB, ab); 
    cosine = ((ab) / (magA * magB));
    //printf("\ncosine %2.5f",cosine);

    *V_angle = magA * magB * cosine;

    *tot = (end - start);
};

void Seq_Eucli_Dista(int N, int *A, int *B, double *Eu_dist, double *tot){
    int i;
    double start, end;
    double eu_dist = 0.0;

    start = omp_get_wtime();
    for(i = 0; i<N; i++){
        eu_dist += (A[i] - B[i]) * (A[i] - B[i]);
    }
    end = omp_get_wtime();
    *Eu_dist = sqrt(eu_dist);
    *tot = end - start;
};


void Seq_manhattan(int N, int *A, int *B, double *Man_Dist, double *tot){
    int i;
    double start, end;
    double manh;
    start = omp_get_wtime();
    for(i = 0; i<N; i++){
       manh += abs(A[i] - B[i]); 
    }
    end = omp_get_wtime();
    *Man_Dist = manh;
    *tot = end - start;
};


void Seq_Weights(int N, int *A, int *B, double *weight, double *tot){
    int i;
    double start, end;
    double par3_arithm, par3_paranom, weights;
    start = omp_get_wtime();
    for(i=0;i<N;i++){
        par3_arithm += A[i] * B[i];
        par3_paranom += B[i];
    }
    end = omp_get_wtime();

    *weight = par3_arithm / par3_paranom;
    *tot = end - start;
};