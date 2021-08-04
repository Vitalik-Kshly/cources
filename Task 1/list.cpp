#include "list.h"

int StringListSize(char **listHead)
{
    if (!listHead[0])
    {
        printf("List is empty! Stop it!");
        return -1;
    }
    char **temp = listHead;
    int index = 1;
    while (temp[1] != nullptr) 
    {
        temp = (char **)temp[1];
        index++;
    }
    return index;
}

void StringListRemove(char ***listHead, string str)
{
    if (!listHead[0])
    {
        printf("List is empty! Stop it!");
        return;
    }

    char **temp = *listHead;
    
    
    while (temp != NULL)
    {
        
        if (strcmp(*listHead[0], str) == 0)
        {
            char *clear = **listHead;
            *listHead = (char **)(*listHead)[1];
            free(clear);
            temp = *listHead;
            continue;
        }
        
        if(temp[1] == NULL)
        {
            break;
        }
        char **cur = (char **)temp[1];
        char **next = (char **)cur[1];
        if (strcmp(*cur, str) == 0)
        {
            temp[1] = (char *)next;
            free(cur);
            cur = NULL;
        }
        else{
            temp = (char **)temp[1];
        }
    }
}

void StringListAdd(char** listHead, string str)
{
    if (listHead[0] == NULL || listHead == NULL)
    {
        *listHead = str;
        return;
    }
    char **temp = listHead;
    while (temp[1] != nullptr) 
    {
        temp = (char **)temp[1];
    }
    char **node = NULL;
    StringListInit(&node);
    node[0] = str;
    temp[1] = (char *)node;
}

void StringListInit(char*** listHead)
{
    *listHead = (char **)malloc(sizeof (char *) * 2);
    (*listHead)[0] = (char*)malloc(sizeof(char*));
    (*listHead)[1] = (char*)malloc(sizeof(char*));
    (*listHead)[0] = NULL;
    (*listHead)[1] = NULL;
}

void StringListIndexOf(char **listHead, string str)
{
    if (!listHead[0])
    {
        printf("List is empty! Stop it!");
        return;
    }
    bool match = 0;
    int tempi = 0;
    char **temp = listHead;
    std::cout << str << "\n";
    
    while (temp[1] != nullptr) 
    {
        if (!strcmp(*temp, str))
        {
            match = 1;
            break;
        }
        tempi++;
        temp = (char **)temp[1];
    }
    match = !strcmp(*temp, str);;
    if (!match)
        {
            std::cout << "There is no matches of " << str << '\n'; 
            return;
        }
    std::cout << "The index of first match for " << str << " is " << tempi << '\n'; 
}

void DisplayList(char **listHead)
{
    if (listHead == NULL || listHead[0] == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    char **curElem = listHead;
    printf("Items of the list:\n");
    int index = 0;
    while (curElem[1] != nullptr)
    {
        std::cout << index << ". " << *curElem << std::endl;
        curElem = (char **)curElem[1];
        index++;
    }

    std::cout << index << ". " << *curElem << std::endl;
}

void StringListReplaceInStrings(char** listHead, string before, string after)
{
    if (!listHead[0])
    {
        printf("List is empty! Stop it!");
        return;
    }
    char **temp = listHead;
    while (temp != NULL)
    {
        if (strcmp(*temp, before) == 0)
        {
            strncpy(*temp, after, sizeof(after));
        }
        temp = (char **)temp[1];
    }
}

void StringListSort(char **listHead)
{
    if (!listHead[0])
    {
        printf("List is empty! Stop it!");
        return;
    }
    //Sorts the list 
    char **curNode = (char **)malloc(1);
    curNode[0] = (char *)malloc(1);
    curNode[0] = NULL;
    bool swapped;
    do
    {
        swapped = 0;
        char **tempNode = listHead;
        while (tempNode[1] != (char *)curNode)
        {
            if (!tempNode[1])
            {
                break;
            }
            
            if (strcmp(*tempNode, *(char **) tempNode[1]) > 0)
                {
                    std::cout << "Shit: " << tempNode[0] << ' ' << *(char **) tempNode[1] << std::endl;
                    char *tempStr = (char *) malloc(sizeof(tempNode[0]));
                    
                    //Swap values
                    strncpy(tempStr, tempNode[0], sizeof(tempNode[0]));
                    strncpy(tempNode[0], *(char **) tempNode[1], sizeof(*(char **) tempNode[1]));
                    strncpy(*(char **) tempNode[1], tempStr, sizeof(tempStr));

                    free(tempStr);
                    swapped = 1;
                }
                
            tempNode = (char **)tempNode[1];
        }
        curNode = (char**) tempNode[1];
    }while(swapped);

}

void StringListDestroy(char*** listHead)
{
     if (!**listHead)
    {
        printf("List is empty! Stop it!");
        return;
    }
    char **tempFree = *listHead;
    while (*listHead != NULL)
    {
        
        *listHead = (char **) (*listHead)[1];
        free(*tempFree);
        free(tempFree);
        tempFree = (char **)*listHead;
    }
    
}