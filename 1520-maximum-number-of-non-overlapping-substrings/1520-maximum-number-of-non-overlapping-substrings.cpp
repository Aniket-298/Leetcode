bool compare(pair<int,int> a, pair<int,int> b) {
    return a.second < b.second;
}

class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<int>first(26,-1);
        vector<int>last(26,-1);
        for(int i=0;i<s.size();i++){
            int idx=s[i]-'a';
            if(first[idx]==-1){
                first[idx]=i;
            }
            last[idx]=i;
        }
        vector<pair<int,int>>vec;
        for(int i=0;i<26;i++){
            if(first[i]==-1) continue;
            int idx=i;
            int l=first[idx];
            int r=last[idx];
            bool valid=true;
            for(int j=l;j<=r;j++){
                if(first[s[j]-'a']<l){
                    valid=false;
                    break;
                }
                r=max(r,last[s[j]-'a']);
            }
            if(valid){
                vec.push_back({l,r});
            }
        }
        sort(vec.begin(),vec.end(),compare);
        vector<string>ans;
        int prev=-1;
        for(auto x:vec){
            int l=x.first;
            int r=x.second;
            if(l>prev){
                ans.push_back(s.substr(l,r-l+1));
                prev=r;
            }
        }
        return ans;
    }
};