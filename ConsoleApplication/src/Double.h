/**
  ==============================================================================

    Double.h
    Created: 16 Jul 2022 12:58:03am
    Author:  Nathan J. Hood
    Website: github.com/StoneyDSP
    email:   nathanjhood@googlemail.com

  ==============================================================================
*/

#pragma once

#ifndef DOUBLE_H_INCLUDED
#define DOUBLE_H_INCLUDED

#include <assert.h>
#include <iostream>
#include <typeinfo>

class Integer;

// To-do...
// 1. Modulus Operator [x]
// 2. Overhaul "typeID()" Operator(s) (how?)
// 3. Unary operators
//==============================================================================

//==============================================================================
/** Double value. */
class Double final
{
public:
    //==========================================================================
    //
    //  CONSTRUCTORS
    //
    //==========================================================================

    // Default Constructor.
    Double();

    /** Initialized Constructor. */
    Double(double initialValue);

    /** Initialized Pointer Constructor. */
    Double(double* initialValue);

    /** Copy Constructor. */
    Double(Double& newValue);

    /** Copy Constructor (const). */
    Double(const Double& newValue);

    /** Move Constructor. */
    Double(Double&& otherValue) noexcept;

    /** Destructor. */
    ~Double() noexcept;

    //==========================================================================
    //
    //  COPY & MOVE ASSIGNMENT OPERATORS
    //
    //==========================================================================

    /** Copy Assignment Operator [=]. */
    Double& operator=(Double& newValue);

    /** Copy Assignment Operator (const) [=]. */
    Double& operator=(const Double& newValue);

    /** Move Assignment Operator [=]. */
    Double& operator=(Double&& otherValue) noexcept;

    //==========================================================================
    //
    //  UNARY ARITHMETIC OPERATORS
    //
    //==========================================================================

    /** Increment Prefix Operator [++]. */ 
    Double& operator++();

    /** Increment Postfix Operator [++]. */ 
    Double operator++(int);

    /** Decrement Prefix Operator [--]. */ 
    Double& operator--();

    /** Decrement Postfix Operator [--]. */ 
    Double operator--(int);

    //==========================================================================
    //
    //  BINARY ARITHMETIC OPERATORS
    //
    //==========================================================================

    /** Addition Assignment Operator [+=]. */
    Double& operator+=(const Double& rhs);

    /** Subtraction Assignment Operator [-=]. */
    Double& operator-=(const Double& rhs);

    /** Multiplication Assignment Operator [*=]. */
    Double& operator*=(const Double& rhs);

    /** Division Assignment Operator [/=]. */
    Double& operator/=(const Double& rhs);

    //==========================================================================
    //
    //  TYPE CONVERSION OPERATORS
    //
    //==========================================================================

    /** Conversion Operator Int(). */
    explicit operator Double() const noexcept;

    /** Conversion Operator int(). */
    explicit operator int() const noexcept;
    
    /** Conversion Operator bool(). */
    explicit operator bool() const noexcept;
    
    /** Conversion Operator float(). */
    explicit operator float() const noexcept;

    /** Conversion Operator double(). */
    explicit operator double() const noexcept;

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

    /** Returns the address-of the current value. */
    Double* addressOf();

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

    /** Assertions to check Constructor succeeded */
    void assertion();

    /** Prints information about this variable to Terminal. */
    friend std::ostream& operator<<(std::ostream& ostream, Double& source);

    /** Prints information about this variable to Terminal. */
    friend std::istream& operator>>(std::istream& istream, Double& source);

    //==========================================================================
    //
    //  DATA MEMBERS
    //
    //==========================================================================
    /** Value. */
    double value;
};
//==============================================================================

//==============================================================================
//
//  BINARY ARITHMETIC OPERATOR NON-MEMBER FUNCTIONS
//
//==============================================================================

//==============================================================================
/** Addition Allocation Operator [+]. */
inline Double operator+(Double lhs, const Double& rhs);

/** Subtraction Allocation Operator [-]. */
inline Double operator-(Double lhs, const Double& rhs);

/** Multiplication Allocation Operator [*]. */
inline Double operator*(Double lhs, const Double& rhs);

