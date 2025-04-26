#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <list>
using namespace std;
const int MAXDIST = 1 << 30;

class ShortestPath{
private:
    vector<int> dist;
    vector<int> parent;
    vector<list<pair<int, int>>> adjacencyList;

    ShortestPath(vector<list<pair<int, int>>> &adjacencyList, int graphSize, int edges){
        this->adjacencyList = adjacencyList;
        dist.assign(graphSize, MAXDIST);
        parent.assign(graphSize, -1); // has no parent
    }

public:

    void dijkstra(int source, int distination){
        set<pair<int, int>> nextNode;
        dist[source] = 0;
        nextNode.insert({dist[source], source});
        while (!nextNode.empty()){
            auto [cost, node] = *nextNode.begin(); // choose nearest node
            nextNode.erase(nextNode.begin());
            for (auto &[child, newCost] : adjacencyList[node]){
                newCost += cost;
                if (newCost >= dist[child])
                    continue;
                nextNode.erase({dist[child], child}); // erase former distance
                // modify node attributes
                parent[child] = node;
                dist[child] = newCost;
                nextNode.insert({dist[child], child}); // add new distance
            }
        }
    }

    void displayShortestPath(int target){
        if (dist[target] == MAXDIST){
            return void(cout << "Can't reach this destination." << endl);
        }

        stack<int> path;
        while (target != -1){
            path.push(target);
            target = parent[target];
        }
        while(!path.empty()){
            cout << path.top() << ' ';
            path.pop();
        }
        cout << '\n';
    }
};