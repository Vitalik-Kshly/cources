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
        printf("Enter 5 to get the length of the list.\n");
        printf("Enter 6 to remove the string by index.\n");
        printf("Enter 7 to sort list.\n");
        printf("Enter 8 to replace string by index.\n");
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
                get_first_match_index(listHead, tempStr);
                break;
            }
        case 5:
        {
            std::cout << "List length is " << get_list_length(listHead) << std::endl;
            break;
        }
        case 6:
        {
            display_list(listHead);
            string str = (string) malloc(STR_LENGTH);
            std::cout << "Enter string: ";
            std::cin >> str;
            StringListRemove(&listHead, str);
            display_list(listHead);
            break;
        }
        case 7:
            display_list(listHead);
            sort_list(listHead);
            display_list(listHead);
            break;
        case 8:
            display_list(listHead);
            // replace_string(listHead);
            display_list(listHead);
            break;
        default:
            continue;
        }
    }
}

int main()
{   
    char **listHead = NULL;
    StringListInit(&listHead);
    // StringListAdd(listHead, "AAA");
    // StringListAdd(listHead, "AAB");
    // StringListAdd(listHead, "AAA");
    // StringListAdd(listHead, "FFF");
    // StringListAdd(listHead, "aVBA");
    menu(listHead);

    return 0;
}