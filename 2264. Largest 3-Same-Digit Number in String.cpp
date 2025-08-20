class Solution {
    vector<string> sameDigitNumbers = {"999", "888", "777", "666", "555", "444", "333", "222", "111", "000"};

    bool contains(string sameDigitNumber, string num) {
        for (int index = 0; index <= num.size() - 3; ++index) {
            if (num[index] == sameDigitNumber[0] and 
                num[index + 1] == sameDigitNumber[1] and 
                num[index + 2] == sameDigitNumber[2]) {
                return true;
            }
        }
        return false;
    }

public:
    string largestGoodInteger(string num) {
        for (auto& sameDigitNumber: sameDigitNumbers) {
            if (contains(sameDigitNumber, num)) {
                return sameDigitNumber;
            }
        }
        return "";
    }
};