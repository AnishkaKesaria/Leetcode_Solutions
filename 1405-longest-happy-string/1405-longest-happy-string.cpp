class Node{
    public:
    char data;
    int count;

    Node(char d, int c)
    {
        this->data = d;
        this->count = c;
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
    string longestDiverseString(int a, int b, int c) {
        map<char,int> m;
        if(a!=0)
            m['a'] = a;
        if(b!=0)
            m['b'] = b;
        if(c!=0)
            m['c'] = c;

        priority_queue<Node*, vector<Node*>, compare> maxHeap;

        for(auto i:m)
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

            if(first->count>=1)
            {
                if(first->count>=2)
                {
                    first->count -= 2;
                    ans += first->data;
                    ans += first->data;
                }
                else
                {
                    first->count -= 1;
                    ans += first->data;
                }

                if(first->count>0)
                    maxHeap.push(first);
            }

            if(second->count>=1)
            {
                if(second->count>=2 && second->count>first->count)
                {
                    second->count -= 2;
                    ans += second->data;
                    ans += second->data;
                }
                else
                {
                    second->count -= 1;
                    ans += second->data;
                }
                if(second->count>0)
                    maxHeap.push(second);
            }
            cout<<ans;
        }

        while(maxHeap.size()==1)
        {
            Node* first = maxHeap.top();
            maxHeap.pop();
                if(first->count>=2)
                {
                    ans += first->data;
                    ans += first->data;
                }
                else
                    ans += first->data;
        }

        return ans;
    }
};