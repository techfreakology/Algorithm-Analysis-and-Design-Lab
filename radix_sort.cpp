#include <bits/stdc++.h>
using namespace std;

void counting_sort(int a[],int n,int exp)
{
	int count[10];
	memset(count,0,sizeof(count));
	
	for(int i=0;i<n;i++)
	{
		count[(a[i]/exp)%10]++;
	}
	for(int i=1;i<10;i++)
	{
		count[i] += count[i-1];
	}

	int out[n];
	for(int i=n-1;i>=0;i--)
	{
		out[count[(a[i]/exp)%10]-1] = a[i];
		count[(a[i]/exp)%10]--;
	}

	for(int i=0;i<n;i++)
	{
		a[i] = out[i];
	}
}

void radix_sort(int a[],int n)
{
	int max_val = a[max_element(a,a+n)-a];
	for(int exp=1;max_val/exp>0;exp*=10)
	{
		counting_sort(a,n,exp);
	}
}

int main(int argc, char const *argv[])
{
	int a[] = {6,1,7,122,50,1,67,1,3211,41,2,65};
	radix_sort(a,sizeof(a)/sizeof(int));
	for(auto it: a)
		cout<<it<<" ";
	return 0;
}

//	Complexity: O(d*(n+b))
//	d = maximum no. of digits in a number, n = size of array, b = base of numbers