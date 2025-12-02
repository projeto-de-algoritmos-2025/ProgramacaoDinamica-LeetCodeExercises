#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
private:
    unordered_set<string> dict;
    unordered_map<int, vector<string>> memo;
    string s;

public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        this->s = s;
        for (const string& w : wordDict) {
            dict.insert(w);
        }
        
        return dp(0);
    }

    vector<string> dp(int start) {
        if (start == s.size()) {
            return {""};
        }

        if (memo.count(start)) {
            return memo[start];
        }

        vector<string> result;

        for (int end = start + 1; end <= s.size(); end++) {
            string word = s.substr(start, end - start);
            
            if (dict.count(word)) {
                vector<string> suffixSentences = dp(end);
                
                for (const string& sentence : suffixSentences) {
                    string space = sentence.empty() ? "" : " ";
                    result.push_back(word + space + sentence);
                }
            }
        }

        return memo[start] = result;
    }
};