//
// Created by Admin on 21.11.2022.
//

#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

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
void printStr(string str);
void printStrArr(stringArr strArr);