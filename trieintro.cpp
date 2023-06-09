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
        int index=word[0]-'A';
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

    // search function
    bool searchUtil(TrieNode * root, string word){
        // base case
        if(word.length()==0){
            return root->isTerminal;
        }
        int index=word[0]-'A';
        TrieNode* child;
        //present
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            //absent
            return false;
        }
        //recusion
        return searchUtil(child,word.substr(1));
    }
    bool searchword(string word){
        return searchUtil(root,word);
    }

};
int main() {
    cout<<"hello"<<endl;
    Trie* t=new Trie('\0');
    t->insertword("ABCD");
    cout<<t->searchword("ABCD");
    
return 0;
}