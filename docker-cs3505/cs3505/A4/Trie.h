/*
Name: Vi Cao
Course: CS3505
Assignment: A Trie and Rule-of-Three
*/

#ifndef TRIE_H
#define TRIE_H

#include <string>
#include <vector>

/// @brief A prefix tree that stores words and supports adding words, checking words, and listing all words with a given prefix
class Trie {
public:
    /// @brief Makes an empty trie with just the root node
    Trie();
    /// @brief Frees all memory used by the trie (called when object is destroyed)
    ~Trie();
    /// @brief Makes a deep copy of another trie
    /// @param other The trie to copy from
    Trie(const Trie& other);
    /// @brief Copies another trie into this one (deep copy)
    /// @param other The trie to copy from
    /// @return A reference to this trie after copying
    Trie& operator=(Trie other);
    /// @brief Adds a lowercase word into the trie
    /// @param word The word to add
    void addWord(std::string word);
    /// @brief Checks if a given word is stored in the trie
    /// @param word The word to check
    /// @return true if the word exists, false otherwise
    bool isWord(std::string word);
    /// @brief Finds all stored words that start with the given prefix
    /// @param startingLetters The prefix to search for
    /// @return A vector of words that start with the prefix
    std::vector<std::string> allWordsStartingWithPrefix(std::string startingLetters);

private:
    /// @brief Represents one node in the trie; each node can have up to 26 children
    class Node {
    public:
        Node* children[26];
        bool isWord;
        /// @brief Makes a node with no children and isWord set to false
        Node();
    };
    
    // the root node of the trie - the empty starting point
    Node* root;

    // helpers

    /// @brief Recursively deletes all nodes in a subtree
    /// @param n The node to delete from
    static void clear(Node* n);
    /// @brief Recursively makes a deep copy of a subtree
    /// @param n The node to copy
    /// @return A pointer to the new copied node
    static Node* clone(Node* n);
    /// @brief Collects all words under a given node and adds them to a vector
    /// @param n The node to start from
    /// @param current The word built so far
    /// @param out The vector to store the found words
    static void collect(Node* n, std::string current, std::vector<std::string>& out);
};

#endif
