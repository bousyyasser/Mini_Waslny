#include "ShortestPath.h"

ShortestPath::ShortestPath(Graph& g) : graph(g)
{
	dist.clear();
	parent.clear();
}

void ShortestPath::dijkstra(const string& source, const string& destination)
{
	 auto& adjList = graph.getAdjacencyList();
	for (const auto& connectedPairs : adjList)
	{
		dist[connectedPairs.first] = MAXDIST;
		parent[connectedPairs.first] = ""; //has no parent
	}

	set<pair<int, string>>nextNode;
	dist[source] = 0;
	nextNode.insert({ dist[source], source });

	while (!nextNode.empty())
	{
		auto it = nextNode.begin(); //choose nearest node
		int cost = it->first;
		string node = it->second;
		nextNode.erase(nextNode.begin());

		for (auto& child: adjList.at(node))
		{
			int newCost = child.distance + cost;

			if (newCost >= dist[child.destination])
				continue;
			
			auto found = nextNode.find({ dist[child.destination],child.destination }); 
			if (found != nextNode.end())
				nextNode.erase(found);       //erase former distance

			//modify node attributes
			parent[child.destination] = node;
			dist[child.destination] = newCost;
			nextNode.insert({ dist[child.destination], child.destination});

		}

	}
}


void ShortestPath::displayShortestPath(const string& target)
{
	if (dist.find(target) == dist.end() || dist[target] == MAXDIST)
	{
		return void(cout << "Can't reach this destination." << endl);
	}

	stack<string>path;
	string current = target;

	while (!current.empty())
	{
		path.push(current);
		current = parent[current];
	}

	while (!path.empty())
	{
		cout << path.top() << " ";
		path.pop();
	}
	cout << '\n';
}