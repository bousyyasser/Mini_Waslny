#pragma once
#include "Graph.h"
#include<unordered_map>
#include<stack>
#include <queue>
#include<vector>
class GraphTraversal
{
private:
	Graph& graph;

public: 
	GraphTraversal(Graph&);

	vector<string>DFS(const string& );
	vector<string> BFS(const string&);
};

