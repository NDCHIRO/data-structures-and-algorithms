#include <iostream>
#include <list>
using namespace std;

class Graph
{
public:
	int V;	//vertics
	list<int> *adj;
	Graph(int V);
	void DFS(int v);
	void addEdge(int v,int w);
	void DFS_utility(int v,bool visited[]);

};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v,int w)
{
	adj[v].push_back(w);
}

void Graph::DFS(int v)
{
	bool* visited = new bool[V];
	//set all the visited nodes to false at begin 
	for (int i = 0; i < V; i++)
		visited[i] = false;

	DFS_utility(v,visited);
}

void Graph::DFS_utility(int v , bool visited[])
{
	//first mark the current node as visited
	visited[v] = true;
	cout << v << " ";
	//explore the neighboors of the current node
	//iterator for a list type int 
	list<int>::iterator i;
	for ( i = adj[v].begin(); i != adj[v].end(); i++)
	{
		if (visited[*i] == false)
			DFS_utility(*i, visited);
	}
}
int main()
{
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);

	cout << "Following is Depth First Traversal"
		" (starting from vertex 2) \n";
	g.DFS(2);
}