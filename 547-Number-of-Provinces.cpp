class Solution {
public:
    void dfs(int node, vector<vector<int>>& adjLs, vector<int>& vis) {
        // Mark the node as visited
        vis[node] = 1; 
        for (auto it : adjLs[node]) {
            if (!vis[it]) {
                dfs(it, adjLs, vis); 
            }
        }
    }

    int findCircleNum(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<vector<int>> adjLs(V); 

        // Convert adjacency matrix to adjacency list
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                // Self nodes are not considered
                if (adj[i][j] == 1 && i != j) {
                    adjLs[i].push_back(j); 
                }
            }
        }

        vector<int> vis(V, 0);  // Correctly initialize the visited array
        int cnt = 0; 

        for (int i = 0; i < V; i++) {
            // If the node is not visited
            if (!vis[i]) {
                cnt++;  // Increment the counter for each province
                dfs(i, adjLs, vis); 
            }
        }

        return cnt; 
    }
};
