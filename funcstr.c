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
        strArr->cap *= 2;
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
    for (size_t i = 0; i < strArr.len; i++) {
        printStr(strArr.start[i]);
        if (i != strArr.len - 1) {
            printf("\n");
        }
    }
}

string temperature(string str) {
    int deg = 0;
    double temp = 0;
    string newStr = strInit();
    int sign = (str.start[0] == '+') ? 1 : -1;
    for (size_t i = str.len - 2; i > 0; i--) {
        temp += pow(10, deg) * (str.start[i] - '0');
        deg++;
    }
    temp = sign * temp;
    temp = (temp - 32) * 5 / 9;
    size_t length = snprintf(NULL, 0, "%.1f", temp);
    newStr.len = length + 1;
    newStr.cap = 2 * (size_t)ceil(log2((double)length));
    newStr.start = (byte*) realloc(newStr.start, sizeof(byte) * newStr.len);
    snprintf(newStr.start, newStr.len, "%.1f", temp);
    newStr.len -= 1;
    addTail(&newStr, 't');
    addTail(&newStr, 'C');
    return newStr;
}


int isPalindrome(string str) {
    int flag = 1;
    for (size_t i = 0; i < (str.len / 2) + 1; i++){
        if (str.start[i] != str.start[str.len - i - 1]){
            flag = 0;
            break;
        }
    }
    return flag;
}


string stripBySpace(string str) {
    string newStr = strInit();
    if (str.start[0] != ' ') {
        addTail(&newStr, str.start[0]);
    }
    for (size_t i = 1; i < str.len; i++) {
        if (!((str.start[i] == ' ') && (str.start[i-1] == ' '))) {
            addTail(&newStr, str.start[i]);
        }
    }
    return newStr;
}


int isSymbolOfWord(byte ch) {
    return (((ch >= 'A') && (ch <= 'Z')) || ((ch >= 'a') && (ch <= 'z')) || ((ch >= '0') && (ch <= '9')));
}

stringArr split(string str) {
    stringArr newStrArr = strArrInit();
    string word = strInit();
    for (size_t i = 0; i < str.len; i++) {
        if (str.start[i] == ' ') {
            addTail(&word, '\0');
            addTailArr(&newStrArr, word);
            word = strInit();
        } else {
            addTail(&word, str.start[i]);
        }
    }
    addTailArr(&newStrArr, word);
    return newStrArr;
}
