
#pragma once

#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED

template <typename Type>
class Object
{
public:
    Object() : x(), y(), z() {}
    explicit Object(Type a, Type b, Type c) : x(a), y(b), z(c) {}
    explicit Object(Type* a, Type* b, Type* c) : x(*a), y(*b), z(*c) {}
    explicit Object(Type& a, Type& b, Type& c) : x(a), y(b), z(c) {}
    explicit Object(Type&& a, Type&& b, Type&& c) : x(a), y(b), z(c) {}
    explicit Object(Value<Type> a, Value<Type> b, Value<Type> c) : x(a), y(b), z(c) {}
    explicit Object(Value<Type>* a, Value<Type>* b, Value<Type>* c) : x(*a), y(*b), z(*c) {}
    explicit Object(Value<Type>& a, Value<Type>& b, Value<Type>& c) : x(a), y(b), z(c) {}
    explicit Object(Value<Type>&& a, Value<Type>&& b, Value<Type>&& c) : x(a), y(b), z(c) {}
    ~Object(){}

private:
    Value<Type> x;
    Value<Type> y;
    Value<Type> z;
};

#endif // OBJECT_H_INCLUDED
