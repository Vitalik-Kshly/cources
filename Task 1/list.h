
#ifndef LIST_H 
#define LIST_H
#include <iostream>
#include <string.h>
#include <stdlib.h>

const int STR_LENGTH = 255;

int get_list_length(char ***listHead);
void remove_string_from_list(char ***&listHead, int index);

void push_item(char ***listHead, char ***item);
char*** build_node(char *str);

void add_elements(char ***listHead);
char*** init_list();

void get_first_match_index(char ***listHead, char *str);

void display_list(char ***listHead);

void sort_list(char ***listHead);
static char ***get_element_by_index(char ***listHead);
void replace_string(char ***listHead, int index);


#endif