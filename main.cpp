#include <iostream>
#include "stack.hpp"
#include "queue.hpp"
#include "list.hpp"
#include "tree.hpp"

using namespace std;

int main()
{
//    Stack<float> stack;
//    stack.push(9);
//    stack.push(5.55454);
//    stack.push(1.4);
//    stack.push(9.1574);
//    stack.push(25.74);
//    auto top = stack.top();
//    top = 10;
//    top = stack.top();
//    cout << stack.pop()<< endl;
//    cout << stack.pop()<< endl;
//    top = stack.pop();
//    cout << top<< endl;
//    stack.pop();
//    cout << stack.empty()<< endl;

//    Queue<float> queue;
//    queue.push(9);
//    queue.push(5.55454);
//    queue.push(9.1574);
//    queue.push(25.74);
//    queue.push(0.1574);
//    auto head = queue.head();
//    head = queue.pop();
//    cout << head<< endl;
//    auto tail = queue.tail();
//    cout << tail<< endl;
//    head = queue.pop();
//    cout << head<< endl;
//    cout << queue.pop()<< endl;
//    cout << queue.pop()<< endl;
//    cout << queue.empty()<< endl;

    List<float> list;
    list.push_back(9);
    list.push_back(5.55454);
    list.push_back(9.1574);
    list.push_back(25.74);
    list.push_back(0.1574);
    cout << list.pop_item(-1) << endl;
    cout << list.pop_item(-1) << endl;
    cout << list.pop_front() << endl;
    cout << list.pop_front() << endl;
    cout << list.pop_front() << endl;
    list.reverse();
    return 0;
}
