#include "GraphTraversal.h"

GraphTraversal::GraphTraversal(Graph& g): graph(g) 
{}

list<string>GraphTraversal::DFS(const string& startCity)
{
	if (!graph.cityExists(startCity))
	{
		return {};
	}

	unordered_map<string, bool>visited;
	list<string>path;
	stack<string>s;

	s.push(startCity);

	while (!s.empty())
	{
		string node = s.top();
		s.pop();
		if (!visited[node])
		{
			visited[node] = true;
			path.push_back(node);

			const auto& neighbours = graph.getAdjacencyList().at(node);
			for (auto it = neighbours.rbegin(); it != neighbours.rend(); ++it)
			{
				if (!visited[it->destination])
				{
					s.push(it->destination);
				}
			}
		}
	}

	return path;
}

list<string> GraphTraversal::BFS(const string& startCity, const string& endCity)
{

	if (!graph.cityExists(startCity) || !graph.cityExists(endCity))
	{
		return {};
	}
	unordered_map<string, bool>visited;
	unordered_map<string, string>parent;
	queue<string>q;

	q.push(startCity);
	visited[startCity] = true;
	parent[startCity] = "";

	while (!q.empty())
	{
		string node = q.front(); 
		q.pop();

		const auto& neighbours = graph.getAdjacencyList().at(node);
		for (const auto& edge : neighbours)
		{
			if (!visited[edge.destination])
			{
				visited[edge.destination] = true;
				parent[edge.destination] = node;
				q.push(edge.destination);
			}
		}
	}

	if (!visited[endCity])
		return {};

	list<string>path;
	string current = endCity;
	while (parent.find(current) != parent.end())
	{
		path.push_front(current);
		current = parent[current];
	}
	
	path.push_front(current);

	return path;
}