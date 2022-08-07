/**
  ==============================================================================

    Integer.h
    Created: 28 Jul 2022 08:58:03am
    Author:  Nathan J. Hood
    Website: github.com/StoneyDSP
    email:   nathanjhood@googlemail.com

  ==============================================================================
*/

#pragma once

#ifndef INTEGER_H_INCLUDED
#define INTEGER_H_INCLUDED

#include <assert.h>
#include <iostream>
#include <typeinfo>

//==============================================================================
/** Integer value. */
class Int final
{
public:
    //==========================================================================
    //
    //  CONSTRUCTORS
    //
    //==========================================================================

    // Default Constructor.
    Int();

    /** Initialized Constructor. */
    Int(int initialValue);

    /** Initialized Pointer Constructor. */
    Int(int* initialValue);

    /** Copy Constructor. */
    Int(Int& newValue);

    /** Copy Constructor (const). */
    Int(const Int& newValue);

    /** Move Constructor. */
    Int(Int&& otherValue) noexcept;

    /** Destructor. */
    ~Int() noexcept;

    //==========================================================================
    //
    //  COPY & MOVE ASSIGNMENT OPERATORS
    //
    //==========================================================================

    /** Copy Assignment Operator [=]. */
    Int& operator=(Int& newValue);

    /** Copy Assignment Operator (const) [=]. */
    Int& operator=(const Int& newValue);

    /** Move Assignment Operator [=]. */
    Int& operator=(Int&& otherValue) noexcept;

    //==========================================================================
    //
    //  UNARY ARITHMETIC OPERATORS
    //
    //==========================================================================

    /** Increment Prefix Operator [++]. */ 
    Int& operator++();

    /** Increment Postfix Operator [++]. */ 
    Int operator++(int);

    /** Decrement Prefix Operator [--]. */ 
    Int& operator--();

    /** Decrement Postfix Operator [--]. */ 
    Int operator--(int);

    //==========================================================================
    //
    //  BINARY ARITHMETIC OPERATORS
    //
    //==========================================================================

    /** Addition Assignment Operator [+=]. */
    Int& operator+=(const Int& rhs);

    /** Subtraction Assignment Operator [-=]. */
    Int& operator-=(const Int& rhs);

    /** Multiplication Assignment Operator [*=]. */
    Int& operator*=(const Int& rhs);

    /** Division Assignment Operator [/=]. */
    Int& operator/=(const Int& rhs);

    /** Modulus Assignment Operator [/=]. */
    Int& operator%=(const Int& rhs);

    //==========================================================================
    //
    //  UNARY BITWISE OPERATORS
    //
    //==========================================================================

    /** Bitwise NOT Operator [~]. */ 
    Int operator~();

    //==========================================================================
    //
    //  BINARY BITWISE OPERATORS
    //
    //==========================================================================

    /** Bitwise AND Assignment Operator [&=]. */
    Int& operator&=(const Int& rhs);

    /** Bitwise OR Assignment Operator [|=]. */
    Int& operator|=(const Int& rhs);

    /** Bitwise XOR Assignment Operator [^=]. */
    Int& operator^=(const Int& rhs);

    /** Bitwise Left Shift Assignment Operator [<<=]. */
    Int& operator<<=(const Int& rhs);

    /** Bitwise Right Shift Assignment Operator [>>=]. */
    Int& operator>>=(const Int& rhs);

    //==========================================================================
    //
    //  TYPE CONVERSION OPERATORS
    //
    //==========================================================================

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
    Int* addressOf();

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
    friend std::ostream& operator<<(std::ostream& ostream, Int& source);

    /** Prints information about this variable to Terminal. */
    friend std::istream& operator>>(std::istream& istream, Int& source);

    //==========================================================================
    //
    //  DATA MEMBERS
    //
    //==========================================================================
    /** Value. */
    int value;
};
//==============================================================================

//==============================================================================
//
//  BINARY ARITHMETIC OPERATOR NON-MEMBER FUNCTIONS
//
//==============================================================================

//==============================================================================
/** Addition Allocation Operator [+]. */
Int operator+(Int lhs, const Int& rhs);

/** Subtraction Allocation Operator [-]. */
Int operator-(Int lhs, const Int& rhs);

/** Multiplication Allocation Operator [*]. */
Int operator*(Int lhs, const Int& rhs);

/** Division Allocation Operator [/]. */
Int operator/(Int lhs, const Int& rhs);

/** Modulus Allocation Operator [%]. */
Int operator%(Int lhs, const Int& rhs);
//==============================================================================

//==============================================================================
//
//  BINARY BITWISE OPERATOR NON-MEMBER FUNCTIONS
//
//==============================================================================

//==============================================================================
/** Bitwise AND Allocation Operator [&]. */
Int operator&(Int lhs, const Int& rhs);

/** Bitwise OR Allocation Operator [|]. */
Int operator|(Int lhs, const Int& rhs);

/** Bitwise XOR Allocation Operator [^]. */
Int operator^(Int lhs, const Int& rhs);

/** Bitwise Left Shift Allocation Operator [<<]. */
Int operator<<(Int lhs, const Int& rhs);

/** Bitwise Right Shift Allocation Operator [>>]. */
Int operator>>(Int lhs, const Int& rhs);
//==============================================================================

//==============================================================================
//
//  COMPARISON OPERATOR NON-MEMBER FUNCTIONS
//
//==============================================================================

//==============================================================================
/** Equality Comparison Operator [==]. */
bool operator==(const Int& lhs, const Int& rhs);

/** Inequality Comparison Operator [!=]. */
bool operator!=(const Int& lhs, const Int& rhs);

/** Less-Than Comparison Operator [<]. */
bool operator< (const Int& lhs, const Int& rhs);

/** Greater-Than Comparison Operator [>]. */
bool operator> (const Int& lhs, const Int& rhs);

/** Less-Than or Equal-To Comparison Operator [<=]. */
bool operator<=(const Int& lhs, const Int& rhs);

/** Greater-Than or Equal-To Comparison Operator [>=]. */
bool operator>=(const Int& lhs, const Int& rhs);

/** Runs and prints a set of boolean checks on this variable. */
void booleanChecks(const Int& lhs, const Int& rhs);
//==============================================================================

//==============================================================================
//
//  IOSTREAM OPERATOR NON-MEMBER FUNCTIONS
//
//==============================================================================

//==============================================================================
/** Prints information about this variable to Terminal. */
std::ostream& operator<<(std::ostream& ostream, Int& source);

/** Prints information about this variable to Terminal. */
std::istream& operator>>(std::istream& istream, Int& source);
//==============================================================================

//==============================================================================
#endif // INTEGER_H_INCLUDED
