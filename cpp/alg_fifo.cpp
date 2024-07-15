#include "alg_fifo.h"


template <typename T>
Class_Fifo<T>::Class_Fifo(int __max_element_number)
{
    Fifo.element_byte_size = sizeof(T);
    // 判断是否超出堆内存最大长度
    if (Fifo.element_byte_size * __max_element_number > MAX_BYTE_SIZE)
    {
        while(1){} //超过最大长度
    }
    else
    {
        Fifo.element_byte_size = sizeof(T);
        Fifo.max_element_number = __max_element_number;
    }
    if (Fifo.pdata = (u8 *)malloc(Fifo.element_byte_size * Fifo.max_element_number))
    {
        memset(Fifo.pdata, 0, Fifo.element_byte_size * Fifo.max_element_number);
        Fifo.front_index = 0;
        Fifo.rear_index = 0;
        Fifo.count = 0;
    }
    else
    {
        while(1){} //内存分配失败
    }
}


/**
 * 初始化循环FIFO。
 *
 * @param __max_element_number 循环FIFO的最大元素数量。
 */
template <typename T>
void Class_Fifo<T>::Fifo_Init(int __max_element_number)
{
    Fifo.element_byte_size = sizeof(T);
    // 判断是否超出堆内存最大长度
    if (Fifo.element_byte_size * __max_element_number > MAX_BYTE_SIZE)
    {
        while(1){} //超过最大长度
    }
    else
    {
        Fifo.element_byte_size = sizeof(T);
        Fifo.max_element_number = __max_element_number;
    }
    if (Fifo.pdata = (u8 *)malloc(Fifo.element_byte_size * Fifo.max_element_number))
    {
        memset(Fifo.pdata, 0, Fifo.element_byte_size * Fifo.max_element_number);
        Fifo.front_index = 0;
        Fifo.rear_index = 0;
        Fifo.count = 0;
    }
    else
    {
        while(1){} //内存分配失败
    } 
}

/**
 * 检查循环FIFO是否已满。
 *
 * @param Fifo 要检查的循环FIFO。
 * @return 如果FIFO已满，则返回1；否则返回0。
 */
template <typename T>
u8 Class_Fifo<T>::Fifo_Is_Full()
{
    return Fifo.count == Fifo.max_element_number;
}

/**
 * 检查循环FIFO是否为空。
 *
 * @param Fifo 要检查的循环FIFO。
 * @return 如果FIFO为空，则返回1；否则返回0。
 */
template <typename T>
u8 Class_Fifo<T>::Fifo_Is_Empty()
{
    return Fifo.count == 0;
}

/**
 * 将一个元素入队列。
 *
 * @param pitem 要入队列的元素。
 */
template <typename T>
Enum_Fifo_Status Class_Fifo<T>::Fifo_Enqueue(T pitem)
{
    if (Fifo_Is_Full())
    {
        memcpy(Fifo.pdata + Fifo.rear_index * Fifo.element_byte_size, &pitem, Fifo.element_byte_size); // 入队列
        Fifo.rear_index = (Fifo.rear_index + 1) % Fifo.max_element_number;
        Fifo.front_index = (Fifo.front_index + 1) % Fifo.max_element_number;
    }
    else
    {
        memcpy(Fifo.pdata + Fifo.rear_index * Fifo.element_byte_size, &pitem, Fifo.element_byte_size); // 入队列
        Fifo.rear_index = (Fifo.rear_index + 1) % Fifo.max_element_number;
        Fifo.count++;
    }
    return FIFO_OK;
}


/**
 * 将一个元素出队列。
 *
 * @param pitem 用于存储出队列元素的缓冲区。
 * @return 如果成功出队列，则返回1；否则返回0。
 */
template <typename T>
Enum_Fifo_Status Class_Fifo<T>::Fifo_Dequeue(T& pitem)
{

    if (Fifo_Is_Empty())
    {
        return FIFO_ERROR;
    }
    else
    {
        memcpy(&pitem, Fifo.pdata + Fifo.front_index * Fifo.element_byte_size, Fifo.element_byte_size); // 出队列
        Fifo.front_index = (Fifo.front_index + 1) % Fifo.max_element_number;
        Fifo.count--;
        return FIFO_OK;
    }
}


// int main() {
//     // Create a FIFO object
//     Class_Fifo<int> fifo(3);

//     int item = 10;
//     // Test enqueue operation
//     fifo.Fifo_Enqueue(item);
//     fifo.Fifo_Enqueue(20);
//     fifo.Fifo_Enqueue(30);
//     fifo.Fifo_Enqueue(40);

//     // // Test dequeue operation
//     int item1, item2, item3, item4;
//     fifo.Fifo_Dequeue(item1);
//     fifo.Fifo_Dequeue(item2);
//     fifo.Fifo_Dequeue(item3);
//     fifo.Fifo_Dequeue(item4);

//     return 0;
// }