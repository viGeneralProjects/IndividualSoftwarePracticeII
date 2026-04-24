/*
Name: Vi Cao
Course: CS3505
Assignment: A Trie and Rule-of-Three
*/

#include <iostream>
#include <fstream>
#include <string>
#include "Trie.h"

using std::cout;
using std::string;
using std::vector;
using std::endl;

int main(int argc, char **argv) {

    if (argc < 3) {
        cout << "Error: Both files not provided" << endl;
        return 0;
    }

    string wordsFile = argv[1];
    string testFile = argv[2];

    std::ifstream wordsIn(wordsFile);
    if (!wordsIn.is_open()) {
        cout << "Error: Could not open " << wordsFile << endl;
        return 0;
    }

    Trie trie;

    string word;
    while ( getline (wordsIn,word) )
    {
        trie.addWord(word);
    }
    wordsIn.close();

    std::ifstream testIn(testFile);
    if (!testIn.is_open()) {
        cout << "Error: Could not open " << testFile << endl;
        return 0;
    }

    string testWord;
    while (getline (testIn,testWord)) {
        cout << "Checking text: " << testWord << endl;

        if (trie.isWord(testWord)) {
            cout << "Word found" << endl;
        } else {
            cout << "Word not found" << endl;
        }

        vector<string> matches = trie.allWordsStartingWithPrefix(testWord);
        for (size_t i = 0; i < matches.size(); i++) {
            cout << matches[i] << " ";
        }
        cout << endl;
    }
    testIn.close();



    // rule of three test
    Trie trieA;
    trieA.addWord("ant");
    trieA.addWord("ante");
    trieA.addWord("antler");

    Trie trieB(trieA);
    Trie trieC;         
    trieC = trieA;

    trieA.addWord("ants"); 

    cout << "trieA has ant and ants: " << endl;
    cout << trieA.isWord("ant") << trieA.isWord("ants") << endl;
    
    cout << "trieB has ant and not ants" << endl;
    cout << trieB.isWord("ant") << trieB.isWord("ants") << endl;


    cout << "trieC has ant and not ants: " << endl;
    cout << trieC.isWord("ant") << trieC.isWord("ants") << endl;


    return 0;
}
