class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int player=0,trainer=0;
        while(trainer<s.size() && player <g.size()){
            if(s[trainer]>=g[player])
                player++;
    
        trainer++; 
        }
        return player;
    }
};
