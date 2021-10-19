/*
 * pi_serial.c		3.1415926535897932384
 * 
 */
#include <stdio.h>
int main(void)
{
	int i,n;
	double x, base, suma=0.0,pi;
	//~ printf("Ingrese n:");
	//~ scanf("%d",&n);
	n=2000000000;
	base=1.0/(double)n;
	for(i=0;i<n;i++)
	{
		x= (i+0.5)*base;
		suma += 4.0/(1.0+x*x);
	}
	pi=suma*base;
	printf("PI (+|-) = %.16f\n",pi);
	return 0;
}
