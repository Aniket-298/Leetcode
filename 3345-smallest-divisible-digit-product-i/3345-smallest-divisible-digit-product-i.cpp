class Solution {
public:
    int smallestNumber(int n, int t) {
        int number=n;
        int ans=0;
        while(true){
            int temp=n;
            int p=1;
            while(temp>0){
                int digit=temp%10;
                p*=digit;
                temp/=10;
            }
                if(p%t==0) return n;
                else n++;
        }
    }
};