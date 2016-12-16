//
// Created by ahmad on 12/16/16.
//

#ifndef TST_TST_H
#define TST_TST_H

#include <string>

#define nullptr 0

struct TSTNode
{
    char chr;
    TSTNode *smallerChild;
    TSTNode *selfChild;
    TSTNode *biggerChild;
    bool isWord;

    TSTNode(char chr);
};

class TST
{
private:
    TSTNode *root;
    bool isCaseSensitive;

public:
    TST(bool caseSensivity = false);

    void add(std::string word);
    bool isExisted(std::string word);
};


#endif //TST_TST_H
