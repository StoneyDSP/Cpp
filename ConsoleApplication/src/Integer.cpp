
/**
  ==============================================================================

    Integer.cpp
    Created: 28 Jul 2022 08:58:03am
    Author:  Nathan J. Hood
    Website: github.com/StoneyDSP
    email:   nathanjhood@googlemail.com

  ==============================================================================
*/

#include "Integer.h"

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
inline Int::Int() : value{0}
{
    std::cout << this << " - " << typeid(*this).name() << " - Called Default Constructor!" << std::endl;
    //*this = value;
    assertion();
    std::cout << this << " - " << typeid(*this).name() << " - Default Constructed!" << std::endl;
    std::cout << this << " - " << typeid(*this).name() << " - Value = " << value << std::endl;
    std::cout << std::endl;
}

/** Initialized Constructor. */
inline Int::Int(int initialValue) : value{initialValue}
{
    std::cout << this << " - " << typeid(*this).name() << " - Called Initialized Constructor from address " << &initialValue << " = " << initialValue << "!" << std::endl;
    //*this = initialValue;
    assertion();
    std::cout << this << " - " << typeid(*this).name() << " - Initialized Constructed!" << std::endl;
    std::cout << this << " - " << typeid(*this).name() << " - initialValue = " << value << std::endl;
    std::cout << std::endl;
}

/** Initialized Pointer Constructor. */
inline Int::Int(int* initialValue) : value{*initialValue}
{
    std::cout << this << " - " << typeid(*this).name() << " - Called Initialized Pointer Constructor from address " << initialValue << " = " << *initialValue << "!" << std::endl;
    //*this = initialValue;
    assertion();
    std::cout << this << " - " << typeid(*this).name() << " - Initialized Constructed!" << std::endl;
    std::cout << this << " - " << typeid(*this).name() << " - initialValue = " << value << std::endl;
    std::cout << std::endl;
}

/** Copy Constructor. */
inline Int::Int(Int& newValue) : value{newValue.value}
{
    std::cout << this << " - " << typeid(*this).name() << " - Called Copy Constructor from address " << &newValue << " = " << newValue.value << "!" << std::endl;
    //*this = newValue;
    assertion();
    std::cout << this << " - " << typeid(*this).name() << " - Copy Constructed!" << std::endl;
    std::cout << this << " - " << typeid(*this).name() << " - newValue = " << value << std::endl;
    std::cout << std::endl;
}

/** Copy Constructor (const). */
inline Int::Int(const Int& newValue) : value{newValue.value}
{
    std::cout << this << " - " << typeid(*this).name() << " - Called Copy Constructor (const) from address " << &newValue << " = " << newValue.value << "!" << std::endl;
    //*this = newValue;
    assertion();
    std::cout << this << " - " << typeid(*this).name() << " - Copy Constructed (const)!" << std::endl;
    std::cout << this << " - " << typeid(*this).name() << " - newValue = " << value << std::endl;
    std::cout << std::endl;
}

/** Move Constructor. */
inline Int::Int(Int&& otherValue) noexcept : value{otherValue.value}
{
    std::cout << this << " - " << typeid(*this).name() << " - Called Move Constructor from address " << &otherValue << " = " << otherValue << "!" << std::endl;
    //*this = otherValue.value;
    assertion();
    std::cout << this << " - " << typeid(*this).name() << " - Move Constructed!" << std::endl;
    std::cout << this << " - " << typeid(*this).name() << " = " << value << std::endl;
    std::cout << std::endl;
}

/** Destructor. */
inline Int::~Int() noexcept
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
inline Int& Int::operator=(Int& newValue)
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
inline Int& Int::operator=(const Int& newValue)
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
inline Int& Int::operator=(Int&& otherValue) noexcept
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
inline Int& Int::operator++()
{
    std::cout << this << " - " << typeid(*this).name() << " - Called Increment Prefix Operator [++]" << std::endl;
    std::cout << this << " - " << typeid(*this).name() << " - "<< value << "++ ";

    ++value; // Do actual increment.

    std::cout << " = " << value << std::endl;
    std::cout << std::endl;

    return *this;
}

/** Increment Postfix Operator [++]. */ 
inline Int Int::operator++(int)
{
    std::cout << this << " - " << typeid(*this).name() << " - Called Increment Postfix Operator [++]" << std::endl;

    Int tmp {*this};

    ++(*this); // Call to class member function.

    return Int{tmp.value};
}

