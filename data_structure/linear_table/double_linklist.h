#ifndef DOUBLE_LINKLIST_H
#define DOUBLE_LINKLIST_H

#include <stdio.h>
#include "common.h"
#define bool int

/**
 * @brief 双向链表初始化
 * 
 * @param d_link_list 
 * @return true 
 * @return false 
 */
bool init_d_list(d_link_list *d_link_list)
{
    // d_link_list 等价于 d_node *
    d_node *temp = (d_node *) malloc(sizeof(d_node));
    if (temp == NULL)
    {
        return 0;
    }
    temp->prior = NULL;
    temp->next = NULL;
    *d_link_list = temp;
    return 1;
}

/**
 * @brief 在p结点之后插入s结点
 * 
 * @param prior_node 
 * @param next_node 
 * @return true 
 * @return false 
 */
bool insert_next_d_node(d_node *prior_node, d_node *next_node)
{
    if (prior_node == NULL || next_node == NULL)
    {
        return 0;
    }

    next_node->next = prior_node->next;

    if (prior_node->next != NULL)
    {   //检查p是否有后继节点
        prior_node->next->prior = next_node;
    }

    next_node->prior = prior_node;
    prior_node->next = next_node;

    return 1;
}

bool delete_d_node(d_node *d_nodes)
{
    if (d_nodes == NULL)
    {
        return 0;
    }
    d_node *node = d_nodes->next;
    d_nodes->next = node->next;
    if (node->next != NULL)
    {
        node->next->prior = d_nodes;
    }
    free(node);
    return 1;
}

bool destroy_d_list(d_link_list *d_link_list)
{
    while ((*d_link_list)->next != NULL)
    {
        delete_d_node(*d_link_list);
    }
    free(*d_link_list);
    *d_link_list = NULL;
    return 1;
}

//todo ...
// 后续遍历 前序遍历 前序遍历(跳过头节点)
#endif // DOUBLE_LINKLIST_H