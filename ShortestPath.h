#pragma once
#include<iostream>
#include <unordered_map>
#include<vector>
#include<set>
#include<stack>
#include "Graph.h"

const int MAXDIST = 1 << 30;

using namespace std;
class ShortestPath
{
private:
	 Graph& graph;
	unordered_map<string, int>dist;
	unordered_map<string, string>parent;

public:
	ShortestPath(Graph&);
	void dijkstra(const string&, const string&);
	void displayShortestPath(const string&);
};

