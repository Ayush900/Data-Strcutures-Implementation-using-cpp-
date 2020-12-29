// find the number of occurances of a particular charachter in a given string using hashmap stl .
#include<bits/stdc++.h>
//#include<unordered_map>
using namespace std;

int main()
{
	unordered_map<char, int> h;
 	string s = "geeksforgeeks";
	for(int i=0;i<s.length();i++)
	{
		if(h.find(s[i])==h.end())
		{
			h.insert(make_pair(s[i],1));
		}
		else
		{
			h[s[i]]++;
		}
	}
	for( auto i : h)
	{
		cout<<i.first<<" = "<<i.second<<endl;
	} 
	return 0;
}
