class Solution {
public:
    vector<string>ans;
    void helper(string &temp,int st,int end){
        if(st==0 && end==0){
            ans.push_back(temp);
            return;
        }
        if(st>0){
            temp.push_back('(');
            helper(temp,st-1,end);
            temp.pop_back();
        }
        if(end>st){
            temp.push_back(')');
            helper(temp,st,end-1);
            temp.pop_back();
        }

    }
    vector<string> generateParenthesis(int n) {
        string temp="";
        helper(temp,n,n);
        return ans;
    }
};