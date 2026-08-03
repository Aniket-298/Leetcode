class Solution {
public:

    void combinations(int start,int n,int k,vector<int> &current,vector<vector<int>>&ans){
        if(current.size()==k){
            ans.push_back({current});
            return;
        }
        for(int j=start;j<=n;j++){
            current.push_back(j);
            combinations(j+1,n,k,current,ans);
            current.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> current;
        vector<vector<int>> ans;
        combinations(1,n,k,current,ans);
        return ans;
    }
};