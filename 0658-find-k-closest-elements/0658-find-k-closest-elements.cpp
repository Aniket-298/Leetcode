class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int st=0;
        int end=arr.size()-k;
        int n=arr.size();
        while(st<end){
            int mid=st+(end-st)/2;
            if((x-arr[mid])<=(arr[mid+k]-x)){
                end=mid;
            }
            else{
                st=mid+1;
            }
        }
        return vector<int>(arr.begin()+st,arr.begin()+st+k);
    }
};