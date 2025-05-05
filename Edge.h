#pragma once
#include <string>
using namespace std;


class Edge
{
public:
	string destination;
	int distance;


	Edge(const string&, int);
};

