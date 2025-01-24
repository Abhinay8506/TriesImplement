// Online C++ compiler to run C++ program online
#include<bits/stdc++.h>
using namespace std;
class trienode{
    public:
    trienode* children[26];
    bool isendofword;
    trienode(){
        for(int i=0;i<26;i++){
            children[i] = NULL;
        }
        isendofword = false;
    }
    
};
class Trie{
    public:
    trienode* root;
    Trie(){
        root = new trienode();
    }
    void insert(const string &word){
        trienode* node = root;
        for(auto w:word){
            int index = w-'a';
            if(node->children[index]==NULL){
                node->children[index] = new trienode();
            }
            node = node->children[index];
        }
        node->isendofword = true;
    }
    
    bool allprefixpresence(const string &word){
        trienode* node = root;
        for(char c:word){
            int index = c-'a';
            if(node->children[index]==NULL){
                 return false;
            }
            node = node->children[index];
            if(node->isendofword == false)return false;
            
        }
        return true;
    }
    string longestprefixinternal(){
        trienode* current = root;
        string prefix="";
        while(current){
            int childcount =0;
            int nextindex = -1;
            for(int i=0;i<26;i++){
                if(current->children[i]){
                    childcount++;
                    nextindex = i;
                }
            }
            if(childcount == 1 && !current->isendofword){
                cout<<prefix<<" ";
                prefix+=(char)(nextindex+'a');
                current=current->children[nextindex];
                cout<<prefix<<endl;
            }else break;
        }
        return prefix;
    }
    
    
    
};

string longestcompletestring(int n,vector<string>&arr){
    Trie T;
    for(const string s:arr){
        T.insert(s);
    }
    string ans = "";
    
    int maxi = -1;
    for(const string word:arr){
        if(T.allprefixpresence(word)){
            if (ans == "" || word.length() > ans.length() || 
                (word.length() == ans.length() && word < ans)) {
                ans = word;
            }
        }
        
    }
    return ans==""?"None":ans;
}
string longestprefix(vector<string>v,int n){
    Trie t1;
    for(auto w:v){
        t1.insert(w);
    }
    return t1.longestprefixinternal();
    
}
int main(){
    int n;
    cin>>n;
    vector<string>v(n);
    string st;
    for(int i=0;i<n;i++){
        
        cin>>st;
        v[i]=st;
    }
    for(int i=0;i<n;i++){
        cout<<v[i];
    }
    cout<<endl;
    cout<<longestprefix(v,n);
    //cout<<longestcompletestring(n,v)<<endl;
    return 0 ;
}
