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

#ifndef FLOAT_H_INCLUDED
#define FLOAT_H_INCLUDED

#include <assert.h>
#include <iostream>
#include <typeinfo>

//#include "UniquePointer.h"

// To-do...
// 1. Implement De-Reference Operators
// 2. Implement Dynamic Memory Operators [X]
// 3. Overhaul "typeID()" Operator(s) (how?)

//==============================================================================
/** Float value. */
class Float final
{
public:

    //==========================================================================
    //
    //  CONSTRUCTORS
    //
    //==========================================================================

    /** Default Constructor. */
    Float();

    /** Initialized Constructor. */
    Float(float initialValue);

    /** Initialized Constructor. */
    Float(float* initialValue);

    /** Copy Constructor. */
    Float(Float& newValue);

    /** Copy Constructor (const). */
    Float(const Float& newValue);

    /** Move Constructor. */
    Float(Float&& otherValue);

    /** Destructor. */
    ~Float() noexcept;

    //==========================================================================
    /** Assertions to check Constructor succeeded */
    void assertion();

    //==========================================================================
    //
    //  COPY & MOVE ASSIGNMENT OPERATORS
    //
    //==========================================================================

    /** Copy Assignment Operator [=]. */
    Float& operator=(Float& newValue);

    /** Copy Assignment Operator (const) [=]. */
    Float& operator=(const Float& newValue);

    /** Move Assignment Operator [=]. */
    Float& operator=(Float&& otherValue);

    //==========================================================================
    //
    //  UNARY ARITHMETIC OPERATORS
    //
    //==========================================================================

    /** Increment Prefix Operator [++]. */ 
    Float& operator++();

    /** Increment Postfix Operator [++]. */ 
    Float operator++(int);

    /** Decrement Prefix Operator [++]. */ 
    Float& operator--();

    /** Decrement Postfix Operator [--]. */ 
    Float operator--(int);

    //==========================================================================
    //
    //  BINARY ARITHMETIC OPERATORS
    //
    //==========================================================================

    /** Addition Assignment Operator [+=]. */
    Float& operator+=(const Float& rhs);

    /** Subtraction Assignment Operator [-=]. */
    Float& operator-=(const Float& rhs);

    /** Multiplication Assignment Operator [*=]. */
    Float& operator*=(const Float& rhs);

    /** Division Assignment Operator [/=]. */
    Float& operator/=(const Float& rhs);

    //==========================================================================
    //
    //  TYPE CONVERSION OPERATORS
    //
    //==========================================================================

    /** Opertor int(). */
    operator int() const noexcept;
    
    /** Operator bool(). */
    operator bool() const noexcept;
    
    /** Operator float(). */
    operator float() const noexcept;

    /** Operator double(). */
    operator double() const noexcept;

    //==========================================================================
    //
    //  DYNAMIC MEMORY OPERATORS
    //
    //==========================================================================

    /** Operator New. */
    static void* operator new(std::size_t count);

    /** Operator Delete. */
    static void  operator delete(void* ptr);

    /** Operator New Array. */
    static void* operator new[](std::size_t count);

    /** Operator Delete Array. */
    static void  operator delete[](void* ptr);

    /** Operator New Placement. */
    static void* operator new(std::size_t count, void* p);

    /** Operator Delete Placement. */
    static void  operator delete(void* ptr, void* p);

    /** Operator New Array Placement. */
    static void* operator new[](std::size_t count,void* p);

    /** Operator Delete Array Placement. */
    static void  operator delete[](void* ptr, void* p);
    
    //==========================================================================
    //
    //  ACCESSOR FUNCTIONS
    //
    //==========================================================================
    
    /** Returns the current value. */
    Float val();

    /** Returns a reference to the current value. */
    Float& get();

    /** Returns the address-of the current value. */
    Float* addressOf();

    /** Returns the size of the current value. */
    int sizeOf();

    /** Returns the type info of this variable. */
    const type_info& typeID();

    /** Returns the name of this variable. */
    const char* name() const noexcept;

    /** Returns the raw name of this variable. */
    const char* raw_name() const noexcept;

    /** Returns the hash code of this variable. */
    size_t hash_code() const noexcept;

    /** typeid().before() Operator. */
    bool before(const type_info &_otherValue);
    
    /** Prints information about this variable. */
    void info();

    /** Runs and prints a set of data checks on this variable. */
    void dataChecks();

    /** Runs and prints a set of boolean checks on this variable. */
    void booleanChecks(const Float& comparison = {0.789f});

    friend std::ostream& operator<<(std::ostream& ostream, Float& source);

    friend std::istream& operator>>(std::istream& istream, Float& source);

private:
    //==========================================================================
    //
    //  DATA MEMBERS
    //
    //==========================================================================
    /** Value. */
    float* value {nullptr};
};
//==============================================================================

