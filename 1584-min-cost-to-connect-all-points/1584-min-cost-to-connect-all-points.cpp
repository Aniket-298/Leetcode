class Solution {
public:
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    void prims(vector<bool>&in_mst,int &ans,vector<vector<int>>& points){
        q.push({0,0});
        // in_mst[0]=true;
        while(q.size()>0){
            int wt=q.top().first;
            int u=q.top().second;
            q.pop();
            if(!in_mst[u]){
                in_mst[u]=true;
                ans+=wt;
                for(int i=0;i<points.size();i++){
                    int wt=abs(points[u][0]-points[i][0])+abs(points[u][1]-points[i][1]);
                    q.push({wt, i});
                }
            }
        }
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<bool> in_mst(n, false);
        int ans = 0;
        prims(in_mst, ans, points);
        return ans;
    }
};