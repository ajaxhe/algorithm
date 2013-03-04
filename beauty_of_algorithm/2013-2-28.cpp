/*
http://t.jobdu.com/thread-98640-1-1.html
设计一个栈，它可以在O(1)的时间内实现push，pop和min操作，所谓min操作就是得到栈中最小的元素。
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class MinStack
{
    const static int LEN = 128;
    int stack[LEN];
    int min_index_stack[LEN];
    int top;
    int min_index;

public:
    MinStack();
    void push(int v);
    int pop();
    int min();
    void print();
};

MinStack::MinStack()
{
    top = -1;
    min_index = -1;
}

void MinStack::push(int value)
{
    top++;
    if (top > LEN)
    {
        cout << "too many element in stack" << endl;
        return ;
    }

    stack[top] = value;
    if (top == 0)
        min_index = top;
    else
    {
        if (value < stack[min_index])
        {
            min_index = top;
        }
    }
    min_index_stack[top] = min_index;
}

int MinStack::pop()
{
    int res;
    if (top < 0)
    {
        cout << "empty stack, no more element to be pop" << endl;
        return -1;
    }

    res = stack[top--];
    return res;
}

int MinStack::min()
{
    return (stack[min_index_stack[top]]);
}

void MinStack::print()
{
    int i;
    for (i = top; i >= 0; i--)
        cout << stack[i] << ", " << stack[min_index_stack[i]] << endl;
}

int main()
{
    int i, len, min;
    MinStack s1;

    len = 10;
    srand((unsigned) time(0));
    for (i = 0; i < len; i++)
    {
        s1.push(rand() % 50);
    }
    cout << "origin stack is:\n";
    s1.print();
    cout << "pop operation:\n";
    for (i = len; i > 0; i--)
    {
        min = s1.min();
        cout << s1.pop() << ", " << min << endl;
    }

    return 0;
}