#endif // FLOAT_H_INCLUDED

//==============================================================================
//
//  BINARY ARITHMETIC OPERATOR NON-MEMBER FUNCTIONS
//
//==============================================================================

//==============================================================================
/** Addition Allocation Operator [+]. */
inline Float operator+(Float lhs, const Float& rhs);

/** Subtraction Allocation Operator [-]. */
inline Float operator-(Float lhs, const Float& rhs);

/** Multiplication Allocation Operator [*]. */
inline Float operator*(Float lhs, const Float& rhs);

/** Division Allocation Operator [/]. */
inline Float operator/(Float lhs, const Float& rhs);

//==============================================================================

//==============================================================================
//
//  COMPARISON OPERATOR NON-MEMBER FUNCTIONS
//
//==============================================================================

//==============================================================================
/** Equality Comparison Operator [==]. */
inline bool operator==(const Float& lhs, const Float& rhs);

/** Inequality Comparison Operator [!=]. */
inline bool operator!=(const Float& lhs, const Float& rhs);

/** Less-Than Comparison Operator [<]. */
inline bool operator< (const Float& lhs, const Float& rhs);

/** Greater-Than Comparison Operator [>]. */
inline bool operator> (const Float& lhs, const Float& rhs);

/** Less-Than or Equal-To Comparison Operator [<=]. */
inline bool operator<=(const Float& lhs, const Float& rhs);

/** Greater-Than or Equal-To Comparison Operator [>=]. */
inline bool operator>=(const Float& lhs, const Float& rhs);
//==============================================================================

//==============================================================================
//
//  IOSTREAM OPERATOR NON-MEMBER FUNCTIONS
//
//==============================================================================

//==============================================================================
/** Prints information about this variable to Terminal. */
inline std::ostream& operator<<(std::ostream& ostream, Float& source);

/** Prints information about this variable to Terminal. */
inline std::istream& operator>>(std::istream& istream, Float& source);
//==============================================================================

//==============================================================================

//==============================================================================
//
//  CONSTRUCTORS
//
//==============================================================================

//==============================================================================

//==============================================================================
/** Assertions to check Constructor succeeded */
inline void Float::assertion()
{ 
    assert(this);
    std::cout << &(*this) << " - " << typeid(*this).name() << " - Passed assertion check!" << std::endl;
}


//==============================================================================
//
//  BINARY ARITHMETIC OPERATORS
//
//==============================================================================

//==============================================================================
/** Addition Assignment Operator [+=]. */
inline Float& Float::operator+=(const Float& rhs)
{
    std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Addition Assignment Operator [+=] with address " << &rhs << " = " << rhs.value << std::endl;
    std::cout << &(*this) << " - " << typeid(*this).name() << " - " << this->value << " += ";

    /** actual addition of rhs to *this. */ 
    value += rhs.value;

    std::cout << rhs.value << " = " << *this << std::endl;
    std::cout << std::endl;

    return *this;
}

/** Addition Allocation Operator [+]. */
inline Float operator+(Float lhs, const Float& rhs)
{
    std::cout << &lhs << " - " << typeid(&lhs).name() << " - Called Addition Allocation Operator [+] with address " << &rhs << std::endl;

    /** Call to class member function */
    lhs += rhs; 
    return lhs;
}

/** Subtraction Assignment Operator [-=]. */
inline Float& Float::operator-=(const Float& rhs)
{
    std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Subtraction Assignment Operator [-=] with address " << &rhs << " = " << rhs.value << std::endl;
    std::cout << &(*this) << " - " << typeid(*this).name() << " - " << this->value << " -= ";

    /** actual subtraction of rhs from *this */
    value -= rhs.value;

    std::cout << rhs.value << " = " << *this << std::endl;
    std::cout << std::endl;

    return *this;
}

/** Subtraction Allocation Operator [-]. */
inline Float operator-(Float lhs, const Float& rhs)
{
    std::cout << &lhs << " - Called Subtraction Allocation Operator [-] with address " << &rhs << std::endl;

    /** Call to class member function */
    lhs -= rhs; 
    return lhs;
}

/** Multiplication Assignment Operator [*=]. */
inline Float& Float::operator*=(const Float& rhs)
{
    std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Multiplication Assignment Operator [*=] with address " << &rhs << " = " << rhs.value << std::endl;
    std::cout << &(*this) << " - " << typeid(*this).name() << " - " << this->value << " *= ";

    /** Actual multiplication of rhs with *this */ 
    value *= rhs.value;

    std::cout << rhs.value << " = " << *this << std::endl;
    std::cout << std::endl;

    return *this;
}

