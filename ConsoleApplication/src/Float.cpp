
/**
  ==============================================================================

    Float.cpp
    Created: 16 Jul 2022 12:58:03am
    Author:  Nathan J. Hood
    Website: github.com/StoneyDSP
    email:   nathanjhood@googlemail.com

  ==============================================================================
*/

#include "Float.h"

// To-do...
// 1. Modulus Operator [x]
// 2. Binary Bitwise Operators [x]
// 3. Overhaul "typeID()" Operator(s) (how?)
// 4. Unary operators
//==============================================================================

//==============================================================================
//
//  CONSTRUCTORS
//
//==============================================================================

//==============================================================================
/** Default Constructor. */
Float::Float() : value(new float(0.0F))
{
    std::cout << this << " - " << typeid(*this).name() << " - Called Default Constructor!" << std::endl;
    assertion();
    std::cout << this << " - " << typeid(*this).name() << " - Default Constructed!" << std::endl;
    std::cout << this << " - " << typeid(*this).name() << " - Initial Value = " << *value << std::endl;
    std::cout << std::endl;
    info();
    std::cout << std::endl;
}

/** Initialized Constructor. */
Float::Float(float initialValue) : value(&initialValue)
{
    std::cout << this << " - " << typeid(*this).name() << " - Called Initialized Constructor from address " << &initialValue << " = " << initialValue << "!" << std::endl;
    assertion();
    std::cout << this << " - " << typeid(*this).name() << " - Initialized Constructed!" << std::endl;
    std::cout << this << " - " << typeid(*this).name() << " - Initial Value = " << *value << std::endl;
    std::cout << std::endl;
    info();
    std::cout << std::endl;
}

/** Initialized Constructor. */
Float::Float(float* initialValue) : value(initialValue)
{
    std::cout << this << " - " << typeid(*this).name() << " - Called Initialized Constructor from address " << &initialValue << " = " << initialValue << "!" << std::endl;
    assertion();
    std::cout << this << " - " << typeid(*this).name() << " - Initialized Constructed!" << std::endl;
    std::cout << this << " - " << typeid(*this).name() << " - Initial Value = " << *value << std::endl;
    std::cout << std::endl;
    info();
    std::cout << std::endl;
}

/** Copy Constructor. */
Float::Float(Float& newValue) : value(nullptr)
{
    std::cout << this << " - " << typeid(*this).name() << " - Called Copy Constructor from address " << &newValue << " = " << newValue.value << "!" << std::endl;
    *this = newValue;
    
    assertion();
    
    std::cout << this << " - " << typeid(*this).name() << " - Copy Constructed!" << std::endl;
    std::cout << this << " - " << typeid(*this).name() << " - Initial Value = " << *value << std::endl;
    std::cout << std::endl;
    info();
    std::cout << std::endl;
}

/** Copy Constructor (const). */
Float::Float(const Float& newValue) : value(nullptr)
{
    std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Copy Constructor (const) from address " << &newValue << " = " << newValue.value << "!" << std::endl;
    
    *this = newValue;
    
    assertion();
    std::cout << this << " - " << typeid(*this).name() << " - Copy Constructed (const)!" << std::endl;
    std::cout << this << " - " << typeid(*this).name() << " - Initial Value = " << *value << std::endl;
    std::cout << std::endl;
    info();
    std::cout << std::endl;
}

/** Move Constructor. */
Float::Float(Float&& otherValue) : value(nullptr)
{
    std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Move Constructor from address " << &otherValue << " = " << otherValue << "!" << std::endl;

    value = otherValue.value;
    *otherValue.value = 0.0F;
    otherValue.value = nullptr;

    assertion();
    std::cout << this << " - " << typeid(*this).name() << " - Move Constructed!" << std::endl;
    std::cout << this << " - " << typeid(*this).name() << " - Initial Value = " << *value << std::endl;
    std::cout << std::endl;
    info();
    std::cout << std::endl;
}

/** Destructor. */
Float::~Float() noexcept
{
    std::cout << this << " - " << typeid(*this).name() << " - Called Destructor!" << std::endl;

    if (value == nullptr)
    {
        std::cout << this << " - " << typeid(*this).name() << " - Final Value = nullptr" << std::endl;
    }

    else
    {
        std::cout << this << " - " << typeid(*this).name() << " - Final Value = " << *value << std::endl;

        *value = 0.0F;
        value = nullptr;
    }

    delete value;

    std::cout << this << " - " << typeid(*this).name() << " - Destroyed!" << std::endl;
    std::cout << std::endl;
}
//==============================================================================

//==============================================================================
//
//  COPY & MOVE ASSIGNMENT OPERATORS
//
//==============================================================================

