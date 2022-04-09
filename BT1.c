#include<stdio.h>
#include<limits.h>
int MaxLeft(int i, int j,int &dau)
{
	int a[100]; 
    int MaxSum = -INT_MAX;
    int Sum = 0;
    for (int k = j; k >= i; k--)
    {
        Sum += a[k];
        if (MaxSum < Sum) { 
		MaxSum = Sum; 
		dau = k; 
		}
    }
    return MaxSum;
}
 
int  MaxRight(int i, int j,int &cuoi)
{
	int a[100]; 
    int MaxSum = -INT_MAX;
    int Sum = 0;
    for (int k = i; k <= j; k++)
    {
        Sum += a[k];
        if (MaxSum < Sum) 
		{ MaxSum = Sum; 
		cuoi= k; 
		}
    }
    return MaxSum;
}
 

int main() {
// Nhap vao mot mang a
	int a[100];
	int n;
	printf("Nhap vao so phan tu cua mang n=");
	scanf("%d", &n);
	
	for (int i=0; i<n; i++) {
		printf("Nhap a[%d]=", i);
		scanf("%d", &a[i]);
	}
// tinh truc tiep	
	int maxSum1=0;
	for (int i=0; i<n; i++) {
		for (int j=i; j<n; j++) {
			int sum1=0;
			for (int k=i; k<=j; k++) {
			sum1+=a[k];
			if (sum1>maxSum1)
				maxSum1=sum1;
			}
		} 
	}
	printf("%d\n", maxSum1);
// co cai tien	
	int maxSum2=a[0];
	for (int i=0; i<n; i++) {
		int sum2=0;
		for (int j=i; j<n; j++) {
			sum2+=a[j];
			if (sum2>maxSum2)
				maxSum2=sum2;
		}
	} 
	printf("%d", maxSum2);
// de quy
	MaxLeft(i, j, dau);
	MaxRight(i, j, cuoi);
	return 0;
}