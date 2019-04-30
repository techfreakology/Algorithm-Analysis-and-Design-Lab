#include <bits/stdc++.h>
using namespace std;

void counting_sort(int a[],int n)
{
	int largest_element = a[max_element(a,a+n)-a];
	int hash[largest_element+1];
	memset(hash,0,sizeof(hash));

	for(int i=0;i<n;i++)
	{
		hash[a[i]]++;
	}

	for(int i=1;i<=largest_element;i++)
	{
		hash[i] += hash[i-1];
	}

	int out[n];
	for(int i=n-1;i>=0;i--)
	{
		out[hash[a[i]]-1] = a[i];
		hash[a[i]]--;
	}

	for(int i=0;i<n;i++)
	{
		a[i] = out[i];
	}

}

int main(int argc, char const *argv[])
{
	int a[] = {6,1,7,12,5,1,67,1,3,41,2,65};
	counting_sort(a,sizeof(a)/sizeof(int));
	for(auto it: a)
		cout<<it<<" ";
	return 0;
}

//	Complexity: O(n+largest_element)
//	n = size of array, largest_element = largest element in the array