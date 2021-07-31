#include "list.h"

void menu(char ***listHead)
{
    int choice = 0;
    
    while (choice != -1)
    {
        printf("Make your choice:\n");
        printf("Enter 1 to add a few strings.\n");
        printf("Enter 2 to push a string.\n");
        printf("Enter 3 to display a list.\n");
        printf("Enter 4 to find the index of exact match.\n");
        printf("Enter 5 to get the length of the list.\n");
        printf("Enter 6 to remove the string by index.\n");
        printf("Enter 7 to sort list.\n");
        printf("Enter -1 to exit.\n");
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            add_elements(listHead);
            break;
        case 2:
            {
                printf("Enter a string.\n");
                char *tempStr = (char *)malloc(255);
                std::cin >> tempStr;
                if (!listHead){
                    free(listHead);
                    listHead = build_node(tempStr);
                    break;
                }
                push_item(listHead, build_node(tempStr));
                break;
            }
        case 3:
            display_list(listHead);
            break;
        case 4:
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
            std::cout << "Enter the index:\n";
            int tempindex;
            std::cin >> tempindex;
            remove_string_from_list(listHead, tempindex);

            break;
        }
        case 7:
            sort_list(listHead);
            display_list(listHead);
            break;
        default:
            continue;
        }
    }
}

int main()
{   
    char ***listHead = init_list();
    menu(listHead);

    return 0;
}