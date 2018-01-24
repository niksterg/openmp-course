#include <stdio.h>
#include <omp.h>

#define N 12

int main(void) {

int i,
    A[N];

 for(i=0;i<N;i++) A[i] = i;

#pragma omp parallel shared(A) private(i) default(none)
{
 for(i=0;i<N;i++) A[i] +=1;
}

 for(i=0;i<N;i++) printf("A[%d] = %d\n",i,A[i]);

return 0;

}
