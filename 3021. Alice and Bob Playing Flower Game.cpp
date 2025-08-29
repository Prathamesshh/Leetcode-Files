/*
Alice and Bob are playing a turn-based game on a field, with two lanes of flowers between them. There are x flowers in the first lane between Alice and Bob, and y flowers in the second lane between them.
*/

class Solution {
public:
    long long flowerGame(int n, int m) {
        return (long long) n*m/2;
    }
};