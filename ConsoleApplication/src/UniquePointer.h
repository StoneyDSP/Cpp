/**
  ==============================================================================

    UniquePointer.h
    Created: 18 Jul 2022 18:42:29pm
    Author:  Nathan J. Hood
    Website: github.com/StoneyDSP
    email:   nathanjhood@googlemail.com

  ==============================================================================
*/

# pragma once

#include <iostream>

template<typename T>
class unique_ptr
{
    T* ptr;

public:
    //==========================================================================
    /** Default Constructor. */
    unique_ptr() : ptr(nullptr) 
    {
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Default Constructor!" << std::endl;
        assertion();
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Default Constructed!" << std::endl;
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Value = " << *this << std::endl;
        std::cout << std::endl;
    }

    /** Initialized Constructor. **/
    explicit unique_ptr(T* source /*= nullptr*/) : ptr(source)
    {
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Initialized Constructor from address " << &source << " = " << source << "!" << std::endl;
        assertion();
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Initialized Constructed!" << std::endl;
        std::cout << &(*this) << " - " << typeid(*this).name() << " - initialValue = " << *this << std::endl;
        std::cout << std::endl;
    }

    /** Move Constructor. */
    unique_ptr(unique_ptr&& source) : ptr()  // note the rvalue reference
    {
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Move Constructor from address " << &otherValue << " = " << otherValue << "!" << std::endl;

        // Assign the class data members from the source object to the 
        // object that is being constructed:
        ptr = source.ptr;

        // Assign the data members of the source object to default values. 
        // This prevents the destructor from freeing resources (such as memory) 
        // multiple times:
        source.ptr = nullptr;

        assertion();
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Move Constructed!" << std::endl;
        std::cout << &(*this) << " - " << typeid(*this).name() << " = " << *this << std::endl;
        std::cout << std::endl;
    }

    /** Destructor. */
    ~unique_ptr()
    {
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Destructor!" << std::endl;

        delete ptr;

        std::cout << &(*this) << " - " << typeid(*this).name() << " - Destroyed!" << std::endl;
        std::cout << &(*this) << " - " << typeid(*this).name() << " = " << *this << std::endl;
        std::cout << std::endl;
    }

    void assertion() 
    { 
        assert(this->ptr != nullptr);
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Passed assertion check!" << std::endl;
    }

    //==========================================================================
    //
    T* operator->()
    {
        return ptr;
    }

    const T* operator->() const
    {
        return ptr;
    }

    T& operator*()
    {
        return *ptr;
    }

    const T& operator*() const
    {
        return *ptr;
    }

    //==========================================================================
    /** Assignment operator [MOVE]. */
    unique_ptr& operator=(unique_ptr&& source)   // note the rvalue reference
    {
        if (this != &source)    // beware of self-assignment
        {
            delete ptr;         // release the old resource

            ptr = source.ptr;   // acquire the new resource
            source.ptr = nullptr;
        }
        return *this;
    }
};

/** Make a unique_ptr */
template <class Type, class... Types>
unique_ptr<Type> make_unique(Types&&... Args)
{
    return unique_ptr<Type> (new Type(std::forward<Types>(Args)...));
}

//==============================================================================
template<typename T>
std::ostream& operator<<(std::ostream& ostream, unique_ptr<T>& source)
{
    ostream << source.operator->();

    return ostream;
}

template<typename T>
std::istream& operator>>(std::istream& istream, unique_ptr<T>& source)
{
  if(source.operator->() != nullptr)
    istream.setstate(std::ios::failbit);

  return istream;
}