/** Multiplication Allocation Operator [*]. */
inline Float operator*(Float lhs, const Float& rhs)
{
    std::cout << &lhs << " - Called Mutliplication Allocation Operator [*] with address " << &rhs << std::endl;

    /** Call to class member function */
    lhs *= rhs; 
    return lhs;
}

/** Division Assignment Operator [/=]. */
inline Float& Float::operator/=(const Float& rhs)
{
    std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Division Assignment Operator [/=] with address " << &rhs << " = " << rhs.value << std::endl;
    std::cout << &(*this) << " - " << typeid(*this).name() << " - " << this->value << " /= ";

    /** actual division of rhs by *this */
    value /= rhs.value;

    std::cout << rhs.value << " = " << *this << std::endl;
    std::cout << std::endl;

    return *this;
}

/** Division Allocation Operator [/]. */
inline Float operator/(Float lhs, const Float& rhs)
{
    std::cout << &lhs << " - Called Division Allocation Operator [/] with address " << &rhs << std::endl;

    /** Call to class member function */
    lhs /= rhs; 
    return lhs;
}
//==============================================================================

//==============================================================================
//
//  TYPE CONVERSION OPERATORS
//
//==============================================================================

//==============================================================================
/** Conversion Operator int(). */
inline Float::operator int() const noexcept
{ 
    std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Conversion Operator int()" << std::endl;

    return static_cast<int>(value);
}

/** Conversion Operator bool(). */
inline Float::operator bool() const noexcept
{
    std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Conversion Operator bool()" << std::endl;

    return value;
}

/** Conversion Operator float(). */
inline Float::operator float() const noexcept
{ 
    std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Conversion Operator float()" << std::endl;

    return value;
}

/** Conversion Operator double(). */
inline Float::operator double() const noexcept
{ 
    std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Conversion Operator double()" << std::endl; 

    return value;
}
//==============================================================================

//==============================================================================
//
//  COMPARISON OPERATORS
//
//==============================================================================

//==============================================================================
/** Equality Comparison Operator [==]. */
inline bool operator==(const Float& lhs, const Float& rhs)
{
    /* do actual comparison */
    return (lhs == rhs) ? true : false;
}

/** Inequality Comparison Operator [!=]. */
inline bool operator!=(const Float& lhs, const Float& rhs)
{
    return !operator==(lhs, rhs);
}

/** Less-Than Comparison Operator [<]. */
inline bool operator< (const Float& lhs, const Float& rhs)
{
    /* do actual comparison */
    return (lhs < rhs) ? true : false;
}

/** Greater-Than Comparison Operator [>]. */
inline bool operator> (const Float& lhs, const Float& rhs)
{
    return  operator< (rhs, lhs);
}

/** Less-Than or Equal-To Comparison Operator [<=]. */
inline bool operator<=(const Float& lhs, const Float& rhs)
{
    return !operator> (lhs,rhs);
}

/** Greater-Than or Equal-To Comparison Operator [>=]. */
inline bool operator>=(const Float& lhs, const Float& rhs)
{
    return !operator< (lhs,rhs);
}
//==========================================================================

//==========================================================================
//
//  DYNAMIC MEMORY OPERATORS
//
//==========================================================================

//==========================================================================
/** Operator New. */
inline void* Float::operator new(std::size_t count)
{
    //std::cout << &(*this) << " - " << typeid(*this).name() << " - Called void* operator new(std::size_t count) = " << count << std::endl;

    std::cout << "custom new for size " << count << '\n';
    return ::operator new(count);
}

/** Operator Delete. */
inline void Float::operator delete(void* ptr)
{
    ::operator delete(ptr);
}

/** Operator New Array. */
inline void* Float::operator new[](std::size_t count)
{
    std::cout << "custom new[] for size " << count << '\n';
    return ::operator new[](count);
}

/** Operator Delete Array. */
inline void Float::operator delete[](void* ptr)
{
    ::operator delete[](ptr);
}

/** Operator New Placement. */
inline void* Float::operator new(std::size_t count, void* p)
{
    std::cout << "custom placement new called, p = " << p << '\n';
    return ::operator new(count, p);
}

/** Operator Delete Placement. */
inline void Float::operator delete(void* ptr, void* p)
{
    std::cout << "custom placement delete called, p = " << p << '\n';
    ::operator delete(ptr, p);
}

/** Operator New Array Placement. */
inline void* Float::operator new[](std::size_t count,void* p)
{
    std::cout << "custom placement new called, p = " << p << '\n';
    return ::operator new[](count, p);
}

/** Operator Delete Array Placement. */
inline void Float::operator delete[](void* ptr, void* p)
{
    std::cout << "custom placement delete called, p = " << p << '\n';
    ::operator delete(ptr, p);
}
//==============================================================================

