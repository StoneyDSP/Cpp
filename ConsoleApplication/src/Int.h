/**
  ==============================================================================

    Int.h
    Created: 28 Jul 2022 08:58:03am
    Author:  Nathan J. Hood
    Website: github.com/StoneyDSP
    email:   nathanjhood@googlemail.com

  ==============================================================================
*/

#pragma once

#include <assert.h>
#include <iostream>
#include <typeinfo>

//#include "Value.h"

//#include "UniquePointer.h"

// To-do...
// 1. Modulus Operator
// 2. Binary Bitwise Operators
// 3. Overhaul "typeID()" Operator(s) (how?)

//==============================================================================
class Int
{
public:
    //==========================================================================
    //
    //  CONSTRUCTORS
    //
    //==========================================================================

    /** Default Constructor. */
    Int();

    /** Initialized Constructor. */
    Int(int initialValue);

    /** Initialized Constructor. */
    Int(int* initialValue);

    /** Copy Constructor. */
    Int(Int& newValue);

    /** Copy Constructor (const). */
    Int(const Int& newValue);

    /** Move Constructor. */
    Int(Int&& otherValue);

    /** Destructor. */
    ~Int() noexcept;

    //==========================================================================
    /** Assertions to check Constructor succeeded */
    void assertion();

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
    Int& operator=(Int&& otherValue);

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

    //==========================================================================
    //
    //  TYPE CONVERSION OPERATORS
    //
    //==========================================================================

    /** Conversion Operator int(). */
    operator int() const noexcept;
    
    /** Conversion Operator bool(). */
    operator bool() const noexcept;
    
    /** Conversion Operator float(). */
    operator float() const noexcept;

    /** Conversion Operator double(). */
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
    Int val();

    /** Returns a reference to the current value. */
    Int& get();

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

    /** Runs and prints a set of boolean checks on this variable. */
    void booleanChecks(const Int& comparison = {3});

    /** Prints information about this variable to Terminal. */
    friend std::ostream& operator<<(std::ostream& ostream, Int& source);

    /** Prints information about this variable to Terminal. */
    friend std::istream& operator>>(std::istream& istream, Int& source);

private:
    //==========================================================================
    //
    //  DATA MEMBERS
    //
    //==========================================================================
    /** Value. */
    int value{0};
};
//==============================================================================

//==============================================================================
//
//  BINARY ARITHMETIC OPERATOR NON-MEMBER FUNCTIONS
//
//==============================================================================

//==============================================================================
/** Addition Allocation Operator [+]. */
inline Int operator+(Int lhs, const Int& rhs);

/** Subtraction Allocation Operator [-]. */
inline Int operator-(Int lhs, const Int& rhs);

/** Multiplication Allocation Operator [*]. */
inline Int operator*(Int lhs, const Int& rhs);

/** Division Allocation Operator [/]. */
inline Int operator/(Int lhs, const Int& rhs);

//==============================================================================

//==============================================================================
//
//  COMPARISON OPERATOR NON-MEMBER FUNCTIONS
//
//==============================================================================

//==============================================================================
/** Equality Comparison Operator [==]. */
inline bool operator==(const Int& lhs, const Int& rhs);

/** Inequality Comparison Operator [!=]. */
inline bool operator!=(const Int& lhs, const Int& rhs);

/** Less-Than Comparison Operator [<]. */
inline bool operator< (const Int& lhs, const Int& rhs);

/** Greater-Than Comparison Operator [>]. */
inline bool operator> (const Int& lhs, const Int& rhs);

/** Less-Than or Equal-To Comparison Operator [<=]. */
inline bool operator<=(const Int& lhs, const Int& rhs);

/** Greater-Than or Equal-To Comparison Operator [>=]. */
inline bool operator>=(const Int& lhs, const Int& rhs);
//==============================================================================

//==============================================================================
//
//  IOSTREAM OPERATOR NON-MEMBER FUNCTIONS
//
//==============================================================================

//==============================================================================
/** Prints information about this variable to Terminal. */
inline std::ostream& operator<<(std::ostream& ostream, Int& source);

/** Prints information about this variable to Terminal. */
inline std::istream& operator>>(std::istream& istream, Int& source);
//==============================================================================

//==============================================================================


//==============================================================================

