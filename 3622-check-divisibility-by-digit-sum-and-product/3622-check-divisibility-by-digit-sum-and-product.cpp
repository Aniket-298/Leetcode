class Solution {
public:
    bool checkDivisibility(int n) {
        int m=n;
        int sum=0;
        int product=1;
        while(n>0){
            int temp=n%10;
            sum+=temp;
            product*=temp;
            n/=10;
        }
        sum+=product;
        if(m%sum==0) return true;
        return false;

    }
};