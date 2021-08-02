
#ifndef LIST_H 
#define LIST_H
#include <iostream>
#include <string.h>
#include <stdlib.h>

typedef char * string;
const int STR_LENGTH = 255;

int get_list_length(char **listHead);
void StringListRemove(char ***listHead, string str);

void StringListAdd(char** listHead, string str);
static void build_node(char ***node);

// void add_elements(char ***listHead);
void StringListInit(char *** listHead);

void get_first_match_index(char **listHead, string str);

void display_list(char **listHead);

void sort_list(char **listHead);
static char **get_element_by_index(char **listHead);
void replace_string(char **listHead, int index);


#endif