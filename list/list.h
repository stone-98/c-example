//
// 顺序链表的定义
// Created by stone on 2022/2/9.
//

#ifndef C_EXAMPLE_LINKEDLIST_H
#define C_EXAMPLE_LINKEDLIST_H

#define DATE_SIZE 1024
typedef int datatype;

typedef struct node {
    datatype data[DATE_SIZE];
    int last;
} list;

list *create();

void no_return_create(list **);

int insert(list *, int i, datatype *);

int delete(list *, int i);

datatype find(list *, datatype *);

int is_empty(list *);

int set_empty(list *);

int get_num(list *);

void show(list *);

int destroy(list *);

int list_union(list *, list *);

#endif //C_EXAMPLE_LINKEDLIST_H
