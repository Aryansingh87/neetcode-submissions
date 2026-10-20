class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n);
        vector<int> right(n);
        stack<int> s;
        for(int i = n-1;i>=0;i--){
            while(s.size()>0 && heights[s.top()]>=heights[i]){
                s.pop();
            } 
            right[i] = s.empty() ? n : s.top();
        
        s.push(i);
        }
        while(!s.empty()){
            s.pop();
        }
        for(int i=0;i<n;i++){
            while(!s.empty() && heights[s.top()]>= heights[i]){
                s.pop();
            }
            left[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
        long long ans=0;
        for(int i=0;i<n;i++){
            long long width = right[i]-left[i]-1;
            long long currarea = (long long) heights[i] * width;
            ans = max(ans , currarea);
        }
        return ans;

    }
};
