class Solution {
public:
    bool checkValidString(string s) {
        stack<int> para;
        stack<int> sym;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]=='(')
                para.push(i);
            else if(s[i]==')')
            {
                if(sym.empty() && para.empty())
                    return false;
                else if(!para.empty())
                    para.pop();
                else
                    sym.pop();
            }
            else
                sym.push(i);
        }
        while(!sym.empty() && !para.empty() && para.top()<sym.top())
        {
            sym.pop();
            para.pop();
        }

        // if(!para.empty())
        // {
        //     if(para.size()<=sym.size())
        //         return true;
        //     else
        //         return false;
        // }
        // if(!para.empty())
        //     return false;
        return para.empty();
    }
};