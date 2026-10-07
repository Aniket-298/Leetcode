class Solution {
public:

    int power(int a,int b,int mod){
        if(b==0) return 1;
        long long half=power(a,b/2,mod);
        if(b%2==0){
            return (half*half)%mod;
        }
        else return (half*half%mod *a)%mod;
    }
    int superPow(int a, vector<int>& b) {
        if(a==1) return 1;
        long long ans=1;
        for(int x:b){
            ans=(long long)power(ans,10,1337)*power(a,x,1337)%1337;
        }
        return ans;
    }
};