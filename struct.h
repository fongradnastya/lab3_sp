#ifndef WORK3_STRUCT_H
#define WORK3_STRUCT_H


typedef struct{
    char* name;
    long population;
    long area;
}Country;

typedef struct Node{
    Country value;
    struct Node* next;
}Node;



#endif
