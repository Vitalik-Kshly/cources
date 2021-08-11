#include "list.h"

void menu(char **listHead)
{
    int choice = 0;
    
    while (choice != -1)
    {
        printf("Make your choice:\n");
        printf("Enter 1 to push a string.\n");
        printf("Enter 2 to display a list.\n");
        printf("Enter 3 to find the index of exact match.\n");
        printf("Enter 4 to get the length of the list.\n");
        printf("Enter 5 to remove the strings.\n");
        printf("Enter 6 to sort list.\n");
        printf("Enter 7 to replace string.\n");
        printf("Enter 8 to remove duplicates.\n");
        printf("Enter 9 to DESTROY list.\n");
        printf("Enter -1 to exit.\n");
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            printf("Enter a string.\n");
            string tempStr = (string)malloc(STR_LENGTH);
            std::cin >> tempStr;
            if (!listHead)
            {
                free(listHead);
                StringListInit(&listHead);
            }
            StringListAdd(listHead, tempStr);
            break;
        }
        case 2:
        {
            DisplayList(listHead);
            break;
        }
        case 3:
        {
            printf("Enter your string:\n");
            string tempStr = (string)malloc(STR_LENGTH);
            std::cin >> tempStr;
            StringListIndexOf(listHead, tempStr);
            break;
        }
        case 4:
        {
            std::cout << "List length is " << StringListSize(listHead) << std::endl;
            break;
        }
        case 5:
        {
            DisplayList(listHead);
            string str = (string) malloc(STR_LENGTH);
            std::cout << "Enter string: ";
            std::cin >> str;
            StringListRemove(&listHead, str);
            DisplayList(listHead);
            break;
        }
        case 6:
        {
            DisplayList(listHead);
            StringListSort(listHead);
            DisplayList(listHead);
            break;
        }
            
        case 7:
        {
            DisplayList(listHead);
            string newStr = (string)malloc(STR_LENGTH);
            string oldStr = (string)malloc(STR_LENGTH);
            std::cout << "Enter old string: ";
            std::cin >> oldStr;
            std::cout << "Enter new string: ";
            std::cin >> newStr;
            StringListReplaceInStrings(listHead, oldStr, newStr);
            free(newStr);
            free(oldStr);
            DisplayList(listHead);
            break;
        }
        case 8:
        {
            StringListRemoveDuplicates(listHead);
            break;
        }
        case 9:
        {
            StringListDestroy(&listHead);
        }
        default:
            continue;
        }
    }
}

int main()
{   
    char **listHead = NULL;
    StringListInit(&listHead);
    menu(listHead);

    return 0;
}