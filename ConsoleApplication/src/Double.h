/**
  ==============================================================================

    Float.h
    Created: 16 Jul 2022 12:58:03am
    Author:  Nathan J. Hood
    Website: github.com/StoneyDSP
    email:   nathanjhood@googlemail.com

  ==============================================================================
*/

#pragma once

#include <assert.h>
#include <iostream>
#include <typeinfo>

#include "Value.h"

//#include "UniquePointer.h"

class Double : public Value<double>
{
public:
    //==========================================================================
    
    //==========================================================================
    //
    //  CONSTRUCTORS
    //
    //==========================================================================
    
    //==========================================================================
    /** Default Constructor. */
    Double() : Value()
    {
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Default Constructor!" << std::endl;
        assertion();
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Default Constructed!" << std::endl;
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Value = " << *this << std::endl;
        std::cout << std::endl;
        info();
        std::cout << std::endl;
    }

    /** Initialized Constructor*. */
    Double(double initialValue) : Value(initialValue)
    {
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Initialized Constructor from address " << &initialValue << " = " << initialValue << "!" << std::endl;
        assertion();
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Initialized Constructed!" << std::endl;
        std::cout << &(*this) << " - " << typeid(*this).name() << " - initialValue = " << *this << std::endl;
        std::cout << std::endl;
        info();
        std::cout << std::endl;
    }

    /** Initialized Constructor. */
    Double(double* initialValue) : Value(*(initialValue))
    {
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Initialized Constructor* from address " << &initialValue << " = " << initialValue << "!" << std::endl;
        assertion();
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Initialized Constructed!" << std::endl;
        std::cout << &(*this) << " - " << typeid(*this).name() << " - initialValue = " << *this << std::endl;
        std::cout << std::endl;
        info();
        std::cout << std::endl;
    }

    /** Copy Constructor. */
    Double(Double& newValue) : Value(newValue)
    {
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Copy Constructor from address " << &newValue << " = " << newValue.value << "!" << std::endl;
        *this = newValue;
        assertion();
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Copy Constructed!" << std::endl;
        std::cout << &(*this) << " - " << typeid(*this).name() << " - newValue = " << *this << std::endl;
        std::cout << std::endl;
        info();
        std::cout << std::endl;
    }

    /** Copy Constructor (const). */
    Double(const Double& newValue) : Value(newValue)
    {
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Copy Constructor (const) from address " << &newValue << " = " << newValue.value << "!" << std::endl;
        *this = newValue;
        assertion();
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Copy Constructed (const)!" << std::endl;
        std::cout << &(*this) << " - " << typeid(*this).name() << " - newValue = " << *this << std::endl;
        std::cout << std::endl;
        info();
        std::cout << std::endl;
    }

    /** Move Constructor. */
    Double(Double&& otherValue) : Value()
    {
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Move Constructor from address " << &otherValue << " = " << otherValue << "!" << std::endl;

        // Assign the class data members from the source object to the 
        // object that is being constructed:
        value = otherValue.value;

        // Assign the data members of the source object to default values. 
        // This prevents the destructor from freeing resources (such as memory) 
        // multiple times:
        otherValue.value = 0.0;

        assertion();
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Move Constructed!" << std::endl;
        std::cout << &(*this) << " - " << typeid(*this).name() << " = " << *this << std::endl;
        std::cout << std::endl;
        info();
        std::cout << std::endl;
    }

    /** Destructor. */
    ~Double() noexcept
    {
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Destructor!" << std::endl;
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Destroyed!" << std::endl;
        std::cout << &(*this) << " - " << typeid(*this).name() << " = " << *this << std::endl;
        std::cout << std::endl;
        info();
        std::cout << std::endl;
    }

    //==========================================================================
    /** Assertions to check Constructor succeeded */
    void assertion()
    { 
        assert(this);
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Passed assertion check!" << std::endl;
    }
    //==========================================================================

    //==========================================================================
    //
    //  COPY & MOVE ASSIGNMENT OPERATORS
    //
    //==========================================================================

    //==========================================================================
    /** Copy Assignment Operator [=]. */
    Double& operator=(Double& newValue)
    {
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Copy Assignment Operator [=] from address " << &newValue << " = " << newValue.value << std::endl;

        // Copy the data from the source object.
        this->value = newValue.value;
        return *this;
    }

    /** Copy Assignment Operator (const) [=]. */
    Double& operator=(const Double& newValue)
    {
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Copy Assignment Operator (const) [=] from address " << &newValue << " = " << newValue.value << std::endl;
        // Copy the data from the source object.
        value = newValue.value;
        return *this;
    }

    /** Move Assignment Operator [=]. */
    Double& operator=(Double&& otherValue)
    {
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Move Assignment Operator [=] from address " << &otherValue << " = " << otherValue.value;    

        //* Performs no operation if you try to assign the object to itself. */
        if (this != &otherValue)
        {
            // Call delete on pointers to free the resource


            // Copy the data from the source object.
            value = otherValue.value;

            // Release the data from the source object so that
            // the destructor does not free the memory multiple times.
            otherValue.value = 0.0;

            std::cout << " - Move successfull!" << std::endl;
        }

        else
        {
            std::cout << " - Move failed!" << std::endl;
        }

        return *this;
    }
    //==========================================================================

        

    friend std::ostream& operator<<(std::ostream& ostream, Double& source);
    friend std::istream& operator>>(std::istream& istream, Double& source);

    //const Value& val;
};
//==============================================================================

//==============================================================================
//
//  BINARY ARITHMETIC OPERATOR NON-MEMBER FUNCTIONS
//
//==============================================================================

//==============================================================================
/** Addition Allocation Operator [+]. */
inline Double operator+(Double lhs, const Double& rhs)
{
    std::cout << &lhs << " - " << typeid(&lhs).name() << " - Called Addition Allocation Operator [+] with address " << &rhs << std::endl;

    /** Call to class member function */
    lhs += rhs; 
    return lhs;
}

/** Subtraction Allocation Operator [-]. */
inline Double operator-(Double lhs, const Double& rhs)
{
    std::cout << &lhs << " - Called Subtraction Allocation Operator [-] with address " << &rhs << std::endl;

    /** Call to class member function */
    lhs -= rhs; 
    return lhs;
}

/** Multiplication Allocation Operator [*]. */
inline Double operator*(Double lhs, const Double& rhs)
{
    std::cout << &lhs << " - Called Mutliplication Allocation Operator [*] with address " << &rhs << std::endl;

    /** Call to class member function */
    lhs *= rhs; 
    return lhs;
}

/** Division Allocation Operator [/]. */
inline Double operator/(Double lhs, const Double& rhs)
{
    std::cout << &lhs << " - Called Division Allocation Operator [/] with address " << &rhs << std::endl;

    /** Call to class member function */
    lhs *= rhs; 
    return lhs;
}

//==============================================================================
inline std::ostream& operator<<(std::ostream& ostream, Double& source)
{
    ostream << source.value;

    return ostream;
}

inline std::istream& operator>>(std::istream& istream, Double& source)
{
  if(source.sizeOf() != 0)
    istream.setstate(std::ios::failbit);

  return istream;
}
//==============================================================================