/*
You are given a string s consisting of lowercase English letters, an integer t representing the number of transformations to perform, and an array nums of size 26. In one transformation, every character in s is replaced according to the following rules:
Replace s[i] with the next nums[s[i] - 'a'] consecutive characters in the alphabet. For example, if s[i] = 'a' and nums[0] = 3, the character 'a' transforms into the next 3 consecutive characters ahead of it, which results in "bcd".
The transformation wraps around the alphabet if it exceeds 'z'. For example, if s[i] = 'y' and nums[24] = 3, the character 'y' transforms into the next 3 consecutive characters ahead of it, which results in "zab".
Return the length of the resulting string after exactly t transformations.
Since the answer may be very large, return it modulo 109 + 7.
*/

class Solution {
    using Matrix = array<array<int,26>,26>;
    int MOD = 1e9+7;

    inline Matrix matrixMultiplication(Matrix& A,Matrix& B){
        Matrix res{};
        for(int i=0;i<26;++i){
            for(int j=0;j<26;++j){
                for(int k=0;k<26;++k){
                    res[i][j] = (res[i][j] + (1LL*A[i][k]*B[k][j]) % MOD) % MOD;
                }
            }
        }
        return res;
    }

    inline Matrix matrixExponentiation(Matrix& transformation_matrix,int t){
        Matrix res{};
        //Create identity matrix (to multiply)
        for(int i=0;i<26;++i)
            res[i][i] = 1;
        
        while(t){
            if(t&1)
                res = matrixMultiplication(transformation_matrix,res);
            
            //Square the base & half the exponent
            transformation_matrix = matrixMultiplication(transformation_matrix,transformation_matrix);
            t /= 2;
        }
        return res;
    }
public:
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        array<int,26> intial_freq{};
        for(char c: s)
            intial_freq[c-'a']++;

        Matrix transformation_matrix{};
        for(int i=0;i<26;++i){
            //Update column for each transformation
            for(int j=i+1; j<=i+nums[i]; ++j)
                transformation_matrix[j%26][i]++;
        }

        Matrix res = matrixExponentiation(transformation_matrix,t);
        //Now calculate res*intial_freq
        array<int,26> final_array{};
        for(int i=0;i<26;++i){
            for(int j=0;j<26;++j)
                final_array[i] = (final_array[i] + (1LL*res[i][j]*intial_freq[j])% MOD) % MOD;
        }

        int string_size = 0;
        for(int i=0;i<26;++i)
            string_size = (string_size + final_array[i]) % MOD;
        
        return string_size;
    }
};
