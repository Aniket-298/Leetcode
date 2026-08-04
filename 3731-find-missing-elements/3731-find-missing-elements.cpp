class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int minimmum=nums[0];
        int maximum=nums[n-1];
        vector<int> ans;
        int j=0;
        for(int i=minimmum;i<=maximum;i++){
            if(j<nums.size() && nums[j]==i){
                j++;
            }
            else{
                ans.push_back(i);
            }
        }
        return ans;
    }
};