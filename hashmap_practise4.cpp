// modify the given array by changing the value of the elements and update it in the range from(0,n-1) such that the 
// max element in the array is updated to n-1 and the min is updated to 0.

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a[]={100,10,5,30};
	int n=sizeof(a)/sizeof(int);
	int t[n];
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" , ";
	}
	cout<<endl;
	for(int i=0;i<n;i++)
	{
		t[i]=a[i];
	}
	sort(t,t+n);
	int v=0;
	unordered_map<int , int> h;
	for(int i=0;i<n;i++)
	{
		h[t[i]]=v;
		v++;
	}
	for(int i=0;i<n;i++)
	{
		a[i]=h[a[i]];
	}
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" , ";
	}
	return 0;
}
