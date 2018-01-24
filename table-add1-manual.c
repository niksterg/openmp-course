#include <stdio.h>
#include <omp.h>

#define N 12

int main(void) {

int myid,
    nThreads,
    i,
    iStart,
    iEnd,
    A[N];

 for(i=0;i<N;i++) A[i] = i;

#pragma omp parallel shared(nThreads, A) \
                     private(myid, i, iStart, iEnd) \
                     default(none)
{
 myid = omp_get_thread_num();
 nThreads = omp_get_num_threads();

 iStart = myid*N/nThreads;
 iEnd = (myid+1)*N/nThreads;

 if(myid == nThreads-1) iEnd = N;

 printf("myid= %d iStart=%d iEnd=%d\n",myid, iStart,iEnd);

 for(i=iStart;i<iEnd;i++) A[i] +=1;
}

 for(i=0;i<N;i++) printf("A[%d] = %d\n",i,A[i]);


return 0;

}
