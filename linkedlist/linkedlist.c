//
// Created by stone on 2022/2/14.
//
#include <stdbool.h>
#include "linkedlist.h"
#include "stdio.h"
#include "stdlib.h"


linked_list_node *linked_list_create() {
    linked_list_node *node;
    node = malloc(sizeof(node));
    // 创建失败，则返回空
    if (node == NULL) {
        return NULL;
    }
    // 将node的next置为NULL
    node->next = NULL;
    return node;
}

int linked_list_insert_at(linked_list_node *node, int index, datatype *data) {
    // index不合法（因为头节点不用来存储数据，所以插入的index从1开始）
    if (index < 1) return -1;
    // 第一个节点作为头节点，不用来存储数据，所以从i = 1开始
    int i = 1;
    // 声明前置节点指针以及新创建节点的指针
    linked_list_node *pre_node = node, *new_node;
    // 两点：
    // 1：当i=index的时候跳出，相当于找到需要插入节点的前置节点，比如我们要插入的节点索引为1，那么当i等于1的时候。
    // 2：如果pre_node为空了，相当于index已经超出链表的界限了。
    while (i < index && pre_node != NULL) {
        pre_node = pre_node->next;
        i++;
    }
    if (pre_node) {
        // 创建新节点
        new_node = malloc(sizeof(new_node));
        // 创建链表失败
        if (new_node == NULL)return -1;
        // 新创建的节点的next指向前置节点的下一个节点
        new_node->next = pre_node->next;
        // 前置节点的下一个节点指向新创建的节点
        pre_node->next = new_node;
        // 将新创建的节点的data属性赋值
        new_node->data = *data;
        return 1;
    } else return -1;
}

int linked_list_order_insert(linked_list_node *node, datatype *data) {
    // 如果链表未被初始化直接返回
    if (node == NULL) {
        return 0;
    }
    // 声明新节点以及当前节点
    linked_list_node *new_node, *current_node = node;

    // 创建新节点
    new_node = malloc(sizeof(new_node));
    if (new_node == NULL)return 0;
    new_node->data = *data;
    new_node->next = NULL;

    // 两种情况
    // 1：找到大于data大于传入参数data的节点的上一个节点
    // 2：下一个节点为空
    // 无论哪种情况，只要找到了，就可以开始插入了
    while (current_node->next && (current_node->next->data > *data)) {
        current_node = current_node->next;
    }

    // 插入
    new_node->next = current_node->next;
    current_node->next = new_node;
    return 1;
}

int linked_list_delete_at(linked_list_node *node, int index) {
    // 如果链表为空，直接返回
    if (node == NULL) return 0;
    int i = 1;
    linked_list_node *pre_node = node;
    // 找到指定下标的元素
    while (i < index && pre_node->next != NULL) {
        pre_node = pre_node->next;
    }
    if (pre_node->next == NULL) return 0;
    // 删除
    linked_list_node *delete_target = pre_node->next;
    pre_node->next = delete_target->next;
    free(delete_target);
    delete_target = NULL;
    return 1;
}

int linked_list_delete(linked_list_node *node, datatype *data) {
    if (node == NULL) return 0;
    // 待删除节点的前置节点
    linked_list_node *pre_node = node;
    // 找到指定数据的节点
    while (pre_node->next && pre_node->next->data != *data) {
        pre_node = pre_node->next;
    }
    if (pre_node->next == NULL) return 0;
    // 删除节点
    linked_list_node *delete_target = pre_node->next;
    pre_node->next = delete_target->next;
    delete_target->next = NULL;
    free(delete_target);
    return 1;
}

bool linked_list_is_empty(linked_list_node *node) {
    // 如果next为空，则约定这个链表为空
    if (node->next == NULL) {
        return 1;
    }
    return 0;
}

void linked_list_show(linked_list_node *node) {
    // 如果链表为空直接返回
    if (linked_list_is_empty(node) == 1)return;
    linked_list_node *current_node = node->next;
    // 当前节点不为空才进行打印
    while (current_node != NULL) {
        printf("%d\t", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
    return;
}

void linked_list_destroy(linked_list_node *node) {
    free(node);
    node = NULL;
}