/** Division Allocation Operator [/]. */
inline Double operator/(Double lhs, const Double& rhs);
//==============================================================================

//==============================================================================
//
//  COMPARISON OPERATOR NON-MEMBER FUNCTIONS
//
//==============================================================================

//==============================================================================
/** Equality Comparison Operator [==]. */
inline bool operator==(const Double& lhs, const Double& rhs);

/** Inequality Comparison Operator [!=]. */
inline bool operator!=(const Double& lhs, const Double& rhs);

/** Less-Than Comparison Operator [<]. */
inline bool operator< (const Double& lhs, const Double& rhs);

/** Greater-Than Comparison Operator [>]. */
inline bool operator> (const Double& lhs, const Double& rhs);

/** Less-Than or Equal-To Comparison Operator [<=]. */
inline bool operator<=(const Double& lhs, const Double& rhs);

/** Greater-Than or Equal-To Comparison Operator [>=]. */
inline bool operator>=(const Double& lhs, const Double& rhs);

/** Runs and prints a set of boolean checks on this variable. */
inline void booleanChecks(const Double& lhs, const Double& rhs);
//==============================================================================

//==============================================================================
//
//  IOSTREAM OPERATOR NON-MEMBER FUNCTIONS
//
//==============================================================================

//==============================================================================
/** Prints information about this variable to Terminal. */
inline std::ostream& operator<<(std::ostream& ostream, Double& source);

/** Prints information about this variable to Terminal. */
inline std::istream& operator>>(std::istream& istream, Double& source);
//==============================================================================

//==============================================================================
#endif // Double_H_INCLUDED


//==============================================================================
/**
  ==============================================================================

    Double.cpp
    Created: 16 Jul 2022 12:58:03am
    Author:  Nathan J. Hood
    Website: github.com/StoneyDSP
    email:   nathanjhood@googlemail.com

  ==============================================================================
*/
//==============================================================================

//==============================================================================
//
//  CONSTRUCTORS
//
//==============================================================================

//==============================================================================
/** Default Constructor. */
inline Double::Double() : value{0}
{
    std::cout << this << " - " << typeid(*this).name() << " - Called Default Constructor!" << std::endl;
    //*this = value;
    assertion();
    std::cout << this << " - " << typeid(*this).name() << " - Default Constructed!" << std::endl;
    std::cout << this << " - " << typeid(*this).name() << " - Value = " << value << std::endl;
    std::cout << std::endl;
}

/** Initialized Constructor. */
inline Double::Double(double initialValue) : value{initialValue}
{
    std::cout << this << " - " << typeid(*this).name() << " - Called Initialized Constructor from address " << &initialValue << " = " << initialValue << "!" << std::endl;
    //*this = initialValue;
    assertion();
    std::cout << this << " - " << typeid(*this).name() << " - Initialized Constructed!" << std::endl;
    std::cout << this << " - " << typeid(*this).name() << " - initialValue = " << value << std::endl;
    std::cout << std::endl;
}

/** Initialized Pointer Constructor. */
inline Double::Double(double* initialValue) : value{*initialValue}
{
    std::cout << this << " - " << typeid(*this).name() << " - Called Initialized Pointer Constructor from address " << initialValue << " = " << *initialValue << "!" << std::endl;
    //*this = initialValue;
    assertion();
    std::cout << this << " - " << typeid(*this).name() << " - Initialized Constructed!" << std::endl;
    std::cout << this << " - " << typeid(*this).name() << " - initialValue = " << value << std::endl;
    std::cout << std::endl;
}

/** Copy Constructor. */
inline Double::Double(Double& newValue) : value{newValue.value}
{
    std::cout << this << " - " << typeid(*this).name() << " - Called Copy Constructor from address " << &newValue << " = " << newValue.value << "!" << std::endl;
    //*this = newValue;
    assertion();
    std::cout << this << " - " << typeid(*this).name() << " - Copy Constructed!" << std::endl;
    std::cout << this << " - " << typeid(*this).name() << " - newValue = " << value << std::endl;
    std::cout << std::endl;
}

