#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* modo de uso: ./serial-rzf term
 * term es un entero cantidad de terminos
 * */
int main(int argc, char const *argv[])
{
 float sum = 0.0;
  if (argc!=2)
  {
	  printf("usage: %s cantidad\n",argv[0]);
	  exit(1);
  }
 int inf = atoi(argv[1]);
 int n=2;
 int k;
 for( k=1 ; k<=inf ; k++) {
	 sum += 1.0/pow(k,(double)n);
 }
 printf("sum %f\n",sum);
}
