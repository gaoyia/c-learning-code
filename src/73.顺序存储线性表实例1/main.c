#include <stdio.h>
#include <stdlib.h>
#include "sqlist.h"
int main()
{
    sqlist *list;
    sqlist_create1(&list);
    sqlist *list2;
    sqlist_create1(&list2);
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

    datatype x = 10;
    datatype y = 1;
    datatype z = 12;

    sqlist_insert(list, 0, &a);                                       // 1
    sqlist_insert(list, 1, &b);                                       // 1,2
    sqlist_insert(list, 2, &c);                                       // 1,2,3
    sqlist_insert(list, 3, &d);                                       // 1,2,3,4
    sqlist_insert(list, 0, &e);                                       // 5,1,2,3,4
    sqlist_delete(list, 2);                                           // 5,1,3,4
    printf("---sqlist_find(list,&e);(%d)---", sqlist_find(list, &d)); // 3

    sqlist_insert(list2, 0, &x); // 5,1,2,3,4
    sqlist_insert(list2, 1, &y); // 5,1,2,3,4
    sqlist_insert(list2, 2, &z); // 5,1,2,3,4

    sqlist_union(list, list2);

    sqlist_display(list);

    sqlist_destroy(list);
    exit(0);
};