//==============================================================================
//
//  ACCESSOR FUNCTIONS
//
//==============================================================================

//==============================================================================
/** Returns the current value. */
inline Float Float::val() 
{
    std::cout << &(*this) << " - " << typeid(*this).name() << " - Called function: Float val() = " << *this << std::endl;

    return value;
}

/** Returns a reference to the current value. */
inline Float& Float::get() 
{
    std::cout << &(*this) << " - " << typeid(*this).name() << " - Called function: Float& get() = " << *this << std::endl;

    return *this; 
}

/** Returns the address-of the current value. */
inline Float* Float::addressOf() 
{
    std::cout << &(*this) << " - " << typeid(*this).name() << " - Called function: Float* addressOf() = " << &(*this) << std::endl;
    return &(*this);
}

/** Returns the size of the current value. */
inline int Float::sizeOf() 
{
    std::cout << &(*this) << " - " << typeid(*this).name() << " - Called function: int sizeOf() = " << sizeof(*this) << std::endl;
    return sizeof(*this);
}

inline const type_info& Float::typeID()
{
    std::cout << &(*this) << " - " << typeid(*this).name() << " - Called function: const type_info& typeID()" << std::endl;

    return typeid(*this);
}

inline const char* Float::name() const noexcept
{
    std::cout << &(*this) << " - " << typeid(*this).name() << " - Called function: const char* name() const noexcept = " << typeid(*this).name() << std::endl;

    return typeid(*this).name();
}

inline const char* Float::raw_name() const noexcept
{
    std::cout << &(*this) << " - " << typeid(*this).name() << " - Called function: const char* raw_name() const noexcept = " << typeid(*this).raw_name() << std::endl;

    return typeid(*this).raw_name();
}

inline size_t Float::hash_code() const noexcept
{
    std::cout << &(*this) << " - " << typeid(*this).name() << " - Called function: size_t hash_code() const noexcept = " << typeid(*this).hash_code() << std::endl;

    return typeid(*this).hash_code();
}

/** typeid().before() Operator. */
inline bool Float::before(const type_info &_otherValue)
{
    std::cout << &(*this) << " - " << typeid(*this).name() << " - Called function: bool before(const type_info &_otherValue) = " << typeid(*this).before(_otherValue) << std::endl;

    return typeid(*this).before(_otherValue);
}

/** Prints information about this variable. */
inline void Float::info()
{
    std::cout << &(*this) << " - " << typeid(*this).name() << " - info:" << std::endl;
    std::cout << std::endl;
    std::cout << &(*this) << " - name - " << typeid(*this).name() << std::endl;
    std::cout << &(*this) << " - raw name - " << typeid(*this).raw_name() << std::endl;
    std::cout << &(*this) << " - hash code - " << typeid(*this).hash_code() << std::endl;
    std::cout << &(*this) << " - value = " << *this << std::endl;
    std::cout << &(*this) << " - &value = " << &(*this) << std::endl;
    std::cout << &(*this) << " - size in bytes = " << sizeof(*this) << std::endl;
    std::cout << std::endl;
    std::cout << &(*this) << " - member type - " << typeid(value).name() << std::endl;
    std::cout << &(*this) << " - member raw name - " << typeid(value).raw_name() << std::endl;
    std::cout << &(*this) << " - member hash code - " << typeid(value).hash_code() << std::endl;
    std::cout << &(*this) << " - member value = " << value << std::endl;
    std::cout << &(*this) << " - member &value = " << &value << std::endl;
    std::cout << &(*this) << " - member size in bytes = " << sizeof(value) << std::endl;
    std::cout << std::endl;
}

/** Runs and prints a set of data checks on this variable. */
inline void Float::dataChecks()
{
    std::cout << &(*this) << " - " << typeid(*this).name() << " - Data checks:" << std::endl;
    get();
    addressOf();
    sizeOf();
    std::cout << std::endl;
}

inline void Float::booleanChecks(const Float& comparison)
{
    std::cout << &(*this) << " - " << typeid(*this).name() << " - Boolean checks:" << std::endl;
    std::cout << std::endl;
    std::cout << "(value < "  << comparison.value << ") = " << (this->value < comparison.value) << std::endl;
    std::cout << "(value > "  << comparison.value << ") = " << (this->value > comparison.value) << std::endl;
    std::cout << "(value <= " << comparison.value << ") = " << (this->value <= comparison.value) << std::endl;
    std::cout << "(value >= " << comparison.value << ") = " << (this->value >= comparison.value) << std::endl;
    std::cout << "(value == " << comparison.value << ") = " << (this->value == comparison.value) << std::endl;
    std::cout << "(value != " << comparison.value << ") = " << (this->value != comparison.value) << std::endl;
    std::cout << std::endl;
}
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
