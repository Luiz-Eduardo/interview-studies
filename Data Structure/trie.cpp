#include <iostream>
#include <vector>
#include <string> 

using namespace std;

const int ALPHABET_SIZE = 26;

struct TrieNode{
    struct TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWorld;
};

struct TrieNode *getNode(void){
    struct TrieNode *Node = new TrieNode;

    Node->isEndOfWorld = false;

    for(int i = 0; i < ALPHABET_SIZE; i++){
        Node->children[i] = NULL;
    }

    return Node;
}

bool isEmpty(TrieNode *root){
    for(int i = 0; i < ALPHABET_SIZE; i++){
        if(root->children[i]){
            return false;
        }
    }

    return true;
}

void insert(struct TrieNode *root, string key){
    struct TrieNode *temp = root;

    for(int i = 0; i < key.size(); i++){
        int index = key[i] - 'a';
        
        if(!temp->children[index]){
            temp->children[index] = getNode();
        }

        temp = temp->children[index];
    }

    temp->isEndOfWorld = true;
}

void insertRecursive(struct TrieNode *temp, string key, int i = 0){
    if(i == key.size()){
        temp->isEndOfWorld = true;
        return;
    }

    int index = key[i] - 'a';

    if(!temp->children[index]){
        temp->children[index] = getNode();
    }

    temp = temp->children[index];

    insertRecursive(temp, key, i+1);
}


bool search(struct TrieNode *root, string key){
    struct TrieNode *temp = root;

    for(int i = 0; i < key.size(); i++){
        int index = key[i] - 'a';

        if(!temp->children[index]){
            return false;
        }
        
        temp = temp->children[index];
    }

    return (temp != NULL && temp->isEndOfWorld);
}

//TO FIX
bool searchRecursive(struct TrieNode *temp, string key, int i = 0){
    if(i == key.size()){
        return (temp != NULL && temp->isEndOfWorld);
    }

    int index = key[i] - 'a';
    
    if(temp->children[index] == 0){
        return false;
    }
        
    temp = temp->children[index];

    searchRecursive(temp, key, i+1);
}

TrieNode* remove(struct TrieNode *root, string key, int i = 0){
    if(!root){
        return NULL;
    }

    if(i == key.size()){
        if(root->isEndOfWorld){
            root->isEndOfWorld = false;
        }

        if(isEmpty(root)){
            delete (root);
            root = NULL;
        }

        return root;
    }

    int index = key[i] - 'a';
    struct TrieNode *temp = root->children[index];
    root->children[index] = remove(temp, key, i+1);

    if(isEmpty(root) && !root->isEndOfWorld){
        delete root;
        root = NULL;
    }

    return root;
}

int main(){
    vector<string> keys;
     
    keys.push_back("the");
    keys.push_back("a");
    keys.push_back("there");
    keys.push_back("answer");
    keys.push_back("any");
    keys.push_back("by");
    keys.push_back("bye"); 
    keys.push_back("their");
    keys.push_back("heroplane");
    keys.push_back("hero");
     
    int n = keys.size(); 
  
    struct TrieNode *root = getNode(); 
  
    // Construct trie 
    for (int i = 0; i < n; i++) 
        insert(root, keys[i]); 
  
    // Search for different keys 
    search(root, "the") ? cout << "Yes\n" : cout << "No\n"; 
    search(root, "these") ? cout << "Yes\n" : cout << "No\n"; 

    search(root, "heroplane") ? cout << "Yes\n" : cout << "No\n"; 
    remove(root, "heroplane"); 
    search(root, "heroplane") ? cout << "Yes\n" : cout << "No\n"; 
    return 0;
}