/** Decrement Prefix Operator [--]. */ 
inline Int& Int::operator--()
{
    std::cout << this << " - " << typeid(*this).name() << " - Called Decrement Prefix Operator [--]" << std::endl;
    std::cout << this << " - " << typeid(*this).name() << " - "<< value << "-- ";

    --value; // Do actual decrement.

    std::cout << " = " << value << std::endl;
    std::cout << std::endl;

    return *this;
}

/** Decrement Postfix Operator [--]. */ 
inline Int Int::operator--(int)
{
    std::cout << this << " - " << typeid(*this).name() << " - Called Decrement Postfix Operator [--]" << std::endl;

    Int tmp {*this};

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
inline Int& Int::operator+=(const Int& rhs)
{
    std::cout << this << " - " << typeid(*this).name() << " - Called Addition Assignment Operator [+=] with address " << &rhs << " = " << rhs.value << std::endl;
    std::cout << this << " - " << typeid(*this).name() << " - " << value << " += " << rhs.value << " = ";

    value = value + rhs.value; // Actual addition of rhs to *this.

    std::cout << value << std::endl;
    std::cout << std::endl;

    return *this;
}

/** Subtraction Assignment Operator [-=]. */
inline Int& Int::operator-=(const Int& rhs)
{
    std::cout << this << " - " << typeid(*this).name() << " - Called Subtraction Assignment Operator [-=] with address " << &rhs << " = " << rhs.value << std::endl;
    std::cout << this << " - " << typeid(*this).name() << " - " << value << " -= " << rhs.value << " = ";

    value = value - rhs.value; // Actual subtraction of rhs from *this.

    std::cout << value << std::endl;
    std::cout << std::endl;

    return *this;
}

/** Multiplication Assignment Operator [*=]. */
inline Int& Int::operator*=(const Int& rhs)
{
    std::cout << this << " - " << typeid(*this).name() << " - Called Multiplication Assignment Operator [*=] with address " << &rhs << " = " << rhs.value << std::endl;
    std::cout << this << " - " << typeid(*this).name() << " - " << value << " *= " << rhs.value << " = ";
 
    value = value * rhs.value; // Actual multiplication of rhs with *this.

    std::cout << value << std::endl;
    std::cout << std::endl;

    return *this;
}

/** Division Assignment Operator [/=]. */
inline Int& Int::operator/=(const Int& rhs)
{
    std::cout << this << " - " << typeid(*this).name() << " - Called Division Assignment Operator [/=] with address " << &rhs << " = " << rhs.value << std::endl;
    std::cout << this << " - " << typeid(*this).name() << " - " << value << " /= " << rhs.value << " = ";

    value = value / rhs.value; // Actual division of *this by rhs.

    std::cout << value << std::endl;
    std::cout << std::endl;

    return *this;
}

/** Modulus Assignment Operator [%=]. */
inline Int& Int::operator%=(const Int& rhs)
{
    std::cout << this << " - " << typeid(*this).name() << " - Called Modulus Assignment Operator [%=] with address " << &rhs << " = " << rhs.value << std::endl;
    std::cout << this << " - " << typeid(*this).name() << " - " << value << " %= " << rhs.value << " = ";

    value = value % rhs.value; // Actual modulo of *this by rhs.

    std::cout << value << std::endl;
    std::cout << std::endl;

    return *this;
}
//==============================================================================

//==============================================================================
//
//  UNARY BITWISE OPERATORS
//
//==============================================================================

//==============================================================================
/** Bitwise NOT Operator [~]. */
inline Int Int::operator~()
{
    std::cout << this << " - " << typeid(*this).name() << " - Called Bitwise NOT Operator [~]" << std::endl;
    std::cout << this << " - " << typeid(*this).name() << " - "<< value << "~ ";

    /** do actual operation. */
    //~value;
    Int result {~value};
    std::cout << " = " << ~value << std::endl;
    std::cout << std::endl;

    return {result};
}
//==============================================================================

//==============================================================================
//
//  BINARY BITWISE OPERATORS
//
//==============================================================================

//==============================================================================
/** Bitwise AND Assignment Operator [&=]. */
inline Int& Int::operator&=(const Int& rhs)
{
    std::cout << this << " - " << typeid(*this).name() << " - Called Bitwise AND Assignment Operator [&=] with address " << &rhs << " = " << rhs.value << std::endl;
    std::cout << this << " - " << typeid(*this).name() << " - " << value << " &= " << rhs.value << " = ";

    value = value & rhs.value; // Actual bitwise OR of rhs and *this.

    std::cout << value << std::endl;
    std::cout << std::endl;

    return *this;
}

/** Bitwise OR Assignment Operator [|=]. */
inline Int& Int::operator|=(const Int& rhs)
{
    std::cout << this << " - " << typeid(*this).name() << " - Called Bitwise OR Assignment Operator [|=] with address " << &rhs << " = " << rhs.value << std::endl;
    std::cout << this << " - " << typeid(*this).name() << " - " << value << " |= " << rhs.value << " = ";

    value = value | rhs.value; // Actual bitwise OR of rhs and *this.

    std::cout << value << std::endl;
    std::cout << std::endl;

    return *this;
}

/** Bitwise XOR Assignment Operator [^=]. */
inline Int& Int::operator^=(const Int& rhs)
{
    std::cout << this << " - " << typeid(*this).name() << " - Called Bitwise XOR Assignment Operator [^=] with address " << &rhs << " = " << rhs.value << std::endl;
    std::cout << this << " - " << typeid(*this).name() << " - " << value << " ^= " << rhs.value << " = ";

    value = value ^ rhs.value; // Actual bitwise OR of rhs and *this.

    std::cout << value << std::endl;
    std::cout << std::endl;

    return *this;
}

/** Bitwise Left Shift Assignment Operator [<<=]. */
inline Int& Int::operator<<=(const Int& rhs)
{
    std::cout << this << " - " << typeid(*this).name() << " - Called Bitwise Left Shift Assignment Operator [<<=] with address " << &rhs << " = " << rhs.value << std::endl;
    std::cout << this << " - " << typeid(*this).name() << " - " << value << " <<= " << rhs.value << " = ";

    value = value << rhs.value; // Actual Bitwise Left Shift of rhs and *this.

    std::cout << value << std::endl;
    std::cout << std::endl;

    return *this;
}

/** Bitwise Right Shift Assignment Operator [>>=]. */
inline Int& Int::operator>>=(const Int& rhs)
{
    std::cout << this << " - " << typeid(*this).name() << " - Called Bitwise Right Shift Assignment Operator [>>=] with address " << &rhs << " = " << rhs.value << std::endl;
    std::cout << this << " - " << typeid(*this).name() << " - " << value << " >>= " << rhs.value << " = ";

    value >>= rhs.value; // Actual Bitwise Right Shift of rhs and *this.

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
inline Int::operator Int() const noexcept
{ 
    std::cout << this << " - " << typeid(*this).name() << " - Called Conversion Operator Int()" << std::endl;
    std::cout << std::endl;

    return value;
}

/** Conversion Operator int(). */
inline Int::operator int() const noexcept
{ 
    std::cout << this << " - " << typeid(*this).name() << " - Called Conversion Operator int()" << std::endl;
    std::cout << std::endl;

    return value;
}

/** Conversion Operator bool(). */
inline Int::operator bool() const noexcept
{
    std::cout << this << " - " << typeid(*this).name() << " - Called Conversion Operator bool()" << std::endl;
    std::cout << std::endl;

    return (value != 0 ? true : false);
}

/** Conversion Operator float(). */
inline Int::operator float() const noexcept
{ 
    std::cout << this << " - " << typeid(*this).name() << " - Called Conversion Operator float()" << std::endl;
    std::cout << std::endl;

    return value;
}

/** Conversion Operator double(). */
inline Int::operator double() const noexcept
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
inline void* Int::operator new(std::size_t count)
{
    std::cout << "Called void* operator new(std::size_t count) = " << count << " bytes." << std::endl;
    std::cout << std::endl;

    return ::operator new(count);
}

/** Operator Delete. */
inline void Int::operator delete(void* ptr)
{
    std::cout << "Called void operator delete(void* ptr) = " << ptr << std::endl;
    std::cout << std::endl;

    ::operator delete(ptr);
}

/** Operator New Array. */
inline void* Int::operator new[](std::size_t count)
{
    std::cout << "Called void* operator new[](std::size_t count) = " << count << " bytes." << std::endl;
    std::cout << std::endl;

    return ::operator new[](count);
}

/** Operator Delete Array. */
inline void Int::operator delete[](void* ptr)
{
    std::cout << "Called void operator delete[](void* ptr) = " << ptr << std::endl;
    std::cout << std::endl;

    ::operator delete[](ptr);
}

/** Operator New Placement. */
inline void* Int::operator new(std::size_t count, void* p)
{
    std::cout << "Called void* operator new(std::size_t count, void* p) = " << count << " bytes, " << p << " offset." << std::endl;
    std::cout << std::endl;

    return ::operator new(count, p);
}

/** Operator Delete Placement. */
inline void Int::operator delete(void* ptr, void* p)
{
    std::cout << "Called void operator delete(void* ptr, void* p) = " << ptr << ", " << p << std::endl;
    std::cout << std::endl;

    ::operator delete(ptr, p);
}

/** Operator New Array Placement. */
inline void* Int::operator new[](std::size_t count, void* p)
{
    std::cout << "Called void* operator new[](std::size_t count, void* p) = " << count << " bytes, " << p << " offset." << std::endl;
    std::cout << std::endl;

    return ::operator new[](count, p);
}

/** Operator Delete Array Placement. */
inline void Int::operator delete[](void* ptr, void* p)
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
inline Int* Int::addressOf() 
{
    std::cout << this << " - " << typeid(*this).name() << " - Called function: Int* addressOf() = " << &(*this) << std::endl;

    return this;
}

/** Returns the size of the current value. */
inline int Int::sizeOf()
{
    std::cout << this << " - " << typeid(*this).name() << " - Called function: int sizeOf() = " << sizeof(*this) << std::endl;

    return sizeof(*this);
}

/** Returns the type info of this variable. */
inline const type_info& Int::typeID()
{
    std::cout << this << " - " << typeid(*this).name() << " - Called function: const type_info& typeID()" << std::endl;

    return typeid(*this);
}

/** Returns the name of this variable. */
inline const char* Int::name() const noexcept
{
    std::cout << this << " - " << typeid(*this).name() << " - Called function: const char* name() const noexcept = " << typeid(*this).name() << std::endl;

    return typeid(*this).name();
}

/** Returns the raw name of this variable. */
inline const char* Int::raw_name() const noexcept
{
    std::cout << this << " - " << typeid(*this).name() << " - Called function: const char* raw_name() const noexcept = " << typeid(*this).raw_name() << std::endl;

    return typeid(*this).raw_name();
}

/** Returns the hash code of this variable. */
inline size_t Int::hash_code() const noexcept
{
    std::cout << this << " - " << typeid(*this).name() << " - Called function: size_t hash_code() const noexcept = " << typeid(*this).hash_code() << std::endl;

    return typeid(*this).hash_code();
}

/** typeid().before() Operator. */
inline bool Int::before(const type_info &_otherValue)
{
    std::cout << this << " - " << typeid(*this).name() << " - Called function: bool before(const type_info &_otherValue) = " << typeid(*this).before(_otherValue) << std::endl;

    return typeid(*this).before(_otherValue);
}

/** Prints information about this variable. */
inline void Int::info()
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
inline void Int::dataChecks()
{
    std::cout << this << " - " << typeid(*this).name() << " - Data checks:" << std::endl;
    addressOf();
    sizeOf();
    std::cout << std::endl;
}

/** Assertions to check Constructor succeeded */
inline void Int::assertion()
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
inline Int operator+(Int lhs, const Int& rhs) // passing lhs by value helps optimize chained a+b+c, otherwise, both parameters may be const references
{
    std::cout << &lhs << " - " << typeid(lhs).name() << " - Called Addition Allocation Operator [+] with address " << &rhs << " = " << rhs.value << std::endl;

    lhs += rhs; // reuse compound assignment
    return {lhs}; // return the result by value (uses move constructor)
}

/** Subtraction Allocation Operator [-]. */ 
inline Int operator-(Int lhs, const Int& rhs) // passing lhs by value helps optimize chained a-b-c, otherwise, both parameters may be const references
{
    std::cout << &lhs << " - " << typeid(lhs).name() << " - Called Subtraction Allocation Operator [-] with address " << &rhs << " = " << rhs.value << std::endl;

    lhs -= rhs; // reuse compound assignment
    return {lhs}; // return the result by value (uses move constructor)
}

/** Multiplication Allocation Operator [*]. */
inline Int operator*(Int lhs, const Int& rhs)
{
    std::cout << &lhs << " - " << typeid(lhs).name() << " - Called Mutliplication Allocation Operator [*] with address " << &rhs << " = " << rhs.value << std::endl;

    lhs *= rhs; // reuse compound assignment
    return {lhs}; // return the result by value (uses move constructor)
}

/** Division Allocation Operator [/]. */
inline Int operator/(Int lhs, const Int& rhs)
{
    std::cout << &lhs << " - " << typeid(lhs).name() << " - Called Division Allocation Operator [/] with address " << &rhs << " = " << rhs.value << std::endl;

    lhs /= rhs; // reuse compound assignment
    return {lhs}; // return the result by value (uses move constructor)
}

/** Modulus Allocation Operator [%]. */
inline Int operator%(Int lhs, const Int& rhs)
{
    std::cout << &lhs << " - " << typeid(lhs).name() << " - Called Modulus Allocation Operator [%] with address " << &rhs << " = " << rhs.value << std::endl;

    lhs %= rhs; // reuse compound assignment
    return {lhs}; // return the result by value (uses move constructor)
}
//==============================================================================

//==============================================================================
//
//  BITWISE OPERATOR NON-MEMBER FUNCTIONS
//
//==============================================================================

//==============================================================================
/** Bitwise AND Allocation Operator [&]. */
inline Int operator&(Int lhs, const Int& rhs)
{
    std::cout << &lhs << " - " << typeid(lhs).name() << " - Called Bitwise AND Allocation Operator [&] with address " << &rhs << " = " << rhs.value << std::endl;

    lhs &= rhs; // reuse compound assignment
    return {lhs}; // return the result by value (uses move constructor)
}

/** Bitwise OR Allocation Operator [|]. */
inline Int operator|(Int lhs, const Int& rhs)
{
    std::cout << &lhs << " - " << typeid(lhs).name() << " - Called Bitwise OR Allocation Operator [|] with address " << &rhs << " = " << rhs.value << std::endl;

    lhs |= rhs; // reuse compound assignment
    return {lhs}; // return the result by value (uses move constructor)
}

/** Bitwise XOR Allocation Operator [^]. */
inline Int operator^(Int lhs, const Int& rhs)
{
    std::cout << &lhs << " - " << typeid(lhs).name() << " - Called Bitwise XOR Allocation Operator [^] with address " << &rhs << " = " << rhs.value << std::endl;

    lhs ^= rhs; // reuse compound assignment
    return {lhs}; // return the result by value (uses move constructor)
}

/** Bitwise Left Shift Allocation Operator [<<]. */
inline Int operator<<(Int lhs, const Int& rhs)
{
    std::cout << &lhs << " - " << typeid(lhs).name() << " - Called Bitwise Left Shift Allocation Operator [<<] with address " << &rhs << " = " << rhs.value << std::endl;

    lhs <<= rhs; // reuse compound assignment
    return {lhs}; // return the result by value (uses move constructor)
}

/** Bitwise Right Shift Allocation Operator [>>]. */
inline Int operator>>(Int lhs, const Int& rhs)
{
    std::cout << &lhs << " - " << typeid(lhs).name() << " - Called Bitwise Right Shift Allocation Operator [>>] with address " << &rhs << " = " << rhs.value << std::endl;

    lhs >>= rhs; // reuse compound assignment
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
inline bool operator==(const Int& lhs, const Int& rhs)
{
    std::cout << &lhs << " - " << typeid(lhs).name() << " - Called Equality Comparison Operator [==] with address " << &rhs << " = " << rhs.value << std::endl;

    return (lhs.value == rhs.value) ? true : false; // do actual comparison
}

/** Inequality Comparison Operator [!=]. */
inline bool operator!=(const Int& lhs, const Int& rhs)
{
    std::cout << &lhs << " - " << typeid(lhs).name() << " - Called Inequality Comparison Operator [!=] with address " << &rhs << " = " << rhs.value << std::endl;

    return !operator==(lhs, rhs);
}

/** Less-Than Comparison Operator [<]. */
inline bool operator< (const Int& lhs, const Int& rhs)
{
    std::cout << &lhs << " - " << typeid(lhs).name() << " - Less-Than Comparison Operator [<] with address " << &rhs << " = " << rhs.value << std::endl;

    return (lhs < rhs) ? true : false; // do actual comparison
}

/** Greater-Than Comparison Operator [>]. */
inline bool operator> (const Int& lhs, const Int& rhs)
{
    std::cout << &lhs << " - " << typeid(lhs).name() << " - Called Greater-Than Comparison Operator [>] with address " << &rhs << " = " << rhs.value << std::endl;

    return  operator< (rhs, lhs);
}

/** Less-Than or Equal-To Comparison Operator [<=]. */
inline bool operator<=(const Int& lhs, const Int& rhs)
{
    std::cout << &lhs << " - " << typeid(lhs).name() << " - Called Less-Than or Equal-To Comparison Operator [<=] with address " << &rhs << " = " << rhs.value << std::endl;

    return !operator> (lhs,rhs);
}

/** Greater-Than or Equal-To Comparison Operator [>=]. */
inline bool operator>=(const Int& lhs, const Int& rhs)
{
    std::cout << &lhs << " - " << typeid(lhs).name() << " - Called Greater-Than or Equal-To Comparison Operator [>=] with address " << &rhs << " = " << rhs.value << std::endl;

    return !operator< (lhs,rhs);
}

/** Runs and prints a set of boolean checks on this variable. */
inline void booleanChecks(const Int& lhs, const Int& rhs)
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