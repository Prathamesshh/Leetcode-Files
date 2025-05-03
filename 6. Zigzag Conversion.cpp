class Solution {
public:
    string convert(string s, int numRows) {
        int n=s.length();
        if(numRows==1 || numRows>=n){
            return s;
        }
        vector<string> store(numRows);
        int i=0;
        int goDown=false;
        for(char ch:s){
            store[i]+=ch;
            if(i==0 || i==numRows-1){
                goDown=!goDown;
            }
            goDown?i+=1:i-=1;
        }
        string ans="";
        for(auto it:store){
            ans+=it;
        }
        return ans;
    }
};
