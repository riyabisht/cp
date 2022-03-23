class Solution {
public:
    int brokenCalc(int startValue, int target) {
        // ans keep track of no of steps 
        int ans =0;
        // we will do bottom up approch (target -> startvalue)
        //because if we do top down approch with dp (startvalue ->target)
        // it will take lot of space it and we can get a endless path for which we dont know the end
        while(target !=startValue)
        {
            if(target&1 || target < startValue)
            //if odd and target value smaller than start add 1 ultil u get startvalue ==target
            {   if(target < startValue)
                {
                    ans += startValue - target;
                    target = target + (startValue - target);
                }
                else
                {target+=1;
                ans++;}
            }
            else
            {target/=2;
                ans++;
            }
        }
        return ans;
    }
};