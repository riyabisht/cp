class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low =0, high = nums.size()-1 ;
        
        int index;
        return binnarysearch(low,high,target,nums);
        
    }
    int binnarysearch(int low ,int high,int key,vector<int>nums)
    {
        if(low<=high)
        {
            int mid = (low + high)/2;
            if ( nums[mid] >= key ) 
               return binnarysearch(low,mid-1,key,nums);
            else
               return binnarysearch(mid+1,high,key,nums);
            
        }
        return low;
        
    }
};