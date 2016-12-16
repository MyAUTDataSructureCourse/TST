//
// Created by ahmad on 12/16/16.
//

#include "TST.h"
#include <algorithm>
#include <iostream>

TSTNode::TSTNode(char chr)
{
    this->chr = chr;
    this->biggerChild = nullptr;
    this->selfChild = nullptr;
    this->smallerChild = nullptr;
    this->isWord = false;
}

TST::TST(bool caseSensivity)
{
    isCaseSensitive = caseSensivity;
    this->root = nullptr;
}

void TST::add(std::string word)
{
    using namespace std;

    if (!isCaseSensitive)
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);

    TSTNode *pointer;
    if(!this->root)
    {

        this->root = new TSTNode(word[0]);
        pointer = this->root;
        for (int i = 1; i < word.size(); ++i) {
            pointer->selfChild = new TSTNode(word[i]);
            pointer = pointer->selfChild;
        }
    }
    else
    {
        int i = 0;

        pointer = this->root;
        char chrWord;

        for (; i < word.size() - 1;) {
            chrWord = word[i];
            if (chrWord < pointer->chr) {
                if (!pointer->smallerChild)
                    pointer->smallerChild = new TSTNode(chrWord);
                pointer = pointer->smallerChild;
            } else if (chrWord > pointer->chr) {
                if (!pointer->biggerChild)
                    pointer->biggerChild = new TSTNode(chrWord);
                pointer = pointer->biggerChild;
            } else {
                if (!pointer->selfChild)
                    pointer->selfChild = new TSTNode(word[i + 1]);
                pointer = pointer->selfChild;
                i++;
            }
        }


    }
    pointer->isWord = true;
}

bool TST::isExisted(std::string word)
{

    if (!isCaseSensitive)
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);

    int i = 0;
    if(!this->root)
        return false;

    TSTNode *pointer = this->root;
    char chrWord;

    for (; i < word.size() - 1;) {

        chrWord = word[i];
        if(chrWord < pointer->chr)
        {
            if (!pointer->smallerChild)
                return false;
            else
                pointer = pointer->smallerChild;
        }
        else if(chrWord > pointer->chr)
        {
            if (!pointer->biggerChild)
                return false;
            pointer = pointer->biggerChild;
        }
        else
        {
            if(! pointer->selfChild)
                return false;
//            if(pointer->selfChild->chr != chrWord)
//                return false;

            pointer = pointer->selfChild;
            i++;
        }
    }

    return pointer->isWord;
}

