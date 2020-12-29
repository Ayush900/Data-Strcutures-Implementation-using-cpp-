// Given an array and a variable sum , find the total number of pairs in the array which add up to give the result equal to sum
// a[] = {1,2,3,4,5} , sum = 6

#include<bits/stdc++.h>
using namespace std;

int findtotalpairs(int a[],int sum,int n)
{
	unordered_map<int , int > m;
	for(int i=0;i<n;i++)
	{
		m[a[i]]+=1;
	}
	int count = 0;
	
	for(int i=0;i<n;i++)
	{
		count=count+m[sum-a[i]];
		if(sum-a[i]==a[i])
		{
			count--;
		}
	}
	return count/2;
}

int main()
{
	int a[]={1,1,2,4,5,5};
	int n=sizeof(a)/sizeof(int);
	int sum=6;
	cout<<findtotalpairs(a,sum,n);
	return 0;
}
