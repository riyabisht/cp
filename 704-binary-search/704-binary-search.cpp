class Solution {
public:
    int binnary(int l,int h ,vector<int>nums,int target)
    {
        if(l<=h)
        {
            int mid = (l+h)/2;
            if(nums[mid]==target)
            {
                return mid;
            }
            if(target>nums[mid])
            return binnary(mid+1,h,nums,target);
            else
            return binnary(l,mid-1,nums,target);
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        return binnary(0,nums.size()-1,nums,target);
        
    }
};