//==============================================================================
//
//  CONSTRUCTORS
//
//==============================================================================

//==============================================================================
/** Default Constructor. */
inline Int::Int() : value(0)
{
    std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Default Constructor!" << std::endl;
    assertion();
    std::cout << &(*this) << " - " << typeid(*this).name() << " - Default Constructed!" << std::endl;
    std::cout << &(*this) << " - " << typeid(*this).name() << " - Value = " << *this << std::endl;
    std::cout << std::endl;
    info();
    std::cout << std::endl;
}

/** Initialized Constructor. */
inline Int::Int(int initialValue) : value(initialValue)
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
inline Int::Int(int* initialValue) : value(*(initialValue))
{
    std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Initialized Constructor from address " << &initialValue << " = " << initialValue << "!" << std::endl;
    assertion();
    std::cout << &(*this) << " - " << typeid(*this).name() << " - Initialized Constructed!" << std::endl;
    std::cout << &(*this) << " - " << typeid(*this).name() << " - initialValue = " << *this << std::endl;
    std::cout << std::endl;
    info();
    std::cout << std::endl;
}

/** Copy Constructor. */
inline Int::Int(Int& newValue) : value()
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
inline Int::Int(const Int& newValue) : value(newValue)
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
inline Int::Int(Int&& otherValue) : value()
{
    std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Move Constructor from address " << &otherValue << " = " << otherValue << "!" << std::endl;

    // Assign the class data members from the source object to the 
    // object that is being constructed:
    value = otherValue.value;

    // Assign the data members of the source object to default values. 
    // This prevents the destructor from freeing resources (such as memory) 
    // multiple times:
    otherValue.value = 0;

    assertion();
    std::cout << &(*this) << " - " << typeid(*this).name() << " - Move Constructed!" << std::endl;
    std::cout << &(*this) << " - " << typeid(*this).name() << " = " << *this << std::endl;
    std::cout << std::endl;
    info();
    std::cout << std::endl;
}

/** Destructor. */
inline Int::~Int() noexcept
{
    std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Destructor!" << std::endl;
    std::cout << &(*this) << " - " << typeid(*this).name() << " - Destroyed!" << std::endl;
    std::cout << &(*this) << " - " << typeid(*this).name() << " = " << *this << std::endl;
    std::cout << std::endl;
    info();
    std::cout << std::endl;
}
//==============================================================================
/** Assertions to check Constructor succeeded */
inline void Int::assertion()
{ 
    assert(this);
    std::cout << &(*this) << " - " << typeid(*this).name() << " - Passed assertion check!" << std::endl;
}
//==============================================================================

//==============================================================================
//
//  COPY & MOVE ASSIGNMENT OPERATORS
//
//==============================================================================

//==============================================================================
/** Copy Assignment Operator [=]. */
inline Int& Int::operator=(Int& newValue)
{
    std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Copy Assignment Operator [=] from address " << &newValue << " = " << newValue.value << std::endl;

    // Copy the data from the source object.
    value = newValue.value;
    return *this;
}

/** Copy Assignment Operator (const) [=]. */
inline Int& Int::operator=(const Int& newValue)
{
    std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Copy Assignment Operator (const) [=] from address " << &newValue << " = " << newValue.value << std::endl;
    // Copy the data from the source object.
    value = newValue.value;
    return *this;
}

