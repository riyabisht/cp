class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i=0,j=0;
        stack<int> s;
        while(i<pushed.size())
        {
            s.push(pushed[i]);
            while(!s.empty() && s.top()==popped[j])
            {
                s.pop();
                j++;
            }
            
          i++;
        }
        
        return s.empty()? true:false;
    }
};