/** Copy Constructor (const). */
inline Double::Double(const Double& newValue) : value{newValue.value}
{
    std::cout << this << " - " << typeid(*this).name() << " - Called Copy Constructor (const) from address " << &newValue << " = " << newValue.value << "!" << std::endl;
    //*this = newValue;
    assertion();
    std::cout << this << " - " << typeid(*this).name() << " - Copy Constructed (const)!" << std::endl;
    std::cout << this << " - " << typeid(*this).name() << " - newValue = " << value << std::endl;
    std::cout << std::endl;
}

/** Move Constructor. */
inline Double::Double(Double&& otherValue) noexcept : value{otherValue.value}
{
    std::cout << this << " - " << typeid(*this).name() << " - Called Move Constructor from address " << &otherValue << " = " << otherValue << "!" << std::endl;
    //*this = otherValue.value;
    assertion();
    std::cout << this << " - " << typeid(*this).name() << " - Move Constructed!" << std::endl;
    std::cout << this << " - " << typeid(*this).name() << " = " << value << std::endl;
    std::cout << std::endl;
}

/** Destructor. */
inline Double::~Double() noexcept
{
    std::cout << this << " - " << typeid(*this).name() << " - Called Destructor!" << std::endl;
    std::cout << this << " - " << typeid(*this).name() << " - Destroyed!" << std::endl;
    std::cout << this << " - " << typeid(*this).name() << " = " << value << std::endl;
    std::cout << std::endl;

    value = 0;
}
//==============================================================================

//==============================================================================
//
//  COPY & MOVE ASSIGNMENT OPERATORS
//
//==============================================================================

//==============================================================================
/** Copy Assignment Operator [=]. */
inline Double& Double::operator=(Double& newValue)
{
    std::cout << this << " - " << typeid(*this).name() << " - Called Copy Assignment Operator [=] from address " << &newValue << " = " << newValue.value << std::endl;

    //* Performs no operation if you try to assign the object to itself. */
    if (this == &newValue)
        return *this;
    
    if (value != newValue.value)
    {
        // Free the resource
        value = 0;

        // Copy the data from the source object.
        value = newValue.value;
    }
    
    return *this;
}

/** Copy Assignment Operator (const) [=]. */
inline Double& Double::operator=(const Double& newValue)
{
    std::cout << this << " - " << typeid(*this).name() << " - Called Copy Assignment Operator (const) [=] from address " << &newValue << " = " << newValue.value << std::endl;

    //* Performs no operation if you try to assign the object to itself. */
    if (this == &newValue)
        return *this;
    
    if (value != newValue.value)
    {
        // Free the resource
        value = 0;

        // Copy the data from the source object.
        value = newValue.value;
    }
    
    return *this;
}

/** Move Assignment Operator [=]. */
inline Double& Double::operator=(Double&& otherValue) noexcept
{
    std::cout << this << " - " << typeid(*this).name() << " - Called Move Assignment Operator [=] from address " << &otherValue << " = " << otherValue.value;    

    if (this == &otherValue)
        return *this;

    //* Performs no operation if you try to assign the object to itself. */
    if (&otherValue != this)
    {
        // Free the resource
        value = 0;

        // Copy the data from the source object.
        value = otherValue.value;

        // Release the data from the source object so that
        // the destructor does not free the memory multiple times.
        otherValue.value = 0;

        std::cout << " - Move successfull!" << std::endl;
        std::cout << std::endl;
    }

    else
    {
        std::cout << " - Move failed!" << std::endl;
        std::cout << std::endl;
    }

    return *this;
}
//==============================================================================

//==============================================================================
//
//  UNARY ARITHMETIC OPERATORS
//
//==============================================================================

//==============================================================================
/** Increment Prefix Operator [++]. */ 
inline Double& Double::operator++()
{
    std::cout << this << " - " << typeid(*this).name() << " - Called Increment Prefix Operator [++]" << std::endl;
    std::cout << this << " - " << typeid(*this).name() << " - "<< value << "++ ";

    ++value; // Do actual increment.

    std::cout << " = " << value << std::endl;
    std::cout << std::endl;

    return *this;
}

