class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int majorityInTops = getMajorityElement(tops);
        int majorityInbottoms = getMajorityElement(bottoms);

        int majorityCountTops = 0;
        int majorityCountBottoms = 0;

        for(int i : tops) {
            if(i == majorityInTops) {
                majorityCountTops++;
            }
        }

        for(int i : bottoms) {
            if(i == majorityInbottoms) {
                majorityCountBottoms++;
            }
        }

        int rotation = INT_MAX;
        int n = tops.size();
        int topRotate = 0;
        int bottomRotate = 0;
        for(int i = 0; i < n; i++) {
            if(tops[i] != majorityInTops && bottoms[i] == majorityInTops) {
                topRotate++;
            }

            if(bottoms[i] != majorityInbottoms && tops[i] == majorityInbottoms) {
                bottomRotate++;
            }
        }

        if(topRotate == n - majorityCountTops) {
            rotation = min(rotation, topRotate);
        }

        if(bottomRotate == n - majorityCountBottoms) {
            rotation = min(rotation, bottomRotate);
        }

        return rotation == INT_MAX ? -1 : rotation;
    }

    int getMajorityElement(vector<int>& list) {
        
        int candidate = list[0];
        int count = 0;
        int n = list.size();
        
        for(int i : list) {
            if(candidate == i) {
                count++;
            } else {
                count--;
            }

            if(count == 0) {
                candidate = i;
                count = 1;
            }
        }
        return candidate;
    }
};
