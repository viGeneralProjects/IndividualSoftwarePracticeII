/*
Name: Vi Cao
Course: CS3505
Assignment: A Trie and Rule-of-Three
*/

#include <string>
using std::string;
#include <vector>
using std::vector;
#include "Trie.h"
#include <utility>

    //default constructor
    Trie::Node::Node(){
        isWord = false;
        for(int i = 0; i < 26; i++){
            children[i] = nullptr;
        }
    }

    // helper methods for recursion
    void Trie::clear(Node* n) {
        if (!n){
            return;
        }
        for (int i = 0; i < 26; ++i) {
            clear(n->children[i]);
        }
        delete n;
    }

    Trie::Node* Trie::clone(Node* n) {
        if (!n){
            return nullptr;
        }
        Node* copy = new Node();
        copy->isWord = n->isWord;
        for (int i = 0; i < 26; ++i) {
            if (n->children[i]) {
                copy->children[i] = clone(n->children[i]);
            }
        }
        return copy;
    }

    // go through this node and its children to collect words
    void Trie::collect(Node* n, string current, vector<string>& out) {
        if (!n){
            return;
        }
        if (n->isWord){
          out.push_back(current);  
        } 
        for (int i = 0; i < 26; ++i) {
            if (n->children[i] != nullptr) {
                char nextChar = static_cast<char>('a' + i);
                collect(n->children[i], current + nextChar, out);
            }
        }
    }

    //default constructor
    Trie::Trie(){
        root = new Node();
    }


    //destructor
    Trie::~Trie(){
        clear(root);
        root = nullptr;
    }
    
    // copy constructor
    Trie::Trie(const Trie& other){
        root = clone(other.root);
    }

    // copy operater; overrides the = ; doesn't copy the pointer - makes new pointers to same number, not value
    Trie& Trie::operator=(Trie other){
        std::swap(root, other.root);
        return *this;
    }

    void Trie::addWord(string word){
        if (word.empty()){
            return;
        }
        Node* currentNode = root;
        for (char letter : word){
            int idx = letter - 'a';           
            if(currentNode -> children[idx] == nullptr){
                currentNode -> children[idx] = new Node();
            }
            currentNode = currentNode -> children[idx];
        }
        currentNode -> isWord = true;
    }

    bool Trie::isWord(string word){
        if (word.empty()){
            return false;
        } 
        Node* currentNode = root;
        for (char letter : word){
            if(letter < 'a' || letter > 'z'){
                return false;  
            }
            int idx = letter - 'a';           
            if(currentNode -> children[idx] == nullptr){
                return false;
            }
            currentNode = currentNode -> children[idx];
        }
        return currentNode -> isWord;
    }

    vector<string> Trie::allWordsStartingWithPrefix(string startingLetters){
        vector<string> out;
        for (char nextChar : startingLetters) {
            if (nextChar < 'a' || nextChar > 'z'){
                return out;
            }
        }
        Node* node = root;
        for (char letter : startingLetters) {
            int letterIndex = letter - 'a';
            if (!node->children[letterIndex]){
                return out;
            }
            node = node->children[letterIndex];
        }
        //recursively collects
        collect(node, startingLetters, out);
        return out;
    } 