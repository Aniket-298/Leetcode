class Solution {
public: 

    
    void subset(vector<int> &vec,vector<int> &ans,int i, vector<vector<int>> &allsubset,set<vector<int>>&st){
        if(i==vec.size()){
            if(st.find(ans)==st.end()){
                allsubset.push_back(ans);
                st.insert(ans);
                // return;
            }
            return; 
            
        }
        ans.push_back(vec[i]);
        subset(vec,ans,i+1,allsubset,st);
        ans.pop_back();
        // int idx=i+1;
        subset(vec,ans,i+1,allsubset,st);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& vec) {
        sort(vec.begin(),vec.end());
        set<vector<int>>st;
        vector<vector<int>> allsubset;
        vector<int> ans;
        subset(vec,ans,0,allsubset,st);
        // sort(allsub)
        return allsubset;
    
    }
};