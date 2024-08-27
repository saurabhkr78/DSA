#include <iostream>
#include <vector>
#include <map>
#include <climits>
#include <string>
#include <unordered_map>

using namespace std;

class Node {
public:
    string name;
    unordered_map<string, int> distanceVector;
    unordered_map<string, string> nextHop;

    Node(string nodeName) : name(nodeName) {
        distanceVector[name] = 0;
    }

    void updateDistanceVector(string neighbor, unordered_map<string, int>& neighborDV) {
        for (auto& entry : neighborDV) {
            string dest = entry.first;
            int newDist = distanceVector[neighbor] + entry.second;

            if (distanceVector.find(dest) == distanceVector.end() || newDist < distanceVector[dest]) {
                distanceVector[dest] = newDist;
                nextHop[dest] = neighbor;
            }
        }
    }

    void printDistanceVector() {
        cout << "Node " << name << " distance vector:" << endl;
        for (auto& entry : distanceVector) {
            cout << "To " << entry.first << ": " << entry.second << " via " << nextHop[entry.first] << endl;
        }
    }
};

class Network {
public:
    unordered_map<string, Node*> nodes;
    unordered_map<string, vector<string>> neighbors;

    void addNode(string nodeName) {
        nodes[nodeName] = new Node(nodeName);
    }

    void addLink(string node1, string node2, int cost) {
        nodes[node1]->distanceVector[node2] = cost;
        nodes[node1]->nextHop[node2] = node2;
        nodes[node2]->distanceVector[node1] = cost;
        nodes[node2]->nextHop[node1] = node1;
        neighbors[node1].push_back(node2);
        neighbors[node2].push_back(node1);
    }

    void simulate() {
        bool converged;
        do {
            converged = true;
            for (auto& node : nodes) {
                string nodeName = node.first;
                Node* currentNode = node.second;

                for (string& neighbor : neighbors[nodeName]) {
                    Node* neighborNode = nodes[neighbor];
                    unordered_map<string, int> prevDV = currentNode->distanceVector;

                    currentNode->updateDistanceVector(neighbor, neighborNode->distanceVector);

                    if (prevDV != currentNode->distanceVector) {
                        converged = false;
                    }
                }
            }
        } while (!converged);
    }

    void printRoutingTables() {
        for (auto& node : nodes) {
            node.second->printDistanceVector();
            cout << endl;
        }
    }

    ~Network() {
        for (auto& node : nodes) {
            delete node.second;
        }
    }
};

int main() {
    Network network;

    network.addNode("A");
    network.addNode("B");
    network.addNode("C");
    network.addNode("D");

    network.addLink("A", "B", 1);
    network.addLink("A", "C", 4);
    network.addLink("B", "C", 2);
    network.addLink("C", "D", 1);

    network.simulate();
    network.printRoutingTables();

    return 0;
}
