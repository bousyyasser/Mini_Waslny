#pragma once
#include<iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <stack>
#include <list>
#include "Edge.h"

#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>

using namespace rapidjson;

using namespace std;

enum operationType { AddCity, DeleteCity, AddEdge, DeleteEdge };

struct LastOperation {
    operationType type;
    string source;
    string destination;
    int distance;
    vector<Edge> cityEdges;
};

class Graph
{
private:
	unordered_map<string, vector<Edge>>adjacencyList;
	stack<LastOperation>undoStack;
	bool isUndo = false;

public:
	/*Main graph functions*/
	void addCity(const string&);
	void addEdge(const string&, const string&, int);
	void deleteEdge(const string&, const string&);
	void deleteCity(const string&);
	void undo();

	/*Helper Methods*/
	bool isUndoEmpty();
	bool cityExists(const string&);
	bool EdgeExists(const string&, const string&);

	/*Get Graph*/
	unordered_map<string, vector<Edge>>& getAdjacencyList();
	Value to_json(Document::AllocatorType& allocator) const;
	static Graph from_json(const Value& obj);
};