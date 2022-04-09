#include<stdio.h>
#include<limits.h>
// Ham max 
int max(int a, int b) {
	if(a>b) 
	return a;
	else return b;	 
}
// Ham max trai  
int maxleft(int a[100], int n) {
	int maxSum=-INT_MIN; 
 	int sum=0; 
	for (int i=0; i<(n/2); i++) {
		int sum=0; 
		for (int j=i; j<(n/2); j++) {
			
			sum+=a[j];
			maxSum=max(sum, maxSum); 
		} 
	}
	return maxSum;
}

// Ham max phai 
int maxrigh(int a[100], int n) {
 	int maxSum=-INT_MIN; 
 	int sum=0; 
	for (int i=(n/2); i<n; i++) {
		int sum=0; 
		for (int j=i; j<n; j++) {
			
			sum+=a[j];
			maxSum=max(sum, maxSum); 
		} 
	}
	return maxSum;
}
// Ham tim day con co trong luong lon nhat 
int maxSub(int a[100], int n) {
	int sub=0; 
	int subgiua=0;
	int trongluong=0;
	sub = max(maxleft(a,n),  maxrigh(a,n));
	/* chua tim ra duoc giai phap */ 
		for (int i=0; i<n; i++) {
		for (int j=i; j<n; j++) {
			subgiua= maxleft(a,n) + maxrigh(a,n); 	}
		}		
		trongluong=max(sub, subgiua);
		
	return trongluong; 
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
	printf("  Tinh truc tiep \n Day con co trong luong lon nhat maxSum1=%d\n", maxSum1);
	
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
	printf("  Co cai tien \n Day con co trong luong lon nhat maxSum2=%d\n", maxSum2);
	
// de quy
	printf("\n.......DE QUY.........\n");
	printf("maxleft=%d\n", maxleft(a,n));
	printf("maxrigh=%d\n", maxrigh(a,n));
	printf("Day con co trong luong lon nhat maxSub=%d\n", maxSub(a,n));
	
	return 0;
}

