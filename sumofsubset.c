#include<stdio.h> 
     
int d, count, w[40], x[40]; 
     
void sumofSubset(int s, int k, int r) { 
    int i; 
    x[k] = 1; 
    if(s + w[k] == d) { 
        printf("Subset %d: ", count++); 
        for(i = 0; i<=k; i++) 
            if(x[i] == 1) 
                printf("%d\t", w[i]); 
                printf("\n"); 
    } else if((s + w[k] + w[k + 1]) <= d) 
        sumofSubset(s + w[k], k + 1, r - w[k]); 
    if((s + r - w[k] >= d) && (s + w[k + 1] <= d)) { 
        x[k] = 0; 
        sumofSubset(s, k + 1, r - w[k]); 
    }   
} 
     
void main() { 
    int i, n, r = 0; 
    printf("\n Demo: Sum of Subset Problem Using Backtracking\n"); 
    printf("\n---------------------------------------------------"); 
    printf("\n Enter the number of elements of set: "); 
    scanf("%d", &n); 
    printf("\n Enter the elements: "); 
    for(i = 0; i < n; i++) { 
        scanf("%d", &w[i]); 
        r = r + w[i]; 
    } 
    printf("\n Enter the sum to be computed: "); 
    scanf("%d", &d); 
    if(r < d) { 
        printf("\n---------------------------------------------------"); 
        printf(" \n Solution does not exist...."); 
        return; 
    } 
    printf(" \n Subsets whose sum is %d are as follows: \n",d); 
	printf("---------------------------------------------------\n");         
	sumofSubset(0, 0, r); 
	if(count==0) {
		printf("\n Sorry...Solution does not exist for the given set of values\n");  
		return;
    }
}