class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        map<int,int> m;
        int ans=0;
        int i=0;
        for(int j=0;j<nums.size();j++){
            m[nums[j]]++;
            while(m[nums[j]]>k){
                m[nums[i]]--;
                i++;
            }
            ans=max(ans,j-i+1);
        }
        return ans;
    }
};