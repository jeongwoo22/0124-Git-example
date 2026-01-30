#include <stdio.h>


int main4()
{
	/*****
	Example1 : Basic array
	*****/
	int a[3] = { 1,2,3 };
	int b[100];
	char c[3] = { 1,2,3 };

	for (int i = 0; i < 3; i++)
	{
		b[i] = a[i];
		a[i] += 1;
		printf("%d, ", b[i]);
	}
	printf("\n\n");

	/*****
	Practice1 : Check memory of a, b, c
	*****/

	/*****
	Example2 : 2D array
	*****/
	int a2[3][3] = { {1,2,3} ,{4,5,6}, {7,8,9} };
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d, ", a2[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	/*****
	Practice2 : Check memory of a2, check value of a2, a2[0], a2[1], a2[2]
	*****/

	/*****
	Example3 : mxn * nxk matrix multiply
	*****/
	double m1[3][3] = { {1,2,3}, {4,5,6 }, {7,8,9,} };
	double m2[3][3] = { {9,8,7}, {6,5,4 }, {3,2,1,} };;
	double result[3][3] = { 0 };
	int m = sizeof(m1[0]) / sizeof(double);
	int n = sizeof(m1) / sizeof(double) / m;
	int k = sizeof(m2) / sizeof(double) / n;
	double elem;
	// Show the step by step 
	for (int v = 0; v < m; v++)
	{
		for (int j = 0; j < k; j++)
		{
			for (int i = 0; i < n; i++) {
				result[v][j] += m1[v][i] * m2[i][j];
			}
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%f, ", result[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	/*****
	Advanced : array and pointer
	*****/
	for (int i = 0; i < 3; i++)
		printf("%d, ", *(a + i));
	printf("\n\n");

	for (int i = 0; i < m; i++) {
		for(int j=0; j< k; j++){
			printf("%.3f, ", *(*(result + i) + j));
		}
		printf("\n");
	}
		
	/*****
	Advanced : why use pointer
	*****/

	return 0;

}