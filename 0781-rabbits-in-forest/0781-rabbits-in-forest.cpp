class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int count = 0;
        map<int,int> m;
        for(int i=0; i<answers.size(); i++) {
            if(answers[i]==0) {
                count++;
            } else {
                if(m.find(answers[i])==m.end() || m[answers[i]]==0) {
                    m[answers[i]] = answers[i];
                    count += (1 + answers[i]);
                } else {
                    m[answers[i]]--;
                }
            }
        }
        return count;
    }
};