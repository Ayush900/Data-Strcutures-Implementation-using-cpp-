#include<iostream>
#include<map>
#include<list>
#include<set>
#include<climits>

using namespace std;

template<typename T>
class Graph
{
	map<T,list<pair<T,int>>> adj_list;
	public:
		
		void addEdge(T u,T v,int d,bool bidirec = true)
		{
			adj_list[u].push_back(make_pair(v,d));
			if(bidirec)
			{
				adj_list[v].push_back(make_pair(u,d));
			}
		}
		
		void djikstra(T src)
		{
			map<T,int> dist;
			set<pair<int,T>> s;
			for(auto i : adj_list )
			{
				dist[i.first] = INT_MAX;
			}
			dist[src]=0;
			s.insert(make_pair(dist[src],src));
			while(s.empty()==false)
			{
				auto p = *(s.begin());
				s.erase(s.begin());
				T parent=p.second;
				int parentdist=p.first;
				for(auto neighbour : adj_list[parent])
				{
					int a = dist[neighbour.first];
					int b = parentdist + neighbour.second;
					if(a>b)
					{
						auto f = s.find(make_pair(dist[neighbour.first],neighbour.first));
						if(f!=s.end())
						{
							s.erase(f);
						}
						dist[neighbour.first]=b;
						s.insert(make_pair(dist[neighbour.first],neighbour.first));
					}
				}
			}
			
			for(auto i : dist)
			{
				cout<<"Distance of "<<i.first<<" from "<<src<<" is : "<<i.second<<endl;
			}
			cout<<endl;
			
		}
};

int main()
{
	Graph<string> g;

	g.addEdge("Amritsar","Agra",1);
	g.addEdge("Amritsar","Jaipur",4);
	g.addEdge("Delhi","Jaipur",2);
	g.addEdge("Delhi","Agra",1);
	g.addEdge("Bhopal","Agra",2);
	g.addEdge("Bhopal","Mumbai",3);
	g.addEdge("Jaipur","Mumbai",8);
	
	g.djikstra("Amritsar");
	
	return 0;
}
