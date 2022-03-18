class Solution {
public:
    string removeDuplicateLetters(string s) {
        //stack for storing character
        stack<char>st;
        //visited - for checking element visited or not
        vector<bool> visited(27,false);
        // count for storing frequency of all elements
        vector<int>count(27);
        
        //calcuate & store frequency of all the elements
        for(int i=0 ;i<s.size();i++)
            count[s[i]-'a']++;
        
        //traverse the string
        for(int i=0 ;i<s.size();i++)
        {
            
            int index =  s[i]-'a';
            // if stack is empty and s[i] element is not visited
            // push s[i] element in the stack and decrease its frequency and mark it as visited
            if(st.empty() && (visited[index]==false) )
            {
                st.push(s[i]);
                count[index]--;
                visited[index]=true;
            }
            else if (visited[index]==false){
                //if s[i] elememt is not visited and smaller than element present at the top of stack
                //pop the element from stack and change not visited in place of visited until 
                // 1- stack is empty
                // 2- frequency of top element in the stack is >0
                // 3- find a element smaller than s[i] 
                if(s[i] < st.top())
                {
                    
                     while(!st.empty()&&count[st.top() - 'a'] > 0 && s[i]< st.top()){
                        visited[st.top()-'a'] = false;
                        st.pop();
                        
                    }
                     
                }
                //push s[i] in the stack and decreases its frequency and mark as visited
                 st.push(s[i]);
                    visited[index] = true;
                    count[index]--;
            }
            // if s[i] is already visited decrease its frequency 
            else {
                count[index]--;
            }
        }
        string ans ="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};