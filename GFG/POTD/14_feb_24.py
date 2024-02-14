/*
Find all Critical Connections in the Graph



A critical connection refers to an edge that, upon removal, will make it impossible for certain nodes to reach each other through any path. You are given an undirected connected graph with v vertices and e edges and each vertex distinct and ranges from 0 to v-1, and you have to find all critical connections in the graph. It is ensured that there is at least one such edge present.

Note: The answers may be presented in various potential orders. Each edge should be displayed in sorted order. For instance, if there's an edge between node 1 and node 2, it should be stored as (1,2) rather than (2,1). Additionally, it is expected that you store the edges in sorted order.


Example 1:

0--------1
 |
  |
   |
    2
Output:
0 1
0 2
Explanation: 
On removing edge (0, 1), you will not be able to
reach node 0 and 2 from node 1. Also, on removing
edge (0, 2), you will not be able to reach node 0
and 1 from node 2.
*/

time=0
class Solution:
    def dfs_mod(self,u,adj,visited,disc,low,bridge,parent):
        visited[u]=True
        global time
        disc[u]=time
        low[u]=time
        time+=1
        for v in adj[u]:
            if visited[v]==False:
                self.dfs_mod(v,adj,visited,disc,low,bridge,u)
                low[u]=min(low[u],low[v])
                if low[v]>disc[u]:
                    bridge.append(sorted([u,v]))
            elif v!=parent:
                low[u]=min(low[u],disc[v])

    def criticalConnections(self, v, adj):
        visited=[False]*v
        disc=[0]*v
        low=[0]*v
        bridge=[]
        self.dfs_mod(0,adj,visited,disc,low,bridge,-1)
        bridge.sort()
        return bridge
