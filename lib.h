//
// Created by Admin on 21.11.2022.
//

#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

typedef char byte;

typedef struct {
    byte* start;
    size_t len;
    size_t cap;
} string;

typedef struct {
    string* start;
    size_t len;
    size_t cap;
} stringArr;

string strInit();
stringArr strArrInit();
void strInfo(string str);
void strArrInfo(stringArr strArr);
void checkFileIsExist(FILE* file);
void nullCheck(void* ptr);
void addTail(string* str, byte ch);
void addTailArr(stringArr* strArr, string str);
void freeStr(string str);
void freeStrArr(stringArr strArr);
void printStr(string str);
void printStrArr(stringArr strArr);
void argCheck(int argc);
string temperature(string str);
int isPalindrome(string str);
void stripBySpace(string* str);
stringArr split(string str);
int isSymbolOfWord(byte ch);
void removeBrackets(string* str);