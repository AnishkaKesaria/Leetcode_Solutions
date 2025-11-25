class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        queue<int> q;
        unordered_map<char,int> m;
        int maxLen = 0;
        for(auto i: s) {
            if(m.find(i)!=m.end() && m[i]!=0) {
                int currLen = q.size();
                maxLen = max(maxLen, currLen);
                while(q.front()!=i) {
                    char ch = q.front();
                    m[ch]--;
                    q.pop();
                }
                q.pop();
                q.push(i);
            } else {
                m[i]++;
                q.push(i);
            }
        }
        int currLen = q.size();
        maxLen = max(maxLen, currLen);
        return maxLen;
    }
};