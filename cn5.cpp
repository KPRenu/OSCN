#include <iostream>
#include <vector>
#include <climits>
using namespace std;
const int INF = INT_MAX;
class Network
{
public:
    int numNodes;
    vector<vector<int>> costMatrix;
    Network(int nodes) : numNodes(nodes)
    {
        costMatrix.resize(nodes, vector<int>(nodes, INF));
    }
    void addLink(int node1, int node2, int cost)
    {
        costMatrix[node1][node2] = cost;
        costMatrix[node2][node1] = cost;
    }
    void printLeastCostTree(int source, const vector<int> &parent)
    {
        cout << "Least Cost Tree:" << endl;
        for (int i = 0; i < numNodes; ++i)
        {
            if (i != source)
            {
                cout << "Node " << i << " -> Node " << parent[i] << " (Cost: " << costMatrix[i][parent[i]] << ")" << endl;
            }
        }
    }
    void linkStateRouting(int source)
    {
        vector<int> distance(numNodes, INF);
        vector<bool> inTree(numNodes, false);
        vector<int> parent(numNodes, -1);
        distance[source] = 0;
        for (int i = 0; i < numNodes - 1; ++i)
        {
            int u = getMinDistanceVertex(distance, inTree);
            inTree[u] = true;
            for (int v = 0; v < numNodes; ++v)
            {
                if (!inTree[v] && costMatrix[u][v] != INF && distance[u] + costMatrix[u][v] < distance[v])
                {
                    parent[v] = u;
                    distance[v] = distance[u] + costMatrix[u][v];
                }
            }
        }
        printLeastCostTree(source, parent);
    }
    int getMinDistanceVertex(const vector<int> &distance, const vector<bool> &inTree)
    {
        int minDistance = INF;
        int minVertex = -1;
        for (int v = 0; v < numNodes; ++v)
        {
            if (!inTree[v] && distance[v] < minDistance)
            {
                minDistance = distance[v];
                minVertex = v;
            }
        }
        return minVertex;
    }
};
int main()
{
    int numNodes = 4;
    Network network(numNodes);
    // Add links with their costs
    network.addLink(0, 1, 4);
    network.addLink(0, 2, 2);
    network.addLink(1, 2, 5);
    network.addLink(1, 3, 10);
    network.addLink(2, 3, 1);
    int sourceNode = 0;
    network.linkStateRouting(sourceNode);
    return 0;
}