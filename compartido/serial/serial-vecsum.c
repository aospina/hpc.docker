#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define LX 30000
#define LY 10000

long vec_sum[LX];
long matrix[LX][LY];

int processRow(long index) {
	long i;
	long result = 0;
	for (i=0;i<LX;i++)
		result = result + matrix[index][i];
	return result;	
}

int doSerial() {
	long i;
	for (i=0;i<LX;i++) {
		vec_sum[i] = processRow(i);
	}
}

 void fillMatrix() {
	long i,j;
	long val;
	int prob;
	for (i=0;i<LX;i++){ 
		for (j=0;j<LY;j++) {
			val = rand()%256;
			matrix[i][j] = val;
		}
	}
 }
int main(int argc, char **argv) {
	fillMatrix();
	doSerial();
	return 0;
 }

