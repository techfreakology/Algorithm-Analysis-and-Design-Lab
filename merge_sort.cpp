#include <bits/stdc++.h>
using namespace std;

void merge(int a[],int s,int e)
{
	int mid = (s+e)/2;
	int i,j,k,temp[e-s];
	i = s,j = mid,k = 0;
	while(i<mid && j<e)
	{
		if(a[i]<=a[j])
		{
			temp[k] = a[i];
			i++;
		}
		else
		{
			temp[k] = a[j];
			j++;
		}
		k++;
	}
	while(i<mid)
	{
		temp[k] = a[i];
		k++;
		i++;
	}
	while(j<e)
	{
		temp[k] = a[j];
		k++;
		j++;
	}
	for(i=s;i<e;i++)
	{
		a[i] = temp[i-s];
	}
}

void merge_sort(int a[],int s,int e)
{
	if(e-s<=1)	return;
	int mid = (s+e)/2;
	merge_sort(a,s,mid);
	merge_sort(a,mid,e);
	merge(a,s,e);
}

int main(int argc, char const *argv[])
{
	int a[] = {6,1,7,12,5,1,67,1,3,41,2,65};
	merge_sort(a,0,sizeof(a)/sizeof(int));
	for(auto it: a)
		cout<<it<<" ";
	return 0;
}


//	Complexity: O(nlogn)
//	n = size of array