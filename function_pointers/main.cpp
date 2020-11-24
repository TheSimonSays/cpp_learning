#include <iostream>
#include <functional>
#include "arithmetics.h"

// typedef int(*fcnPtr)(int, int);
typedef std::function<int(int, int)> fcnPtr;

int getInteger()
{
    int x;
    std::cout << "Enter integer: ";
    std::cin >> x;
    return x;
}

char getOperator()
{
    char op;
    do
    {
        std::cout << "Enter operator: ";
        std::cin >> op;
    } while (op != '+' && op != '-' && op != '*' && op != '/');
    return op;
}

struct arithmeticStruct
{
    char op;
    fcnPtr fn;
};

arithmeticStruct arithmeticArray[] {
    { '+', Arithmetics::add },
    { '-', Arithmetics::subtract },
    { '*', Arithmetics::multiple },
    { '/', Arithmetics::divide }
};

fcnPtr getArithmeticsFcn(char op)
{
    for (auto &i : arithmeticArray)
    {
        if (op == i.op)
            return i.fn;
    }
    return Arithmetics::add;
}

int main(int argc, char const *argv[])
{
    int x = getInteger();
    char op = getOperator();
    int y = getInteger();
    fcnPtr fcn = getArithmeticsFcn(op);
    std::cout << x << " " << op << " " << y <<  " = " << fcn(x, y) << "\n";
    return 0;
}
