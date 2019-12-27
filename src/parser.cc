#include "parser.h"

Parser::Parser(std::string path) {
    this->path = path;
    this->file = std::ifstream(path);
}

Parser::~Parser() {
    file.close();
}
