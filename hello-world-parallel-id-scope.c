#include <stdio.h>
#include <omp.h>

int main(void) {

int myid,
    nThreads;

#pragma omp parallel shared(nThreads) private(myid) default(none)
{
 myid = omp_get_thread_num();
 nThreads = omp_get_num_threads();

 printf("Thread %d says: Hello World!\n",myid);
}

 printf("The total number of threads used was %d.\n",nThreads);

return 0;
}
