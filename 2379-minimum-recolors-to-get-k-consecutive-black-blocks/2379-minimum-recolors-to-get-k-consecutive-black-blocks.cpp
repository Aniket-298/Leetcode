class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int min_ans=INT_MAX;
        int l=0;
        string temp="";
        int ans=0;
        for(int r=0;r<blocks.size();r++){
           
            if(blocks[r]=='W'){
                ans+=1;
            }
            if(r-l+1>k){
                if(blocks[l]=='W') ans-=1;
                l++;
            }
            if(r-l+1==k) min_ans=min(min_ans,ans);
        }
        return min_ans;
    }
};