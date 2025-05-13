class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        queue<char> q;
        map<int, int> m;
        int i =0;
        int maxLength = 0;
        while(i!=s.length()) {
            if(q.empty())
            {
                q.push(s[i]);
                m[s[i]-'a']++;
            } else {
                if(m[s[i]-'a']!=0) {
                    if(q.front()==s[i]) {
                        q.pop();
                        q.push(s[i]);
                    }
                    else {
                        int queueSize = q.size();
                        maxLength = max(maxLength, queueSize);
                        while(q.front()!=s[i]) {
                            m[(q.front()-'a')]--;
                            q.pop();
                        }
                        q.pop();
                        q.push(s[i]);
                    }
                } else {
                    q.push(s[i]);
                    m[s[i]-'a']++;
                }
            }
            i++;
        }

        int queueSize = q.size();
        maxLength = max(maxLength, queueSize);
        return maxLength;
    }
};