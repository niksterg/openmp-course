// pi_mc.c
//
// This program calculates the value of pi using the Monte Carlo method.
// It uses OpenMP for parallelization.
// The number of threads is set by the environment variable OMP_NUM_THREADS.
// The code is written for unsigned long int, which is 64 bits on a 64-bit machine.
// The random number generator is rand_long, which is thread-safe and works with unsigned long int.
// The random number generator is seeded with the time in seconds times the thread number.  
//
// Nikolaos Stergioulas, Aristotle University of Thessaloniki 
//
// Content provided under a Creative Commons Attribution license, CC BY-NC-SA 4.0; code under GNU GPLv3 License. 
// (c)2024 Nikolaos Stergioulas     

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>
#include <limits.h>
#include <unistd.h>


unsigned long int rand_long(unsigned int *seed) {

    // This function defines a random number generator that returns an unsigned long int
    // between 0 and UINT_MAX*UINT_MAX, given a seed. It calls rand_r, which produces two
    // random numbers between 0 and RMAX and combines them into a single random number between
    // RAND_MAX << 32 | RAND_MAX.

    long int result = rand_r(seed);
    result <<= 32;
    result |= rand_r(seed);
    return result;
}

int main(int argc, char *argv[]) {
        
    int opt;                    // Command line option      

    long int count = 0;
             
    long int i,                 // Loop counter
             N = 1000000000;    // How many random numbers to generate (default value)

    double x,                   // Random number
           y,                   // Random number
           pi,                  // Estimate of pi
           scale_factor;        // Scale factor for random numbers

    unsigned int seed;          // Declare the seed variable
    
    unsigned long int  unsigned_long_scale_max; // Maximum value of unsigned long int

    // Parse the command line arguments to set how many random numbers to generate
    while ((opt = getopt(argc, argv, "n:")) != -1) {
        switch (opt) {
            case 'n':
                N = atol(optarg);
                break;
            default:
                fprintf(stderr, "Usage: %s [-n N]\n", argv[0]);
                exit(EXIT_FAILURE);
        }
    }


    // This is the maximum value of unsigned long int produced by rand_long
    unsigned_long_scale_max = ((unsigned long int)RAND_MAX << 32) | RAND_MAX;

    scale_factor = 1.0/ unsigned_long_scale_max; // Scale the random numbers to the range [0, 1]

    #pragma omp parallel private(x, y, seed) reduction(+:count)
    {
        seed = time(NULL) * omp_get_thread_num(); // Initialize private seed for each thread

        #pragma omp for                           // Loop over the number of random numbers to generate
        for(i = 0; i < N; i++) {
             x = rand_long(&seed) *scale_factor * 2.0 - 1.0;   // Generate a random number between -1 and 1
             y = rand_long(&seed) *scale_factor* 2.0 - 1.0;    // Generate a random number between -1 and 1

            if(x * x + y * y <= 1.0) {                         // If the random number is in the unit circle
                count++;                                       // increment the count
            }
        }
    }

    pi = 4.0 * count / N;                                      // Calculate the estimate of pi

    printf("Estimated value of Pi = %f\n", pi);

    return 0;
}