/** Increment Postfix Operator [++]. */ 
inline Double Double::operator++(int)
{
    std::cout << this << " - " << typeid(*this).name() << " - Called Increment Postfix Operator [++]" << std::endl;

    Double tmp {*this};

    ++(*this); // Call to class member function.

    return tmp.value;
}

/** Decrement Prefix Operator [--]. */ 
inline Double& Double::operator--()
{
    std::cout << this << " - " << typeid(*this).name() << " - Called Decrement Prefix Operator [--]" << std::endl;
    std::cout << this << " - " << typeid(*this).name() << " - "<< value << "-- ";

    --value; // Do actual decrement.

    std::cout << " = " << value << std::endl;
    std::cout << std::endl;

    return *this;
}

/** Decrement Postfix Operator [--]. */ 
inline Double Double::operator--(int)
{
    std::cout << this << " - " << typeid(*this).name() << " - Called Decrement Postfix Operator [--]" << std::endl;

    Double tmp {*this};

    --(*this);   // Call to class member function.

    return tmp;
}
//==============================================================================

//==============================================================================
//
//  BINARY ARITHMETIC OPERATORS
//
//==============================================================================

//==============================================================================
/** Addition Assignment Operator [+=]. */
inline Double& Double::operator+=(const Double& rhs)
{
    std::cout << this << " - " << typeid(*this).name() << " - Called Addition Assignment Operator [+=] with address " << &rhs << " = " << rhs.value << std::endl;
    std::cout << this << " - " << typeid(*this).name() << " - " << value << " += " << rhs.value << " = ";

    value = value + rhs.value; // Actual addition of rhs to *this.

    std::cout << value << std::endl;
    std::cout << std::endl;

    return *this;
}

/** Subtraction Assignment Operator [-=]. */
inline Double& Double::operator-=(const Double& rhs)
{
    std::cout << this << " - " << typeid(*this).name() << " - Called Subtraction Assignment Operator [-=] with address " << &rhs << " = " << rhs.value << std::endl;
    std::cout << this << " - " << typeid(*this).name() << " - " << value << " -= " << rhs.value << " = ";

    value = value - rhs.value; // Actual subtraction of rhs from *this.

    std::cout << value << std::endl;
    std::cout << std::endl;

    return *this;
}

/** Multiplication Assignment Operator [*=]. */
inline Double& Double::operator*=(const Double& rhs)
{
    std::cout << this << " - " << typeid(*this).name() << " - Called Multiplication Assignment Operator [*=] with address " << &rhs << " = " << rhs.value << std::endl;
    std::cout << this << " - " << typeid(*this).name() << " - " << value << " *= " << rhs.value << " = ";
 
    value = value * rhs.value; // Actual multiplication of rhs with *this.

    std::cout << value << std::endl;
    std::cout << std::endl;

    return *this;
}

/** Division Assignment Operator [/=]. */
inline Double& Double::operator/=(const Double& rhs)
{
    std::cout << this << " - " << typeid(*this).name() << " - Called Division Assignment Operator [/=] with address " << &rhs << " = " << rhs.value << std::endl;
    std::cout << this << " - " << typeid(*this).name() << " - " << value << " /= " << rhs.value << " = ";

    value = value / rhs.value; // Actual division of *this by rhs.

    std::cout << value << std::endl;
    std::cout << std::endl;

    return *this;
}
//==============================================================================

//==============================================================================
//
//  TYPE CONVERSION OPERATORS
//
//==============================================================================

//==============================================================================
/** Conversion Operator Int(). */
inline Double::operator Double() const noexcept
{ 
    std::cout << this << " - " << typeid(*this).name() << " - Called Conversion Operator Int()" << std::endl;
    std::cout << std::endl;

    return value;
}

/** Conversion Operator int(). */
inline Double::operator int() const noexcept
{ 
    std::cout << this << " - " << typeid(*this).name() << " - Called Conversion Operator int()" << std::endl;
    std::cout << std::endl;

    return value;
}

