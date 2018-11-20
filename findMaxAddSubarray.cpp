#include<iostream>
#include<math.h>
using namespace std;

typedef struct subarrayIndex
{
	int leftIndex;
	int rightIndex;
	double subarraySum;
}subarrayIndex;

subarrayIndex findMaxAddCrossingSubarray(double *Array, int low, int high)
{
	int i,j,mid;
	double maxleftSum,maxrightSum,leftsum,rightsum;
	int leftIndex,rightIndex;
	subarrayIndex subaIdx;
	mid = (low+high)/2;

	leftsum = 0;
	rightsum = 0;
	leftIndex = mid;
	rightIndex = mid;

	maxleftSum = Array[mid];
	for(i = mid;i>=low;i--)
	{
		leftsum = leftsum + Array[i]; 
		if(leftsum > maxleftSum)
		{
			maxleftSum = leftsum;
			leftIndex = i;
		}
	}

	maxrightSum = Array[mid+1];
	for(j = mid+1;j<=high;j++)
	{
		rightsum = rightsum + Array[j];
		if(rightsum > maxrightSum)
		{
			maxrightSum = rightsum;
			rightIndex = j;
		}
	}

	subaIdx.leftIndex = leftIndex;
	subaIdx.rightIndex = rightIndex;
	subaIdx.subarraySum = maxleftSum + maxrightSum;

	return subaIdx;
}

subarrayIndex findMaxAddSubarray(double *Array, int low, int high)
{
	int mid;
	subarrayIndex subaIndex,subaleftIndex,subarightIndex,subamidIndex;
	mid = (low+high)/2;

	if(low == high)
	{
		subaIndex.leftIndex = low;
		subaIndex.rightIndex = high;
		subaIndex.subarraySum = Array[low];
		return subaIndex;
	}
	else
	{
		subaleftIndex = findMaxAddSubarray(Array, low, mid);
		subarightIndex = findMaxAddSubarray(Array, mid+1, high);
		subamidIndex = findMaxAddCrossingSubarray(Array,low,high);

		if(subaleftIndex.subarraySum >= subarightIndex.subarraySum && subaleftIndex.subarraySum >= subamidIndex.subarraySum)
		{
			return subaleftIndex;
		}
		else
		{
			if(subarightIndex.subarraySum >= subaleftIndex.subarraySum && subarightIndex.subarraySum >= subamidIndex.subarraySum)
			{
				return subarightIndex;
			}
			else
				return subamidIndex;
		}
	}

}
int main()
{
	double Array[16]={13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
	subarrayIndex subIdx;
	subIdx = findMaxAddSubarray(Array, 0, 15);
	cout<<subIdx.leftIndex<<"   "<<subIdx.rightIndex<<"   "<<subIdx.subarraySum<<endl;
	return 0;

}