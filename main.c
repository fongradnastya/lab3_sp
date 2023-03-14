#include <stdio.h>
#include<stdlib.h>
#include"struct.h"
#include"countries.c"

void printChangeMenu(){
    printf("___________________CHANGE_MENU___________________\n");
    printf("1 - to change a country name\n");
    printf("2 - to change a country area\n");
    printf("3 - to change a country population\n");
    printf("_________________________________________________\n");
}

void printMenu(){
    printf("_____________________MENU________________________\n");
    printf("1 - to add new country\n");
    printf("2 - to change a country\n");
    printf("3 - to delete a country\n");
    printf("4 - to print all the countries\n");
    printf("5 - to find a country\n");
    printf("6 - to get a list of the most populous countries\n");
    printf("7 - to sort countries by their population\n");
    printf("8 - to exit\n");
    printf("_________________________________________________\n");
}

int main(){
    Node* head = NULL;
    int end = 0;
    while(end == 0){
        printMenu();
        int command = 0;
        int res = 0;
        while(res == 0){
            res = InputInt(&command);
        }
        switch(command)
        {
            case 1:
            {
                Node* node = createNewNode(getCountry());
                appendCountry(&head, node);
                freeCountries(node);
            }     
            case 2:
            {
                changeCountry(head);
            }  
            case 3:
            {
                deleteCountry(&head);
            }
            case 4:
            {
                printAllCountries(head);
            }
            case 8:
            {
                freeCountries(head);
                end = 1;
            }
            default:
            {
                printf("This command is incorrect!");
            }
        }
    }
    return 0;
}
