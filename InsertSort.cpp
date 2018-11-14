#include<iostream>
#include<math.h>
using namespace std;

bool Insertsort(double *A, int N)
//Êı×é²åÈëÅÅĞò
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

int main()
{
	double A[10]={
		31,41,59,26,41,57,2,44,97,21
	};

	Insertsort(A, 10);
	for(int i=0;i<10;i++)
	{
		cout<<A[i]<<"   ";
	}
	return 0;
}