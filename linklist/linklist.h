//
// Created by stone on 2022/2/14.
//

#ifndef C_EXAMPLE_LINKLIST_H
#define C_EXAMPLE_LINKLIST_H

typedef int datatype;

typedef struct {
    datatype data;
    struct node *next;
} node;

node *l_create();

int l_insert(node *, int, datatype *);

int l_order_insert(node *, datatype *);

int l_delete_at(node *, int, datatype *);

int l_delete(node *, datatype *);

bool l_is_empty(node *);

void l_destroy();

#endif //C_EXAMPLE_LINKLIST_H
