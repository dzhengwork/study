#include <stdio.h>
#include <stdlib.h>


int main()
{
	int xdim = 3;
	int ydim = 4;
	int zdim = 5;
	int ***a3d = (int***) malloc(xdim * sizeof(int**));
	for (int i = 0; i < xdim; i++) {
		a3d[i] = (int**) malloc(ydim * sizeof(int*));
		for (int j = 0; j < ydim; j++) {
			a3d[i][j] = (int*) malloc(zdim * sizeof(int));
		}
	}

	int row = 3;
	int col = 5;
	int **b2d = (int**) malloc(row * sizeof(int*));
	b2d[0] = malloc(row * col * sizeof(int));
	for (int i = 1; i < row; i++) {
		b2d[i] = b2d[0] + i * col;
	}
	
	return 0;
}
