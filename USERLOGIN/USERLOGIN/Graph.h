#pragma once
#include<iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <stack>
#include "Edge.h"


using namespace std;

class Graph
{
private:
	unordered_map<string, vector<Edge>>adjacencyList;


public:
	void addCity(const string&); //To add a new city
	void addEdge(const string&, const string&, int);//add edge between cities


	void deleteEdge(const string&, const string&); //delete an edge between two cities
	void deleteCity(const string&); //delete a city and all edges connected


	bool cityExists(const string&);
	bool EdgeExists(const string&, const string&);

	void displayGraph(); //normal displaying 


};