//==============================================================================
/** Copy Assignment Operator [=]. */
Float& Float::operator=(Float& newValue)
{
    std::cout << this << " - " << typeid(*this).name() << " - Called Copy Assignment Operator [=] from address " << &newValue << " = " << newValue.value << std::endl;

    // Free the resource
    value = nullptr;

    // Copy the data from the source object.
    value = newValue.value;

    return *this;
}

/** Copy Assignment Operator (const) [=]. */
Float& Float::operator=(const Float& newValue)
{
    std::cout << this << " - " << typeid(*this).name() << " - Called Copy Assignment Operator (const) [=] from address " << &newValue << " = " << newValue.value << std::endl;
    
    // Free the resource
    value = nullptr;

    // Copy the data from the source object.
    value = newValue.value;

    return *this;
}

/** Move Assignment Operator [=]. */
Float& Float::operator=(Float&& otherValue)
{
    std::cout << this << " - " << typeid(*this).name() << " - Called Move Assignment Operator [=] from address " << &otherValue << " = " << otherValue.value;

    //* Performs no operation if you try to assign the object to itself. */
    if (&otherValue != this)
    {
        // Free the resource
        *value = 0.0F;
        value = nullptr;

        // Copy the data from the source object.
        value = otherValue.value;

        // Release the data from the source object so that
        // the destructor does not free the memory multiple times.
        *otherValue.value = 0.0F;
        otherValue.value = nullptr;

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
Float& Float::operator++()
{
    std::cout << this << " - " << typeid(*this).name() << " - Called Increment Prefix Operator [++]" << std::endl;
    std::cout << this << " - " << typeid(*this).name() << " - " << *value << "++ ";

    ++* this; // Do actual increment.

    std::cout << " = " << *value << std::endl;
    std::cout << std::endl;

    return *this;
}

/** Increment Postfix Operator [++]. */
Float Float::operator++(int)
{
    std::cout << this << " - " << typeid(*this).name() << " - Called Increment Postfix Operator [++]" << std::endl;

    Float tmp{ *this };

    ++(*this); // Call to Prefix Operator.

    return tmp;
}

/** Decrement Prefix Operator [--]. */
Float& Float::operator--()
{
    std::cout << this << " - " << typeid(*this).name() << " - Called Decrement Prefix Operator [--]" << std::endl;
    std::cout << this << " - " << typeid(*this).name() << " - " << *value << "-- ";

    --* this; // Do actual decrement.

    std::cout << " = " << *value << std::endl;
    std::cout << std::endl;

    return *this;
}

/** Decrement Postfix Operator [--]. */
Float Float::operator--(int)
{
    std::cout << this << " - " << typeid(*this).name() << " - Called Decrement Postfix Operator [--]" << std::endl;

    Float tmp{ *this };

    --(*this);   // Call to Prefix Operator.

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
Float& Float::operator+=(const Float& rhs)
{
    std::cout << this << " - " << typeid(*this).name() << " - Called Addition Assignment Operator [+=] with address " << &rhs << " = " << *rhs.value << std::endl;
    std::cout << this << " - " << typeid(*this).name() << " - " << *value << " += " << *rhs.value << " = ";

    *value = *value + *rhs.value; // Actual addition of rhs to *this.

    std::cout << *value << std::endl;
    std::cout << std::endl;

    return *this;
}

/** Subtraction Assignment Operator [-=]. */
Float& Float::operator-=(const Float& rhs)
{
    std::cout << this << " - " << typeid(*this).name() << " - Called Subtraction Assignment Operator [-=] with address " << &rhs << " = " << *rhs.value << std::endl;
    std::cout << this << " - " << typeid(*this).name() << " - " << *value << " -= " << *rhs.value << " = ";

    *value = *value - *rhs.value; // Actual subtraction of rhs from *this.

    std::cout << *value << std::endl;
    std::cout << std::endl;

    return *this;
}

/** Multiplication Assignment Operator [*=]. */
Float& Float::operator*=(const Float& rhs)
{
    std::cout << this << " - " << typeid(*this).name() << " - Called Multiplication Assignment Operator [*=] with address " << &rhs << " = " << *rhs.value << std::endl;
    std::cout << this << " - " << typeid(*this).name() << " - " << *value << " *= " << *rhs.value << " = ";

    *value = *value * *rhs.value; // Actual multiplication of rhs with *this.

    std::cout << *value << std::endl;
    std::cout << std::endl;

    return *this;
}

/** Division Assignment Operator [/=]. */
inline Float& Float::operator/=(const Float& rhs)
{
    std::cout << this << " - " << typeid(*this).name() << " - Called Division Assignment Operator [/=] with address " << &rhs << " = " << *rhs.value << std::endl;
    std::cout << this << " - " << typeid(*this).name() << " - " << *value << " /= " << *rhs.value << " = ";

    *value = *value / *rhs.value; // Actual division of *this by rhs.

    std::cout << *value << std::endl;
    std::cout << std::endl;

    return *this;
}


//==========================================================================
//
//  ARITHMETIC OPERATOR NON-MEMBER FUNCTIONS
//
//==========================================================================

/** Addition Allocation Operator [+]. */
friend Float operator+(Float lhs, const Float& rhs) // passing lhs by value helps optimize chained a+b+c, otherwise, both parameters may be const references
{
    std::cout << &lhs << " - " << typeid(lhs).name() << " - Called Addition Allocation Operator [+]  with address " << &rhs << " = " << *rhs.value << std::endl;

    lhs += rhs; // reuse compound assignment
    return { lhs }; // return the result by value (uses move constructor)
}

/** Subtraction Allocation Operator [-]. */
friend Float operator-(Float lhs, const Float& rhs) // passing lhs by value helps optimize chained a-b-c, otherwise, both parameters may be const references
{
    std::cout << &lhs << " - " << typeid(lhs).name() << " - Called Subtraction Allocation Operator [-]  with address " << &rhs << " = " << *rhs.value << std::endl;

    lhs -= rhs; // reuse compound assignment
    return { lhs }; // return the result by value (uses move constructor)
}

/** Multiplication Allocation Operator [*]. */
friend inline Float operator*(Float lhs, const Float& rhs)
{
    std::cout << &lhs << " - " << typeid(lhs).name() << " - Called Mutliplication Allocation Operator [*]  with address " << &rhs << " = " << *rhs.value << std::endl;

    lhs *= rhs; // reuse compound assignment
    return { lhs }; // return the result by value (uses move constructor)
}

/** Division Allocation Operator [/]. */
friend inline Float operator/(Float lhs, const Float& rhs)
{
    std::cout << &lhs << " - " << typeid(lhs).name() << " - Called Division Allocation Operator [/]  with address " << &rhs << " = " << *rhs.value << std::endl;

    lhs /= rhs; // reuse compound assignment
    return { lhs }; // return the result by value (uses move constructor)
}

//==========================================================================

//==========================================================================
//
//  COMPARISON OPERATOR NON-MEMBER FUNCTIONS
//
//==========================================================================

//==========================================================================
/** Equality Comparison Operator [==]. */
friend inline bool operator==(const Float& lhs, const Float& rhs)
{
    std::cout << &lhs << " - " << typeid(lhs).name() << " - Called Equality Comparison Operator [==] with address " << &rhs << " = " << *rhs.value << std::endl;

    return (lhs.value == rhs.value) ? true : false; // do actual comparison
}

/** Inequality Comparison Operator [!=]. */
friend inline bool operator!=(const Float& lhs, const Float& rhs)
{
    std::cout << &lhs << " - " << typeid(lhs).name() << " - Called Inequality Comparison Operator [!=] with address " << &rhs << " = " << *rhs.value << std::endl;

    return !operator==(lhs, rhs);
}

/** Less-Than Comparison Operator [<]. */
friend inline bool operator< (const Float& lhs, const Float& rhs)
{
    std::cout << &lhs << " - " << typeid(lhs).name() << " - Less-Than Comparison Operator [<] with address " << &rhs << " = " << *rhs.value << std::endl;

    return (lhs < rhs) ? true : false; // do actual comparison
}

/** Greater-Than Comparison Operator [>]. */
friend inline bool operator> (const Float& lhs, const Float& rhs)
{
    std::cout << &lhs << " - " << typeid(lhs).name() << " - Called Greater-Than Comparison Operator [>] with address " << &rhs << " = " << *rhs.value << std::endl;

    return  operator< (rhs, lhs);
}

/** Less-Than or Equal-To Comparison Operator [<=]. */
friend inline bool operator<=(const Float& lhs, const Float& rhs)
{
    std::cout << &lhs << " - " << typeid(lhs).name() << " - Called Less-Than or Equal-To Comparison Operator [<=] with address " << &rhs << " = " << *rhs.value << std::endl;

    return !operator> (lhs, rhs);
}

/** Greater-Than or Equal-To Comparison Operator [>=]. */
friend inline bool operator>=(const Float& lhs, const Float& rhs)
{
    std::cout << &lhs << " - " << typeid(lhs).name() << " - Called Greater-Than or Equal-To Comparison Operator [>=] with address " << &rhs << " = " << *rhs.value << std::endl;

    return !operator< (lhs, rhs);
}

//==========================================================================
//
//  TYPE CONVERSION OPERATORS
//
//==========================================================================

/** Conversion Operator Int*(). */
inline explicit operator Int* () noexcept
{
    std::cout << this << " - " << typeid(*this).name() << " - Called Conversion Operator Int()" << std::endl;
    std::cout << std::endl;

    //return &Int(*value);

    return this;
}

/** Conversion Operator const Int*(). */
inline explicit operator const Int* () const noexcept
{
    std::cout << this << " - " << typeid(*this).name() << " - Called Conversion Operator Int()" << std::endl;
    std::cout << std::endl;

    return this;
}

/** Conversion Operator const Int&(). */
inline explicit operator const Int& () const noexcept
{
    std::cout << this << " - " << typeid(*this).name() << " - Called Conversion Operator const Int&()" << std::endl;
    std::cout << std::endl;

    return *this;
}

/** Conversion Operator Int&(). */
inline explicit operator Int& () noexcept
{
    std::cout << this << " - " << typeid(*this).name() << " - Called Conversion Operator Int&()" << std::endl;
    std::cout << std::endl;

    return *this;
}

/** Conversion Operator int*(). */
inline explicit operator int* () const noexcept
{
    std::cout << this << " - " << typeid(*this).name() << " - Called Conversion Operator Int*()" << std::endl;
    std::cout << std::endl;

    return this->value;
}

/** Conversion Operator int(). */
inline explicit operator int() const noexcept
{
    std::cout << this << " - " << typeid(*this).name() << " - Called Conversion Operator int()" << std::endl;
    std::cout << std::endl;

    return int(*value);
}

/** Conversion Operator bool(). */
inline explicit operator bool() const noexcept
{
    std::cout << this << " - " << typeid(*this).name() << " - Called Conversion Operator bool()" << std::endl;
    std::cout << std::endl;

    return bool(*this);
}

/** Conversion Operator float(). */
inline explicit operator float() const noexcept
{
    std::cout << this << " - " << typeid(*this).name() << " - Called Conversion Operator float()" << std::endl;
    std::cout << std::endl;

    return float(*this);
}

/** Conversion Operator double(). */
inline explicit operator double() const noexcept
{
    std::cout << this << " - " << typeid(*this).name() << " - Called Conversion Operator double()" << std::endl;
    std::cout << std::endl;

    return double(*this);
}

//==========================================================================
//
//  DYNAMIC MEMORY OPERATORS
//
//==========================================================================

/** Operator New. */
static inline void* operator new(std::size_t count)
{
    std::cout << "Called void* operator new(std::size_t count) = " << count << " bytes." << std::endl;
    std::cout << std::endl;

    return ::operator new(count);
}

/** Operator Delete. */
static inline void operator delete(void* ptr)
{
    std::cout << "Called void operator delete(void* ptr) = " << ptr << std::endl;
    std::cout << std::endl;

    ::operator delete(ptr);
}

/** Operator New Array. */
static inline void* operator new[](std::size_t count)
{
    std::cout << "Called void* operator new[](std::size_t count) = " << count << " bytes." << std::endl;
    std::cout << std::endl;

    return ::operator new[](count);
}

/** Operator Delete Array. */
static inline void operator delete[](void* ptr)
{
    std::cout << "Called void operator delete[](void* ptr) = " << ptr << std::endl;
    std::cout << std::endl;

    ::operator delete[](ptr);
}

/** Operator New Placement. */
static inline void* operator new(std::size_t count, void* p)
{
    std::cout << "Called void* operator new(std::size_t count, void* p) = " << count << " bytes, " << p << " offset." << std::endl;
    std::cout << std::endl;

    return ::operator new(count, p);
}

/** Operator Delete Placement. */
static inline void operator delete(void* ptr, void* p)
{
    std::cout << "Called void operator delete(void* ptr, void* p) = " << ptr << ", " << p << std::endl;
    std::cout << std::endl;

    ::operator delete(ptr, p);
}

/** Operator New Array Placement. */
static inline void* operator new[](std::size_t count, void* p)
{
    std::cout << "Called void* operator new[](std::size_t count, void* p) = " << count << " bytes, " << p << " offset." << std::endl;
    std::cout << std::endl;

    return ::operator new[](count, p);
}

/** Operator Delete Array Placement. */
static inline void operator delete[](void* ptr, void* p)
{
    std::cout << "Called void operator delete[](void* ptr, void* p) = " << ptr << ", " << p << std::endl;
    std::cout << std::endl;

    ::operator delete(ptr, p);
}