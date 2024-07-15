#include "message.h"

#pragma pack(push, 1)
struct Data
{
  int score;
  int name;
  int age;
};
#pragma pack(pop)
int main() {

  // 创建消息中心实例
  Class_Message Message_Center;
  // 注册发布者 fisrt_pub_topic 是第一个发布者指针，topic是话题名，sizeof(Data)是消息数据长度
  Struct_Publisher* First_Pub_Topic = Message_Center.PubRegister("topic", sizeof(Data));
  // 注册订阅者 first_sub_topic 是第一个订阅者指针，topic是话题名，sizeof(Data)是消息数据长度
  Struct_Subscriber* First_Sub_Topic = Message_Center.SubRegister("topic", sizeof(Data));
  // 注册订阅者 second_sub_topic 是第二个订阅者指针，topic是话题名，sizeof(Data)是消息数据长度
  Struct_Subscriber* Second_Sub_Topic = Message_Center.SubRegister("topic", sizeof(Data));
  // 发布消息
  Data data1 = {100, 1, 20};
  // 根据发布者指针 和 数据发布消息
  Message_Center.PubPush_Message<Data>(First_Pub_Topic, data1);
  Data data2 = {100, 1, 21};
  Message_Center.PubPush_Message<Data>(First_Pub_Topic, data2);
  Data data3 = {100, 1, 22};
  Message_Center.PubPush_Message<Data>(First_Pub_Topic, data3);
  Data data4 = {100, 1, 23};
  Message_Center.PubPush_Message<Data>(First_Pub_Topic, data4);

  // 获取消息
  Data data_get;
  // 根据订阅者指针 和 数据获取消息
  Message_Center.SubGet_Message<Data>(First_Sub_Topic, data_get);
  Message_Center.SubGet_Message<Data>(First_Sub_Topic, data_get);
  Message_Center.SubGet_Message<Data>(First_Sub_Topic, data_get);
  Message_Center.SubGet_Message<Data>(First_Sub_Topic, data_get);
  Message_Center.SubGet_Message<Data>(First_Sub_Topic, data_get);
  Message_Center.SubGet_Message<Data>(Second_Sub_Topic, data_get);

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