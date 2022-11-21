//
// Created by Admin on 21.11.2022.
//

#include "lib.h"

string strInit(){
    string str;
    str.start = NULL;
    str.len = 0;
    str.cap = 1;
    return str;
}

void printStr(string str){
    printf("start: %p\nlen: %zu\ncap: %zu\n", str.start, str.len, str.cap);
}

stringArr strArrInit(){
    stringArr strArr;
    strArr.start = NULL;
    strArr.len = 0;
    strArr.cap = 1;
    return strArr;
}

void printStrArr(stringArr strArr){
    printf("start: %p\nlen: %zu\ncap: %zu\n", strArr.start, strArr.len, strArr.cap);
}