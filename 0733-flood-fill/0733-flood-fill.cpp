class Solution {
public:

    void bfs(vector<vector<bool>>&vis,vector<vector<int>> &image,int color,queue<pair<int,int>> &q,int n,int m,int target){
        while(q.size()>0){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            if(i-1>=0 && !vis[i-1][j] && image[i-1][j]==target){
                q.push({i-1,j});
                vis[i-1][j]=true;
                image[i-1][j]=color;
            }

            if(i+1<n && !vis[i+1][j] && image[i+1][j]==target){
                q.push({i+1,j});
                vis[i+1][j]=true;
                image[i+1][j]=color;
            }

             if(j-1>=0 && !vis[i][j-1] && image[i][j-1]==target){
                q.push({i,j-1});
                vis[i][j-1]=true;
                image[i][j-1]=color;
            }

            if(j+1<m && !vis[i][j+1] && image[i][j+1]==target){
                q.push({i,j+1});
                vis[i][j+1]=true;
                image[i][j+1]=color;
            }
        }
    }


    vector<vector<int>> floodFill(vector<vector<int>>& image, int i, int j, int color) {
        int n=image.size();
        int m=image[0].size();
        if(image[i][j]==color) return image;
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        queue<pair<int,int>> q; 
        int target=image[i][j];
        q.push({i,j});
        vis[i][j]=true;
        image[i][j]=color;
        bfs(vis,image,color,q,n,m,target);
        return image;
    }
};