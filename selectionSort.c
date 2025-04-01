#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(long int a[], int n) {
	for(int i=0; i<=n-2; i++) {
		long int min = i;
		for(int j=i+1; j<=n-1; j++) {
			if(a[j] < a[min]) {
				min = j;
			}
		}
		long int temp = a[min];
		a[min] = a[i];
		a[i] = temp;
	}
}

void print(long int a[], int n) {
	for(int i=0; i<n; i++)
		printf("%d\t", a[i]);
}

int main() {
	double tim[10];
	int i, n;
	printf("Enter the array size: ");
	scanf("%d", &n);
	long int a[n];
	printf("Enter array elements: ");
	for(i=0; i<n; i++)
		scanf("%d", &a[i]);
	printf("\n\nBefore sorting: \n");
	print(a, n);
	selectionSort(a, n);
	printf("\n\nAfter sorting: \n");
	print(a, n);
	printf("\n\n----Selection sort demo for N>5000 -----\n");
	printf("\n Value of N \t Time(in millisecends)");
	printf("\n------------    -----------------------\n");
	long int N = 6000;
	for(int count = 0; count<10; count++) {
		long int a[N];
		for(int i=1; i<=N; i++) {
			a[i] = rand() % N+1;
		}
		clock_t start, end;
		start = clock();
	    selectionSort(a, N);
	    end = clock();
	    tim[count] = ((double)(end - start));
	    printf("    %li\t\t%li\n", N, (long int)tim[count]);
	    N += 1000;
	}
	printf("\n--------------------------------------------------");
	return 0;
}