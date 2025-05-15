#include "GraphTraversal.h"

GraphTraversal::GraphTraversal(Graph& g): graph(g) 
{}

vector<string>GraphTraversal::DFS(const string& startCity)
{
	if (!graph.cityExists(startCity))
	{
		return {};
	}

	unordered_map<string, bool>visited;
	vector<string>path;
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

vector<string> GraphTraversal::BFS(const string& startCity)
{

	if (!graph.cityExists(startCity))
	{
		return {};
	}
	unordered_map<string, bool>visited;
	queue<string>q;

	vector<string>path;

	q.push(startCity);
	visited[startCity] = true;


	while (!q.empty())
	{
		string node = q.front(); 
		q.pop();
		path.push_back(node);
		const auto& neighbours = graph.getAdjacencyList().at(node);
		for (const auto& edge : neighbours)
		{
			if (!visited[edge.destination])
			{
				visited[edge.destination] = true;
				q.push(edge.destination);
			}
		}
	}




	return path;
}