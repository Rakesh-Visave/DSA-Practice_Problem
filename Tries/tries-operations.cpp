#include<iostream>
using namespace std;

class TrieNode{
    public:
      char data;
      TrieNode* children[26];
      bool isTerminal;

      TrieNode(char ch)
      {
        data = ch;
        for(int i = 0; i<26 ; i++){
            children[i] = NULL;
        }
        isTerminal = false;
      }      
};

class trie{
        public: 
            TrieNode* root;

        trie(){
            root = new TrieNode('\0');
        }

            void insertUtils(TrieNode* root , string word)
            {
                // base case
                if(word.length() == 0)
                {
                    root->isTerminal = true;
                    return;
                }
                // find index of given character
                int index = word[0] - 'a';
                TrieNode* child;

                // character is present at index go to next character
                if(root->children[index] != NULL)
                    child = root->children[index];
                
                // Not present so create a new node for those character and go to next node
                else{
                    child = new TrieNode(word[0]);
                    root->children[index] = child;
                }

                // recursive call
                insertUtils(child,word.substr(1));
            
            }

            void insertWord(string word)
            {
                insertUtils(root,word);
            }

            bool searchUtil(TrieNode* root , string word)
            {
                // base case
                if(word.length() == 0)
                    return root->isTerminal;
                
                int index = word[0] -'a';
                TrieNode* child;
                
                // character is present go to next node
                if(root->children[index] != NULL)
                {
                    child = root->children[index];
                }
                // character is not present so return false
                else    
                    return false;
                
                // recursive call
                return searchUtil(child,word.substr(1));
            }

            bool searchWord(string word)
            {
                return searchUtil(root,word);
            }

            bool removeUtil(TrieNode* root , string word,int depth = 0)
            {
                 if(word.size() == depth)
                 {
                    if(root->isTerminal)
                        root->isTerminal = false;
                 }
                 int index = word[0]-'a';
                 TrieNode* child;
                if(root->children[index] != NULL)
                {
                    child = root->children[index];
                }
                removeUtil(root,word.substr(1),depth+1);

                

            }

            bool removeWord(string word)
            {
                return removeUtil(root,word);
            }

};

int main()
{
    trie *t = new trie();
    t->insertWord("arm");
    t->insertWord("time");
    t->insertWord("rakesh");
    t->insertWord("example");

    t->removeWord("example");

  cout << "Present or not: " << t->searchWord("example") << endl;


}