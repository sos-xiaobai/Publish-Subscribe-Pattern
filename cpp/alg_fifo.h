#ifndef ALG_FIFO_H
#define ALG_FIFO_H

#include <stdio.h>
#include <stdlib.h> // Include the header file for 'malloc'
#include <string.h>

#define MAX_BYTE_SIZE 512 // fifo可以申请的最大堆长度（单位Byte）

typedef char u8;

/**
 * @brief 队列操作状态
 * 
 */
enum Enum_Fifo_Status
{
    FIFO_ERROR = 0,
    FIFO_OK,
};

/**
 * @brief 循环队列结构体
 * 
 * @param pdata 队列首地址
 * @param element_byte_size 元素大小（单位Byte）
 * @param max_element_number 队列能装下的该元素最大个数
 * @param front_index 队头index
 * @param rear_index 队尾index
 * @param count 队列中元素个数
 */
struct CircularFifo
{
    u8 *pdata;             // 队列首地址
    int element_byte_size;  // 元素大小（单位Byte）
    int max_element_number; // 队列能装下的该元素最大个数
    int front_index;        // 队头index
    int rear_index;         // 队尾index
    int count;              // 队列中元素个数
} ;

template <typename T>
class Class_Fifo
{
    public:

        CircularFifo Fifo;

        Class_Fifo(int __max_element_number);

        u8 Fifo_Is_Full();
        u8 Fifo_Is_Empty();
        void Fifo_Init(int __max_element_number);
        Enum_Fifo_Status Fifo_Enqueue(T pitem);
        Enum_Fifo_Status Fifo_Dequeue(T& pitem);
};


#endif // ALG_FIFO_H

