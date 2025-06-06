#include<stdio.h> 
#include<math.h> 
int board[20],count; 
int main() 
{ 
 int n,i,j; 
 void queen(int row,int n); 
 printf(" - N Queens Problem Using Backtracking -"); 
 printf("\n\nEnter number of Queens:"); 
 scanf("%d",&n); 
 queen(1,n); 
 printf("\n\n No.of solutions for %d queen problem : %d",n,count); 
 return 0; 
} 
 
//Function for printing the Solution 
void print(int n) 
{ 
 int i,j; 
 printf("\n\nSolution %d:\n",++count); 
 for(i=1;i<=n;i++) 
 { 
  for(j=1;j<=n;j++)  
  { 
   if(board[i]==j) 
    printf("\tQ");  
   else 
    printf("\t-");  
  } 
  printf("\n\n"); 
 } 
} 
 
/* funtion to check conflicts 
If no conflict for desired postion returns 1 otherwise returns 0*/ 
int place(int row,int column) 
{ 
 int i; 
 for(i=1;i<=row-1;i++) 
 { 
  if((board[i]==column)|| (abs(board[i]-column)==abs(i-row))) 
    return 0; 
  } 
 return 1;  
} 
 
//function to check for proper positioning of queen 
void queen(int row,int n) 
{ 
 int column; 
 for(column=1;column<=n;column++) 
 { 
  if(place(row,column)) 
{ 
board[row]=column;  
if(row==n)    
print(n);  
else  
queen(row+1,n); 
} 
} 
} 
