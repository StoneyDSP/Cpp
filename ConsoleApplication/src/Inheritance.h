
#pragma once

#ifndef INHERITANCE_H_INCLUDED
#define INHERITANCE_H_INCLUDED

class Abstract
{
public:
    Abstract();
    virtual ~Abstract() = 0;
    virtual int getInt() = 0;

    int x;
};

class Base : public Abstract
{
public:
    Base(){ std::cout << "Constructed Base = " << sizeof(*this) << std::endl; }
    ~Base(){ std::cout << "Destroyed Base = " << sizeof(*this) << std::endl; }

    int getInt(){ return 1; }
    virtual double getDbl() { return 2.0; };

    int y;
};

class Derived final : public Base
{
public:
    Derived(){ std::cout << "Constructed Derived = " << sizeof(*this) << std::endl; }
    ~Derived(){ std::cout << "Destroyed Derived = " << sizeof(*this) << std::endl; }

    double getDbl() override { return 3.0; }

    int z;
};

Abstract::Abstract()  { std::cout << "Constructed Abstract = " << sizeof(*this) << std::endl; }
Abstract::~Abstract() { std::cout << "Destroyed Abstract = " << sizeof(*this) << std::endl; }

#endif // INHERITANCE_H_INCLUDED