/*
- val ~ 24 by abs(val - 24) < epsilon, epsilon = 1e-6 
- when reach leaves(list.size() == 1) -> check if we reach 24
for pair (a, b) in current list:
    array resOps = gen 6 ops of a,b
    for (int x: resOps)
        cpy list = original removed (a,b) + x
        if backtrack(cpylist) return true

return false // if none fail
*/
class Solution {
private:
    // calculate all possible value form by a and b
    vector<double>genOps(double a, double b){
        return {a+b, a-b, b-a, a*b, (double)a/b, (double)b / a};
    }

    bool backtrack(vector<double>& list){
        if (list.size() == 1) return abs(list[0] - 24) < epsilon;

        for (int i = 0; i < list.size(); i++){
            for (int j = i + 1; j < list.size(); j++){
                double a = list[i], b = list[j];
                vector<double>copyList;
                for (int k = 0; k < list.size(); k++){
                    if (k != i && k != j) copyList.push_back(list[k]);
                }

                vector<double>resOps = genOps(a, b);
                for (double x: resOps){
                    copyList.push_back(x);
                    if (backtrack(copyList)) return true;
                    // try other ops if fail
                    copyList.pop_back();
                }
            }
        }
        return false;
    }
public:
    const double epsilon = 1e-6;
    bool judgePoint24(vector<int>& cards) {  
        // cast to double
        vector<double>list(cards.begin(), cards.end());
        return backtrack(list);
    }
};