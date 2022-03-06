//
// Created by stone on 2022/2/14.
//

#include "stdio.h"
#include "stdlib.h"
#include "linkedlist.h"

// TODO struct sizeof的 概念要了解清楚
int main() {
    datatype arr[] = {22, 11, 33, 44, 55};
    linked_list_node *list = linked_list_create();
    if (list == NULL)
        exit(1);
//    指定下标插入
//    for (int i = 0; i < sizeof(arr) / sizeof(*arr); i++) {
//        if (!linked_list_insert_at(list, i + 1, &arr[i])) exit(1);
//    }
    // 顺序插入
    for (int i = 0; i < sizeof(arr) / sizeof(*arr); i++) {
        if (!linked_list_order_insert(list, &arr[i])) exit(1);
    }
    linked_list_show(list);
    linked_list_delete(list, &arr[0]);
    printf("Prints after deleting element:\n");
    linked_list_show(list);
    int delete_value = 55;
    linked_list_delete_at(list, 1);
    printf("Prints after removing the specified subscript element:%d\n", delete_value);
    linked_list_show(list);
    linked_list_destroy(list);
    exit(0);
}
