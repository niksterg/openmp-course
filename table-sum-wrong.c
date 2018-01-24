#include <stdio.h>
#include <omp.h>

#define N 10

int main(void) {

int i,
    sum,
    a[N];

 for(i=0;i<N;i++) a[i] = i;

 sum = 0;

#pragma omp parallel for shared(a,sum) private(i) \
                     default(none)
 for(i=0;i<N;i++) sum += a[i];

 printf("sum = %d\n",sum);

return 0;

}
