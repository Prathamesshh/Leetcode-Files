/*
There are n 1-indexed robots, each having a position on a line, health, and movement direction.

You are given 0-indexed integer arrays positions, healths, and a string directions (directions[i] is either 'L' for left or 'R' for right). All integers in positions are unique.

All robots start moving on the line simultaneously at the same speed in their given directions. If two robots ever share the same position while moving, they will collide.

If two robots collide, the robot with lower health is removed from the line, and the health of the other robot decreases by one. The surviving robot continues in the same direction it was going. If both robots have the same health, they are both removed from the line.

Your task is to determine the health of the robots that survive the collisions, in the same order that the robots were given, i.e. final health of robot 1 (if survived), final health of robot 2 (if survived), and so on. If there are no survivors, return an empty array.

Return an array containing the health of the remaining robots (in the order they were given in the input), after no further collisions can occur.

Note: The positions may be unsorted.

Example 1:
Input: positions = [5,4,3,2,1], healths = [2,17,9,15,10], directions = "RRRRR"
Output: [2,17,9,15,10]
Explanation: No collision occurs in this example, since all robots are moving in the same direction. So, the health of the robots in order from the first robot is returned, [2, 17, 9, 15, 10].
  */


class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();

        vector<int> indices(n);
        for (int i = 0; i < n; i++) {
            indices[i] = i;
        }

        sort(indices.begin(), indices.end(),
            [&](auto& a, auto& b) { return positions[a] < positions[b]; });

        stack<int> st;

        for (const auto& index : indices) {
            if (directions[index] == 'R') {
                st.push(index);
            } else {
                while (!st.empty() && healths[index] > 0) {
                    int topIndex = st.top();

                    if (healths[index] > healths[topIndex]) {
                        healths[topIndex] = 0;
                        healths[index] -= 1;
                        st.pop();
                    } else if (healths[index] < healths[topIndex]) {
                        healths[index] = 0;
                        healths[topIndex] -= 1;
                    } else {
                        healths[topIndex] = 0;
                        healths[index] = 0;
                        st.pop();
                    }
                }
            }
        }

        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (healths[i] > 0) {
                result.push_back(healths[i]);
            }
        }

        return result;
    }
};
