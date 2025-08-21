#include<stdio.h>
int main(){
	int rows,cols,i,j;
	printf("enter rows:");
	scanf("%d",&rows);
	printf("\n enter cols:");
	scanf("%d",&cols);
	int matrix[rows][cols];
	printf("enter  data");
	for( i=0;i<rows;i++)
	{
		for( j=0;j<cols;j++)
		{
			scanf("%d",&matrix[i][j]);
		}
	}
	printf("\nyour matrix is :\n");
	for( i=0;i<rows;i++)
	{
		for (j=0;j<cols;j++)
		{
			printf("%2d",matrix[i][j]);
		}
		printf("\n");
	}

}