class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<string>ans;
        int product = 1;
        for(int i = 1;i<=30;i++){
            ans.push_back(to_string(product));
            product *= 2;
        }

        for(auto &i:ans){
            sort(i.begin(),i.end());
        }

        string tocheck = "";
        while(n > 0){
            int digit = n%10;
            tocheck.push_back(digit + '0');
            n /= 10;
        }

        sort(tocheck.begin(),tocheck.end());
        if(find(ans.begin(),ans.end(),tocheck) != ans.end()){
            return true;
        }
        return false;
    }
};