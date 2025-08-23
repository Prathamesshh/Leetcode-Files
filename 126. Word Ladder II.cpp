/*
A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:
Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return all the shortest transformation sequences from beginWord to endWord, or an empty list if no such sequence exists. Each sequence should be returned as a list of the words [beginWord, s1, s2, ..., sk].
*/


/*
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        if (!st.count(endWord)) return {};

        queue<vector<string>> q;
        q.push({beginWord});
        unordered_set<string> usedOnLvl;
        int lvl = 1;
        vector<vector<string>> ans;

        while (!q.empty()) {
            vector<string> vec = q.front();
            q.pop();

            if (vec.size() > lvl) {
                lvl++;
                for (auto &w : usedOnLvl) st.erase(w);
                usedOnLvl.clear();
            }

            string word = vec.back();
            if (word == endWord) {
                if (ans.empty() || ans[0].size() == vec.size()) {
                    ans.push_back(vec);
                }
            }

            for (int i = 0; i < word.size(); i++) {
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    if (ch == original) continue;
                    word[i] = ch;
                    if (st.count(word)) {
                        vec.push_back(word);
                        q.push(vec);
                        usedOnLvl.insert(word);
                        vec.pop_back();
                    }
                }
                word[i] = original;
            }
        }
        return ans;
    }
};

*/
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        if(find(wordList.begin(), wordList.end(), endWord) == wordList.end()) return {};

        unordered_set<string> words(wordList.begin(), wordList.end());
        queue<string> qu;
        unordered_map<string, vector<string>> parent;

        qu.push(beginWord);
        parent[beginWord] = {};
        words.erase(beginWord);
        bool found = false;
        int level = 1;
        unordered_map<string, int> levels;
        levels[beginWord] = 1;

        while(!qu.empty() && !found) {
            int size = qu.size();
            unordered_set<string> toRemove;
            for(int i = 0; i < size; i++) {
                string word = qu.front();
                qu.pop();
                string original = word;

                for(int j = 0; j < word.size(); j++) {
                    char c = word[j];
                    for(char k = 'a'; k <= 'z'; k++) {
                        word[j] = k;
                        if(word == endWord) {
                            parent[word].push_back(original);
                            found = true;
                        } else if(words.find(word) != words.end()) {
                            parent[word].push_back(original);
                            if(levels.find(word) == levels.end()) {
                                levels[word] = level + 1;
                                qu.push(word);
                            }
                            toRemove.insert(word);
                        }
                    }
                    word[j] = c;
                }
            }
            for(auto &word : toRemove) words.erase(word);
            level++;
        }

        vector<vector<string>> ans;
        if(found) {
            vector<string> path = {endWord};
            backtrack(endWord, beginWord, parent, path, ans);
        }

        return ans;
    }

    void backtrack(const string& word, const string& beginWord, unordered_map<string, vector<string>>& parent, vector<string>& path, vector<vector<string>>& ans) {
        if(word == beginWord) {
            reverse(path.begin(), path.end());
            ans.push_back(path);
            reverse(path.begin(), path.end());
            return;
        }

        for(auto &p : parent[word]) {
            path.push_back(p);
            backtrack(p, beginWord, parent, path, ans);
            path.pop_back();
        }
    }
};

