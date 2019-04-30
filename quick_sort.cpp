#include <bits/stdc++.h>
using namespace std;

int partition(int a[],int s,int e)
{
	int i,j;
	int p = e;
	j = s-1;
	for(i=s;i<e;i++)
	{
		if(a[i]<=a[e])
		{
			swap(a[i],a[j+1]);
			j++;
		}
	}
	swap(a[j+1],a[e]);
	return j+1;
}

void quick_sort(int a[],int s,int e)
{
	if(s>=e)	return;
	int p = partition(a,s,e-1);
	quick_sort(a,s,p);
	quick_sort(a,p+1,e);
}

int main(int argc, char const *argv[])
{
	int a[] = {6,1,7,12,5,1,67,1,3,41,2,65};
	quick_sort(a,0,sizeof(a)/sizeof(int));
	for(auto it: a)
		cout<<it<<" ";
	return 0;
}

//	Complexity: O(n^2)
//	n = size of array