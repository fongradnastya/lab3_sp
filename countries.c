#include<stdio.h>
#include<stdlib.h>
#include"struct.h"

Node* createNewNode(char* name, long peopleNumb, long area){
    Node* node = (Node*)malloc(sizeof(Node));
    if (node == NULL) {
        printf("Unpossible to allocate memory\n");
        exit(1);
    }
    node->value.name = name;
    node->value.area = area;
    node->value.population = peopleNumb;
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

void appendCountry(Node* head, Node* newNode){
    if(head == NULL){
        head = newNode;
    }
    else{
        Node* tail = getTail(head);
        tail->next = newNode;
    }
}

void deleteCountry(){
}

void printAllCountries(Node* head){
    if(head == NULL){
        printf("There are no countries yet\n");
    }
    else{
        printf("__________________COUNTRIES____________________");
    }
    

}

void printCountry(Country country){
    printf("%s %d %d\n", country.name, country.population, country.area);
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

void freeCountries(){

}