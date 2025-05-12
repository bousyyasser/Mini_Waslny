#include "Edge.h"


Edge::Edge(const string& destination, int distance)
{
	this->destination = destination;
	this->distance = distance;
}
Edge::Edge()
{
	this->destination = "";
	this->distance = 0;
}