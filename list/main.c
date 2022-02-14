#include <stdio.h>
#include "list.h"
#include "stdlib.h"

int main() {
    printf("init list_p and union_list_p.\n");
    list *list_p, *union_list_p;
    list_p = create(&list_p);
    union_list_p = create(&union_list_p);
    if (list_p == NULL) {
        fprintf(stderr, "create() list_p failed!");
        exit(1);
    }
    if (union_list_p == NULL) {
        fprintf(stderr, "create() union_list_p failed!");
        exit(1);
    }
    datatype arr[] = {11, 22, 33, 44, 55};
    datatype union_arr[] = {66, 77};
    for (int i = 0; i < sizeof(arr) / sizeof(*arr); i++) {
        insert(list_p, 0, &arr[i]);
    }

    for (int i = 0; i < sizeof(union_arr) / sizeof(*union_arr); i++) {
        insert(union_list_p, 0, &union_arr[i]);
    }
    printf("init success.\n\n\n");
    printf("printf list_p:\n");
    show(list_p);
    printf("printf union_list_p:\n");
    show(union_list_p);
    printf("printf finish.\n\n");
    printf("delete element.\n");
    delete(list_p, 0);
    printf("printf list_p after delete element.\n");
    show(list_p);
    printf("find %d in the list_p.\n", arr[0]);
    int i = find(list_p, &arr[0]);
    if (i < 0) {
        printf("find failed.\n");
    } else {
        printf("find success,i = %d\n", i);
    }
    printf("union list_p and union_list_p.\n");
    list_union(list_p, union_list_p);
    printf("printf list after union list_p and union_list_p:\n");
    show(list_p);
    printf("destroy");
    destroy(list_p);
    exit(0);
}
