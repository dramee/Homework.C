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
        addTail(&str, ch);
        if (ch == '\n') {
            addTailArr(&strArr, str);
            str = strInit();
        }
    }
    fclose(file);
    printStrArr(strArr);
    freeStrArr(strArr);
    return 0;
}
