#include <stdio.h>
#include <omp.h>

void printmessage(int myid)
{
  printf("Thread %d says: Hello World!\n",myid);
}

int main(void) {

int nThreads;

#pragma omp parallel
{
 int myid = omp_get_thread_num();
 nThreads = omp_get_num_threads();

 printmessage(myid);
}

 printf("The total number of threads used was %d.\n",nThreads);

return 0;
}
