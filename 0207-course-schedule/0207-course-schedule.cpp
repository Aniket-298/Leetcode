class Solution {
public:
    bool dfs(int src,vector<bool> &vis,vector<bool>& recPath,vector<vector<int>>& prerequisites){
            vis[src]=true;
            recPath[src]=true;
            for(int i=0;i<prerequisites.size();i++){
                int u=prerequisites[i][1];
                int v=prerequisites[i][0];
                if(u==src){
                    if(!vis[v]){
                        if(dfs(v,vis,recPath,prerequisites)) return true;
                    }
                    else if(recPath[v]){
                        return true;
                        }
                }
            }
            recPath[src]=false;
            return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
         
        vector<bool> vis(numCourses,false);
        vector<bool> recPath(numCourses,false);
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(dfs(i,vis,recPath,prerequisites)) return false;
            }
        }
        return true;
    }
};