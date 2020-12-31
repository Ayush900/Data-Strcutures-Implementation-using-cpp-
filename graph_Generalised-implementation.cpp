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
		
		int SSSP(T src,T dest)
		{
			queue<T> q;
			map<T,int> dist;
			for(auto i : m)
			{
				dist[i.first]=INT_MAX;
			}
			dist[src]=0;
			map<T,T> parent;
			parent[src]=src;
			q.push(src);
			while(q.empty()==false)
			{
				T temp = q.front();
				q.pop();
				for(auto neighbour : m[temp] )
				{
					if(dist[neighbour]==INT_MAX)
					{
						dist[neighbour]=dist[temp]+1;
						parent[neighbour]=temp;
						q.push(neighbour);
					}
				}
			}
			for(auto i : dist)
			{
				cout<<"Distance of "<<i.first<<" from "<<src<<" -> "<<i.second<<endl;
			}
			for(auto i : parent)
			{
				cout<<"Parent of "<<i.first<<" is"<<" -> "<<i.second<<endl;
			}
			return dist[dest];			
		}
		
		void DFS_helper(T src , map<T,bool> &visited )
		{
			cout<<src<<" ";
			visited[src]=true;
			
			for(auto i : m[src] )
			{
				if(visited[i] == false)
				{
					DFS_helper(i,visited);
				}
			}
			return;
		}
		
		void DFS(T src)
		{
			map<T, bool> visited;
			DFS_helper(src,visited);
			return;
		}
		
		int DFS_multiple_components(T src)
		{
			map<T, bool> visited;
			DFS_helper(src,visited);
			int components=1;
			for(auto i:m)
			{
				if(visited[i.first]==false)
				{
					DFS_helper(i.first,visited);
					components++;
				}
			}
			cout<<endl;
			return components;
		}
		
		
};

int main()
{
//	Graph<string> g;
//	g.AddEdge("Putin","Trump",false);
//	g.AddEdge("Putin","Modi",false);
//	g.AddEdge("Putin","Pope",false);
//	g.AddEdge("Modi","Trump");	
//	g.AddEdge("Prabhu","Modi",false);	
//	g.AddEdge("Modi","Yogi");	
//	g.AddEdge("Yogi","Prabhu",false);
//	g.AddEdge("A","B");
//	g.AddEdge("C","B");
//	g.AddEdge("A","C");
//	g.AddEdge("C","D");
//	g.AddEdge("D","G");
//	g.AddEdge("D","E");
//	g.AddEdge("D","F");
//	g.AddEdge("F","E");
//	g.bfs("A");
//	cout<<endl;
////	cout<<g.SSSP("A","G");
//	g.DFS("A");
	
	// If we have more than one isolated components stored in our graph and we have to print out the DFS for all the edges including all the edges isolated and otherwise 
	// , we will print values as follows and also the number of components in the graph as:
	
	Graph<int> g;
	g.AddEdge(0,1);
	g.AddEdge(4,1);
	g.AddEdge(4,5);
	g.AddEdge(5,6);
	g.AddEdge(3,6);
	g.AddEdge(3,4);
	g.AddEdge(2,3);
	g.AddEdge(0,2);	
	g.AddEdge(16,17);	
	g.AddEdge(17,18);
	g.print();
	cout<<endl;
	
	cout<<endl<<g.DFS_multiple_components(0)<<endl;
	g.DFS(0);

	return 0;
	

}













