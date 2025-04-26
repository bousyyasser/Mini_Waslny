#include "Graph.h"


void Graph::addCity(const string& city)
{
	
	if (adjacencyList.find(city) == adjacencyList.end())
	{
		adjacencyList[city] = vector<Edge>();
	}
}

void Graph::addEdge(const string& source, const string& destination, int distance)
{
	addCity(source);
	addCity(destination);

	bool exists = false; 

	for (const Edge& edge : adjacencyList[source])
	{
		if (edge.destination == destination)
		{
			exists = true;
			break;
		}
	}

	if (!exists)
	{
		adjacencyList[source].push_back(Edge(destination, distance));
		adjacencyList[destination].push_back(Edge(source, distance));
	}
}

void Graph::deleteEdge(const string& source, const string& destination)
{
	if (!EdgeExists(source, destination)) return;


		auto& sourceEdges = adjacencyList[source];
		for (auto it = sourceEdges.begin(); it != sourceEdges.end(); )
		{
			if (it->destination == destination)
			{
				it = sourceEdges.erase(it);
			}
			else
				++it;
		}

		auto& destEdges = adjacencyList[destination];
		for (auto it = destEdges.begin(); it != destEdges.end(); )
		{
			if (it->destination == source)
				it = destEdges.erase(it);
			else
				++it;
		}
	

}

void Graph::deleteCity(const string& cityToDelete)
{
	
	if (!cityExists(cityToDelete)) return;


		
		for (auto& items : adjacencyList)
		{
			const string& connectedCity = items.first;
			
			if (connectedCity != cityToDelete)
			{
				auto& edges = items.second;
				for (auto it = edges.begin(); it != edges.end(); )
				{
					if (it->destination == cityToDelete)
					{
						it = edges.erase(it);
					}
					else
					{
						++it;
					}
				}
			}

		}
		//after deleting edges->delete the city
		adjacencyList.erase(cityToDelete);

}




bool Graph::cityExists(const string& cityName)
{
	return (adjacencyList.find(cityName) != adjacencyList.end());
}
bool Graph::EdgeExists(const string& source, const string& dest)
{

	if (adjacencyList.find(source) != adjacencyList.end())
	{
		for (const auto& edge : adjacencyList[source])
			if (edge.destination == dest) return true;
	}

	if (adjacencyList.find(dest) != adjacencyList.end())
	{
		for (const auto& edge : adjacencyList[dest])
			if (edge.destination == source) return true;
	}


	return false;
}


void Graph::displayGraph() 
{
	
}