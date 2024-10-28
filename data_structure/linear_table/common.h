#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#define MAX 10
#include <stdlib.h>

#define bool int

#include "struct.h"

int init_node(link_list *a)
{
    *a = (l_node *)malloc(sizeof(l_node));
    if (*a == NULL)
    {
        return 0;
    }
    (*a)->next = NULL;
    return 1;
}

bool get_item(l_node *a, int insert_address)
{
    int i = 1;
    l_node *p = a->next;
    if (insert_address < 1)
    {
        return 0;
    }
    if (insert_address == 0)
    {
        return 0;
    }
    // check
    while (p != NULL && i < insert_address)
    {
        p = p->next;
        i++;
    }
    return p->data;
}

link_list head_insert(link_list *l)
{
    /**
     * @brief 头插法
     *
     */
    // head insert
    l_node *list_node_pointer;
    int node_value;
    *l = (link_list)malloc(sizeof(l_node));
    (*l)->next = NULL; // must be null, fundamental of linked list
    scanf("%d", &node_value);
    while (node_value != 9999)
    {
        /**
         * @brief note
         *  结束代码为9999
         */
        list_node_pointer = (l_node *)malloc(sizeof(l_node));
        list_node_pointer->data = node_value;
        list_node_pointer->next = (*l)->next;
        (*l)->next = list_node_pointer;
        scanf("%d", &node_value);
    }
    return *l;
}

bool init_list_no_head(link_list *l)
{
    /**
     * @brief 无头结点的初始化
     *
     */
    *l = NULL;
    return 1;
}

bool init_list_with_head(link_list *l)
{
    /**
     * @brief 有头结点的初始化
     *
     */
    *l = (link_list)malloc(sizeof(l_node));
    if (*l == NULL)
    {
        return 0;
    }
    (*l)->next = NULL; // 确保下一节点为空
    return 1;
}

bool list_insert(link_list *l, int insert_address, int element_data)
{
    /**
     * @brief 在表insert_address处插入元素element_data(按地址插入,属于后插法)
     *  1. 从头结点开始，遍历到insert_address-1处
     *  2. 创建新节点
     *  3. 新节点的next指向当前节点的next,next可能存在后续节点
     *  4. 当前节点的next指向新节点
     *  5. 返回1
     *
     */
    if (insert_address < 1)
    {
        return 0;
    }
    // //check 头节点为空,如果为空创建一个真正意义上的空头结点
    // void func( )
    // {
    //     if (insert_address == 1)
    //     {
    //         /* code */
    //         l_node *new_node = (l_node *)malloc(sizeof(l_node));
    //         new_node->data = element_data;
    //         new_node->next = *l;
    //         *l = new_node;
    //         return 1;
    //     }
    // }

    // check
    l_node *current_node = *l; // l指向头结点，p指向当前节点
    int index = 0;             // 计数器，用于计数当前节点
    while (current_node != NULL && index < insert_address - 1)
    { // 循环到insert_address-1处
        current_node = current_node->next;
        index++;
    }
    // check
    if (current_node == NULL)
    {
        return 0;
    }

    l_node *new_node = (l_node *)malloc(sizeof(l_node)); // 新节点
    if (new_node == NULL)
    {
        return 0;
    }

    new_node->data = element_data;

    new_node->next = current_node->next;
    current_node->next = new_node;
    /**
     * @brief ! 注意
     *      1. new_node->next = current_node->next;
     *      2. current_node->next = new_node;
     */
    return 1;
}

