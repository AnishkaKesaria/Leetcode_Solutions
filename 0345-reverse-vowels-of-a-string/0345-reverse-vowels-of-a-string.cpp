class Solution {
private:
    bool isVowel(char c) {
        c = tolower(c);
        if(c == 97 || c == 101 || c == 105 || c == 111 || c == 117) 
            return true;
        return false;
    }

public:
    string reverseVowels(string s) {
        int start = 0, end = s.length() -1;
        while(start<end) {
            if(isVowel(s[start]) && isVowel(s[end])) {
                cout<<s[start]<<" "<<s[end]<<endl;
                swap(s[start], s[end]);
                start++;
                end--;
            } else if (!isVowel(s[start])) 
                start++;
            else
                end--;
        }

        return s;
    }
};