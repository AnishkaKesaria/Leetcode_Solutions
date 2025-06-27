class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<pair<int,int>> diffArr;
        for(int i=0; i<arr.size(); i++) {
            int diff = abs(arr[i]-x);
            diffArr.push_back({diff, i});
        }

        sort(diffArr.begin(), diffArr.end());
        vector<int> ans;
        for(int i=0; i<k; i++)
        {
            ans.push_back(arr[diffArr[i].second]);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};