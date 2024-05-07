#include <stdio.h>
#include "alg_fifo.h"

#pragma pack(1)
typedef struct 
{
    uint8_t data_1;
    uint8_t data_2;
    int data_3;
} Data;
#pragma pack()


int main() 
{
    Data data_input[5] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}, {13, 14, 15}};
    Data data_output[5] = {0};
    CircularFifo fifo;
    Fifo_Init(&fifo, sizeof(Data), 3);

    for (int i = 0; i < 5; i++) 
    {
        Fifo_Enqueue(&fifo, (uint8_t*)&data_input[i], sizeof(Data));
    }

    for (int i = 0; i < 5; i++) 
    {
        Fifo_Dequeue(&fifo, (uint8_t*)&data_output[i], sizeof(Data));
    }

    return 0;
}

/*

   █████▒█    ██  ▄████▄   ██ ▄█▀       ██████╗ ██╗   ██╗ ██████╗
 ▓██   ▒ ██  ▓██▒▒██▀ ▀█   ██▄█▒        ██╔══██╗██║   ██║██╔════╝
 ▒████ ░▓██  ▒██░▒▓█    ▄ ▓███▄░        ██████╔╝██║   ██║██║  ███╗
 ░▓█▒  ░▓▓█  ░██░▒▓▓▄ ▄██▒▓██ █▄        ██╔══██╗██║   ██║██║   ██║
 ░▒█░   ▒▒█████▓ ▒ ▓███▀ ░▒██▒ █▄       ██████╔╝╚██████╔╝╚██████╔╝
  ▒ ░   ░▒▓▒ ▒ ▒ ░ ░▒ ▒  ░▒ ▒▒ ▓▒       ╚═════╝  ╚═════╝  ╚═════╝
  ░     ░░▒░ ░ ░   ░  ▒   ░ ░▒ ▒░
  ░ ░    ░░░ ░ ░ ░        ░ ░░ ░
           ░     ░ ░      ░  ░

*/