/*
A robot on an infinite XY-plane starts at point (0, 0) facing north. The robot receives an array of integers commands, which represents a sequence of moves that it needs to execute. There are only three possible types of instructions the robot can receive:

-2: Turn left 90 degrees.
-1: Turn right 90 degrees.
1 <= k <= 9: Move forward k units, one unit at a time.
Some of the grid squares are obstacles. The ith obstacle is at grid point obstacles[i] = (xi, yi). If the robot runs into an obstacle, it will stay in its current location (on the block adjacent to the obstacle) and move onto the next command.

Return the maximum squared Euclidean distance that the robot reaches at any point in its path (i.e. if the distance is 5, return 25).

Note:

There can be an obstacle at (0, 0). If this happens, the robot will ignore the obstacle until it has moved off the origin. However, it will be unable to return to (0, 0) due to the obstacle.
North means +Y direction.
East means +X direction.
South means -Y direction.
West means -X direction.
 

Example 1:

Input: commands = [4,-1,3], obstacles = []

Output: 25

Explanation:

The robot starts at (0, 0):

Move north 4 units to (0, 4).
Turn right.
Move east 3 units to (3, 4).
The furthest point the robot ever gets from the origin is (3, 4), which squared is 32 + 42 = 25 units away.

Example 2:

Input: commands = [4,-1,4,-2,4], obstacles = [[2,4]]

Output: 65

Explanation:

The robot starts at (0, 0):

Move north 4 units to (0, 4).
Turn right.
Move east 1 unit and get blocked by the obstacle at (2, 4), robot is at (1, 4).
Turn left.
Move north 4 units to (1, 8).
The furthest point the robot ever gets from the origin is (1, 8), which squared is 12 + 82 = 65 units away.
  */


class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // lambda functions

        auto f = [](int x, int y) {
            return x * 60010 + y;
        };

        unordered_set<int> st;
        for(auto &obs : obstacles){
            st.insert( f(obs[0], obs[1]) ) ;
        }

        vector<pair<int,int>> dir = { {0,1} , {1,0} , {0,-1}, {-1,0}};
        //                            north    east    south   west

        int x = 0 , y =0;
        int d = 0; //north
        long long max_dist = 0;

        for(int cmd : commands){
            if(cmd == -2){
                d = (d+3)%4 ;
            } else if (cmd == -1){
                d = (d+1)%4 ;
            } else {
                for(int i = 0; i<cmd; i++){
                    int nx = x + dir[d].first;
                    int ny = y + dir[d].second;

                    int key = f(nx , ny);

                    if(st.find(key) != st.end()){
                        break;
                    }

                    x = nx;
                    y = ny;

                    max_dist = max( max_dist, 1LL*x*x + 1LL* y*y);
                
                }
            }
        }
        
        return max_dist;
    }
};

