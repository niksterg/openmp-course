#include <stdio.h>
#include <omp.h>

int main(void) {

int nThreads;

#pragma omp parallel 
{
 int myid = omp_get_thread_num(); 
 printf("Thread %d says: Hello World!\n",myid);

 if(myid == 0) nThreads = omp_get_num_threads();
}

 printf("The total number of threads used was %d.\n",nThreads);

return 0;
}
