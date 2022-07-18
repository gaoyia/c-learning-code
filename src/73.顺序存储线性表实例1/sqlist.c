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
    if (i < 0 || i > list->last)
    {
        return -1;
    }
    for (int j = i; j < list->last; j++)
    {
        list->data[j] = list->data[j + 1];
    }

    list->last = list->last - 1;
    return 0;
};

int sqlist_find(sqlist *list, datatype *data)
{
    if (sqlist_is_empty(list) == 0)
    {
        return -1;
    }
    for (int i = 0; i <= list->last; i++)
    {
        if (list->data[i] == *data)
        {
            return i;
        }
    }
    return -1;
};

int sqlist_is_empty(sqlist *list){
    if (list->last == -1)
    {
        return 0;
    }
    else
    {
        return 1;
    }
};

int sqlist_set_empty(sqlist *list){
    list->last = -1;
    return 0;
};

int sqlist_get_length(sqlist *list){
    return (list->last + 1);
};

void sqlist_display(sqlist *list)
{
    printf("\n--------sqlist_display-------\n");

    for (int i = 0; i <= list->last; i++)
    {
        printf("data(%d)\n", list->data[i]);
    }
    printf("---------end:length(%d)--------\n", sqlist_get_length(list));
};

int sqlist_destroy(sqlist *list)
{
    free(list);
    return 0;
};

int sqlist_union(sqlist *list1, sqlist *list2)
{
    for (int i = 0; i <= list2->last; i++)
    {
        if (sqlist_find(list1, &(list2->data[i])) < 0)
        {
            sqlist_insert(list1, list1->last + 1, &(list2->data[i]));
        }
    }
};