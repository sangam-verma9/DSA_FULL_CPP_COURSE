#include<bits/stdc++.h>
using namespace std;
class TrieNode{
    public:
    char data;
    bool isTerminal;
    TrieNode* children[26];
    TrieNode(char ch){
        data=ch;
        for(int i=0; i<26; i++){
            children[i]=NULL;
        }
        isTerminal=false;
    }
};
class Trie{
    public:
    TrieNode* root;
    Trie(char ch){
        root=new TrieNode(ch);
    }

    void insertUtil(TrieNode* root, string word){
        // base case
        if(word.length()==0){
            root->isTerminal=true;
            return;
        }
        //assmption word in capiral case
        int index=word[0]-'a';
        TrieNode *child;

        //present 
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            //absent
            child=new TrieNode(word[0]);
            root->children[index]=child;
        }

        //recursion
        insertUtil(child,word.substr(1));

    }

    void insertword(string word){
        insertUtil(root,word);
    }
    void printsuggestion(TrieNode* curr,vector<string>&temp,string prefix){
        if(curr->isTerminal){
            temp.push_back(prefix);
        }
        for(char i='a';i<='z';i++){
            TrieNode* next=curr->children[i-'a'];
            if(next!=NULL){
                prefix.push_back(i);
                printsuggestion(next,temp,prefix);
                prefix.pop_back();
            }
        }

    }
    vector<vector<string>>getsuggestion(string str){
        TrieNode* prev=root;
        vector<vector<string>>ans;
        string prefix="";
        for(int i=0;i<str.length();i++){
            char lastch=str[i];
            prefix.push_back(lastch);

            //check trienode
            TrieNode* curr=prev->children[lastch-'a'];
            // if not found 
            if(curr==NULL){
                break;
            }
            // if found
            vector<string>temp;
            printsuggestion(curr,temp,prefix);
            ans.push_back(temp);
            temp.clear();
            prev=curr;
        }
        return ans;
    }

};
vector<vector<string>>phonedirectory(vector<string>&contactlist,string querystr){
    Trie* t=new Trie('\0');
    for(int i=0; i<contactlist.size();i++){
        string str=contactlist[i];
        t->insertword(str);
    }
    return t->getsuggestion(querystr);
}
int main() {

return 0;
}