#include<iostream>
#include<math.h>
using namespace std;

bool Insertsort(double *A, int N)
//数组插入排序
{
	int i,j;
	double key;
	for(i = 1; i< N; i++)
	{
		j=i-1;
		key=A[i];
		while(j>=0 && A[j]>key)
		{
			A[j+1]=A[j];
			j--;
		}
		A[j+1]=key;
	}
	return true;
}

void merge(double *A, int p, int q, int r)
{
	int i,j,count;
	double *temp = new double[r-p+1];
	i=p;
	j=q+1;
	count =0;

	while(i<=q && j<=r)
	{
		if(A[i]<A[j])
		{
			temp[count]=A[i];
			i++;
			count++;
		}
		else
		{
			temp[count]=A[j];
			j++;
			count++;
		}
	}

	while(i<=q)
	{
		temp[count]=A[i];
		i++;
		count++;
	}

	while(j<=r)
	{
		temp[count]=A[j];
		j++;
		count++;
	}

	for(i=0;i<r-p+1;i++)
	{
		A[i+p]=temp[i];
	}
	
	delete temp;
}

void Mergesort(double *A, int p, int r)
{
	//数组归并排序
	int q;
	q=(p+r)/2;

	if(p<r)
	{
		Mergesort(A,p,q);
		Mergesort(A,q+1,r);
		merge(A,p,q,r);
	}
}

int main()
{
	double A[10]={
		31,41,59,26,41,57,2,44,97,21
	};

	//Insertsort(A, 10);
	Mergesort(A,0,9);
	for(int i=0;i<10;i++)
	{
		cout<<A[i]<<"   ";
	}
	return 0;
}