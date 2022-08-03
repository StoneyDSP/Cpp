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
Double operator+(Double lhs, const Double& rhs);

/** Subtraction Allocation Operator [-]. */
Double operator-(Double lhs, const Double& rhs);

/** Multiplication Allocation Operator [*]. */
Double operator*(Double lhs, const Double& rhs);

/** Division Allocation Operator [/]. */
Double operator/(Double lhs, const Double& rhs);
//==============================================================================

//==============================================================================
//
//  COMPARISON OPERATOR NON-MEMBER FUNCTIONS
//
//==============================================================================

//==============================================================================
/** Equality Comparison Operator [==]. */
bool operator==(const Double& lhs, const Double& rhs);

/** Inequality Comparison Operator [!=]. */
bool operator!=(const Double& lhs, const Double& rhs);

/** Less-Than Comparison Operator [<]. */
bool operator< (const Double& lhs, const Double& rhs);

/** Greater-Than Comparison Operator [>]. */
bool operator> (const Double& lhs, const Double& rhs);

/** Less-Than or Equal-To Comparison Operator [<=]. */
bool operator<=(const Double& lhs, const Double& rhs);

/** Greater-Than or Equal-To Comparison Operator [>=]. */
bool operator>=(const Double& lhs, const Double& rhs);

/** Runs and prints a set of boolean checks on this variable. */
void booleanChecks(const Double& lhs, const Double& rhs);
//==============================================================================

//==============================================================================
//
//  IOSTREAM OPERATOR NON-MEMBER FUNCTIONS
//
//==============================================================================

//==============================================================================
/** Prints information about this variable to Terminal. */
std::ostream& operator<<(std::ostream& ostream, Double& source);

/** Prints information about this variable to Terminal. */
std::istream& operator>>(std::istream& istream, Double& source);
//==============================================================================

//==============================================================================
#endif // Double_H_INCLUDED
