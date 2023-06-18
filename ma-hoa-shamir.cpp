#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
	
void mahoa(long S,int k,int n); // khai báo hàm mã hóa
void giaima(int k); // khai báo hàm giải mã
int main(){ // khai báo hàm main
	int choice; 
	long S;
	int n,k;
	
		do{
		printf("Menu\n");
		printf("1. Ma Hoa Shamir\n");
		printf("2. Giai Ma Shamir\n");
		printf("3. Thoat chuong trinh\n");
		printf("---------------------\n");
		printf("Nhap 1 so: "); scanf("%d",&choice);
		switch(choice){
			case 1:
			{
				printf("Nhap vao so muon ma hoa S: ");
				scanf("%ld",&S);
				printf("Nhap so nguong K: ");
				scanf("%d",&k);
				printf("Nhap vao tong so chia se bi mat N: ");
				scanf("%d",&n);
				mahoa(S,k,n);
				break;
			}
			case 2:
			{
				printf("Nhap so nguong K: ");
				scanf("%d",&k);
				giaima(k);
				break;
			}
			case 3:
				break;
		}
	}
		while(choice !=3);
}
	
void giaima(int k) // Viết hàm void giải mã
	{
	int x[100];
	int y[100];
	double L[100];
	double S=0;
	for(int i = 0; i < 100; i++)
		L[i]=1;
		int n;
		printf("Nhap vao tong so chia se bi mat N: ");
		scanf("%d",&n);
	for(int i = 0; i < k; i++){
		printf("Nhap ma chia se bi mat thu %d: ", i+1);
		scanf("%d %ld",&x[i],&y[i]);
	}
	for(int i = 0; i < k; i++)
	for(int j = 0; j < k; j++){
		if(i!=j)
			L[i]*=((-x[j]*1.0)/(x[i]-x[j]));
	}
	/*  printf("-----\n");
	for(int i=0;i<k;i++)
	{
	printf("%f\n",L[i]);
	printf("%d\n",y[i]);
	}
	printf("-----\n");*/
	for(int i=0;i<k;i++)
		S+=L[i]*y[i]*1.0;
		printf("Bi mat = %1.lf\n",S);
	}

void mahoa(long S,int k,int n) // viết hàm mã hóa
{
	int a[100];
	long fx[100]={0};
	int x[100];
	srand((unsigned)time(NULL));
	for(int i=0;i<n;i++){
		a[i]=rand()%100;
		x[i]=rand()%20+1;
	}
	for(int i=0;i<n;i++)
	for(int j=i+1;j<n;j++){
		if(x[i]==x[j]){
		x[i]=rand()%20+1;
		i--;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=1;j<k;j++)
			fx[i]+=a[j]*pow(x[i],j);
			fx[i]+=S;
			printf("chia se bi mat thu %d la: ", i+1);
			printf("(x,y) = (%d,%ld)\n",x[i],fx[i]);
	}
}