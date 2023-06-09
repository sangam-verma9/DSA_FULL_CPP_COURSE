/* 1st solution 
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int size=strs.size(), n=strs[0].length();
        for(int i=1;i<size; i++){
            int m=0;
            while (m<n && strs[0][m]==strs[i][m]){
                m++;
            }
            n=min(n,m);
        }
        return strs[0].substr(0,n);
    }
};
int main() {

return 0;
}
*/
// second solution using trie
#include<bits/stdc++.h>
using namespace std;
class TrieNode{
    public:
    char data;
    bool isTerminal;
    TrieNode* children[26];
    int childcount;
    TrieNode(char ch){
        data=ch;
        for(int i=0;i<26; i++){
            children[i]=NULL;
        }
        isTerminal=false;
        childcount=0;
    }
};
class Trie{
    public:
    TrieNode* root;
    Trie(char ch){
        root=new TrieNode(ch);
    }
    void insertUtil(TrieNode* root,string word){
        if(word.length()==0){
            root->isTerminal=true;
            return;
        }
        int index=word[0]-'a';
        TrieNode* child;
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            child=new TrieNode(word[0]);
            root->children[index]=child;
            root->childcount++;
        }
        insertUtil(child,word.substr(1));
    }
    void insertword(string word){
        insertUtil(root,word);
    }

    void lcp(string str,string& ans){
        for(int i=0;i<str.length();i++){
            char ch=str[i];
            if(root->childcount==1){
                ans.push_back(ch);
                int index=ch-'a';
                root=root->children[index];
            }
            else break;

            if(root->isTerminal) {
                break;
            }
        }
    }
   
};
string longestcommonprefix(vector<string>& arr, int n){
    Trie* t=new Trie('\0');
    for(int i=0;i<n;i++){
        t->insertword(arr[i]);
    }
    string first=arr[0];
    string ans="";
    t->lcp(first,ans);
    return ans;

}
int main() {
    vector<string>arr={"codeingninja","codewithharry","codestdio","coder","codehelp"};
    int n=arr.size();
    string s=longestcommonprefix(arr,n);
    cout<<s<<endl;

return 0;
}
