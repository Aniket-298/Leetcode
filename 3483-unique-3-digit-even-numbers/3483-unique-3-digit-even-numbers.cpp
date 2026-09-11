class Solution {
public:
    
    int totalNumbers(vector<int>& digits) {
        unordered_map<int,int>m;
        int ans=0;
        for(int i:digits) m[i]++;
        for(int i=100;i<1000;i++){
            if(i%2!=0) continue;
            int x=i;
            int a=x/100;
            int b=(x/10)%10;
            int c=x%10;
            m[a]--;
            m[b]--;
            m[c]--;
            if(m[a]>=0 && m[b]>=0 && m[c]>=0) ans++;
            m[a]++;
            m[b]++;
            m[c]++;
        }
        return ans;

    }
};