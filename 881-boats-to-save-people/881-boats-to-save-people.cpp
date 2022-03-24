class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int boat=0;
        // sort
        sort(people.begin(),people.end());
        // take two pointer
        int l=0;
        int r = people.size()-1;
        while(l<=r){
            while(people[r]==limit)
            {
                boat++;
                r--;
            }
            if(people[r]+people[l] <= limit)
            {
                boat++;
                l++;
                r--;
            }
            else
            {
                boat++;
                r--;
            }
            
        }
        return boat;
        
    }
};