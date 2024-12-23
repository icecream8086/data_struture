#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>
#include <windows.h>

void getDateTime(char* dateTime) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(dateTime, "%04d-%02d-%02d %02d:%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min);
}

void writeTree(const char* folderPath) {
    char command[512];
    snprintf(command, sizeof(command), "chcp 65001 > nul && tree /f \"%s\"", folderPath);
    system(command);
}

void convertToUTF8(const char* input, char* output, size_t outputSize) {
    int wcharsNum = MultiByteToWideChar(CP_ACP, 0, input, -1, NULL, 0);
    wchar_t* wstr = (wchar_t*)malloc(wcharsNum * sizeof(wchar_t));
    MultiByteToWideChar(CP_ACP, 0, input, -1, wstr, wcharsNum);

    int utf8Size = WideCharToMultiByte(CP_UTF8, 0, wstr, -1, NULL, 0, NULL, NULL);
    WideCharToMultiByte(CP_UTF8, 0, wstr, -1, output, (int)outputSize, NULL, NULL);

    free(wstr);
}

void printUTF8(const char* str) {
    int wcharsNum = MultiByteToWideChar(CP_UTF8, 0, str, -1, NULL, 0);
    wchar_t* wstr = (wchar_t*)malloc(wcharsNum * sizeof(wchar_t));
    MultiByteToWideChar(CP_UTF8, 0, str, -1, wstr, wcharsNum);
    WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE), wstr, wcharsNum - 1, NULL, NULL);
    free(wstr);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Please provide the folder path as a parameter. \n");
        printf("example: %s \"C:\\path\\to\\your\\folder\"\n", argv[0]);
        return 1;
    }

    const char* targetFolder = argv[1];
    char dateTime[32];
    char utf8Folder[512];

    setlocale(LC_ALL, "");

    // Change the console output code page to UTF-8
    SetConsoleOutputCP(CP_UTF8);

    writeTree(targetFolder);
    getDateTime(dateTime);

    convertToUTF8(targetFolder, utf8Folder, sizeof(utf8Folder));

    printf("\n");
    printUTF8("文件夹名称: ");
    printUTF8(utf8Folder);
    printf("\n");

    printUTF8("日期时间: ");
    printUTF8(dateTime);
    printf("\n");

    // printUTF8("完成！结构已输出到控制台。\n");

    return 0;
}
