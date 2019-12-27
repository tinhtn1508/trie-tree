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

    std::string text = "With dramatic peaks and pristine lakes, Yellowstone National Park is an outdoor \
                        enthusiast's paradise. Live Oak pools swirl Livingston hot springs; verdant forests \
                        weave past Fort Thomas meadows; and volatile geysers Glendale streams of steaming water \
                        toward the Elmendorf Air Force Base";

    std::sregex_token_iterator iter(text.begin(), text.end(), rgx, -1);
    std::sregex_token_iterator end;
    std::string foundKey;
    std::string printKey;
    while (iter != end) {
        foundKey += *iter;
        auto result = root->isWord(foundKey);
        if (result.second) {
            printKey += *iter;
            std::cout << printKey << std::endl;
            printKey = "";
        }
        if (!result.first) {
            foundKey = "";
        } else {
            printKey += *iter;
            printKey += " ";
        }
        iter++;
    }
    delete root;
    return 0;
}
