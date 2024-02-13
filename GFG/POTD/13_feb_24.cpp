/*
Clone an Undirected Graph

Graph (DFS, BFS) based question

Given a connected undirected graph with n nodes and m edges, with each node having a distinct label from 0 to n-1, create a clone of the graph. Each node in the graph contains an integer val and an array (neighbors) of nodes, containing nodes that are adjacent to the current node.

Note: If the user returns a correct copy of the given graph, then the system will print 1; in the case when an incorrect copy is generated or when the user returns the original node, the system will print 0.

For Example :    

class Node {
    val: integer
    neighbors: List[Node]
}
Example 1:

Input:
adjList = 
{
    {1, 3},
    {0, 2},
    {1, 3},
    {0, 2}
}
Output: 1
Explanation:
1 is the output that the driver code will print in case 
you successfully cloned the given graph

Example 2:

Input:
adjList = 
{
    {1},
    {0}
}
Output: 1
Explanation: 
1 is the output that the driver code will print in case
you successfully cloned the given graph.
*/


class Solution
{
public:
  Node* cloneGraph(Node* node) {
        if (!node) {
            return nullptr;
        }

        unordered_map<Node*, Node*> visited;

        return cloneHelper(node, visited);
    }

private:
    Node* cloneHelper(Node* originalNode, unordered_map<Node*, Node*>& visited) {
        if (!originalNode) {
            return nullptr;
        }

        // Check if the node is already visited
        if (visited.find(originalNode) != visited.end()) {
            return visited[originalNode];
        }

        // Create a copy of the current node
        Node* clonedNode = new Node(originalNode->val);

        // Mark the current node as visited
        visited[originalNode] = clonedNode;

        // Recursively clone the neighbors of the current node
        for (Node* neighbor : originalNode->neighbors) {
            clonedNode->neighbors.push_back(cloneHelper(neighbor, visited));
        }

        return clonedNode;
    }
    
};
