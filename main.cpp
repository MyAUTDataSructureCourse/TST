#include <iostream>
#include "TST.h"

using namespace std;

int main() {
    TST tst;

//    string t("this");
//
//    for (int i = 0; i < t.size(); ++i) {
//        cout << t[i] << endl;
//    }


    tst.add(string("macbook"));
    tst.add(string("this"));
    tst.add(string("book"));
    tst.add(string("aree"));
    tst.add(string("ehsan"));
    tst.add(string("dif"));
    tst.add(string("those"));
    tst.add(string("we"));
    tst.add(string("nose"));
    tst.add(string("load"));
    tst.add(string("price"));
    tst.add(string("transform"));
    tst.add(string("blaaaaaaaaaaaaaaaaaaaaaaaaaaa"));


    cout << tst.isExisted(string("apple")) << endl;
    cout << tst.isExisted(string("book")) << endl;
    cout << tst.isExisted(string("are")) << endl;
    cout << tst.isExisted(string("ehsan")) << endl;
    cout << tst.isExisted(string("this")) << endl;
    cout << tst.isExisted(string("erfan")) << endl;
    cout << tst.isExisted(string("blaaaaaaaaaaaaaaaaaaaaaaaaaaa")) << endl;
    return 0;
}