/** Conversion Operator bool(). */
inline Double::operator bool() const noexcept
{
    std::cout << this << " - " << typeid(*this).name() << " - Called Conversion Operator bool()" << std::endl;
    std::cout << std::endl;

    return (value != 0 ? true : false);
}

/** Conversion Operator float(). */
inline Double::operator float() const noexcept
{ 
    std::cout << this << " - " << typeid(*this).name() << " - Called Conversion Operator float()" << std::endl;
    std::cout << std::endl;

    return value;
}

/** Conversion Operator double(). */
inline Double::operator double() const noexcept
{ 
    std::cout << this << " - " << typeid(*this).name() << " - Called Conversion Operator double()" << std::endl;
    std::cout << std::endl;

    return value;
}
//==============================================================================

//==============================================================================
//
//  DYNAMIC MEMORY OPERATORS
//
//==============================================================================

//==============================================================================
/** Operator New. */
inline void* Double::operator new(std::size_t count)
{
    std::cout << "Called void* operator new(std::size_t count) = " << count << " bytes." << std::endl;
    std::cout << std::endl;

    return ::operator new(count);
}

/** Operator Delete. */
inline void Double::operator delete(void* ptr)
{
    std::cout << "Called void operator delete(void* ptr) = " << ptr << std::endl;
    std::cout << std::endl;

    ::operator delete(ptr);
}

/** Operator New Array. */
inline void* Double::operator new[](std::size_t count)
{
    std::cout << "Called void* operator new[](std::size_t count) = " << count << " bytes." << std::endl;
    std::cout << std::endl;

    return ::operator new[](count);
}

/** Operator Delete Array. */
inline void Double::operator delete[](void* ptr)
{
    std::cout << "Called void operator delete[](void* ptr) = " << ptr << std::endl;
    std::cout << std::endl;

    ::operator delete[](ptr);
}

/** Operator New Placement. */
inline void* Double::operator new(std::size_t count, void* p)
{
    std::cout << "Called void* operator new(std::size_t count, void* p) = " << count << " bytes, " << p << " offset." << std::endl;
    std::cout << std::endl;

    return ::operator new(count, p);
}

/** Operator Delete Placement. */
inline void Double::operator delete(void* ptr, void* p)
{
    std::cout << "Called void operator delete(void* ptr, void* p) = " << ptr << ", " << p << std::endl;
    std::cout << std::endl;

    ::operator delete(ptr, p);
}

/** Operator New Array Placement. */
inline void* Double::operator new[](std::size_t count, void* p)
{
    std::cout << "Called void* operator new[](std::size_t count, void* p) = " << count << " bytes, " << p << " offset." << std::endl;
    std::cout << std::endl;

    return ::operator new[](count, p);
}

/** Operator Delete Array Placement. */
inline void Double::operator delete[](void* ptr, void* p)
{
    std::cout << "Called void operator delete[](void* ptr, void* p) = " << ptr << ", " << p << std::endl;
    std::cout << std::endl;

    ::operator delete(ptr, p);
}
//==============================================================================

//==============================================================================
//
//  ACCESSOR FUNCTIONS
//
//==============================================================================

//==============================================================================
/** Returns the address-of the current value. */
inline Double* Double::addressOf() 
{
    std::cout << this << " - " << typeid(*this).name() << " - Called function: Int* addressOf() = " << &(*this) << std::endl;

    return this;
}

/** Returns the size of the current value. */
inline int Double::sizeOf()
{
    std::cout << this << " - " << typeid(*this).name() << " - Called function: int sizeOf() = " << sizeof(*this) << std::endl;

    return sizeof(*this);
}

/** Returns the type info of this variable. */
inline const type_info& Double::typeID()
{
    std::cout << this << " - " << typeid(*this).name() << " - Called function: const type_info& typeID()" << std::endl;

    return typeid(*this);
}

/** Returns the name of this variable. */
inline const char* Double::name() const noexcept
{
    std::cout << this << " - " << typeid(*this).name() << " - Called function: const char* name() const noexcept = " << typeid(*this).name() << std::endl;

    return typeid(*this).name();
}

