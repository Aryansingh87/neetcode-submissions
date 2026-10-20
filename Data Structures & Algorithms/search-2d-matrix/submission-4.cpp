class Solution {
public:
bool searchrow(vector<vector<int>>& matrix, int target , int row){
    int n= matrix[0].size();
    int st = 0 , end = n-1;
    while(st <= end){
        int mid = st + (end - st)/2;
        if(target == matrix[row][mid]){
            return true;
        }else if(target > matrix[row][mid]){
            st = mid + 1;
        }
        else{
            end = mid-1;
        }
    }
    return false;
}
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       int m= matrix.size() , n=matrix[0].size();
        int srow = 0 , erow= m-1;
        while(srow <= erow){
            int mrow = srow + (erow-srow)/2;
            if(target >= matrix[mrow][0] && target<= matrix[mrow][n-1]){
                return searchrow(matrix , target , mrow);
            }
            else if(target > matrix[mrow][n-1]){
                srow = mrow+1;
            }else{
                erow = mrow-1;
            }
        }
         return false;
    }
   
};
