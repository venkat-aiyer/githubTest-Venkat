// TestApp2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

// C++ program to detect if a path
// exists between any two vertices
// for the given undirected graph
#include <iostream>
#include <vector>
#include <queue>
#include <stdexcept>
#include <iostream>
#include <stack>
#include <concurrent_priority_queue.h>
#include <unordered_map>
using namespace std;

// Class representing a undirected
// graph using matrix
// representation
class Graph {
	int V;
	int** g;

public:
	Graph(int V);

	// Function to add an edge to graph
	void addEdge(int v, int w);

	// Function to check if
	// there exists a path or not
	bool isReachable(int s, int d);

	// function to compute paths
	// in the matrix using
	// Floyd Warshall Algorithm
	void computePaths();
};

Graph::Graph(int V)
{
	this->V = V;
	g = new int*[V + 1];
	for (int i = 1; i < V + 1; i++) {
		// Rows may not be contiguous
		g[i] = new int[V + 1];

		// Initialize all entries
		// as false to indicate
		// that there are
		// no edges initially
		memset(g[i], 0, (V + 1) * sizeof(int));
	}

	// Initializing node to itself
	// as it is always reachable
	for (int i = 1; i <= V; i++)
		g[i][i] = 1;
}

// Function to add edge between nodes
void Graph::addEdge(int v, int w)
{
	g[v][w] = 1;
	g[w][v] = 1;
}

// Function to compute the path
void Graph::computePaths()
{
	// Use Floyd Warshall algorithm
	// to detect if a path exists
	for (int k = 1; k <= V; k++) {

		// Try every vertex as an
		// intermediate vertex
		// to check if a path exists
		for (int i = 1; i <= V; i++) {
			for (int j = 1; j <= V; j++)
				g[i][j] = g[i][j]
				| (g[i][k]
					&& g[k][j]);
		}
	}
}

// Function to check if nodes are reachable
bool Graph::isReachable(int s, int d)
{

	if (g[s][d] == 1)
		return true;
	else
		return false;
}

// Function to find the k'th smallest element in an array using max-heap
int findKthSmallest(vector<int> const &v, int k)
{
	// create a max-heap using `std::priority_queue` and
	// insert the first `k` array elements into the heap
	
	priority_queue<int, vector<int>> pq(v.begin(), v.begin() + k);
	//make_heap()

	// do for remaining array elements
	for (int i = k; i < v.size(); i++)
	{
		// if the current element is less than the root of the heap
		if (v[i] < pq.top())
		{
			// replace root with the current element
			pq.pop();
			pq.push(v[i]);
		}
	}

	// return the root of max-heap
	return pq.top();
}
int nthLowestSelling(const std::vector<int>& sales, int n)
{
	// throw std::logic_error("Waiting to be implemented");
	priority_queue<int, vector<int>> pq(sales.begin(), sales.begin() + n);
	//make_heap()

	// do for remaining array elements
	for (int i = n; i < sales.size(); i++)
	{
		// if the current element is less than the root of the heap
		if (sales[i] < pq.top())
		{
			// replace root with the current element
			pq.pop();
			pq.push(sales[i]);
		}
	}

	// return the root of max-heap
	return pq.top();
}


class Friend
{
public:
	std::vector<Friend*> friends;

	Friend(std::string email)
	{
		this->email = email;
	}


	void addFriendship(Friend* target)
	{
		friends.push_back(target);
		target->friends.push_back(this);
	}

	bool canBeConnected(Friend* target)
	{
		// throw std::logic_error("Waiting to be implemented");
		stack<Friend*> stck;
		unordered_map<string, bool> visited;
		bool bRetVal = false;

		stck.push(this);
		while (!stck.empty())
		{
			std::vector<Friend*> friendsList = (stck.top())->friends;
			stck.pop();
			for (int i = 0; i< friendsList.size(); i++)
			{
				vector<Friend*> mutualFirendList = (friendsList[i])->friends;
				for (int j = 0; j< mutualFirendList.size(); i++)
				{
					Friend* mutualPossibleFirend((mutualFirendList[i]));
					if(mutualPossibleFirend != nullptr && visited.find(mutualPossibleFirend->friends[j]->email) == visited.end())
					{
						stck.push(mutualPossibleFirend->friends[j]);
						visited[mutualPossibleFirend->friends[j]->email] = true;
					}
					if (visited[target->email] == true)
					{
						bRetVal = true;
						break;
					}
				}
			}
		}
		return bRetVal;
	}

private:
	std::string email;
};

// Driver code
int main()
{

	Graph _g(4);
	_g.addEdge(1, 2);
	_g.addEdge(2, 3);
	_g.addEdge(1, 4);
	_g.computePaths();

	int u = 4, v = 3;
	if (_g.isReachable(u, v))
		cout << "Yes\n";
	else
		cout << "No\n";



	// Second problem driver code
	std::vector<int> input;
	input.push_back(5);
	input.push_back(4);
	input.push_back(3);
	input.push_back(2);
	input.push_back(1);
	input.push_back(5);
	input.push_back(4);
	input.push_back(3);
	input.push_back(2);
	input.push_back(5);
	input.push_back(4);
	input.push_back(3);
	input.push_back(5);
	input.push_back(4);
	input.push_back(5);

	int x = nthLowestSelling(input, 2);

	int nArr[] = { 1, 3, 4, 5,6 };
	int nVal1 = ++(*(nArr + 4));
	int nVal  = ++(nArr[4]);
	// *nArr[4]++;
	//int nValue = (nArr + 4)++;
	std::cout << x;


	Friend a("A");
	Friend b("B");
	Friend c("C");

	a.addFriendship(&b);
	b.addFriendship(&c);

	std::cout << a.canBeConnected(&c);
	return 0;
}


