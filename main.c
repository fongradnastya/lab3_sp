#include <stdio.h>
#include<stdlib.h>
#include"struct.h"

Node* createNewNode(char* name, long peopleNumb, long area){
    Node* node = (Node*)malloc(sizeof(Node));
    node->value.name = name;
    node->value.area = area;
    node->value.population = peopleNumb;
    node->next = NULL;
    return node;
}

int main(){
    createNewNode("tttt", 5, 6);
    return 0;
}
