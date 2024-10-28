#include <stdio.h>
#define MAX 10

#define bool int
/**
 * @brief 顺序表
 * 
 */
typedef struct {
    int length;
    int value[MAX];
    //element Type []
} sq_list;

void init(sq_list *a)
{
    for (int i = 0; i < MAX; i++)
    {
        a->length = 0;
    }
    
}

bool insert_data(sq_list *a, int insert_address,int element_data){
    if (insert_address<1||insert_address>a->length+1)
    {
        return 0;
    }
    if (a->length>=MAX)
    {
        return 0;
    }
    //check
    for (int i=a->length;i>=insert_address;i--)
    {
        a->value[i]=a->value[i-1];
    }
    a->value[insert_address-1]=element_data;
    a->length++;
    return 1;
}

bool delete_data(sq_list *a, int insert_address)
{
    if (insert_address<1||insert_address>a->length||a->length==0)
    {
        return 0;
    }
    //check
    for (int j=insert_address;j<a->length;j++)
    {
        a->value[j-1]=a->value[j];  //地址偏移量为1，重新赋值元素
        a->length--;    //减去长度
    }
    return 1;
}

bool get_item(sq_list *a, int insert_address)
{
    //传入为虚拟元素地址,转换为地址偏移量
    return a->value[insert_address-1];
}

int locate_item(sq_list *a, int element_data)
{
    for (int i = 0; i < a->length; i++)
    {
        if (a->value[i]==element_data)
        {
            return i+1;
        }
    }
    return 0;
}
int main()
{
    sq_list a;
    init(&a);
    for (int i = 0; i < MAX; i++)
    {
        insert_data(&a, i+1, i+1);
    }
    printf("%d\n", get_item(&a, 5));
    printf("%d\n", locate_item(&a, 5));
    printf("%d\n", delete_data(&a, 5));

}
