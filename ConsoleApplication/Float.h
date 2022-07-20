
#pragma once

#include <assert.h>
#include <iostream>

#include "UniquePointer.h"

// Issues...
// 1. Implement Modulus Operators

class Float
{
public:
    //==========================================================================
    friend std::ostream& operator<<(std::ostream& ostream, Float& source);
    friend std::istream& operator>>(std::istream& istream, Float& source);
    //==========================================================================
    
    //==========================================================================
    //
    //  ACCESSOR FUNCTIONS
    //
    //==========================================================================
    
    //==========================================================================
    /** Returns the current value. */
    Float val() 
    {
        std::cout << &(*this) << " - Called function: Float val() = " << value << std::endl;

        return value;
    }

    /** Returns a reference to the current value. */
    Float& get() 
    {
        std::cout << &(*this) << " - Called function: Float& get() = " << *this << std::endl;

        return *this; 
    }

    /** Returns the address-of the current value. */
    Float* addressOf() 
    {
        std::cout << &(*this) << " - Called function: Float* addressOf() = " << &(*this) << std::endl;
        return &(*this);
    }

    /** Returns the size of the current value. */
    int sizeOf() 
    {
        std::cout << &(*this) << " - Called function: int sizeOf() = " << sizeof(*this) << std::endl;
        return sizeof(*this);
    }

    /** Member Access Operator. */
    Float* operator->()
    {

    }

    

    /** Prints information about this variable. */
    void info()
    {
        std::cout << &(*this) << " - info:" << std::endl;
        std::cout << &(*this) << " - value = " << *this << std::endl;
        std::cout << &(*this) << " - &value = " << &(*this) << std::endl;
        std::cout << std::endl;
    }

    /** Runs and prints a set of data checks on this variable. */
    void dataChecks()
    {
        std::cout << &(*this) << " - Data checks:" << std::endl;
        get();
        addressOf();
        sizeOf();
        std::cout << std::endl;
    }

    void booleanChecks(const Float& comparison = {0.789f})
    {
        std::cout << &(*this) << " - Boolean checks:" << std::endl;
        std::cout << std::endl;
        std::cout << "(value < "  << comparison.value << ") = " << (value <  comparison.value) << std::endl;
        std::cout << "(value > "  << comparison.value << ") = " << (value >  comparison.value) << std::endl;
        std::cout << "(value <= " << comparison.value << ") = " << (value <= comparison.value) << std::endl;
        std::cout << "(value >= " << comparison.value << ") = " << (value >= comparison.value) << std::endl;
        std::cout << "(value == " << comparison.value << ") = " << (value == comparison.value) << std::endl;
        std::cout << "(value != " << comparison.value << ") = " << (value != comparison.value) << std::endl;
        std::cout << std::endl;
    }
    //==========================================================================
    
    //==========================================================================
    //
    //  CONSTRUCTORS
    //
    //==========================================================================
    
    //==========================================================================
    /** Default Constructor. */
    Float()// : value()
    {
        std::cout << &(*this) << " - Called Default Constructor!" << std::endl;
        assertion();
        std::cout << &(*this) << " - Default Constructed!" << std::endl;
        std::cout << &(*this) << " - value = " << *this << std::endl;
        std::cout << std::endl;
    }

    /** Initialized Constructor. */
    Float(float initialValue) : value(initialValue)
    {
        std::cout << &(*this) << " - Called Initialized Constructor from address " << &initialValue << " = " << initialValue << "!" << std::endl;
        assertion();
        std::cout << &(*this) << " - Initialized Constructed!" << std::endl;
        std::cout << &(*this) << " - initialValue = " << *this << std::endl;
        std::cout << std::endl;
    }

    /** Copy Constructor. */
    Float(Float& newValue) : value()
    {
        std::cout << &(*this) << " - Called Copy Constructor from address " << &newValue << " = " << newValue.value << "!" << std::endl;
        *this = newValue;
        assertion();
        std::cout << &(*this) << " - Copy Constructed!" << std::endl;
        std::cout << &(*this) << " - newValue = " << *this << std::endl;
        std::cout << std::endl;
    }

    /** Copy Constructor (const). */
    Float(const Float& newValue) : value(newValue)
    {
        std::cout << &(*this) << " - Called Copy Constructor (const) from address " << &newValue << " = " << newValue.value << "!" << std::endl;
        *this = newValue;
        assertion();
        std::cout << &(*this) << " - Copy Constructed (const)!" << std::endl;
        std::cout << &(*this) << " - newValue = " << *this << std::endl;
        std::cout << std::endl;
    }

