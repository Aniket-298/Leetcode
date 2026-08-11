class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        queue<int>q;
        vector<bool>visited(n,false);
        q.push(source);
        visited[source]=true;
        vector<vector<int>> adj(n);
        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(auto u:adj[curr]){
                if(!visited[u]){
                        visited[u]=true;
                        q.push(u);
                }    
            }
        }
        return visited[destination]==true;
    }
};