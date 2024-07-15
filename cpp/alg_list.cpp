#include "alg_list.h"


/**
 * 删除链表中指定的节点。
 *
 * @param __data 要删除的节点的数据。
 */
template<typename T>
void Class_List<T>::Delete_Node(Node* __data) 
{
    Node* current = head;
    Node* prev = nullptr;

    while (current != nullptr) 
    {
        if (current == __data) 
        {
            if (prev == nullptr) 
            {
                head = current->next;
            } else 
            {
                prev->next = current->next;
            }

            delete current;
            return;
        }

        prev = current;
        current = current->next;
    }
}

/**
 * 在链表中搜索指定数据的节点。
 * 
 * @param __data 要搜索的数据
 * @return 如果找到了包含指定数据的节点，则返回该节点的指针；否则返回nullptr
 */
template<typename T>
typename Class_List<T>::Node* Class_List<T>::Search_Node(Node* __data) 
{
    Node* current = head;

    while (current != nullptr) {
        if (current == __data){
            return current;
        }
        current = current->next;
    }

    return nullptr;
}


/**
 * 向链表中添加节点。
 *
 * @param __data 要添加的节点的数据。
 */
template<typename T>
void Class_List<T>::Add_Node(T __data) 
{
    Node* newNode = new Node;
    newNode->data = __data;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
}

// int main() {
//     // Create an instance of Class_List with int as the template parameter

//     struct test_elemnt
//     {
//         int data;
//         char name[4];
//         int age;
//     } __attribute__((packed));

//     test_elemnt test1 =
//     {
//         10,
//         "abc",
//         20
//     };
//     test_elemnt test2 =
//     {
//         20,
//         "def",
//         30
//     };
//     test_elemnt test3 =
//     {
//         30,
//         "ghi",
//         40
//     };

//     Class_List<test_elemnt> myList;

//     // Add nodes to the list
//     myList.Add_Node(test1);
//     myList.Add_Node(test2);
//     myList.Add_Node(test3);

    // Search for a node with data 20
    //Class_List<test_elemnt>::Node* node = myList.Search_Node(test2);


    // Delete a node with data 20
    //myList.Delete_Node(test2);

    // Search for the deleted node
    //node = myList.Search_Node(test3);

//     return 0;
// }