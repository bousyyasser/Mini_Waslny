#include "Graph.h"


void Graph::addCity(const string& city)
{

	if (!cityExists(city))
	{
		adjacencyList[city] =vector<Edge>();

		if(!isUndo)
		undoStack.push({ AddCity,city });
	}
}
void Graph::addEdge(const string& source, const string& destination, int distance)
{
	

	if (!cityExists(source)) {
		addCity(source);
		
	}
	if (!cityExists(destination)) {
		addCity(destination);
		       
	}

	if (!EdgeExists(source, destination)) {
		adjacencyList[source].push_back(Edge(destination, distance));
		adjacencyList[destination].push_back(Edge(source, distance));
		if (!isUndo) {
			undoStack.push({ AddEdge, source, destination, distance, {}});
		}
	}
}

void Graph::deleteEdge(const string& source, const string& destination)
{
	if (!EdgeExists(source, destination))
	{
		return;
	}

	int dist = -1;
	for (const auto& edge : adjacencyList[source])
	{
		if (edge.destination == destination)
		{
			dist = edge.distance;
		}
	}


	auto& sourceEdges = adjacencyList[source];
	for (auto it = sourceEdges.begin(); it != sourceEdges.end(); )
	{
		if (it->destination == destination)
		{
			it = sourceEdges.erase(it);
		}
		else
		{
			++it;
		}
	}

	auto& destEdges = adjacencyList[destination];
	for (auto it = destEdges.begin(); it != destEdges.end(); )
	{
		if (it->destination == source)
		{
			it = destEdges.erase(it);
		}
		else
		{
			++it;
		}
	}

	if(!isUndo)
	undoStack.push({ DeleteEdge,source,destination,dist });
}
void Graph::deleteCity(const string& cityToDelete)
{
	if (!cityExists(cityToDelete))
	{
		return;
	}

	vector<Edge> EdgesConnected = adjacencyList[cityToDelete];

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

	adjacencyList.erase(cityToDelete);

	if (!isUndo)
	{
		undoStack.push({ DeleteCity, cityToDelete, "", 0, EdgesConnected });
	}
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

unordered_map<string, vector<Edge>>& Graph::getAdjacencyList()
{
	return adjacencyList;
}


void Graph::undo()
{
	if (isUndoEmpty())
	{
		return;
	}

	isUndo = true;
	LastOperation lastOp = undoStack.top();
	undoStack.pop();


	if (lastOp.type == AddCity)
	{
		deleteCity(lastOp.source);
	}
	else if (lastOp.type == DeleteCity)
	{
		addCity(lastOp.source);
		for (const auto& edge : lastOp.cityEdges)
		{
			adjacencyList[lastOp.source].push_back(edge);
			adjacencyList[edge.destination].push_back(Edge(lastOp.source, edge.distance));

		}
	}

	else if (lastOp.type == AddEdge)
	{
		deleteEdge(lastOp.source, lastOp.destination);
	}

	else if (lastOp.type == DeleteEdge)
	{
		addEdge(lastOp.source, lastOp.destination, lastOp.distance);
	}
	isUndo = false;
}
bool Graph::isUndoEmpty()
{
	return (!undoStack.size());
}