bool insert_next(l_node *targetNode, int element_data)
{
    /**
     * @brief 在指定节点后插入元素，不需要元素地址
     *
     */
    l_node *new_node = (l_node *)malloc(sizeof(l_node));
    if (new_node == NULL)
    {
        return 0;
    }
    new_node->data = element_data;     // 新节点保存数据
    new_node->next = targetNode->next; // 新节点的next指向targetNode的next
    targetNode->next = new_node;
    return 1;
}
bool insert_prior(l_node *targetNode, l_node *new_node)
{
    /**
     * @brief 在指定节点前插入元素，不需要元素地址
     *
     */
    if (targetNode == NULL || new_node == NULL)
    {
        return 0;
    }
    new_node->next = targetNode->next; // 目标节点下一个指向新节点
    targetNode->next = new_node;       // 新节点指向目标节点

    int temp = targetNode->data; // 临时数据交换

    targetNode->data = new_node->data; // 新节点数据赋值给目标节点
    new_node->data = temp;             // 目标节点数据赋值给新节点

    return 1;
}

bool list_del(link_list *l, int insert_address, int *e)
{
    /**
     * @brief 按位序删除节点
     *
     */
    if (insert_address < 1)
    {
        return 0;
    }
    l_node *current_node = *l; // l指向头结点，p指向当前节点
    int count = 0;             // 计数器，用于计数当前current_node是第几个节点
    while (current_node != NULL && count < insert_address - 1)
    { // 循环到insert_address-1处
        current_node = current_node->next;
        count++;
    }
    // check
    if (current_node == NULL)
    {
        return 0;
    }
    if (current_node->next == NULL)
    {
        return 0;
        // 无节点可删除
    }

    l_node *del_node = current_node->next; // 令del_node指向要删除的节点
    if (del_node == NULL)
    {
        return 0;
    }
    *e = del_node->data;                 // 将要删除的节点的数据赋值给e
    current_node->next = del_node->next; // 删除节点 del_node
    free(del_node);                      // 释放del_node
    return 1;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief 按位查找,确认元素位置,根据元素地址返回变量
 *
 * @param lists
 * @param element_data
 * @return l_node*
 */
l_node *get_items(link_list lists, int element_data)
{
    if (element_data < 0)
    {
        return NULL;
    }
    l_node *active_node = lists;
    while (active_node != NULL && active_node->data < element_data)
    {
        active_node = active_node->next; // 更新节点下一个值权重
    }
    return active_node;
}

/**
 * @brief Get the item by value object
 *
 *  按值查找,确认元素位置,根据元素地址返回链表元素
 * @param list
 * @param element_data
 * @return l_node*
 */
l_node *get_item_by_value(link_list list, int element_data)
{
    l_node *active_node = list;
    while (active_node != NULL && active_node->data != element_data) // 遍历链表,确认值和元素相同
    {
        active_node = active_node->next;
    }
    return active_node;
}

/**
 * @brief 计数链表长度
 *
 * 遍历链表,计数链表长度
 * @param list
 * @return int
 */
int length(link_list link_list)
{
    int length = 0;
    l_node *active_node = link_list;
    while (active_node != NULL)
    {
        active_node = active_node->next;
        length++;
    }
    return length;
}
/**
 * @brief 头插法(默认为尾插法)
 *
 * @param target_node
 * @param element_data
 * @return int
 */
int insert_next_node_prior(l_node target_node, int element_data)
{
    l_node *new_node = (l_node *)malloc(sizeof(l_node));
    if (new_node == NULL)
    {
        return 0;
    }
    new_node->data = element_data;
    new_node->next = target_node.next;
    target_node.next = new_node;
    return 1;
}

link_list *list_head_insert(link_list link_list)
{
    l_node *list_node_pointer;
    int node_value;
    link_list = malloc(sizeof(l_node));
    link_list->next = NULL;
    scanf("%d", &node_value);
    while (node_value != 9999)
    {
        list_node_pointer = (l_node *)malloc(sizeof(l_node));       // 为新节点分配内存
        list_node_pointer->data = node_value;                // 为新节点赋值    
        list_node_pointer->next = link_list->next;      // 新节点的next指向头结点的next
        link_list->next = list_node_pointer;        // 头结点的next指向新节点
        scanf("%d", &node_value);
    }
    return link_list;
}
#endif // COMMON_H