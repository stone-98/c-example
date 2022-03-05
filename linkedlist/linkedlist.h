//
// Created by stone on 2022/2/14.
//

#ifndef C_EXAMPLE_LINKEDLIST_H
#define C_EXAMPLE_LINKEDLIST_H

typedef int datatype;

/**
 * 单向链表的实现
 * 第一个节点作为头节点不用来存储数据！
 * 数据结构：(节点)data:null,next->（节点）data:1,next->（节点）data:2,next:null
 */
typedef struct link_list_node {
    datatype data;
    struct link_list_node *next;
} linked_list_node;

/**
 * 创建链表
 * @return
 */
linked_list_node *linked_list_create();

/**
 * 指定下标插入节点
 * @param node
 * @param index
 * @param data
 * @return
 */
int linked_list_insert_at(linked_list_node *, int, datatype *);

/**
 * 链表的顺序插入[1,2,3,4,5],从小打到升序排列
 * @return
 */
int linked_list_order_insert(linked_list_node *, datatype *);

int linked_list_delete_at(linked_list_node *, int, datatype *);

int linked_list_delete(linked_list_node *, datatype *);

/**
 * 判断链表是否为空
 * @param node
 * @return
 */
_Bool linked_list_is_empty(linked_list_node *);

/**
 * 打印链表
 * @param node
 */
void linked_list_show(linked_list_node *);

void linked_list_destroy(linked_list_node *);

#endif //C_EXAMPLE_LINKEDLIST_H