    /** Move Constructor. */
    Float(Float&& otherValue) : value()
    {
        std::cout << &(*this) << " - Called Move Constructor from address " << &otherValue << " = " << otherValue << "!" << std::endl;

        // Assign the class data members from the source object to the 
        // object that is being constructed:
        value = otherValue.value;

        // Assign the data members of the source object to default values. 
        // This prevents the destructor from freeing resources (such as memory) 
        // multiple times:
        otherValue.value = 0.0f;

        assertion();
        std::cout << &(*this) << " - Move Constructed!" << std::endl;
        std::cout << &(*this) << " = " << *this << std::endl;
        std::cout << std::endl;
    }

    /** Destructor. */
    ~Float() 
    {
        std::cout << &(*this) << " - Called Destructor!" << std::endl;
        std::cout << &(*this) << " - Destroyed!" << std::endl;
        std::cout << &(*this) << " = " << *this << std::endl;
        std::cout << std::endl;
    }

    //==========================================================================
    /** Assertions to check Constructor succeeded */
    void assertion() 
    { 
        assert(this);
        std::cout << &(*this) << " - Passed assertion check!" << std::endl;
    }
    //==========================================================================

    //==========================================================================
    //
    //  COPY & MOVE ASSIGNMENT OPERATORS
    //
    //==========================================================================

    //==========================================================================
    /** Copy Assignment Operator [=]. */
    Float& operator=(Float& newValue)
    {
        std::cout << &(*this) << " - Called Copy Assignment Operator [=] from address " << &newValue << " = " << newValue.value << std::endl;

        // Copy the data from the source object.
        this->value = newValue.value;
        return *this;
    }

    /** Copy Assignment Operator (const) [=]. */
    Float& operator=(const Float& newValue)
    {
        std::cout << &(*this) << " - Called Copy Assignment Operator (const) [=] from address " << &newValue << " = " << newValue.value << std::endl;
        // Copy the data from the source object.
        value = newValue.value;
        return *this;
    }

    /** Move Assignment Operator [=]. */
    Float& operator=(Float&& otherValue)
    {
        std::cout << &(*this) << " - Called Move Assignment Operator [=] from address " << &otherValue << " = " << otherValue.value;    

        //* Performs no operation if you try to assign the object to itself. */
        if (this != &otherValue)
        {
            // Call delete on pointers to free the resource


            // Copy the data from the source object.
            value = otherValue.value;

            // Release the data from the source object so that
            // the destructor does not free the memory multiple times.
            otherValue.value = 0.0f;

            std::cout << " - Move successfull!" << std::endl;
        }

        else
        {
            std::cout << " - Move failed!" << std::endl;
        }

        return *this;
    }
    //==========================================================================

    //==========================================================================
    //
    //  UNARY ARITHMETIC OPERATORS
    //
    //==========================================================================

    //==========================================================================
    /** Increment Prefix Operator [++]. */ 
    Float& operator++()
    {
        std::cout << &(*this) << " - Called Increment Prefix Operator [++]" << std::endl;
        std::cout << &(*this) << " - "<< this->value << "++ ";

        // do actual increment
        this->value++;

        std::cout << " = " << *this << std::endl;
        std::cout << std::endl;

        return *this;
    }

    /** Increment Postfix Operator [++]. */ 
    Float operator++(int)
    {
        std::cout << &(*this) << " - Called Increment Postfix Operator [++]" << std::endl;

        Float tmp = *this;
        ++*this;
        return tmp;
    }

    /** Decrement Prefix Operator [++]. */ 
    Float& operator--()
    {
        std::cout << &(*this) << " - Called Decrement Prefix Operator [--]" << std::endl;
        std::cout << &(*this) << " - "<< this->value << "-- ";

        // do actual increment
        this->value--;

        std::cout << " = " << *this << std::endl;
        std::cout << std::endl;

        return *this;
    }

    /** Decrement Postfix Operator [--]. */ 
    Float operator--(int)
    {
        std::cout << &(*this) << " - Called Decrement Postfix Operator [--]" << std::endl;

        Float tmp = *this;
        --*this;
        return tmp;
    }
    //==========================================================================

    //==========================================================================
    //
    //  BINARY ARITHMETIC OPERATORS
    //
    //==========================================================================

    //==========================================================================
    /** Addition Assignment Operator [+=]. */
    Float& operator+=(const Float& rhs)
    {
        std::cout << &(*this) << " - Called Addition Assignment Operator [+=] with address " << &rhs << " = " << rhs.value << std::endl;
        std::cout << &(*this) << " - " << this->value << " += ";

        /** actual addition of rhs to *this. */ 
        this->value += rhs.value;

        std::cout << rhs.value << " = " << *this << std::endl;
        std::cout << std::endl;

        return *this;
    }

    /** Subtraction Assignment Operator [-=]. */
    Float& operator-=(const Float& rhs)
    {
        std::cout << &(*this) << " - Called Subtraction Assignment Operator [-=] with address " << &rhs << " = " << rhs.value << std::endl;
        std::cout << &(*this) << " - " << this->value << " -= ";

        /** actual subtraction of rhs from *this */
        this->value -= rhs.value;

        std::cout << rhs.value << " = " << *this << std::endl;
        std::cout << std::endl;

        return *this;
    }

