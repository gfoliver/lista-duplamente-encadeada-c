#include<stdlib.h>
#include<stdio.h>
#include "LDE.h"

List* cria() {
    List* newList = (List*) malloc(sizeof(List));

    newList->start = NULL;
    newList->end = NULL;

    return newList;
}

void insertInStart(List** list, int value) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->value = value;

    if ((*list)->start == NULL) {
        node->previous = NULL;
        node->next = NULL;
        (*list)->end = node;
    }
    else {
        node->next = (*list)->start;
        node->previous = NULL;

        (*list)->start->previous = node;
    }

    (*list)->start = node;
}

void insertInEnd(List** list, int value) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->value = value;

    Node* current = (*list)->start;
    if ((*list)->start == NULL) {
        node->previous = NULL;
        node->next = NULL;
        
        (*list)->start = node;
    }
    else {
        if (current->next == NULL) {
            node->next = NULL;
            node->previous = current;
            current->next = node;
        }
        else {
            while (current->next != NULL) {
                current = current->next;
            }

            node->next = NULL;
            node->previous = current;
            current->next = node;
        }
    }

    (*list)->end = node;
}

void removeFromStart(List** list) {
    Node* newStart = (*list)->start->next;

    if (newStart == NULL) {
        (*list)->start = NULL;

        return;
    }

    newStart->previous = NULL;
    
    (*list)->start = newStart;
}

void removeFromEnd(List** list) {
    if ((*list)->end != NULL) {
        if ((*list)->end->previous != NULL) {
            (*list)->end->previous->next = NULL;
            (*list)->end = (*list)->end->previous;

            return;
        }

        (*list)->end = NULL;
    }
}

void printList(List* list) {
    Node* current = list->start;

    while(current != NULL) {
        printf("%d\n", current->value);
        current = current->next;
    }
}