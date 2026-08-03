class Solution {
public:
    vector<string> mp = {"", "", "abc", "def", "ghi","jkl", "mno", "pqrs", "tuv", "wxyz"};
    void helper(string& digits, int i,string& current,vector<string>& ans) {
    if(current.size()==digits.size()){
        ans.push_back(current);
        return;
    }
    string letter=mp[digits[i]-'0'];
    for(int j=0;j<letter.size();j++){
        current.push_back(letter[j]);
        helper(digits,i+1,current,ans);
        current.pop_back();
    }
}
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        string current="";
        helper(digits,0,current,ans);
        return ans;
    }
};