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

void strInfo(string str){
    printf("start: %p\nlen: %zu\ncap: %zu\n", str.start, str.len, str.cap);
}

stringArr strArrInit(){
    stringArr strArr;
    strArr.start = NULL;
    strArr.len = 0;
    strArr.cap = 1;
    return strArr;
}

void strArrInfo(stringArr strArr){
    printf("start: %p\nlen: %zu\ncap: %zu\n", strArr.start, strArr.len, strArr.cap);
}

void nullCheck(void* ptr){
    if (ptr == NULL) {
        printf("Out of memory");
        exit(1);
    }
}

void checkFileIsExist(FILE* file){
    if (file == NULL){
        printf("File doesn't exist\n");
        exit(1);
    }
}

void argCheck(int argc){
    if (argc == 0){
        printf("No arguments");
        exit(2);
    }
}

void addTail(string* str, byte ch){
    if (str->len + 1 < str->cap){
        str->start[str->len] = ch;
    } else {
        str->cap = str->cap * 2;
        str->start = (byte *) realloc(str->start, sizeof(byte) * str->cap);
        nullCheck(str->start);
        str->start[str->len] = ch;
    }
    str->len++;
}

void addTailArr(stringArr* strArr, string str){
    if (strArr->len + 1 < strArr->cap){
        strArr->start[strArr->len] = str;
    } else {
        strArr->cap = strArr->cap * 2;
        strArr->start = (string *) realloc(strArr->start, sizeof(string) * strArr->cap);
        nullCheck(strArr->start);
        strArr->start[strArr->len] = str;
    }
    strArr->len++;
}

void freeStrArr(stringArr strArr){
    for (size_t i = 0; i < strArr.len; i++){
        free(strArr.start[i].start);
    }
    free(strArr.start);
}


void printStr(string str){
    for (size_t i = 0; i < str.len; i++){
        printf("%c", str.start[i]);
    }
}


void printStrArr(stringArr strArr){
    for (size_t i = 0; i < strArr.len; i++){
        printStr(strArr.start[i]);
    }
}
