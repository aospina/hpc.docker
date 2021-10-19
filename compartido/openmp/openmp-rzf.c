#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

int main(int argc, char const *argv[])
{
 float sum = 0.0;
 if (argc!=2)
 {
	  printf("usage: %s n\n",argv[0]);
	  exit(1);
 }
 int inf = atoi(argv[1]);
 int n=2;
 int k;
 
 #pragma omp parallel for reduction(+: sum)
 for( k=1 ; k<=inf ; k++) {
  sum += 1.0/pow(k,(double)n);
 }
 printf("sum: %f\n",sum);
}
