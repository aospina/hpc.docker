#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* modo de uso: ./serial-mm n
 * n es un entero DIM
 * matrix multiply
 * *
 * * c[i][j]= a_row[i] dot b_col[j] for all i,j
 * * a_row[i] -> a[i][0 .. DIM-1]
 * * b_col[j] -> b[0 .. DIM-1][j]
 * *
 * */

int main(int argc, char const *argv[])
{
  if (argc!=2)
  {
	  printf("usage: %s n\n",argv[0]);
	  exit(1);
  }	
  int n = atoi(argv[1]);
  int a[n][n], b[n][n], c[n][n];
  int i,j,k;
  float dot;  
  for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			a[i][j] = (rand()%4)+1;
			b[i][j] = (rand()%4)+1;
		}
	}
  for(i=0;i<n;i++) {
    for(j=0;j<n;j++) {
		dot=0.0;
		for(k=0;k<n;k++)
			dot += a[i][k]*b[k][j];
		c[i][j]=dot;
	}
  }
}
