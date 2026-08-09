class Solution {
public:
    int myAtoi(string s) {
        set<char>st={'1','2','3','4','5','6','7','8','9','0','-','+'};
        string ans="";
        int j=0;
        while( j<s.size() && s[j]==' ') j++;
        
        for(int i=j;i<s.size();i++){
            if(s[i]=='-' && ans.size()>0) break;
            if(s[i]=='+' && ans.size()>0) break;
            if(st.find(s[i])!=st.end()) ans+=s[i];
            if(st.find(s[i])==st.end()) break;
        }
        long long num=0;
        if(ans.size()==0 || (ans.size()==1 && (ans[0]=='-' || ans[0]=='+'))) return 0;

        int start=0;
        char minus='-';
        char plus='+';
        if(ans[0]=='+'){
            start=1;
            while(start<ans.size() && ans[start]=='0') start++;
            ans=plus+ans.substr(start,ans.size());
        }
        else if(ans[0]=='-'){
            start=1;
            while(start<ans.size() && ans[start]=='0') start++;
            ans=minus+ans.substr(start,ans.size());
        }
        else{
            while(start<ans.size() && ans[start]=='0') start++;
            ans=ans.substr(start,ans.size());
        }
        if(ans == "" || ans == "+" || ans == "-") return 0;
        if(ans[0]=='-'){
            if(ans.size()>11) return INT_MIN;
            if(ans.size()==11 && ans.substr(1)>"2147483648") return INT_MIN;
            for(int i=1;i<ans.size();i++){
                num=num*10+(ans[i]-'0');
            }
            return -num;
        }
        else if (ans[0]=='+'){
            if(ans.size()>11) return INT_MAX;
            if(ans.size()==11 && ans.substr(1)> "2147483647") return INT_MAX;
            for(int i=1;i<ans.size();i++){
                num=num*10+(ans[i]-'0');
            }
            return num;
        }
        else{ 
            if(ans.size()>10) return INT_MAX;
             if(ans.size()==10 && ans> "2147483647") return INT_MAX;
            for(int i=0;i<ans.size();i++){
                num=num*10+(ans[i]-'0');
            }
            return num;
        }
        return 0;
    }
};