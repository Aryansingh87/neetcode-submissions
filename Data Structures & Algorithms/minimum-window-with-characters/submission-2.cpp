class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char , int> mp;
        int stidx = -1 , minlength = INT_MAX;
        int right = 0 , left= 0;
        int count =0;
        int  n = s.length(), m = t.length();
        for(int i=0;i<m;i++){
            mp[t[i]]++;
        }
        while(right < n){
            if(mp[s[right]]>0){
                count++;
            }
            mp[s[right]]--;
            while(count == m){
                if(right-left+1 < minlength){
                    minlength = right-left+1;
                    stidx = left;
                }
                mp[s[left]]++;
                if(mp[s[left]]>0){
                    count--;
                }
                left++;
            }
            right++;
        }
        return stidx == -1 ? "" : s.substr(stidx , minlength);
    }
};
