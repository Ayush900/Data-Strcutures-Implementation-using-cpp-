#include<bits/stdc++.h>

using namespace std;

template<typename T>

class Graph
{
	map<T,list<T>> m;
	public:
		
		void AddEdge(T src,T dest,bool bidirec=true)
		{
			m[src].push_back(dest);
			if(bidirec)
			{
				m[dest].push_back(src);
			}
		}
		void print()
		{
			for(auto i : m)
			{
				cout<<i.first<<"--->";
				for(auto j : i.second)
				{
					cout<<j<<" , ";
				}
				cout<<endl;
			}
		}
		
		void bfs(T src)
		{
			map<T,bool> visited;
			queue<T> q;
			q.push(src);
			visited[src]=true;
			while(q.empty()==false)
			{
				T node=q.front();
				q.pop();
				cout<<node<<" ";
				for(T i : m[node])
				{
					if(visited[i]==false)
					{
						q.push(i);
						visited[i]= true;	
					}
				}
				
			}
			
		}
};

int main()
{
	Graph<int> g;
//	g.AddEdge("Putin","Trump",false);
//	g.AddEdge("Putin","Modi",false);
//	g.AddEdge("Putin","Pope",false);
//	g.AddEdge("Modi","Trump");	
//	g.AddEdge("Prabhu","Modi",false);	
//	g.AddEdge("Modi","Yogi");	
//	g.AddEdge("Yogi","Prabhu",false);
	g.AddEdge(0,1);
	g.AddEdge(1,2);
	g.AddEdge(2,3);
	g.AddEdge(0,3);
	g.AddEdge(3,4);
	g.AddEdge(4,5);
	g.bfs(0);
	return 0;
	

}













