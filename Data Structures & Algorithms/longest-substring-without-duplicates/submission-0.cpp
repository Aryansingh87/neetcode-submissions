class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char , int> m;
        int j =0 , ans =0;
        for(int i=0;i<s.size();i++){
            if(m.find(s[i])!=m.end()){
                j = max(m[s[i]]+1 , j);
            }
            m[s[i]] = i;

        
        ans = max(ans , i-j+1);
        }
        return ans;
    }
};
