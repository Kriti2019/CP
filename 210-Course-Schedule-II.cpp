class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& prerequisites) {
       vector<int> adj[V];
\t\tfor (auto it : prerequisites) {
\t\t\tadj[it[1]].push_back(it[0]);
\t\t}



\t\tvector<int>indegree(V,0);
\t\tfor (int i = 0; i < V; i++) {
\t\t\tfor (auto it : adj[i]) {
\t\t\t\tindegree[it]++;
\t\t\t}
\t\t}

\t\tqueue<int> q;
\t\tfor (int i = 0; i < V; i++) {
\t\t\tif (indegree[i] == 0) {
\t\t\t\tq.push(i);
\t\t\t}
\t\t}
\t\tvector<int> topo;
\t\twhile (!q.empty()) {
\t\t\tint node = q.front();
\t\t\tq.pop();
\t\t\ttopo.push_back(node);
\t\t\t// node is in your topo sort
\t\t\t// so please remove it from the indegree

\t\t\tfor (auto it : adj[node]) {
\t\t\t\tindegree[it]--;
\t\t\t\tif (indegree[it] == 0) q.push(it);
\t\t\t}
\t\t}

\t\tif (topo.size() == V) return topo;
\t\treturn {}; 
    }
};