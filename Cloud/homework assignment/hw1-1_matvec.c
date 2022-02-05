//
// 2021 Fall - Cloud Computing (01)
// Homework #1: Parallelize matrix-vector multiplication, 
// 		and max operation using OpenMPI
//
// Copyright (c) Prof. Jaehyeong Sim
// Department of Computer Science and Engineering, Ewha Womans University
//

#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define max(a,b) (((a)>(b))?(a):(b))
// #define N 16
#define N 1024

double mat[N][N];
double vec[N];

int main (int argc, char* argv[]) {
	int rank, size;
	double t1, t2;
	char filename[16];

	// Read matrix and vector data from file
	sprintf(filename, "%d.txt", N);
	FILE *fp = fopen(filename, "r");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			fscanf(fp, "%lf", &mat[i][j]);
		}
	}
	for (int i = 0; i < N; i++) {
		fscanf(fp, "%lf", &vec[i]);
	}
	fclose(fp);

	// MPI start
	MPI_Init(&argc, &argv);
	t1 = MPI_Wtime();

	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	////////////////////////
	double* out;
	int iter = N / size;
	out = malloc(sizeof(double) * iter);
	memset(out, 0, sizeof(double) * iter);
	for (int i = rank * iter; i < (rank+1) * iter; i++) {
		for (int j = 0; j < N; j++)
			out[i % iter] += (mat[i][j] * vec[j]);
	}

	double local_maximum = 0;
	for (int i = 0; i < iter; i++) {
		local_maximum = max(local_maximum, out[i]);
	}
	// here you can check rank's local maximum;
	// printf("rank %d's maximum = %f\n", rank, local_maximum);
	
	double global_maximum;
	MPI_Reduce(&local_maximum, &global_maximum, 1, MPI_DOUBLE, MPI_MAX, 0, MPI_COMM_WORLD);	
	////////////////////////

	t2 = MPI_Wtime();
	if (rank == 0) {
		printf("Elapsed time for rank 0 is %f\n", t2 - t1);
		printf("final Maximum = %f\n", global_maximum);
	}
	if (rank == 1)
		printf("Elapsed time for rank 1 is %f\n", t2 - t1);
	
	free(out);
	MPI_Finalize();
	
	return 0;
}

