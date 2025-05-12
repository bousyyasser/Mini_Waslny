#pragma once
#include <string>
using namespace std;
#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>

using namespace rapidjson;

class Edge
{
public:
	string destination;
	int distance;


	Edge(const string&, int);
	Edge();
	rapidjson::Value to_json(rapidjson::Document::AllocatorType& allocator) const;
	static Edge from_json(const rapidjson::Value& obj);
};

