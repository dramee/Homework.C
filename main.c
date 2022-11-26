#include "lib.h"

int main(int argc, byte* argv[]) {
    FILE* file;
    argCheck(argc);
    file = fopen("H:\\Projects\\GitHub\\Homework.C\\test.txt", "r");
    checkFileIsExist(file);
    string str = strInit();
    stringArr strArr = strArrInit();
    while (!feof(file)){
        byte ch = (byte) fgetc(file);
        if (ch == '\n') {
            addTail(&str, '\0');
            addTailArr(&strArr, str);
            str = strInit();
        } else {
            addTail(&str, ch);
        }
    }
    addTail(&str, '\0');
    addTailArr(&strArr, str);
    fclose(file);
    stringArr testStrArr = split(strArr.start[0]);
    strArrInfo(testStrArr);
    for (size_t i = 0; i < testStrArr.len; i++) {
        printStr(testStrArr.start[i]);
        printf(" true_length: %zu length: %zu\n", testStrArr.start[i].len, strlen(testStrArr.start[i].start));
    }
    freeStrArr(testStrArr);
    freeStrArr(strArr);
    return 0;
}
