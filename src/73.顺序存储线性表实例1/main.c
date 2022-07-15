#include <stdio.h>
#include <stdlib.h>
#include "sqlist.h"
int main()
{
    sqlist *list;
    sqlist_create1(&list);

    if (list == NULL)
    {
        fprintf(stderr, "sqlist_create() failde!:\n");
        exit(1);
    }
    datatype a = 1;
    datatype b = 2;
    datatype c = 3;
    datatype d = 4;
    datatype e = 5;
    sqlist_insert(list, 0, &a);
    sqlist_insert(list, 1, &b);
    sqlist_insert(list, 2, &c);
    sqlist_insert(list, 3, &d);
    sqlist_insert(list, 0, &e);
    sqlist_insert(list, 0, &e);

    sqlist_display(list);

    sqlist_destroy(list);
    exit(0);
};