/** Move Assignment Operator [=]. */
inline Int& Int::operator=(Int&& otherValue)
{
    std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Move Assignment Operator [=] from address " << &otherValue << " = " << otherValue.value;    

    //* Performs no operation if you try to assign the object to itself. */
    if (&otherValue != this)
    {
        // Call delete on pointers to free the resource


        // Copy the data from the source object.
        value = otherValue.value;

        // Release the data from the source object so that
        // the destructor does not free the memory multiple times.
        otherValue.value = 0;

        std::cout << " - Move successfull!" << std::endl;
    }

    else
    {
        std::cout << " - Move failed!" << std::endl;
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
inline Int& Int::operator++()
{
    std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Increment Prefix Operator [++]" << std::endl;
    std::cout << &(*this) << " - " << typeid(*this).name() << " - "<< this->value << "++ ";

    // do actual increment
    value++;

    std::cout << " = " << *this << std::endl;
    std::cout << std::endl;

    return *this;
}

/** Increment Postfix Operator [++]. */ 
inline Int Int::operator++(int)
{
    std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Increment Postfix Operator [++]" << std::endl;

    Int tmp = *this;
    ++*this;
    return tmp;
}

/** Decrement Prefix Operator [--]. */ 
inline Int& Int::operator--()
{
    std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Decrement Prefix Operator [--]" << std::endl;
    std::cout << &(*this) << " - " << typeid(*this).name() << " - "<< this->value << "-- ";

    // do actual decrement
    value--;

    std::cout << " = " << *this << std::endl;
    std::cout << std::endl;

    return *this;
}

/** Decrement Postfix Operator [--]. */ 
inline Int Int::operator--(int)
{
    std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Decrement Postfix Operator [--]" << std::endl;

    Int tmp = *this;
    --*this;
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
inline Int& Int::operator+=(const Int& rhs)
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
inline Int operator+(Int lhs, const Int& rhs)
{
    std::cout << &lhs << " - " << typeid(&lhs).name() << " - Called Addition Allocation Operator [+] with address " << &rhs << std::endl;

    /** Call to class member function */
    lhs += rhs; 
    return lhs;
}

/** Subtraction Assignment Operator [-=]. */
inline Int& Int::operator-=(const Int& rhs)
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
inline Int operator-(Int lhs, const Int& rhs)
{
    std::cout << &lhs << " - Called Subtraction Allocation Operator [-] with address " << &rhs << std::endl;

    /** Call to class member function */
    lhs -= rhs; 
    return lhs;
}

/** Multiplication Assignment Operator [*=]. */
inline Int& Int::operator*=(const Int& rhs)
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
inline Int operator*(Int lhs, const Int& rhs)
{
    std::cout << &lhs << " - Called Mutliplication Allocation Operator [*] with address " << &rhs << std::endl;

    /** Call to class member function */
    lhs *= rhs; 
    return lhs;
}

/** Division Assignment Operator [/=]. */
inline Int& Int::operator/=(const Int& rhs)
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
inline Int operator/(Int lhs, const Int& rhs)
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
inline Int::operator int() const noexcept
{ 
    std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Conversion Operator int()" << std::endl;

    return *this;
}

/** Conversion Operator bool(). */
inline Int::operator bool() const noexcept
{
    std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Conversion Operator bool()" << std::endl;

    return *this;
}

/** Conversion Operator float(). */
inline Int::operator float() const noexcept
{ 
    std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Conversion Operator float()" << std::endl;

    return *this;
}

/** Conversion Operator double(). */
inline Int::operator double() const noexcept
{ 
    std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Conversion Operator double()" << std::endl; 

    return *this;
}
//==============================================================================

//==============================================================================
//
//  COMPARISON OPERATOR NON-MEMBER FUNCTIONS
//
//==============================================================================

//==============================================================================
/** Equality Comparison Operator [==]. */
inline bool operator==(const Int& lhs, const Int& rhs)
{
    /* do actual comparison */
    return (lhs == rhs) ? true : false;
}

/** Inequality Comparison Operator [!=]. */
inline bool operator!=(const Int& lhs, const Int& rhs)
{
    return !operator==(lhs, rhs);
}

/** Less-Than Comparison Operator [<]. */
inline bool operator< (const Int& lhs, const Int& rhs)
{
    /* do actual comparison */
    return (lhs < rhs) ? true : false;
}

/** Greater-Than Comparison Operator [>]. */
inline bool operator> (const Int& lhs, const Int& rhs)
{
    return  operator< (rhs, lhs);
}

/** Less-Than or Equal-To Comparison Operator [<=]. */
inline bool operator<=(const Int& lhs, const Int& rhs)
{
    return !operator> (lhs,rhs);
}

/** Greater-Than or Equal-To Comparison Operator [>=]. */
inline bool operator>=(const Int& lhs, const Int& rhs)
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
inline void* Int::operator new(std::size_t count)
{
    //std::cout << &(*this) << " - " << typeid(*this).name() << " - Called void* operator new(std::size_t count) = " << count << std::endl;

    std::cout << "custom new for size " << count << '\n';
    return ::operator new(count);
}

/** Operator Delete. */
inline void Int::operator delete(void* ptr)
{
    ::operator delete(ptr);
}

/** Operator New Array. */
inline void* Int::operator new[](std::size_t count)
{
    std::cout << "custom new[] for size " << count << '\n';
    return ::operator new[](count);
}

/** Operator Delete Array. */
inline void Int::operator delete[](void* ptr)
{
    ::operator delete[](ptr);
}

/** Operator New Placement. */
inline void* Int::operator new(std::size_t count, void* p)
{
    std::cout << "custom placement new called, p = " << p << '\n';
    return ::operator new(count, p);
}

/** Operator Delete Placement. */
inline void Int::operator delete(void* ptr, void* p)
{
    std::cout << "custom placement delete called, p = " << p << '\n';
    ::operator delete(ptr, p);
}

/** Operator New Array Placement. */
inline void* Int::operator new[](std::size_t count,void* p)
{
    std::cout << "custom placement new called, p = " << p << '\n';
    return ::operator new[](count, p);
}

/** Operator Delete Array Placement. */
inline void Int::operator delete[](void* ptr, void* p)
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
inline Int Int::val() 
{
    std::cout << &(*this) << " - " << typeid(*this).name() << " - Called function: Int val() = " << *this << std::endl;

    return value;
}

/** Returns a reference to the current value. */
inline Int& Int::get() 
{
    std::cout << &(*this) << " - " << typeid(*this).name() << " - Called function: Int& get() = " << *this << std::endl;

    return *this; 
}

/** Returns the address-of the current value. */
inline Int* Int::addressOf() 
{
    std::cout << &(*this) << " - " << typeid(*this).name() << " - Called function: Int* addressOf() = " << &(*this) << std::endl;
    return &(*this);
}

/** Returns the size of the current value. */
inline int Int::sizeOf() 
{
    std::cout << &(*this) << " - " << typeid(*this).name() << " - Called function: int sizeOf() = " << sizeof(*this) << std::endl;
    return sizeof(*this);
}

inline const type_info& Int::typeID()
{
    std::cout << &(*this) << " - " << typeid(*this).name() << " - Called function: const type_info& typeID()" << std::endl;

    return typeid(*this);
}

inline const char* Int::name() const noexcept
{
    std::cout << &(*this) << " - " << typeid(*this).name() << " - Called function: const char* name() const noexcept = " << typeid(*this).name() << std::endl;

    return typeid(*this).name();
}

inline const char* Int::raw_name() const noexcept
{
    std::cout << &(*this) << " - " << typeid(*this).name() << " - Called function: const char* raw_name() const noexcept = " << typeid(*this).raw_name() << std::endl;

    return typeid(*this).raw_name();
}

inline size_t Int::hash_code() const noexcept
{
    std::cout << &(*this) << " - " << typeid(*this).name() << " - Called function: size_t hash_code() const noexcept = " << typeid(*this).hash_code() << std::endl;

    return typeid(*this).hash_code();
}

/** typeid().before() Operator. */
inline bool Int::before(const type_info &_otherValue)
{
    std::cout << &(*this) << " - " << typeid(*this).name() << " - Called function: bool before(const type_info &_otherValue) = " << typeid(*this).before(_otherValue) << std::endl;

    return typeid(*this).before(_otherValue);
}

/** Prints information about this variable. */
inline void Int::info()
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
    std::cout << &(*this) << " - member &value = " << value << std::endl;
    std::cout << &(*this) << " - member size in bytes = " << sizeof(value) << std::endl;
    std::cout << std::endl;
}

/** Runs and prints a set of data checks on this variable. */
inline void Int::dataChecks()
{
    std::cout << &(*this) << " - " << typeid(*this).name() << " - Data checks:" << std::endl;
    get();
    addressOf();
    sizeOf();
    std::cout << std::endl;
}

inline void Int::booleanChecks(const Int& comparison)
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
/** Prints information about this variable to Terminal. */
inline std::ostream& operator<<(std::ostream& ostream, Int& source)
{
    ostream << source.value;

    return ostream;
}

/** Prints information about this variable to Terminal. */
inline std::istream& operator>>(std::istream& istream, Int& source)
{
  if(source)
    istream.setstate(std::ios::failbit);

  return istream;
}
//==============================================================================

//==============================================================================