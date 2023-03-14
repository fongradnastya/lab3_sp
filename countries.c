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

void deleteCountry(Node** head){
    Node* temp = *head;
    Node* prevNode = NULL;
    printf("Please, enter the country name:");
    char* name = GetString();
    if (temp == NULL){
        printf("Nothing to delete\n");
    }
    else if (strcmp(temp->value.name, name) == 0){
        *head = (*head)->next;
        printf("The country was successfully deleted\n");
    }
    else{
        while(temp->next != NULL){
            if(strcmp(temp->value.name, name) == 0){
                prevNode = temp;
                break;
            }
            temp = temp->next;
        }
        if(prevNode == NULL){
            printf("There are no countries with such name\n");
        }
        else{
            Node* currNode = prevNode->next;
            prevNode->next = currNode->next;
            printf("The country was successfully deleted\n");
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

Node* findCountry(Node* head){
    printf("Please, enter the country name:");
    char* name = GetString();
    while(head != NULL){
        if(strcmp(head->value.name, name) == 0){
            printCountry(head->value);
            return head;
        }
        head = head->next;
    }
    printf("Country %s wasn't found", name);
    return NULL;
}

void printChangeMenu(){
    printf("___________________CHANGE_MENU___________________\n");
    printf("1 - to change a country name\n");
    printf("2 - to change a country population\n");
    printf("3 - to change a country area\n");
    printf("_________________________________________________\n");
}

void changeCountry(Node* head){
    int num = getCountriesQuantity(head);
    if(num == 0){
        printf("Nothing to change.");
    }
    printf("There are %d countries", num);
    Node* node = findCountry(head);
    if(node != NULL){
        printChangeMenu();
        int command;
        int res = 0;
        while(res == 0){
            printf("Your command: ");
            res = InputInt(&command);
        }
        if(command == 1){
            printf("Please, enter the country name: ");
            char* name = GetString();
        }
        else if(command == 2){
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
        }
        else if(command == 3){
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
        }
        else{
            printf("Wrong command");
        }
    }
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