/** Returns the raw name of this variable. */
inline const char* Double::raw_name() const noexcept
{
    std::cout << this << " - " << typeid(*this).name() << " - Called function: const char* raw_name() const noexcept = " << typeid(*this).raw_name() << std::endl;

    return typeid(*this).raw_name();
}

/** Returns the hash code of this variable. */
inline size_t Double::hash_code() const noexcept
{
    std::cout << this << " - " << typeid(*this).name() << " - Called function: size_t hash_code() const noexcept = " << typeid(*this).hash_code() << std::endl;

    return typeid(*this).hash_code();
}

/** typeid().before() Operator. */
inline bool Double::before(const type_info &_otherValue)
{
    std::cout << this << " - " << typeid(*this).name() << " - Called function: bool before(const type_info &_otherValue) = " << typeid(*this).before(_otherValue) << std::endl;

    return typeid(*this).before(_otherValue);
}

/** Prints information about this variable. */
inline void Double::info()
{
    std::cout << this << " - " << typeid(*this).name() << " - info:" << std::endl;
    std::cout << std::endl;
    std::cout << this << " - name - " << typeid(*this).name() << std::endl;
    std::cout << this << " - raw name - " << typeid(*this).raw_name() << std::endl;
    std::cout << this << " - hash code - " << typeid(*this).hash_code() << std::endl;
    std::cout << this << " - this = " << this << std::endl;
    std::cout << this << " - *this = " << *this << std::endl;
    std::cout << this << " - size in bytes = " << sizeof(*this) << std::endl;
    std::cout << std::endl;
    std::cout << this << " - member type - " << typeid(value).name() << std::endl;
    std::cout << this << " - member raw name - " << typeid(value).raw_name() << std::endl;
    std::cout << this << " - member hash code - " << typeid(value).hash_code() << std::endl;
    std::cout << this << " - member value = " << value << std::endl;
    std::cout << this << " - member &value = " << &value << std::endl;
    std::cout << this << " - member size in bytes = " << sizeof(value) << std::endl;
    std::cout << std::endl;
}

/** Runs and prints a set of data checks on this variable. */
inline void Double::dataChecks()
{
    std::cout << this << " - " << typeid(*this).name() << " - Data checks:" << std::endl;
    addressOf();
    sizeOf();
    std::cout << std::endl;
}

/** Assertions to check Constructor succeeded */
inline void Double::assertion()
{ 
    assert(this != nullptr);
    std::cout << this << " - " << typeid(*this).name() << " - Passed assertion check!" << std::endl;
}
//==============================================================================

//==============================================================================
//
//  ARITHMETIC OPERATOR NON-MEMBER FUNCTIONS
//
//==============================================================================

//==============================================================================
/** Addition Allocation Operator [+]. */
inline Double operator+(Double lhs, const Double& rhs) // passing lhs by value helps optimize chained a+b+c, otherwise, both parameters may be const references
{
    std::cout << &lhs << " - " << typeid(lhs).name() << " - Called Addition Allocation Operator [+] with address " << &rhs << " = " << rhs.value << std::endl;

    lhs += rhs; // reuse compound assignment
    return {lhs}; // return the result by value (uses move constructor)
}

/** Subtraction Allocation Operator [-]. */ 
inline Double operator-(Double lhs, const Double& rhs) // passing lhs by value helps optimize chained a-b-c, otherwise, both parameters may be const references
{
    std::cout << &lhs << " - " << typeid(lhs).name() << " - Called Subtraction Allocation Operator [-] with address " << &rhs << " = " << rhs.value << std::endl;

    lhs -= rhs; // reuse compound assignment
    return {lhs}; // return the result by value (uses move constructor)
}

/** Multiplication Allocation Operator [*]. */
inline Double operator*(Double lhs, const Double& rhs)
{
    std::cout << &lhs << " - " << typeid(lhs).name() << " - Called Mutliplication Allocation Operator [*] with address " << &rhs << " = " << rhs.value << std::endl;

    lhs *= rhs; // reuse compound assignment
    return {lhs}; // return the result by value (uses move constructor)
}

