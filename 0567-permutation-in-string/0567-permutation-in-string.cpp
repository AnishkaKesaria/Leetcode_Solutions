class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size())
            return false;
        vector<int> s1hash(26,0);
        vector<int> s2hash(26,0);
        int s1len = s1.size();
        int s2len = s2.size();
        int left = 0, right = 0;
        while(right<s1len)
        {
            s1hash[s1[right] - 'a'] ++;
            s2hash[s2[right] - 'a'] ++;
            right++;
        }
        right--;
        while(right<s2len)
        {
            if(s1hash==s2hash)
                return true;
            right+=1;
            if(right!=s2len)
                s2hash[s2[right] - 'a']++;
            s2hash[s2[left] - 'a']--;
            left +=1;
        }
        return false;
    }
};