class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size());
        int n=nums.size();
        int prod = 1 , count=0;
        int st=0 , end=n-1;
       for(int num : nums){
        if(num!=0){
            prod = prod*num;
        }
        else{
            count++;
        }
        }
        if(count > 1){
            return vector<int>(nums.size() ,0);
        }
       for(int i=0;i<n;i++){
        if(count > 0){
            ans[i] = (nums[i]==0) ? prod : 0;
        }
        else{
            ans[i] = prod/nums[i];
        }
       }

return ans;

    }
};