/** Division Allocation Operator [/]. */
inline Double operator/(Double lhs, const Double& rhs)
{
    std::cout << &lhs << " - " << typeid(lhs).name() << " - Called Division Allocation Operator [/] with address " << &rhs << " = " << rhs.value << std::endl;

    lhs /= rhs; // reuse compound assignment
    return {lhs}; // return the result by value (uses move constructor)
}
//==============================================================================

//==============================================================================
//
//  COMPARISON OPERATOR NON-MEMBER FUNCTIONS
//
//==============================================================================

//==============================================================================
/** Equality Comparison Operator [==]. */
inline bool operator==(const Double& lhs, const Double& rhs)
{
    std::cout << &lhs << " - " << typeid(lhs).name() << " - Called Equality Comparison Operator [==] with address " << &rhs << " = " << rhs.value << std::endl;

    return (lhs.value == rhs.value) ? true : false; // do actual comparison
}

/** Inequality Comparison Operator [!=]. */
inline bool operator!=(const Double& lhs, const Double& rhs)
{
    std::cout << &lhs << " - " << typeid(lhs).name() << " - Called Inequality Comparison Operator [!=] with address " << &rhs << " = " << rhs.value << std::endl;

    return !operator==(lhs, rhs);
}

/** Less-Than Comparison Operator [<]. */
inline bool operator< (const Double& lhs, const Double& rhs)
{
    std::cout << &lhs << " - " << typeid(lhs).name() << " - Less-Than Comparison Operator [<] with address " << &rhs << " = " << rhs.value << std::endl;

    return (lhs.value < rhs.value) ? true : false; // do actual comparison
}

/** Greater-Than Comparison Operator [>]. */
inline bool operator> (const Double& lhs, const Double& rhs)
{
    std::cout << &lhs << " - " << typeid(lhs).name() << " - Called Greater-Than Comparison Operator [>] with address " << &rhs << " = " << rhs.value << std::endl;

    return  operator< (rhs, lhs);
}

/** Less-Than or Equal-To Comparison Operator [<=]. */
inline bool operator<=(const Double& lhs, const Double& rhs)
{
    std::cout << &lhs << " - " << typeid(lhs).name() << " - Called Less-Than or Equal-To Comparison Operator [<=] with address " << &rhs << " = " << rhs.value << std::endl;

    return !operator> (lhs,rhs);
}

/** Greater-Than or Equal-To Comparison Operator [>=]. */
inline bool operator>=(const Double& lhs, const Double& rhs)
{
    std::cout << &lhs << " - " << typeid(lhs).name() << " - Called Greater-Than or Equal-To Comparison Operator [>=] with address " << &rhs << " = " << rhs.value << std::endl;

    return !operator< (lhs,rhs);
}

/** Runs and prints a set of boolean checks on this variable. */
inline void booleanChecks(const Double& lhs, const Double& rhs)
{
    std::cout << &lhs << " - " << typeid(lhs).name() << " - Boolean checks:" << std::endl;
    std::cout << std::endl;
    std::cout << "(value < "  << rhs.value << ") = " << (lhs < rhs) << std::endl;
    std::cout << "(value > "  << rhs.value << ") = " << (lhs > rhs) << std::endl;
    std::cout << "(value <= " << rhs.value << ") = " << (lhs <= rhs) << std::endl;
    std::cout << "(value >= " << rhs.value << ") = " << (lhs >= rhs) << std::endl;
    std::cout << "(value == " << rhs.value << ") = " << (lhs == rhs) << std::endl;
    std::cout << "(value != " << rhs.value << ") = " << (lhs != rhs) << std::endl;
    std::cout << std::endl;
}
//==============================================================================

//==============================================================================
//
//  IOSTREAM OPERATOR NON-MEMBER FUNCTIONS
//
//==============================================================================

//==============================================================================
/** Prints information about this variable to Terminal. */
inline std::ostream& operator<<(std::ostream& ostream, Double& source)
{
    ostream << source.value;

    return ostream;
}

/** Prints information about this variable to Terminal. */
inline std::istream& operator>>(std::istream& istream, Double& source)
{
  if(source)
    istream.setstate(std::ios::failbit);

  return istream;
}
//==============================================================================
