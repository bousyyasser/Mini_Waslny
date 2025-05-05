#pragma once
#include "Graph.h"
#include<unordered_map>
#include<stack>
#include <queue>
#include<list>
class GraphTraversal
{
private:
	Graph& graph;

public: 
	GraphTraversal(Graph&);

	list<string>DFS(const string& );
	list<string> BFS(const string&);
};

