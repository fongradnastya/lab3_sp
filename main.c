#include <stdio.h>
#include<stdlib.h>
#include"struct.h"
#include"countries.c"


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
            printf("Your command: ");
            res = InputInt(&command);
        }
        if(command == 1){
            Node* node = createNewNode(getCountry());
            appendCountry(&head, node);
        }
        else if(command == 2){
            changeCountry(&head);
        }
        else if(command == 3){
            deleteCountry(&head);
        }
        else if(command == 4){
            printAllCountries(head);
        }
        else if(command == 5){
            findCountry(head);
        }
        else if(command == 8){
            freeCountries(head);
            end = 1;
        }
    }
    return 0;
}
