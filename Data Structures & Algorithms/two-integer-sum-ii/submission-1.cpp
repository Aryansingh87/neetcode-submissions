class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int , int> m;
        for(int i=0;i<numbers.size();i++){
            int second = target - numbers[i];
            if(m.count(second)){
                return {m[second] , i+1};
            }
            m[numbers[i]] = i+1;
        }
        return {};
    }
};
