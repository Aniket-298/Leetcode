class Solution {
public:

    bool cycle(vector<bool>& vis,vector<bool>& recpath,int src,vector<vector<int>>& prerequisites){
        vis[src]=true;
        recpath[src]=true;
        for(int i=0;i<prerequisites.size();i++){
            int u=prerequisites[i][1];
            int v=prerequisites[i][0];
            if(src==u){
                if(!vis[v]){
                    if(cycle(vis,recpath,v,prerequisites)) return true;
                }
                else if(recpath[v]) return true;
            }
        }
        recpath[src]=false;
        return false;
    }

    void topological_sort(int src,vector<bool> &vis2,stack<int>&s,vector<vector<int>>& prerequisites){
        vis2[src]=true;
        for(int i=0;i<prerequisites.size();i++){
            int u=prerequisites[i][1];
            int v=prerequisites[i][0];

            if(src==u){
                if(!vis2[v]){
                   topological_sort(v,vis2,s,prerequisites);
                }
            }
        }
        s.push(src);
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool>vis(numCourses,false);
        vector<bool>recpath(numCourses,false);
        vector<int> ans;
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(cycle(vis,recpath,i,prerequisites)){
                    return ans;
                }
            }
        }

        stack<int>s;
        vector<bool>vis2(numCourses,false);
        for(int i=0;i<numCourses;i++){
            if(!vis2[i]){
                topological_sort(i,vis2,s,prerequisites);
            }
        }
        while(s.size()>0){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};