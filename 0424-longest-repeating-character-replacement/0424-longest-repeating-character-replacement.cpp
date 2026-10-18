class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>freq(26,0);
        int k1=k;
        int l=0;
        int ans=0;
        for(int r=0;r<s.size();r++){
            freq[s[r]-'A']++;
            int max_freq=*max_element(freq.begin(),freq.end());
            if(((r-l+1)-max_freq)>k){
                freq[s[l]-'A']--;
                l++;
                max_freq=*max_element(freq.begin(),freq.end());
            }
            ans=max(r-l+1,ans);
        }
        return ans;
    }
};