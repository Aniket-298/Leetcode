class Solution {
public:

    void bfs(vector<vector<int>> & isConnected,int i,vector<bool> & vis){
        queue<int>q;
        q.push(i);
        vis[i]=true;
        int n=isConnected.size();
        while(q.size()>0){
            int curr=q.front();
            q.pop();
            for(int j=0;j<n;j++){
                if(isConnected[curr][j]==1 && !vis[j]){
                    q.push(j);
                    vis[j]=true;
                }
            }
        }
    }

       
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int m=isConnected[0].size();
        vector<bool>vis(n,false);
        int ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                ans++;
                bfs(isConnected,i,vis);
            }
        }
        return ans;
    }
};