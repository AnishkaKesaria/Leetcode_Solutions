class Node{
    public:
    char data;
    int count;

    Node(char data, int count)
    {
        this->data = data;
        this->count = count;
    }
};

class compare{
    public:

    bool operator()(Node* a, Node* b)
    {
        return a->count<b->count;
    }
};

class Solution {
public:
    string reorganizeString(string s) {
        map<char,int> m;
        for(int i=0; i<s.length(); i++)
            m[s[i]]++;
        
        priority_queue<Node*, vector<Node*>, compare> maxHeap;

        for(auto i: m)
        {
            Node* newNode = new Node(i.first,i.second);
            maxHeap.push(newNode);
        }

        string ans;

        while(maxHeap.size()>1)
        {
            Node* first = maxHeap.top();
            maxHeap.pop();
            Node* second = maxHeap.top();
            maxHeap.pop();

            ans += first->data;
            ans += second->data;

            if(first->count>1)
            {
                first->count -= 1;
                maxHeap.push(first);
            }
            if(second->count>1)
            {
                second->count -= 1;
                maxHeap.push(second);
            }
        }

        if(maxHeap.size()==1)
        {
            Node* first = maxHeap.top();
            maxHeap.pop();
            if(first->count>1)
                return "";
            else
                ans += first->data;
        }

        return ans;
    }
};