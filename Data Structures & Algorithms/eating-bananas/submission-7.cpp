class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();

        int st =1 , end = *max_element(piles.begin() , piles.end());
                while(st < end){
            int mid = (st + end) /2;
            int hours = 0;
            for(int pile : piles){
                hours += (pile+mid-1)/mid;
            }
            if(hours<=h){
                end = mid;
            }else{
                st = mid +1;
            }
        }
        return st;
    }
};
