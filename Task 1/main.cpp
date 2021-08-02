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
        printf("Enter -1 to exit.\n");
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            {
                printf("Enter a string.\n");
                char *tempStr = (char *)malloc(255);
                std::cin >> tempStr;
                if (!listHead){
                    free(listHead);
                    StringListInit(&listHead);
                }
                StringListAdd(listHead, tempStr);
                break;
            }
        case 2:
            display_list(listHead);
            break;
        case 3:
            {
                printf("Enter your string:\n");
                char *tempStr = (char *)malloc(255);
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
            display_list(listHead);
            string str = (string) malloc(STR_LENGTH);
            std::cout << "Enter string: ";
            std::cin >> str;
            StringListRemove(&listHead, str);
            display_list(listHead);
            break;
        }
        case 6:
        {
            display_list(listHead);
            StringListSort(listHead);
            display_list(listHead);
            break;
        }
            
        case 7:
        {
            display_list(listHead);
            string newStr = (char *)malloc(STR_LENGTH);
            string oldStr = (char *)malloc(STR_LENGTH);
            std::cout << "Enter old string: ";
            std::cin >> oldStr;
            std::cout << "Enter new string: ";
            std::cin >> newStr;
            StringListReplaceInStrings(listHead, oldStr, newStr);
            free(newStr);
            free(oldStr);
            display_list(listHead);
            break;
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