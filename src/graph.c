
#include "./graph.h"

#include <stdio.h>
#include <stdlib.h>

/*
 * Create the graph character array and return it
 *
 * '*x' and '*y' are arrays for X and Y point values
 * 'xlen' and 'ylen' are distances from their respective axes
 *
 * So, along the x-axis, the graph will stretch from -xlen to +xlen.
 * The same logic applies to 'ylen'.
 */

char* createGraph2D(float *x, float *y, uint count, uint xlen, uint ylen) {

	/*
	 * Setting grid dimensions
	 *
	 * The addition of 1 is done to make space for the axis itself
	 */

	int gxlen = 2 * xlen + 1;
	int gylen = 2 * ylen + 1;

	/* Defining square grid for the graph */

	char *grid = (char*)calloc(sizeof(char), gxlen*gylen);

	/*
	 * Drawing lines
	 *
	 * 'xmid' and 'ymid' are middle values (15/2 = 7.5 => 7)
	 *
	 * 'xq' and 'yq' are boolean-like values that determine weather on not
	 * the given value of 'i' is qualified to be on the x-axis or y-axis
	 */

	int xmid = gxlen / 2;
	int ymid = gylen / 2;

	int xq, yq;

	for (uint i = 0; i < gxlen * gylen; i++) {

		xq = ( (i % gxlen) == xmid );
		yq = ( i >= gxlen * ymid ) && ( i < gxlen * (ymid + 1) );

		grid[i] =
			C_XAXIS      * ( xq * !yq) +
			C_YAXIS      * (!xq *  yq) +
			C_COORDBEGIN * ( xq *  yq) +
			C_EMPTY      * (!xq * !yq);

	}

	/*
	 * Drawing points
	 *
	 * The procedure for each axis is:
	 *
	 *     Find the maximum absolute value
	 *     Use the following formula to find the position of the point on the graph:
	 *         graph_size : max_axis_value = graph_position : axis_value
	 *         graph_position * max_axis_value = graph_size * axis_value
	 *         graph_position = ( graph_size * axis_value ) / max_axis_value
	 *     Draw points
	 */

	float xmax, ymax = 0;
	int xf, yf;

	/* Finding x and y coordinate absolute maximums */
	for (uint i = 0; i < count; i++) if ( f_abs(x[i]) > xmax ) xmax = f_abs(x[i]);
	for (uint i = 0; i < count; i++) if ( f_abs(y[i]) > ymax ) ymax = f_abs(y[i]);

	for (uint i = 0; i < count; i++) {

		xf = f_round(( xlen * x[i] ) / xmax);
		yf = f_round(( ylen * y[i] ) / ymax);

		/*    Middle point        Distance from origin */
		grid[ ymid*gxlen + xlen - yf*gxlen + xf ] = C_POINT;

	}

	/* Return grid */

	return grid;

}

/*
 * Display the graph character array
 *
 * '*grid' respresents the graph character array
 * 'xlen' and 'ylen' serve the same purpose as in createGraph2D
 */

void drawGraph2D(char *grid, uint xlen, uint ylen) {

	int gxlen = 2 * xlen + 1;
	int gylen = 2 * ylen + 1;

	for (uint j = 0; j < gxlen * gylen; j++) {
		if ( (j % gxlen == 0) * (j != 0) ) printf("\n");
		printf("%c", grid[j]);
	}
	printf("\n");

}
