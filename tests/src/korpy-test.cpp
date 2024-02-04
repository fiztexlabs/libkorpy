#include <libkorpy/korpy.h>
#include <iostream>

int main()
{
    double a[2] {};
    double o[2] {};

    callfunc("calc", o, a);
    callfunc("calc", o, a);

    std::cout << "out: " << o[0] <<std::endl;

    return 0;
}