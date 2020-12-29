#include<bits/stdc++.h>
using namespace std;

int main()
{
	// Syntax
	
//	unordered_map<string , int> h;
	
	//ordered map or simply map is also a hashmap with a difference that in this hashap the key value pairs are sorted according to the values of the keys..
	
	map<string,int> h;
	
	//Insertion in hashmap can be done using 3 methods
	//1.
	h.insert(make_pair("Aayush" , 100));
	//2.
	pair<string,int> p("Mehrotra" , 200);
	h.insert(p);
	//3.
	h["Ak Go"]=200;
	h["Arsenal"]=15;
	//Searching a particular key in hashmap and printing its value
	//the function h.count(KEY) takes in as parameter a key which we would like to search and print value for and returns 1 if it exists and 0 if it doesn't exist.
	string s= "Ayush";
	if(h.count(s))
	{
		cout<<"value of "<<s<<" is:"<<h[s];
	}
	else
	{
		cout<<"Key doesn't exist";
	}
	
	//printing in hashmap
	for(auto i:h)
	{
		cout<<endl<<i.first<<"--->"<<i.second;
	}
	
}





