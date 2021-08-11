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
    if (!*listHead)
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
    if (!*listHead)
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
    if(!listHead)
    {
        printf("Error Empty HEAD!");
        return;
    }
    *listHead = (char **)malloc(sizeof (char *) * 2);
    if (!*listHead) {
        printf("Memory did not allocate!");
        return;
    }
    (*listHead)[0] = (char*)malloc(sizeof(char*));
    (*listHead)[1] = (char*)malloc(sizeof(char*));
    (*listHead)[0] = NULL;
    (*listHead)[1] = NULL;
}

void StringListIndexOf(char **listHead, string str)
{
    if (!*listHead || !listHead)
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
    if (!listHead || !*listHead)
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
    if (!*listHead || !listHead)
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

static void swap(char ***a, char**&b)
{
    char** c = *a;
    *a = b;
    b = c;
}

void StringListSort(char **listHead)
{
    if (!*listHead || !listHead)
    {
        printf("List is empty! Stop it!");
        return;
    }
    //Sorts the list 
    char **curNode = (char **)malloc(1);
    if (!curNode) {
        printf("Memory did not allocate!");
        return;
    }
    *curNode = (char *)malloc(1);
    *curNode = NULL;
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
                    //Swap values
                    char** nextNode = (char**)tempNode[1];
                    char* tempStr = *nextNode;
                    *nextNode = *tempNode;
                    *tempNode = tempStr;
                    swapped = 1;
                }
                
            tempNode = (char **) tempNode[1];
        }
        curNode = (char**) tempNode[1];
    }while(swapped);

}

void StringListDestroy(char*** listHead)
{
    if (!*listHead || !listHead || !***listHead)
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

void StringListRemoveDuplicates(char** listHead)
{
    if (!*listHead || !listHead)
    {
        printf("List is empty! Stop it!");
        return;
    }
    char **tempCheck = NULL;
    char ** temp = listHead;

    while(temp != NULL && temp[1] != NULL)
    {
        tempCheck = temp; 
        while (tempCheck[1] != NULL)
        {

            if (!strcmp(*temp, *(char**)tempCheck[1]))
            {
                char **tempFree = (char **)tempCheck[1];
                tempCheck[1] = ((char **) tempCheck[1])[1];
                free(*tempFree);
                free(tempFree);
            }else
            {
                tempCheck = (char **) tempCheck[1];
            }

        } 
        temp = (char **) temp[1];
    }

}