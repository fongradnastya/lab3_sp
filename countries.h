#ifndef COUNTRIES_H
#define COUNTRIES_H
#include"struct.h"

Country getCountry();

Node* createNewNode(Country country);

Node* getTail(Node* head);

int getCountriesQuantity(Node* head);

void appendCountry(Node** head, Node* newNode);

void deleteCountry(Node** head);

void printCountry(Country country);

void printAllCountries(Node* head);

Node* findCountry(Node* head);

void printChangeMenu();

void changeCountry(Node** head);

void freeCountries(Node* head);

Node* sort( Node* root );

void getHightPopulate(Node* head);

void getTheMostPopulous(Node* head);

#endif