#include <stdio.h>
#include <stdlib.h>
#define N 9
int S[N] = { 0,15,22,13,27,12,10,20,25 };

void merge2(int low, int mid, int high) {
	int i, j, k;


	i = low;
	j = mid+1;
	k = low;

	int *U = malloc(sizeof(int) * (N));


	while (i <= mid && j <= high ) {
		if (S[i] < S[j]) {
			U[k] = S[i];
			i++;
		}
		else {
			U[k] = S[j];
			j++;
		}
		k++;
	

	}

	



	if (i > mid)
		for ( ; j <= high; j++) {
			U[k] = S[j];
			k++;
		}
	else
		for (; i <= mid; i++) {
			U[k] = S[i];
			k++;
		}
	


	for (; low <= high; low++) {
		S[low] = U[low];
	}

	free(U);

}

void mergesort2(int low, int high) {

	int mid;

	

	if (low < high ) {
		mid = (low + high) / 2;
	
		mergesort2(low, mid);
		mergesort2(mid + 1, high);
		merge2(low, mid, high);
	}
	
}
int main()
{
	mergesort2(1, 8);

	printf("====mergesort2====\n");
	for (int i=1; i < N; i++)
		printf("S[%d] = %d\n",i, S[i]);

	

    return 0;
}

