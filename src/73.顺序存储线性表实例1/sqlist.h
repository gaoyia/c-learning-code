#ifndef SQLIST_H__
#define SQLIST_H__
#define DATASIZE 5
typedef int datatype;

typedef struct sqlist
{
    datatype data[DATASIZE];
    int last;
} sqlist;

sqlist *sqlist_create();
void sqlist_create1(sqlist **space);

int sqlist_insert(sqlist *, int, datatype *);
int sqlist_delete(sqlist *, int);
int sqlist_find(sqlist *, datatype *);
int sqlist_is_empty(sqlist *);
int sqlist_set_empty(sqlist *);
int sqlist_get_length(sqlist *);
void sqlist_display(sqlist *);
int sqlist_destroy(sqlist *);

#endif