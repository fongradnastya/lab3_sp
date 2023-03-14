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

int main(){
    
    Node* node = createNewNode(getCountry());
    printCountry(node->value);
    Node* head = NULL;
    printChangeMenu();
    appendCountry(&head, node);
    printAllCountries(head);
    return 0;
}
