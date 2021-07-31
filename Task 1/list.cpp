#include "list.h"

int get_list_length(char ***listHead)
{
    if (!listHead)
        return 0;
    char ***temp = listHead;
    int index = 1;
    while (*(temp[1])!=nullptr) {
        temp = (char ***)temp[1];
        index++;
    }
    return index;
}

void remove_string_from_list(char ***&listHead, int index)
{
    if (!listHead){
        printf("List is empty! Stop it!");
        return;
    }
    if (index == 0)
    {
        listHead = (char ***) listHead[1];
        return;
    }
    char ***temp = listHead;
    for (int i = 0; i < index - 1; i++)
    {
        temp = (char ***)temp[1];
    }
    char ***prev = temp;
    char ***next = (char ***)((temp[1]))[1];
    free(temp[1]);
    prev[1] = (char **) next;
}

void push_item(char ***&listHead, char ***item)
{
    if (!listHead){
        listHead = item;
        return;
    }
    char ***temp = listHead;
    while (*(temp[1])!=nullptr) {
        temp = (char ***)temp[1];
    }
    temp[1] = (char **)item;
}

char*** build_node(char *str)
{
    char ***node = (char***) malloc(2*sizeof(char*));
    node[0] = (char**)malloc(sizeof(char*));
    node[1] = (char**)malloc(sizeof(char*));
    *(node[0]) = str;
    *(node[1]) = nullptr;
    return node;
}

void add_elements(char ***listHead)
{
    printf("Enter count of elements:\n");
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        char *str = (char *)malloc(255);
        std::cin >> str;
        char ***tempNode = build_node(str);
        push_item(listHead, tempNode);
    }
}

char*** init_list()
{
    
    char* firstElement = (char *) malloc(255);
    printf("Enter the first element:\n");
    std::cin >> firstElement;
    char ***listHead = build_node(firstElement);
    return listHead;
}

void get_first_match_index(char ***listHead, char *str)
{
    bool match = 0;
    int tempi = 0;
    char ***temp = listHead;
    std::cout << str << "\n";
    
    while (temp[1] != nullptr) {
        if (!strcmp(**temp, str))
        {
            match = 1;
            break;
        }
        tempi++;
        temp = (char ***)temp[1];
    }
    match = !strcmp(**temp, str);;
    if (!match)
        {
            std::cout << "There is no matches of " << str << '\n'; 
            return;
        }
    std::cout << "The index of first match for " << str << " is " << tempi << '\n'; 
}

void display_list(char ***listHead)
{
    if (!(*listHead))
    {
        printf("List is empty!\n");
        return;
    }
    char ***curElem = listHead;
    printf("Items of the list:\n");
    int index = 0;
    while (*(curElem[1]) != nullptr)
    {
        std::cout << index << ". " << **curElem << std::endl;
        curElem = (char ***)curElem[1];
        index++;
    }

    std::cout << index << ". " << **curElem << std::endl;
}

void sort_list(char ***&listHead)
{
    int listLength = get_list_length(listHead);
    char ***curNode = nullptr;
    bool swapped;
    do
    {
        swapped = 0;
        char ***tempNode = listHead;
        while (tempNode[1] != (char **)curNode)
        {
            if (!*(char ***) tempNode[1])
                break;
            if (strcmp(*tempNode[0], **(char ***)tempNode[1]) > 0)
                {
                    std::cout << "Shit: " << *tempNode[0] << ' ' << (char ***) *tempNode[1] << std::endl;
                    char *tempStr = (char *) malloc(255);
                    // char *str1[100];
                    // tempStr = *(tempNode[0]);
                    // *(tempNode[0]) = *(tempNode[1]);
                    
                    strncpy(tempStr, *tempNode[0], sizeof(*tempNode[0]));
                    strncpy(*(tempNode[0]), **(char ***)tempNode[1], sizeof(**(char ***)tempNode[1]));
                    
                    strncpy(**(char ***)tempNode[1], tempStr, sizeof(tempStr));
                    free(tempStr);
                    swapped = 1;
                }
                
            tempNode = (char ***)tempNode[1];
        }
        curNode = (char***) tempNode[1];
    }while(swapped);

}