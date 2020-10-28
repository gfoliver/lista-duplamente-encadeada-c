#include<stdlib.h>
#include<stdio.h>
#include "LDE.h"

int main() {
    List* list = cria();

    insertInStart(&list, 1);
    insertInEnd(&list, 2);
    insertInEnd(&list, 3);
    insertInStart(&list, 0);

    printList(list);

    printf("\n\n");

    removeFromEnd(&list);
    removeFromStart(&list);

    printList(list);

    return 0;
}