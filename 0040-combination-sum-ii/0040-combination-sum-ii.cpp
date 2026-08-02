class Solution {
public:
set<vector<int>> s;

    void helper(vector<int> &vec,int target,int i,int n,vector<int> &temp,vector<vector<int>> &ans){
        if(target==0){
            if(s.find(temp)==s.end()){
                s.insert(temp);
                ans.push_back({temp});
                return;
            }
            return;
        }
        if(target<0 || i==n) return;
        for(int j=i;j<n;j++){
        if(j>i && vec[j]==vec[j-1]) continue;
        temp.push_back(vec[j]);
        helper(vec,target-vec[j],j+1,n,temp,ans);
        temp.pop_back();
        // helper(vec,target,j+1,n,temp,ans);
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& vec, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n=vec.size();
        sort(vec.begin(),vec.end());
        helper(vec,target,0,n,temp,ans);
        return ans;
    }
};