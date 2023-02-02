#include<bits/stdc++.h>
using namespace std;
bool redendentBracket(string &s){
    stack<int> st;
    for(int i=0; i<s.size();i++){
        char ch=s[i];
        if(ch=='('||ch=='+'|| ch=='-' ||ch=='*' || ch=='/'){
            st.push(ch);
        }
        else{
            if(ch==')'){
                bool isredendet =true;
                while (st.top()!='('){
                    char top=st.top();
                    if(top=='+'|| top=='-' || top=='/'||top=='*'){
                        isredendet=false;
                    }
                    st.pop();
                }
                if (isredendet==true){
                    return true;
                }
                st.pop();
            }
        }
    }
    return false;
}
int main() {

return 0;
}