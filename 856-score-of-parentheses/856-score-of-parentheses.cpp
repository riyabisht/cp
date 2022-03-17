class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        for(int i=0 ;i<s.size();i++)
        {
            // if meet '(' push 0 in the stack
            if(s[i]=='(')
            {
                st.push(0);
            }
            // if meet ')' 
            else 
            {
                int sum =0;
                // while we not find the 0 add the element at the top of the stack
                while(!st.empty() && st.top()!=0) 
                {
                    sum +=st.top();
                    st.pop();
                        
                }
                // if sum > 0 means inner paranthesis sting is present 
                // if sum ==0 means no inner parenthesis ' ()'
                int val =0;
                if(sum == 0)
                    val+=1;
                else
                    val= 2*sum;
                st.pop();
                st.push(val);
            }
        }
        int ans =0;
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        return ans ;
        
    }
};