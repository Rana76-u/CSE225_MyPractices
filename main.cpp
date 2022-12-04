#include <iostream>
#include <string.h>
#include "stacktype.h"
#include "stacktype.cpp"
using namespace std;

int PriorityChecker(char c)
{
    switch(c)
    {
    case '+':
        return 1;
        break;
    case '-':
        return 2;
        break;
    case '*':
        return 3;
        break;
    case '/':
        return 4;
        break;
    case '(':
        return 0;
        break;
    case ')':
        return 10;
        break;
    default:
        return 101;
    }
}

int main()
{
    StackType<string> postfix;
    StackType<string> Stack;
    string item;
    int i = 0;
    cout << "Enter an Expression: ";
    while(1>0)
    {
        cin >> item;
        if(item == "stop")
        {
            break;
        }
        else
        {
            int a = PriorityChecker(item[0]);
            string str;
            if(Stack.IsEmpty() == false){
                str = Stack.Top();
            }
            int b = PriorityChecker(str[0]);
            if(item[0] == '+' || item[0] == '-' || item[0] == '*' || item[0] == '/' || item[0] == '(')
            {
                if(Stack.IsEmpty() == false && a <= b)
                {
                    Stack.Push(item);
                }
                else if(Stack.IsEmpty() == false && a >= b)
                {
                    if(Stack.IsEmpty()){
                        Stack.Push(item);
                    }else{
                        postfix.Push(Stack.Top());
                        Stack.Pop();
                        Stack.Push(item);
                    }
                }
            }else if(item[0] == ')'){
                while(Stack.IsEmpty() == false && Stack.Top() != "("){
                    postfix.Push(Stack.Top());
                    Stack.Pop();
                }
                if(!Stack.IsEmpty()){
                    Stack.Pop();
                }
            }else{
                postfix.Push(item);
            }

        }
        i++;
    }

    for(int j=0; j<i+1; i++)
    {
        cout << postfix.Top() << " ";
        postfix.Pop();
    }
    return 0;
}

/*
if(check(item[0]) == 1)
            {
                if(item[0] == '+')
                {
                    if(Stack.Top() == "-")
                    {
                        postfix.Push(Stack.Top());
                        Stack.Pop();
                        Stack.Push("+");
                    }
                }
                else if(item[0] == '*')
                {
                    if(Stack.Top() == "/")
                    {
                        postfix.Push(Stack.Top());
                        Stack.Pop();
                        Stack.Push("*");
                    }
                }
                else
                {
                    Stack.Push(item);
                }
            }
            else
            {
                postfix.Push(item);
            }
*/
