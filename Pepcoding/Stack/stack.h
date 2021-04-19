//industry level stack
//1. all data members should be private
//2. handle  all the exceptions
//3. oop's concept create microservices (break into function)
//(update easily possible)
//4. public->size,empty,push(data),pop,peak
//constructor->default,

// arr bool isEmpty int size return -1 void push int top return -1 int pop return -1
#include <bits/stdc++.h>
using namespace std;
class Stack
{
    int maxSize = 5;
    int *arr = new int(maxSize);
    int tos = -1;
    int noOfEle = 0;

public:
    Stack(){};
    Stack(int sz)
    {
        maxSize = sz;
    }
    bool isEmpty()
    {
        return noOfEle == 0;
    }
    int size()
    {
        return noOfEle;
    }
    void push(int data)
    {
        if (checkUB())
        {
            throw std::out_of_range("-1");
        }
        tos++;
        noOfEle++;
        arr[tos] = data;
    }
    bool checkLB()
    {
        if (tos == -1)
            return true;
        else
            return false;
    }

    bool checkUB()
    {
        if (tos == maxSize - 1)
            return true;
        else
            return false;
    }
    int top()
    {
        if (checkLB() || checkUB())
        {
            throw std::out_of_range("-1");
        }
        return arr[tos];
    }
    int pop()
    {
        if (checkLB())
        {
            throw std::out_of_range("-1");
        }
        int ans = arr[tos];
        tos--;
        noOfEle--;
        return ans;
    }
};