    /** Multiplication Assignment Operator [*=]. */
    Float& operator*=(const Float& rhs)
    {
        std::cout << &(*this) << " - Called Multiplication Assignment Operator [*=] with address " << &rhs << " = " << rhs.value << std::endl;
        std::cout << &(*this) << " - " << this->value << " *= ";

        /** Actual multiplication of rhs with *this */ 
        this->value *= rhs.value;

        std::cout << rhs.value << " = " << *this << std::endl;
        std::cout << std::endl;

        return *this;
    }

    /** Division Assignment Operator [/=]. */
    Float& operator/=(const Float& rhs)
    {
        std::cout << &(*this) << " - Called Division Assignment Operator [/=] with address " << &rhs << " = " << rhs.value << std::endl;
        std::cout << &(*this) << " - " << this->value << " /= ";

        /** actual division of rhs by *this */
        this->value /= rhs.value;

        std::cout << rhs.value << " = " << *this << std::endl;
        std::cout << std::endl;

        return *this;
    }
    //==========================================================================

    //==========================================================================
    //
    //  TYPE CONVERSION OPERATORS
    //
    //==========================================================================

    //==========================================================================
    /** Opertor int(). */
    operator int() const noexcept
    { 
        std::cout << &(*this) << " - Called operator int()" << std::endl;

        return this->value;
    }
    
    /** Operator bool(). */
    operator bool() const noexcept
    {
        std::cout << &(*this) << " - Called operator bool()" << std::endl;

        return this->value;
    }
    
    /** Operator float(). */
    operator float() const noexcept
    { 
        std::cout << &(*this) << " - Called Operator float()" << std::endl;

        return this->value;
    }

    /** Operator double(). */
    operator double() const noexcept
    { 
        std::cout << &(*this) << " - Called Operator double()" << std::endl; 

        return this->value;
    }
    //==========================================================================

private:
    //==========================================================================
    float value{0.0F};
};
//==============================================================================

//==============================================================================
//
//  BINARY ARITHMETIC OPERATOR NON-MEMBER FUNCTIONS
//
//==============================================================================

//==============================================================================
/** Addition Allocation Operator [+]. */
inline Float operator+(Float lhs, const Float& rhs)
{
    std::cout << &lhs << " - Called Addition Allocation Operator [+] with address " << &rhs << std::endl;

    /** Call to class member function */
    lhs += rhs; 
    return lhs;
}

/** Subtraction Allocation Operator [-]. */
inline Float operator-(Float lhs, const Float& rhs)
{
    std::cout << &lhs << " - Called Subtraction Allocation Operator [-] with address " << &rhs << std::endl;

    /** Call to class member function */
    lhs -= rhs; 
    return lhs;
}

/** Multiplication Allocation Operator [*]. */
inline Float operator*(Float lhs, const Float& rhs)
{
    std::cout << &lhs << " - Called Mutliplication Allocation Operator [*] with address " << &rhs << std::endl;

    /** Call to class member function */
    lhs *= rhs; 
    return lhs;
}

/** Division Allocation Operator [/]. */
inline Float operator/(Float lhs, const Float& rhs)
{
    std::cout << &lhs << " - Called Division Allocation Operator [/] with address " << &rhs << std::endl;

    /** Call to class member function */
    lhs *= rhs; 
    return lhs;
}
//==============================================================================

//==============================================================================
//
//  COMPARISON OPERATOR NON-MEMBER FUNCTIONS
//
//==============================================================================

//==============================================================================
inline bool operator==(const Float& lhs, const Float& rhs)
{
    /* do actual comparison */
    return (lhs==rhs) ? true : false;
}

inline bool operator!=(const Float& lhs, const Float& rhs)
{
    return !operator==(lhs,rhs);
}

inline bool operator< (const Float& lhs, const Float& rhs)
{
    /* do actual comparison */
    return (lhs<rhs) ? true : false;
}
inline bool operator> (const Float& lhs, const Float& rhs){return  operator< (rhs,lhs);}
inline bool operator<=(const Float& lhs, const Float& rhs){return !operator> (lhs,rhs);}
inline bool operator>=(const Float& lhs, const Float& rhs){return !operator< (lhs,rhs);}
//==============================================================================

//==============================================================================
//
//  IOSTREAM OPERATOR NON-MEMBER FUNCTIONS
//
//==============================================================================

//==============================================================================
inline std::ostream& operator<<(std::ostream& ostream, Float& source)
{
    ostream << source.value;

    return ostream;
}

inline std::istream& operator>>(std::istream& istream, Float& source)
{
  if(source)
    istream.setstate(std::ios::failbit);

  return istream;
}
//==============================================================================
