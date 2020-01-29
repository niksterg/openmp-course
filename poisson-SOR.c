/*****************************************************************************
*
* Poisson solver for red-black SOR method in OpenMP
*
* Author: Nikolaos Stergioulas, Aristotle University of Thessaloniki
* 
* Content provided under a Creative Commons Attribution license, 
* CC BY-NC-SA 4.0; code under GNU GPLv3 License. (c)2020 Nikolaos Stergioulas
*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>

int main(int argc,                  
         char **argv) {

  int i, j, k=0,
      shift=0,
      *shift0,
      *shift1,
      N=200,               /* default value */
      M=200;               /* default value */

  double 
       **uold,
       **unew,
        *x,
        *y,
         test = 0.0,
         oldavg,
         newavg,
         dx,
         dy,
         omega=1.9,        /* default value */
         accuracy = 1e-4,  /* default value */
         fTimeStart, 
         fTimeEnd;

// Record start time

  fTimeStart = omp_get_wtime();

// Read grid size, accuracy and omega from command line

   for(i=1;i<argc;i++) 
         if(argv[i][0]=='-'){
           switch(argv[i][1]){
             case 'N': sscanf(argv[i+1],"%d",&N);
                       break;

             case 'M': sscanf(argv[i+1],"%d",&M);
                       break;   

             case 'a': sscanf(argv[i+1],"%lf",&accuracy);
                       break;      

             case 'o': sscanf(argv[i+1],"%lf",&omega);
                       break;                                   
           }
         } 

// Allocate memory

  uold = (double**) malloc(N*sizeof(double*));
  for (int i = 0; i < N; i++)
      uold[i] = (double*) malloc(M*sizeof(double));

  unew = (double**) malloc(N*sizeof(double*));
  for (int i = 0; i < N; i++)
      unew[i] = (double*) malloc(M*sizeof(double));

  shift0 = malloc(N*sizeof(int));
  shift1 = malloc(M*sizeof(int));

  x = malloc(N*sizeof(double));
  y = malloc(M*sizeof(double));

  
// grid spacings
  dx = (1.0-0.0)/(N-1);
  dy = (1.0-0.0)/(M-1);

  #pragma omp parallel private(i,j,shift) shared(x,dx,y,dy,uold,unew,shift0,shift1,omega,k,accuracy,test,N,M) default(none)
  {
    // x and y grids
    #pragma omp for
    for(i=0;i<N;i++) x[i] = 0 + i*dx;

    #pragma omp for 
    for(j=0;j<M;j++) y[j] = 0 + j*dy;

    // initial guess 
    #pragma omp for collapse(2)
    for(i=0;i<N;i++) 
       for(j=0;j<M;j++)
          uold[i][j] = 0.0;

    // boundary conditions
    #pragma omp for 
    for(i=0;i<N;i++) {
       uold[i][0] = 0.0;
       uold[i][N-1] = 1.0;
       unew[i][0] = 0.0;
       unew[i][N-1] = 1.0;
    }

    #pragma omp for 
    for(j=0;j<M;j++) {
       uold[0][j] = 0.0;
       uold[M-1][j] = 0.0;
       unew[0][j] = 0.0;
       unew[M-1][j] = 0.0;
    }

    // calculate position shift for red-black
    #pragma omp for 
    for(i=1;i<N-1;i++) {

          if(i%2 == 0) {
            shift0[i] = 1;
            shift1[i] = 0;
          }
          else{
              shift0[i] = 0;
              shift1[i] = 1;
          }
    }

    // iterative solution

    do{

       // red pass
       #pragma omp for collapse(2) schedule(static)
       for(i=1;i<N-1;i++) 
          for(j=1;j<M-1;j+=2) {
             shift = shift0[i];
             unew[i][j+shift] = (1.0-omega)*uold[i][j+shift]+0.25*omega*( uold[i+1][j+shift] + uold[i][j+shift+1] + uold[i-1][j+shift]
                                + uold[i][j+shift-1] - dx*dx*(-10.0*(x[i]*x[i]+y[j+shift]*y[j+shift]+5.0)) );
          }
       

       // black pass
       #pragma omp for collapse(2) schedule(static)
       for(i=1;i<N-1;i++) 
          for(j=1;j<M-1;j+=2) {
             shift = shift1[i];
             unew[i][j+shift] = (1.0-omega)*uold[i][j+shift]+0.25*omega*( unew[i+1][j+shift] + unew[i][j+shift+1] + unew[i-1][j+shift]
                                + unew[i][j+shift-1] - dx*dx*(-10.0*(x[i]*x[i]+y[j+shift]*y[j+shift]+5.0)) );
          }
       

       // evaluate test
       #pragma omp single
       test = 0;


       #pragma omp for collapse(2) reduction(+:test) schedule(static)
       for(i=1;i<N-1;i++)
          for(j=1;j<M-1;j++)
             test += fabs( (unew[i][j] - uold[i][j]) );
          
       #pragma omp single
       {
        test /= ((N-2)*(M-2));
        // increase iteration count
        k++;
        printf("%d %6.5e %6.5e\n",k, unew[N/2][M/2], test);
       }  

       // reset uold for next iteration
       #pragma omp for collapse(2) schedule(static)
       for(i=1;i<N-1;i++)
          for(j=1;j<M-1;j++) 
             uold[i][j] = unew[i][j];

    }while( test > accuracy);

  }

// Free memory

  for (i = 0; i < N; i++){
        free(unew[i] );
      }
  free(unew);

  for (i = 0; i < N; i++){
        free(uold[i] );
     }
  free(uold);

  free(shift0);
  free(shift1);
  free(x);
  free(y);

// Record end time

  fTimeEnd = omp_get_wtime();

// Print elapsed time

  printf("wall clock time     = %.20f\n", fTimeEnd - fTimeStart);

  return 0; 
}
