// yet to solve


class TrieNode{
    public:
    char data;
    bool isTerminal;
    TrieNode* children[26];
    TrieNode(char ch){
        data=ch;
        for(int i=0;i<26; i++){
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
        }
        insertUtil(child,word.substr(1));
    }
    void insertword(string word){
        insertUtil(root,word);
    }
    int count=0;
    int ans=0;
    bool solve(string s){
        if(count==s.length())return true;
        if(count>0 && ans>1) return false;
        TrieNode* temp=root;
        for(int i=count;i<s.length(); ){
            char ch=s[i];
            int index=ch-'a';
            if(temp->children[index]!=NULL){
                temp=temp->children[index];
                count++;
            }
            else{
                ans++;
                solve(s);
            }
        }
        return true;
    }

};
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        Trie* t=new Trie('\0');
        for(int i=0;i<wordDict.size();i++){
            t->insertword(wordDict[i]);
        }
        return t->solve(s); 
    }
};