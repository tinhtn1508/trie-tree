#include <fstream>
#include <regex>
#include "trieTree.h"
#include "parser.h"

#define KEY_PATH "../data/place_to_travel.txt"
#define TEXT_PATH "../data/text_sample.txt"

int main() {
    // Build internal data
    auto file = std::ifstream(KEY_PATH);
    auto root = new TrieTree();
    std::string rawKey;
    std::regex rgx ("\\s+");
    while(file.good()) {
        std::getline(file, rawKey);
        std::sregex_token_iterator iter(rawKey.begin(), rawKey.end(), rgx, -1);
        std::sregex_token_iterator end;
        std::string key = {};
        while (iter != end) {
            key += *iter;
            iter++;
        }
        root->insert(key);
    }
    std::string rawText;
    std::string text;
    auto fileText = std::ifstream(TEXT_PATH);
    while(fileText.good()) {
        std::getline(fileText, rawText);
        text += rawText;
    }
    std::sregex_token_iterator iter(text.begin(), text.end(), rgx, -1);
    std::sregex_token_iterator end;
    std::string foundKey = "";
    std::string printKey;
    std::string cacheKey;
    std::sregex_token_iterator back;
    bool flag = true;
    std::cout << "\nText: \n" << text << std::endl;
    std::cout << "\nKeys found: \n";
    while (iter != end) {
        foundKey += *iter;
        printKey += *iter;
        printKey += " ";
        auto result = root->isWord(foundKey);
        if (result.second) {
            std::cout << printKey << std::endl;
            foundKey = "";
            printKey = "";
            flag = true;
        }
        if (!result.first) {
            foundKey = "";
            printKey = "";
            if (!result.second) {
                iter = back++;
            }
            flag = true;
        } else {
            iter++;
            if (flag) {
                back = iter;
                flag = false;
            }
        }
    }
    delete root;
    return 0;
}
