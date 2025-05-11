/*
We are given an array asteroids of integers representing asteroids in a row. The indices of the asteriod in the array represent their relative position in space.
For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.
Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. 
Two asteroids moving in the same direction will never meet.
  */
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        vector<int> temp;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            if (arr[i] > 0) {
                temp.push_back(arr[i]);
            } else {
                while (!temp.empty() && temp.back() > 0 &&
                       temp.back() < abs(arr[i])) {
                    temp.pop_back();
                }
                if (temp.empty() || temp.back() < 0) {
                    temp.push_back(arr[i]);
                }
                else if (!temp.empty() && temp.back() == abs(arr[i])) {
                    temp.pop_back();
                }
                
            }
        }
        return temp;
    }
};
