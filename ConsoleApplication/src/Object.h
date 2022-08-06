
#pragma once

class Object
{
public:
    Object();
    ~Object();
    int x, y, z;

    int func()
    {
        return 0;
    }

    // int = 0;

    int funcTwo(const int& a)
    {
        return a;
    }

    // int = x;
};
