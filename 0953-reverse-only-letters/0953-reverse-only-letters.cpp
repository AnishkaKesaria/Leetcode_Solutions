class Solution {
public:
    string reverseOnlyLetters(string s) {
        int start = 0, end = s.length()-1;
        while(start<end) {
            if(isalpha(s[start]) && isalpha(s[end])) {
                char a = s[start];
                char b = s[end];
                s[start++] = b;
                s[end--] = a;
            } else {
                if(!isalpha(s[start])) 
                    start++;
                if(!isalpha(s[end]))
                    end--;
            }
        }

        return s;
    }
};