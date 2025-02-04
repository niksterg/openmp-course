/* laplace.c: Solving Laplace's equation in 2D by Jacobi iteration using OpenMP.
 *
 *    ∇²u(x,y) = 0   on a rectangular domain.
 *
 * We set up a grid (nx x ny) with Dirichlet boundary conditions (here we fix
 * the top boundary to 1.0 and the other boundaries to 0.0). Then we iteratively
 * update the interior points with the average of their four neighbors.
 *
 * To compile:
 *      gcc -O3 -fopenmp laplace.c -o laplace
 *
 * To run (example with grid size 10000x10000):
 *      ./laplace 10000 10000
 *
 * You can control the number of threads via the environment variable OMP_NUM_THREADS.
 *
 * This code is intended as a demonstration for MSc computational physics courses.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

int main(int argc, char *argv[]) {
    // Grid dimensions (default: 1000 x 1000; increase for larger memory usage / longer runtime)
    int nx = 1000;
    int ny = 1000;
    if (argc >= 3) {
        nx = atoi(argv[1]);
        ny = atoi(argv[2]);
    }
    
    // Total number of grid points.
    int size = nx * ny;
    
    // Allocate two 1D arrays to represent the 2D grid (row-major order).
    double *u     = (double*) malloc(sizeof(double) * size);
    double *u_new = (double*) malloc(sizeof(double) * size);
    if (!u || !u_new) {
        fprintf(stderr, "Error allocating memory.\n");
        return 1;
    }
    
    // Initialize arrays: interior points start at 0.0.
    for (int i = 0; i < size; i++){
        u[i] = 0.0;
        u_new[i] = 0.0;
    }
    
    // Set boundary conditions.
    // Here, we fix the top boundary (last row) to 1.0 and all others to 0.0.
    for (int i = 0; i < nx; i++){
        int idx = i * ny + (ny - 1);  // index for top boundary in each column
        u[idx] = 1.0;
        u_new[idx] = 1.0;
    }
    
    // Convergence parameters.
    double tol = 1e-6;      // convergence tolerance
    int max_iter = 1000000; // maximum number of iterations
    int iter = 0;
    double diff = 0.0;      // will hold maximum difference between iterations
    
    // Timing the computation
    double start_time = omp_get_wtime();
    
    // Main Jacobi iteration loop.
    while (iter < max_iter) {
        diff = 0.0;
        
        // Update the interior points.
        // Note: The update at each point depends only on values from the previous iteration,
        // so we can parallelize the two nested loops using OpenMP.
        #pragma omp parallel for reduction(max:diff) schedule(static)
        for (int i = 1; i < nx - 1; i++) {
            for (int j = 1; j < ny - 1; j++) {
                int idx       = i * ny + j;
                int idx_up    = (i - 1) * ny + j;
                int idx_down  = (i + 1) * ny + j;
                int idx_left  = i * ny + (j - 1);
                int idx_right = i * ny + (j + 1);
                
                // Compute the new value as the average of the four neighbors.
                u_new[idx] = 0.25 * (u[idx_up] + u[idx_down] + u[idx_left] + u[idx_right]);
                
                // Compute the local difference.
                double local_diff = fabs(u_new[idx] - u[idx]);
                if (local_diff > diff)
                    diff = local_diff;
            }
        }
        
        // Copy new values back into u (this loop can also be parallelized).
        #pragma omp parallel for schedule(static)
        for (int i = 1; i < nx - 1; i++) {
            for (int j = 1; j < ny - 1; j++) {
                int idx = i * ny + j;
                u[idx] = u_new[idx];
            }
        }
        
        iter++;
        if (iter % 100 == 0) {
            printf("Iteration %d: max diff = %e\n", iter, diff);
        }
        if (diff < tol)
            break;
    }
    
    double end_time = omp_get_wtime();
    printf("Converged after %d iterations with max diff = %e\n", iter, diff);
    printf("Total runtime = %f seconds\n", end_time - start_time);
    
    // Clean up.
    free(u);
    free(u_new);
    
    return 0;
}
