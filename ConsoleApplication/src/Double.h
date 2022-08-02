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

#include <assert.h>
#include <iostream>
#include <typeinfo>

//#include "UniquePointer.h"

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

    /** Default Constructor. */
    Double();

    /** Initialized Constructor. */
    Double(double initialValue);

    /** Initialized Constructor. */
    Double(double* initialValue);

    /** Copy Constructor. */
    Double(Double& newValue);

    /** Copy Constructor (const). */
    Double(const Double& newValue);

    /** Move Constructor. */
    Double(Double&& otherValue);

    /** Destructor. */
    ~Double() noexcept;

    //==========================================================================
    /** Assertions to check Constructor succeeded */
    void assertion();

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
    Double& operator=(Double&& otherValue);

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
    Double val();

    /** Returns a reference to the current value. */
    Double& get();

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

    /** Runs and prints a set of boolean checks on this variable. */
    void booleanChecks(const Double& comparison = {3.14169});

    /** Prints information about this variable to Terminal. */
    friend std::ostream& operator<<(std::ostream& ostream, Double& source);

    /** Prints information about this variable to Terminal. */
    friend std::istream& operator>>(std::istream& istream, Double& source);

private:
    //==========================================================================
    //
    //  DATA MEMBERS
    //
    //==========================================================================
    /** Value. */
    double value{0.0};
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
//
//  CONSTRUCTORS
//
//==============================================================================

//==============================================================================
/** Default Constructor. */
inline Double::Double() : value(0.0)
{
    std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Default Constructor!" << std::endl;
    assertion();
    std::cout << &(*this) << " - " << typeid(*this).name() << " - Default Constructed!" << std::endl;
    std::cout << &(*this) << " - " << typeid(*this).name() << " - Value = " << *this << std::endl;
    std::cout << std::endl;
}

/** Initialized Constructor. */
inline Double::Double(double initialValue) : value(initialValue)
{
    std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Initialized Constructor from address " << &initialValue << " = " << initialValue << "!" << std::endl;
    assertion();
    std::cout << &(*this) << " - " << typeid(*this).name() << " - Initialized Constructed!" << std::endl;
    std::cout << &(*this) << " - " << typeid(*this).name() << " - initialValue = " << *this << std::endl;
    std::cout << std::endl;
}

/** Initialized Constructor. */
inline Double::Double(double* initialValue) : value(*(initialValue))
{
    std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Initialized Constructor from address " << &initialValue << " = " << initialValue << "!" << std::endl;
    assertion();
    std::cout << &(*this) << " - " << typeid(*this).name() << " - Initialized Constructed!" << std::endl;
    std::cout << &(*this) << " - " << typeid(*this).name() << " - initialValue = " << *this << std::endl;
    std::cout << std::endl;
}

/** Copy Constructor. */
inline Double::Double(Double& newValue) : value()
{
    std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Copy Constructor from address " << &newValue << " = " << newValue.value << "!" << std::endl;
    *this = newValue;
    assertion();
    std::cout << &(*this) << " - " << typeid(*this).name() << " - Copy Constructed!" << std::endl;
    std::cout << &(*this) << " - " << typeid(*this).name() << " - newValue = " << *this << std::endl;
    std::cout << std::endl;
}

/** Copy Constructor (const). */
inline Double::Double(const Double& newValue) : value(newValue)
{
    std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Copy Constructor (const) from address " << &newValue << " = " << newValue.value << "!" << std::endl;
    *this = newValue;
    assertion();
    std::cout << &(*this) << " - " << typeid(*this).name() << " - Copy Constructed (const)!" << std::endl;
    std::cout << &(*this) << " - " << typeid(*this).name() << " - newValue = " << *this << std::endl;
    std::cout << std::endl;
}

/** Move Constructor. */
inline Double::Double(Double&& otherValue) : value()
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
}

/** Destructor. */
inline Double::~Double() noexcept
{
    std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Destructor!" << std::endl;
    std::cout << &(*this) << " - " << typeid(*this).name() << " - Destroyed!" << std::endl;
    std::cout << &(*this) << " - " << typeid(*this).name() << " = " << *this << std::endl;
    std::cout << std::endl;
}
//==============================================================================
/** Assertions to check Constructor succeeded */
inline void Double::assertion()
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
inline Double& Double::operator=(Double& newValue)
{
    std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Copy Assignment Operator [=] from address " << &newValue << " = " << newValue.value << std::endl;

    // Copy the data from the source object.
    value = newValue.value;
    return *this;
}

/** Copy Assignment Operator (const) [=]. */
inline Double& Double::operator=(const Double& newValue)
{
    std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Copy Assignment Operator (const) [=] from address " << &newValue << " = " << newValue.value << std::endl;
    // Copy the data from the source object.
    value = newValue.value;
    return *this;
}

