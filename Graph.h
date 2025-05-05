#pragma once
#include<iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <stack>
#include <list>
#include "Edge.h"


using namespace std;

enum operationType { AddCity, DeleteCity, AddEdge, DeleteEdge };
struct LastOperation
{
	operationType type;
	string source;
	string destination;
	int distance;
	list<Edge>cityEdges;
};

class Graph
{
private:
	unordered_map<string, list<Edge>>adjacencyList;
	stack<LastOperation>undoStack;
	bool isUndo = false;
	


public:
	/**/
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
	unordered_map<string, list<Edge>>& getAdjacencyList();


};