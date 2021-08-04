
#ifndef LIST_H 
#define LIST_H
#include <iostream>
#include <string.h>
#include <stdlib.h>

typedef char * string;
const int STR_LENGTH = 255;

int StringListSize(char **listHead);

void StringListRemove(char ***listHead, string str);

void StringListAdd(char** listHead, string str);

void StringListInit(char *** listHead);

void StringListIndexOf(char **listHead, string str);

void DisplayList(char **listHead);

void StringListReplaceInStrings(char** list, char* before, char* after);

void StringListSort(char **listHead);

void StringListDestroy(char*** list);

void StringListRemoveDuplicates(char** list);

#endif