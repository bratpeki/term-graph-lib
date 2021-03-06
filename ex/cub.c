
#include "../src/include/graph.h"

#include <stdlib.h>

int main() {

	const int count = 100;
	double *x = (double*)calloc(sizeof(double), count);
	double *y = (double*)calloc(sizeof(double), count);

	int ind = 0;
	for (int i = -count/2; i < count/2; i++) {
		x[ind] = (double)i;
		y[ind] = (double)(i*i*i);
		ind++;
	}

	char *grid = graphCreate(x, y, count, 22, 12);

	graphDrawInfo(x, y, count, "Cube function y=x^3", "X values", "Y values");
	graphDraw(grid, 22, 12);

	free(grid);
	free(x);
	free(y);

}

