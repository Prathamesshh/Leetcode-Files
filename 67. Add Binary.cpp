class Solution {
 public:
  string addBinary(string a, string b) {
    string res;
    int carrry = 0;
    int i = a.length() - 1;
    int j = b.length() - 1;

    while (i >= 0 || j >= 0 || carrry) {
      if (i >= 0)
        carrry += a[i--] - '0';
      if (j >= 0)
        carrry += b[j--] - '0';
      res += carrry % 2 + '0';
      carrry /= 2;
    }

    reverse(begin(res), end(res));
    return res;
  }
};