/** Move Assignment Operator [=]. */
inline Double& Double::operator=(Double&& otherValue)
{
    std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Move Assignment Operator [=] from address " << &otherValue << " = " << otherValue.value << std::endl;    

    //* Performs no operation if you try to assign the object to itself. */
    if (&otherValue != this)
    {
        // Call delete on pointers to free the resource


        // Copy the data from the source object.
        value = otherValue.value;

        // Release the data from the source object so that
        // the destructor does not free the memory multiple times.
        otherValue.value = 0;

        std::cout << &(*this) << " - " << typeid(*this).name() << " - Move successfull!" << std::endl;
    }

    else
    {
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Move failed!" << std::endl;
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
    std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Increment Prefix Operator [++]" << std::endl;
    std::cout << &(*this) << " - " << typeid(*this).name() << " - "<< this->value << "++ ";

    // do actual increment
    value++;

    std::cout << " = " << *this << std::endl;
    std::cout << std::endl;

    return *this;
}

/** Increment Postfix Operator [++]. */ 
inline Double Double::operator++(int)
{
    std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Increment Postfix Operator [++]" << std::endl;

    Double tmp = *this;
    ++*this;
    return tmp;
}

/** Decrement Prefix Operator [--]. */ 
inline Double& Double::operator--()
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
inline Double Double::operator--(int)
{
    std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Decrement Postfix Operator [--]" << std::endl;

    Double tmp = *this;
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
inline Double& Double::operator+=(const Double& rhs)
{
    std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Addition Assignment Operator [+=] from address " << &rhs << " = " << rhs.value << std::endl;
    std::cout << &(*this) << " - " << typeid(*this).name() << " - " << this->value << " += ";

    /** actual addition of rhs to *this. */ 
    value += rhs.value;

    std::cout << rhs.value << " = " << *this << std::endl;
    std::cout << std::endl;

    return *this;
}

/** Addition Allocation Operator [+]. */
inline Double operator+(Double lhs, const Double& rhs)
{
    std::cout << &lhs << " - " << typeid(lhs).name() << " - Called Addition Allocation Operator [+] from address " << &rhs << std::endl;
    /** Call to class member function */
    lhs += rhs;

    return lhs;
}

/** Subtraction Assignment Operator [-=]. */
inline Double& Double::operator-=(const Double& rhs)
{
    std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Subtraction Assignment Operator [-=] from address " << &rhs << " = " << rhs.value << std::endl;
    std::cout << &(*this) << " - " << typeid(*this).name() << " - " << this->value << " -= ";

    /** actual subtraction of rhs from *this */
    value -= rhs.value;

    std::cout << rhs.value << " = " << *this << std::endl;
    std::cout << std::endl;

    return *this;
}

/** Subtraction Allocation Operator [-]. */
inline Double operator-(Double lhs, const Double& rhs)
{
    std::cout << &lhs <<  " - " << typeid(lhs).name() << " - Called Subtraction Allocation Operator [-] from address " << &rhs << std::endl;

    /** Call to class member function */
    lhs -= rhs; 
    return lhs;
}

/** Multiplication Assignment Operator [*=]. */
inline Double& Double::operator*=(const Double& rhs)
{
    std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Multiplication Assignment Operator [*=] from address " << &rhs << " = " << rhs.value << std::endl;
    std::cout << &(*this) << " - " << typeid(*this).name() << " - " << this->value << " *= ";

    /** Actual multiplication of rhs with *this */ 
    value *= rhs.value;

    std::cout << rhs.value << " = " << *this << std::endl;
    std::cout << std::endl;

    return *this;
}

/** Multiplication Allocation Operator [*]. */
inline Double operator*(Double lhs, const Double& rhs)
{
    std::cout << &lhs << " - " << typeid(lhs).name() << " - Called Mutliplication Allocation Operator [*] from address " << &rhs << std::endl;

    /** Call to class member function */
    lhs *= rhs; 
    return lhs;
}

/** Division Assignment Operator [/=]. */
inline Double& Double::operator/=(const Double& rhs)
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
inline Double operator/(Double lhs, const Double& rhs)
{
    std::cout << &lhs << " - " << typeid(lhs).name() << " - Called Division Allocation Operator [/] with address " << &rhs << std::endl;

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
inline Double::operator int() const noexcept
{ 
    std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Conversion Operator int()" << std::endl;

    return *this;
}

/** Conversion Operator bool(). */
inline Double::operator bool() const noexcept
{
    std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Conversion Operator bool()" << std::endl;

    return *this;
}

/** Conversion Operator float(). */
inline Double::operator float() const noexcept
{ 
    std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Conversion Operator float()" << std::endl;

    return *this;
}

/** Conversion Operator double(). */
inline Double::operator double() const noexcept
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
inline bool operator==(const Double& lhs, const Double& rhs)
{
    /* do actual comparison */
    return (lhs == rhs) ? true : false;
}

/** Inequality Comparison Operator [!=]. */
inline bool operator!=(const Double& lhs, const Double& rhs)
{
    return !operator==(lhs, rhs);
}

/** Less-Than Comparison Operator [<]. */
inline bool operator< (const Double& lhs, const Double& rhs)
{
    /* do actual comparison */
    return (lhs < rhs) ? true : false;
}

/** Greater-Than Comparison Operator [>]. */
inline bool operator> (const Double& lhs, const Double& rhs)
{
    return  operator< (rhs, lhs);
}

/** Less-Than or Equal-To Comparison Operator [<=]. */
inline bool operator<=(const Double& lhs, const Double& rhs)
{
    return !operator> (lhs,rhs);
}

/** Greater-Than or Equal-To Comparison Operator [>=]. */
inline bool operator>=(const Double& lhs, const Double& rhs)
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
inline void* Double::operator new(std::size_t count)
{
    //std::cout << &(*this) << " - " << typeid(*this).name() << " - Called void* operator new(std::size_t count) = " << count << std::endl;

    std::cout << "custom new for size " << count << '\n';
    return ::operator new(count);
}

/** Operator Delete. */
inline void Double::operator delete(void* ptr)
{
    ::operator delete(ptr);
}

/** Operator New Array. */
inline void* Double::operator new[](std::size_t count)
{
    std::cout << "custom new[] for size " << count << '\n';
    return ::operator new[](count);
}

/** Operator Delete Array. */
inline void Double::operator delete[](void* ptr)
{
    ::operator delete[](ptr);
}

/** Operator New Placement. */
inline void* Double::operator new(std::size_t count, void* p)
{
    std::cout << "custom placement new called, p = " << p << '\n';
    return ::operator new(count, p);
}

/** Operator Delete Placement. */
inline void Double::operator delete(void* ptr, void* p)
{
    std::cout << "custom placement delete called, p = " << p << '\n';
    ::operator delete(ptr, p);
}

/** Operator New Array Placement. */
inline void* Double::operator new[](std::size_t count,void* p)
{
    std::cout << "custom placement new called, p = " << p << '\n';
    return ::operator new[](count, p);
}

/** Operator Delete Array Placement. */
inline void Double::operator delete[](void* ptr, void* p)
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
inline Double Double::val() 
{
    std::cout << &(*this) << " - " << typeid(*this).name() << " - Called function: Int val() = " << *this << std::endl;

    return value;
}

/** Returns a reference to the current value. */
inline Double& Double::get() 
{
    std::cout << &(*this) << " - " << typeid(*this).name() << " - Called function: Int& get() = " << *this << std::endl;

    return *this; 
}

/** Returns the address-of the current value. */
inline Double* Double::addressOf() 
{
    std::cout << &(*this) << " - " << typeid(*this).name() << " - Called function: Int* addressOf() = " << &(*this) << std::endl;
    return &(*this);
}

/** Returns the size of the current value. */
inline int Double::sizeOf() 
{
    std::cout << &(*this) << " - " << typeid(*this).name() << " - Called function: int sizeOf() = " << sizeof(*this) << std::endl;
    return sizeof(*this);
}

inline const type_info& Double::typeID()
{
    std::cout << &(*this) << " - " << typeid(*this).name() << " - Called function: const type_info& typeID()" << std::endl;

    return typeid(*this);
}

inline const char* Double::name() const noexcept
{
    std::cout << &(*this) << " - " << typeid(*this).name() << " - Called function: const char* name() const noexcept = " << typeid(*this).name() << std::endl;

    return typeid(*this).name();
}

inline const char* Double::raw_name() const noexcept
{
    std::cout << &(*this) << " - " << typeid(*this).name() << " - Called function: const char* raw_name() const noexcept = " << typeid(*this).raw_name() << std::endl;

    return typeid(*this).raw_name();
}

inline size_t Double::hash_code() const noexcept
{
    std::cout << &(*this) << " - " << typeid(*this).name() << " - Called function: size_t hash_code() const noexcept = " << typeid(*this).hash_code() << std::endl;

    return typeid(*this).hash_code();
}

/** typeid().before() Operator. */
inline bool Double::before(const type_info &_otherValue)
{
    std::cout << &(*this) << " - " << typeid(*this).name() << " - Called function: bool before(const type_info &_otherValue) = " << typeid(*this).before(_otherValue) << std::endl;

    return typeid(*this).before(_otherValue);
}

/** Prints information about this variable. */
inline void Double::info()
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
inline void Double::dataChecks()
{
    std::cout << &(*this) << " - " << typeid(*this).name() << " - Data checks:" << std::endl;
    get();
    addressOf();
    sizeOf();
    std::cout << std::endl;
}

inline void Double::booleanChecks(const Double& comparison)
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

//==============================================================================
