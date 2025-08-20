class Solution {
public:
    bool isPowerOfFour(int n) {
        unsigned int res=1;
        for(int i=0;i<n;i++)
        {
            if(n==1)
            {
                return 1;
            }
            res*=4;
            if(res==n)
            {
                return true;
            }
        }

        return false;
        
    }
};