//
// Created by stone on 2022/2/9.
//
#include "stdio.h"
#include "stdlib.h"
#include "list.h"

list *create() {
    list *list_p;
    list_p = malloc(sizeof(*list_p));
    if (list_p == NULL) {
        return NULL;
    }
    list_p->last = -1;
    return list_p;
}

void no_return_create(list **p) {
    *p = malloc(sizeof(**p));
    if (*p == NULL) {
        return;
    }
    (*p)->last = -1;
    return;
}


int insert(list *list_p, int i, datatype *data) {
    if (i >= DATE_SIZE - 1 || i < 0 || i > list_p->last + 1) {
        return -1;
    }

    int index;
    for (index = list_p->last; i <= index; index--) {
        list_p->data[index + 1] = list_p->data[index];
    }
    list_p->data[i] = *data;
    list_p->last++;
    return 1;
}

int delete(list *p, int i) {
    if (i < 0 || i > p->last) {
        return -1;
    }
    for (; i <= p->last; i++) {
        p->data[i] = p->data[i + 1];
    }
    p->last--;
    return 0;
}

int find(list *list_p, datatype *data) {
    if (is_empty(list_p) == 1)
        return -1;
    for (int i = 0; i <= list_p->last; i++) {
        if (list_p->data[i] == *data) {
            return i;
        }
    }
    return -1;
}

int is_empty(list *p) {
    return p->last == -1;
}

int set_empty(list *list_p) {
    list_p->last = -1;
    return 1;
}

int get_num(list *list_p) {
    return list_p->last++;
}

void show(list *list_p) {
    if (list_p->last < 0)
        return;
    for (int i = 0; i <= list_p->last; i++) {
        printf("%d\t", list_p->data[i]);
    }
    printf("\n");
    return;
}

int destroy(list *list_p) {
    free(list_p);
    return 1;
}

int list_union(list *list_p, list *union_list_p) {
    for (int i = 0; i <= (union_list_p->last); i++) {
        if (find(list_p, &union_list_p->data[i]) != 1) {
            insert(list_p, 0, &union_list_p->data[i]);
        }
    }
    return 1;
}