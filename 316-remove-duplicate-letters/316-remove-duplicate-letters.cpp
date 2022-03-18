class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char>st;
        vector<bool> hash(27,false);
        
        
        vector<int>count(27);
        
        for(int i=0 ;i<s.size();i++)
        {
            count[s[i]-'a']++;
            //cout<<count[s[i]-'a'];
            //cout<<hash[i];
        }
        
        for(int i=0 ;i<s.size();i++)
        {
            int index =  s[i]-'a';
            if(st.empty() && (hash[index]==false) )
            {
                st.push(s[i]);
                count[index]--;
                hash[index]=true;
                //cout<<count[index];
                //cout<<hash[index];
            }
            else if (hash[index]==false){
                if(s[i] < st.top())
                {
                     while(!st.empty()&&count[st.top() - 'a'] > 0 && s[i]< st.top()){
                        hash[st.top()-'a'] = false;
                        st.pop();
                        
                    }
                     
                }
                 st.push(s[i]);
                    hash[index] = true;
                    count[index]--;
            }
            else if(hash[index]==true){
                count[index]--;
            }
        }
        string ans ="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
            
        }
        cout<<ans;
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};