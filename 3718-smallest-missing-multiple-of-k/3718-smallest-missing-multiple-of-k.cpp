class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int ans=0;
        bool found=false;
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%k==0){
                m[nums[i]]++;
                ans=max(nums[i],ans);
            }

        }
        int n=ans/k;
        for(int i=1;i<=n+1;i++){
            int a=k*i;
            if(m.find(a)==m.end()){
                return a;
            }
        }
        return 0;
    }
};