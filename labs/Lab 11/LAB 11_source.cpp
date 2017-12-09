//NAME: SAAD IQBAL
//CLASS: BEE-6B
//REG: 32903


// A C++ program to print topological sorting of a DAG
#include<iostream>
#include <list>
#include <queue>

using namespace std;

// Class to represent a graph
class Graph
{
	int V; // No. of vertices'

	// Pointer to an array containing adjacency lists List
	list<int> *adj;

	vector<int> indegree; // in-degree table
	vector<bool> visited; // visited table

public:
	Graph(int V);   // Constructor

	// ADD an edge to graph
	void AddEdge(int v, int w);

	// PRINT Topological Sort of the DAG
	void TopologicalSort();
};

Graph::Graph(int V) : indegree(V), visited(V)
{
	this->V = V;
	adj = new list<int>[V]; // INIT V adjacency lists

	std::fill(indegree.begin(), indegree.end(), 0); // INIT in-degree table to 0
	std::fill(visited.begin(), visited.end(), false); // INIT visited table to false
}

void Graph::AddEdge(int v, int w)
{
	// Step 1. ADD w to v's adjacency list.
	adj[v].push_back(w);
	

	// Step 2. UPDATE w's in-degree count
	indegree[w]++;
	
}

void Graph::TopologicalSort()
{
	queue<int> Queue;

	// Step 1. PUSH vertices with in-degree zero
	for (int i = 0; i < 6; i++){
		if (indegree[i]==0)
			Queue.push(i);
	}


	do {
		// Step 2. DEQUEUE and PRINT vertex
		int temp = Queue.front();
		Queue.pop();
		cout << temp<< " ";


		// Step 3. SET v to is-visited
		visited[temp] = 1;

		// Step 4. DECREMENT the v's adjacent vertices in-degree
		// Step 5. PUSH adjacent vertices with in-degree zero
		list<int>::iterator x=adj[temp].begin();
		while (x != adj[temp].end()){
			indegree[*x]--;
			if (indegree[*x] == 0 && visited[*x]!= true){
				Queue.push(*x);
			}
			x++;
		}
		

	} while (Queue.size() != 0); // LOOP UNTIL the queue is empty
}

// Driver program to test above functions
int main()
{
	// Create a graph given in the above diagram
	Graph g(6);
	g.AddEdge(0, 1);
	g.AddEdge(0, 3);
	g.AddEdge(1, 2);
	g.AddEdge(1, 3);
	g.AddEdge(1, 4);
	g.AddEdge(2, 1);
	g.AddEdge(4, 2);
	g.AddEdge(5, 2);
	g.AddEdge(5, 4);

	cout << "Following is a Topological Sort of the given graph \n";
	g.TopologicalSort();
	system("pause");
	return 0;
}