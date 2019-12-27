#pragma once

#include <iostream>
#include <unordered_map> 

class TrieTree
{
public:
    TrieTree();
    ~TrieTree() = default;
    void insert(std::string key);
    bool isKey(std::string key);
    std::pair<bool, bool> isWord(std::string word);
private:
    std::unordered_map<std::string, TrieTree*> children;
    bool isEndOfWord;
};
