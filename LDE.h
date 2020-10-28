#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

typedef struct node {
    int value;
    struct node* previous;
    struct node* next;
} Node;

typedef struct list {
    Node* start;
    Node* end;
} List;

List* cria();

void insertInStart(List** list, int value);

void insertInEnd(List** list, int value);

void removeFromStart(List** list);

void removeFromEnd(List** list);

void printList(List* list);

#endif // NODE_H_INCLUDED