class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int stud=0,cookie=0;
        while(cookie<s.size() && stud <g.size()){
            if(s[cookie]>=g[stud])
                stud++;
    
        cookie++; 
        }
        return stud;
        
    }

};
