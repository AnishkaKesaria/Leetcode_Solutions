class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<map<char,int>, vector<string>> ans;
        for(auto i : strs) {
            map<char, int> m;
            for(auto ch : i) {
                m[ch]++;
            }
            ans[m].push_back(i);
        }
        vector<vector<string>> result;
        for(auto i : ans) {
            result.push_back(i.second);
        }
        return result;
    }
};