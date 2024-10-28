#ifndef LINK_LIST_H
#define LINK_LIST_H
// 为了将结构体和类型定义作为宏导入导出，可以使用条件编译来确保头文件只被包含一次，并且可以通过定义导出宏来控制导出

#ifdef EXPORTING_LINK_LIST
#define LINK_LIST_API __declspec(dllexport)
#else
#define LINK_LIST_API __declspec(dllimport)
#endif

/**
 * @brief 链表结构体
 *
 * l_node 节点
 * link_list 链表指针
 *  l_node` 是 `struct l_node` 的别名
 *  data 数据域
 *  next 指针域
 */
typedef struct l_node
{
    int data;
    struct l_node *next; // 指向下一个结构体l_node的指针,起到连接作用
} l_node, *link_list;
/**
 * @brief 双向链表
 *  d_node 节点
 *
 *  d_link_list 链表指针
 *
 *  d_node` 是 `struct d_node` 的别名
 * 
 *  data 数据域
 * 
 *  prior 指向前一个结构体d_node的指针
 * 
 *  next 指向下一个结构体d_node的指针
 *
 */
typedef struct d_node
{
    int data;
    struct d_node *prior;
    struct d_node *next;
} d_node, *d_link_list;
#endif // LINK_LIST_H