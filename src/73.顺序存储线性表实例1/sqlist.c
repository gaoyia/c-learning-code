#include <stdio.h>
#include <stdlib.h>
#include "sqlist.h"

sqlist *sqlist_create()
{
    sqlist *space;
    space = (sqlist *)malloc(sizeof(*space));
    if (space == NULL)
        return NULL;
    space->last = -1;

    return space;
};

void sqlist_create1(sqlist **space)
{
    *space = (sqlist *)malloc(sizeof(**space));
    if (*space == NULL)
        return;

    (*space)->last = -1;
    return;
};

// i 是0-1023
int sqlist_insert(sqlist *list, int index, datatype *data)
{
    if (list->last == DATASIZE - 1)
    {
        printf("-1\n");
        printf("list->last(%d)\n", list->last);
        return -1;
    }
    if (index < 0 || index > list->last + 1)
    {
        printf("-2\n");
        printf("index(%d)\n", index);
        printf("list->last + 1(%d)\n", list->last + 1);
        return -2;
    }
    for (
        int j = list->last;
        index <= j;
        j--)
    {
        list->data[j + 1] = list->data[j];
    }
    list->last++;
    list->data[index] = *data;
};

int sqlist_delete(sqlist *list, int i){

};

int sqlist_find(sqlist *list, datatype *dt){

};

int sqlist_is_empty(sqlist *list){

};

int sqlist_set_empty(sqlist *list){

};

int sqlist_get_length(sqlist *list){

};

void sqlist_display(sqlist *list)
{
    printf("\n-----sqlist_display----\n");

    for (int i = 0; i <= list->last; i++)
    {
        printf("data(%d)\n", list->data[i]);
    }
    printf("---------end--------\n");
};

int sqlist_destroy(sqlist *list)
{
    free(list);
    return 0;
};
