#include <stdio.h>
#include <stdlib.h> 



void merge(int h, int m,  int U[], int V[], int S[])
{
	int Ind_i, Ind_j, Ind_k;

	Ind_i = 0;
	Ind_j = 0;
	Ind_k = 0;
	
	
	
	
	while (Ind_i< h && Ind_j< m)
	{
		
		if (U[Ind_i] < V[Ind_j]) {
			S[Ind_k] = U[Ind_i];
			Ind_i++;
		}
		else {
			S[Ind_k] = V[Ind_j];
			Ind_j++;
		}
		Ind_k++;
		
		
		
	}

	int i = Ind_i;
	int j = Ind_j;
	int k = Ind_k;
	if(Ind_i >= h)
		for (int x = Ind_k; x < h + m; x++) {
			S[x] = V[j];
			j++;
			
		}
	else
		for (int y = Ind_k; y < h + m; y++) {
			S[y] = U[i];
			i++;
			
		}
	
}

void mergesort(int n, int S[])
{
	int h;
	if (n % 2 == 1)
		h = n / 2 + 1;
	else
		h = n / 2;

	int m = n - h;
	


	int *U = (int*)malloc(sizeof(int) * h);
	for (int i = 0; i < h; i++)
	{
		
		U[i] = S[i];
		
	}


	int *V = (int*)malloc(sizeof(int) * m);
	for (int i = 0; i < m; i++)
	{
		V[i] = S[h + i];
		
	}

	
	if (n > 1)
	{
		mergesort(h, U);		
		mergesort(m, V);
		merge(h, m, U, V, S);
	}
}

int main()
{
	int S[] = { 27,10,12,20,25,13,15,22 };
	int n = sizeof(S) / sizeof(int);
	mergesort(n, S);


	printf("-----mergesort-----\n");
	for (int i = 0; i < n; i++)
		printf("S[%d] =  %d\n",i, S[i]);
    return 0;
}

