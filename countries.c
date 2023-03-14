#include<stdio.h>
#include<stdlib.h>
#include"struct.h"
#include"input.c"

Country getCountry()
{
    printf("Please, enter the country name: ");
    char* name = GetString();
    long population;
    int res = 0;
    while(res != 1){
        printf("Please, enter the country population: ");
        res = InputLong(&population);
        if(res == 0){
            printf("This value should be digit!\n");
        }
        else if(res == -1){
            printf("This value should be positive!\n");
        }
    }
    long area;
    res = 0;
    while(res != 1){
        printf("Please, enter the country area: ");
        res = InputLong(&area);
        if(res == 0){
            printf("This value should be digit!\n");
        }
        else if(res == -1){
            printf("This value should be positive!\n");
        }
    }
    Country newCountry;
    newCountry.name = name;
    newCountry.area = area;
    newCountry.population = population;
    return newCountry;
}

Node* createNewNode(Country country){
    Node* node = (Node*)malloc(sizeof(Node));
    if (node == NULL) {
        printf("Unpossible to allocate memory\n");
        exit(1);
    }
    node->value = country;
    node->next = NULL;
    return node;
}

Node* getTail(Node* head){
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    return temp;
}

int getCountriesQuantity(Node* head){
    if(head == NULL){
        return 0;
    }
    int cnt = 1;
    Node* temp = head;
    while(temp->next != NULL){
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

void appendCountry(Node** head, Node* newNode){
    if(*head == NULL){
        *head = newNode;
    }
    else{
        Node* tail = getTail(*head);
        tail->next = newNode;
    }
}

Node* findCountry(Node* head){
    printf("Please, enter the country name:");
    char* name = GetString();
    while(head != NULL){
        if(head->value.name == name){
            return head;
        }
        head = head->next;
    }
    return NULL;
}

void deleteCountry(Node** head){
    Node* temp = *head;
    Node* prevNode = NULL;
    printf("Please, enter the country name:");
    char* name = GetString();
    if (temp == NULL){
        printf("Nothing to delete\n");
    }
    else if (temp->value.name == name){
        *head = (*head)->next;
        printf("The country was successfully deleted");
    }
    else{
        while(temp->next != NULL){
            if(temp->value.name == name){
                prevNode = temp;
                break;
            }
            temp = temp->next;
        }
        if(prevNode == NULL){
            printf("There are no countries with such name");
        }
        else{
            Node* currNode = prevNode->next;
            prevNode->next = currNode->next;
            printf("The country was successfully deleted");
        }
    }
}

void printCountry(Country country){
    printf("%s %d %d\n", country.name, country.population, country.area);
}


void printAllCountries(Node* head){
    if(head == NULL){
        printf("There are no countries yet\n");
    }
    else{
        printf("__________________COUNTRIES______________________\n");
        while(head != NULL){
            printCountry(head->value);
            head = head->next;
        }
        printf("_________________________________________________\n");
    }
    

}

void changeCountry(Node* head){
    int num = getCountriesQuantity(head);
    if(num == 0){
        printf("Nothing to change.");
    }
    else{

    }
    printf("There are %d countries", num);
    printf("Please, enter the country number to change: ");


}

void freeCountries(Node* head){
    Node* current = head;
    Node* next;
    while (current != NULL){
        next = current->next;
        free(current->value.name);
        free(current);
        current = next;
    }
}