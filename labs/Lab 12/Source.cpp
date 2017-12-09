#include<iostream> 
#include<queue>
#include<list>
#include<algorithm>
#include<vector>

using namespace std; 

class node 
{
public:
	int weight;
	int sec_val;
	node(int w, int s){
		weight = w;
		sec_val = s;
	}
};

class graph 
{
	int vertex;
	list<node> *adj;
	vector<bool>visited;
	vector<int>parent;
	vector<int>displacement;
public:
	~graph(){}
	graph(int x) : parent(x), visited(x), displacement(x) 
	{
		vertex = x;
		adj = new list<node>[vertex];
		std::fill(parent.begin(), parent.end(), -1); 
		std::fill(visited.begin(), visited.end(), false); 
		std::fill(displacement.begin(), displacement.end(), 999999);
	}
	void add_edge(int u,int v,int w) 
	{
		adj[u].push_back(node(w, v));
		adj[v].push_back(node(w, u));
		cout << u << " ----- " << v << " Weight " << w << endl;
	}
	void mst(int q) 
	{
		int counter_x = 0;
		int count = vertex;
		displacement[q] = 0;
		queue<int> *que = new queue<int>[vertex];

		for (int i = 0; i < vertex; i++) 
			que[i].push(10000);
		while (1)
		{
			cout << parent[q] << " -----> " << q << " having Weight " << displacement[q] << endl;
			counter_x += displacement[q]; 
			count--;
			visited[q] = true; 
			while (adj[q].size() != 0)
			{
				node f = adj[q].front();
				if (f.weight < que[f.sec_val].front() && visited[f.sec_val] == false) 
				{
					que[f.sec_val].pop();
					que[f.sec_val].push(f.weight);
					displacement[f.sec_val] = f.weight;
					parent[f.sec_val] = q;
				}
				adj[q].pop_front();
			}
			int y = 10000;
			int s=0;
			for (int i = 0; i < vertex; i++)
			{
				if (displacement[i] < y && visited[i] == false) 
				{
					y = displacement[i];
					s = i;
				}
			}
			q = s;
			if (count == 0)
			{
				cout << endl << "Total displacement used = " << counter_x << endl;
				break;
			}
		}		
	}
};

int main() 
{
	graph x(9); 
	cout << "graph is:" << endl;
	x.add_edge(0,1,4); 
	x.add_edge(1,2,2);
	x.add_edge(0,3,1);
	x.add_edge(3,6,9);
	x.add_edge(6,7,6);
	x.add_edge(7,8,3);
	x.add_edge(8,5,8);
	x.add_edge(5,2,5);
	x.add_edge(1,4,6);
	x.add_edge(4,7,1);
	x.add_edge(3,4,11);
	x.add_edge(4,5,3);
	x.add_edge(0,4,8);
	x.add_edge(1,3,2);
	x.add_edge(1,5,1);
	x.add_edge(2,4,2);
	x.add_edge(3,7,8);
	x.add_edge(4,6,4);
	x.add_edge(4,8,5);
	x.add_edge(5,7,7);
	cout << endl << "Minimum spanning tree" << endl;
	x.mst(0); 
	system("pause");
	return 0; 
}