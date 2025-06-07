/*
You are given a directed graph of n nodes numbered from 0 to n - 1, where each node has at most one outgoing edge.

The graph is represented with a given 0-indexed array edges of size n, indicating that there is a directed edge from node i to node edges[i]. If there is no outgoing edge from i, then edges[i] == -1.

You are also given two integers node1 and node2.

Return the index of the node that can be reached from both node1 and node2, such that the maximum between the distance from node1 to that node, and from node2 to that node is minimized. If there are multiple answers, return the node with the smallest index, and if no possible answer exists, return -1.

Note that edges may contain cycles.
*/
class Solution {
public:
    void bfs(int startNode, vector<int>& edges, vector<int>& dist) {
        int n = edges.size();
        queue<int> q;
        q.push(startNode);

        vector<bool> visit(n);
        dist[startNode] = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            if (visit[node]) {
                continue;
            }

            visit[node] = true;
            int neighbor = edges[node];
            if (neighbor != -1 && !visit[neighbor]) {
                dist[neighbor] = 1 + dist[node];
                q.push(neighbor);
            }
        }
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dist1(n, numeric_limits<int>::max()), dist2(n, numeric_limits<int>::max());

        bfs(node1, edges, dist1);
        bfs(node2, edges, dist2);

        int minDistNode = -1, minDistTillNow = numeric_limits<int>::max();
        for (int currNode = 0; currNode < n; currNode++) {
            if (minDistTillNow > max(dist1[currNode], dist2[currNode])) {
                minDistNode = currNode;
                minDistTillNow = max(dist1[currNode], dist2[currNode]);
            }
        }

        return minDistNode;
    }
};
