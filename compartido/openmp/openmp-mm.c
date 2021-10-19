#include <stdio.h>
#include <omp.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int i, j;
	srand(time(NULL));
	if (argc!=2)
	{
	  printf("usage: %s n\n",argv[0]);
	  exit(1);
	}
	int n = atoi(argv[1]);
	int matriz_1[n][n], matriz_2[n][n], matriz_res[n][n];
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			matriz_1[i][j] = (rand()%4)+1;
			matriz_2[i][j] = (rand()%4)+1;
		}
	}
	/* realizar la multiplicación en paralelo */
	#pragma omp parallel
	{
		int tid;
		int i, j, k, suma = 0;
		tid = omp_get_thread_num();
		#pragma omp for 
		for(i = 0; i < n; i++)
		{
			for(j = 0; j < n; j++)
			{
				for(k = 0; k < n; k++)
				{
					suma += (matriz_1[i][k] * matriz_2[k][j]);
				}
				matriz_res[i][j] = suma;
				suma = 0;
			}
		}
	}
	/* mostrar parte de la matriz resultante */
	for(i = 0; i < 5; i++){
		for(j = 0; j < 5; j++){
			printf("%d ", matriz_res[i][j]);
		}
		printf("\n");
	} 
	return 0;
}

