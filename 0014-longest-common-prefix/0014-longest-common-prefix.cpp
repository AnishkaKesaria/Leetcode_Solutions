
class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    int childCount;

    TrieNode(char d)
    {
        this->data = d;
        for(int i=0; i<26; i++)
            this->children[i] = NULL;
        this->childCount = 0;
        this->isTerminal = false;
    }
};

void insertWord(TrieNode* root, string word)
{
    if(word.length()==0)
    {
        root->isTerminal = true;
        return;
    }

    char ch = word[0];
    int index = ch - 'a';
    TrieNode* child;

    if(root->children[index] != NULL)
        child = root->children[index];
    else
    {
        child = new TrieNode(ch);
        root->children[index] = child; 
        root->childCount += 1;
    }

    insertWord(child, word.substr(1));
    return;
}

class Solution {
public:
    void findLCP(string word, string &ans, TrieNode* root)
    {
        for(int i=0; i<word.length(); i++)
        {
            char ch = word[i];
            if(root->childCount == 1 && root->isTerminal == false)
            {
                int index = ch-'a';
                root = root->children[index];
                ans += ch;
            }
            else
                break;
        }
        return;
    }

    string longestCommonPrefix(vector<string>& strs) {
        TrieNode* root = new TrieNode('-');
        for(int i=0; i<strs.size(); i++)
            insertWord(root, strs[i]);

        string ans = "";
        string first = strs[0];
        findLCP(first, ans, root);
        return ans;
    }
};