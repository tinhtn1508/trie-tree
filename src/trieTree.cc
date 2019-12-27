#include "trieTree.h"

TrieTree::TrieTree() {
    this->isEndOfWord = false;
}

void TrieTree::insert(std::string key) {
    auto pNext = this;
    for (int i = 0; i < (int)key.length(); i++) {
        std::string keyTable = {key[i]};
        auto itr = pNext->children.find(keyTable);
        if (itr == pNext->children.end()) {
            pNext->children.insert(std::make_pair(keyTable, new TrieTree()));
        }
        pNext = pNext->children[keyTable];
    }
    pNext->isEndOfWord = true;
}

bool TrieTree::isKey(std::string key) {
    auto pNext = this;
    for (int i = 0; i < (int)key.length(); i++){
        std::string keyTable = {key[i]};
        auto itr = pNext->children.find(keyTable);
        if (itr == pNext->children.end()) {
            return false;
        }
        pNext = pNext->children[keyTable];
    }
    return pNext != nullptr && pNext->isEndOfWord;
}

std::pair<bool, bool> TrieTree::isWord(std::string key) {
    auto pNext = this;
    for (int i = 0; i < (int)key.length(); i++){
        std::string keyTable = {key[i]};
        auto itr = pNext->children.find(keyTable);
        if (itr == pNext->children.end()) {
            return std::make_pair(false, false);
        }
        pNext = pNext->children[keyTable];
    }
    return std::make_pair(pNext != nullptr, pNext->isEndOfWord);
}
