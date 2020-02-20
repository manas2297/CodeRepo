/**
 * Question :- https://practice.geeksforgeeks.org/problems/trie-insert-and-search/0
*/

#include<bits/stdc++.h>
using namespace std;
struct node{
    bool isEnd;
    struct node *children[26];
};
node *getNode(){
    node *pNode = new node;
    pNode->isEnd = false;
    for(int i=0;i<26;i++){
        pNode->children[i] = NULL;
    }
    return pNode;
}
void insert(node *head, string str){
    int i,j;
    node *p = head;
    for(i=0;i<str.length();i++){
        int index = str[i]-'a';
        if(!p->children[index]) {
            p->children[index] = getNode();
        }
        p = p->children[index];
    }
    p->isEnd = true;
}
bool search(node *root, string key) {
    node *p = root;
    for(int i=0;i<key.length();i++){
        int index = key[i] - 'a';
        if(!p->children[index])
            return false;
        p = p->children[index];
    }
    return (p !=NULL && p->isEnd==true);
}
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<string> s(n);
	    node *root = getNode();
	    for(int i=0;i<n;i++){
	        cin>>s[i];
	    }
	    for(int i=0;i<n;i++){
	        insert(root,s[i]);
	    }
	    string a;
	    cin>>a;
	    cout<<search(root,a)<<endl;
	}
	return 0;
}