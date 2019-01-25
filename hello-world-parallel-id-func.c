#include <stdio.h>
#include <omp.h>

void printmessage(int myid)
{
  printf("Thread %d says: Hello World!\n",myid);
}

int main(void) {

int myid, 
    nThreads;

#pragma omp parallel private(myid) shared(nThreads)
{
 myid = omp_get_thread_num();

 printmessage(myid);

 if(myid==0) nThreads = omp_get_num_threads();
}

 printf("The total number of threads used was %d.\n",nThreads);

return 0;
}
