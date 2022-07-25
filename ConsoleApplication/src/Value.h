/**
  ==============================================================================

    Value.h
    Created: 16 Jul 2022 12:58:03am
    Author:  Nathan J. Hood
    Website: github.com/StoneyDSP
    email:   nathanjhood@googlemail.com

  ==============================================================================
*/

#pragma once

#include <assert.h>
#include <iostream>

//#include "UniquePointer.h"

// Issues...
// 1. Ambiguous Constructor calls [X]
// 2. Boolean operator method copying [X]
// 3. Implicit conversion to avoid code duplication



/** Value Class. */
template <typename Type>
class Value
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
    Value() : value()
    {
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Default Constructor!" << std::endl;
        assertion();
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Default Constructed!" << std::endl;
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Value = " << *this << std::endl;
        std::cout << std::endl;
        info();
        std::cout << std::endl;
    }

    // /** Initialized Constructor. */
    Value(Type initialValue) : value(initialValue)
    {
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Initialized Constructor from address " << &initialValue << " = " << initialValue << "!" << std::endl;
        assertion();
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Initialized Constructed!" << std::endl;
        std::cout << &(*this) << " - " << typeid(*this).name() << " - initialValue = " << *this << std::endl;
        std::cout << std::endl;
        info();
        std::cout << std::endl;
    }

    /** Initialized Constructor*. */
    Value(Type* initialValue) : value(*(initialValue))
    {
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Initialized Constructor* from address " << &initialValue << " = " << initialValue << "!" << std::endl;
        assertion();
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Initialized Constructed!" << std::endl;
        std::cout << &(*this) << " - " << typeid(*this).name() << " - initialValue = " << this << std::endl;
        std::cout << std::endl;
        info();
        std::cout << std::endl;
    }

    /** Copy Constructor. */
    Value(Value& newValue) : value(this->value)
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
    Value(const Value& newValue) : value(this->value)
    {
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Copy Constructor (const) from address " << &newValue << " = " << newValue.value << "!" << std::endl;
        this->value = newValue.value;
        assertion();
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Copy Constructed (const)!" << std::endl;
        std::cout << &(*this) << " - " << typeid(*this).name() << " - newValue = " << *this << std::endl;
        std::cout << std::endl;
        info();
        std::cout << std::endl;
    }

    /** Move Constructor. */
    Value(Value&& otherValue) : value(this->value)
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
    ~Value() 
    {
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Destructor!" << std::endl;
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Destroyed!" << std::endl;
        std::cout << &(*this) << " - " << typeid(*this).name() << " = " << this << std::endl;
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
    Value& operator=(Value& newValue)
    {
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Copy Assignment Operator [=] from address " << &newValue << " = " << newValue.value << std::endl;

        // Copy the data from the source object.
        this->value = newValue.value;
        return *this;
    }

    /** Copy Assignment Operator (const) [=]. */
    Value& operator=(const Value& newValue)
    {
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Copy Assignment Operator (const) [=] from address " << &newValue << " = " << newValue.value << std::endl;
        // Copy the data from the source object.
        value = newValue.value;
        return *this;
    }

    /** Move Assignment Operator [=]. */
    Value& operator=(Value&& otherValue)
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
            otherValue.value = 0;

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
    Value& operator++()
    {
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Increment Prefix Operator [++]" << std::endl;
        std::cout << &(*this) << " - " << typeid(*this).name() << " - "<< this->value << "++ ";

        // do actual increment
        this->value++;

        std::cout << " = " << *this << std::endl;
        std::cout << std::endl;

        return *this;
    }

    /** Increment Postfix Operator [++]. */ 
    Value operator++(int)
    {
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Increment Postfix Operator [++]" << std::endl;

        Value tmp = *this;
        ++*this;
        return tmp;
    }

    /** Decrement Prefix Operator [++]. */ 
    Value& operator--()
    {
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Decrement Prefix Operator [--]" << std::endl;
        std::cout << &(*this) << " - " << typeid(*this).name() << " - "<< this->value << "-- ";

        // do actual increment
        this->value--;

        std::cout << " = " << *this << std::endl;
        std::cout << std::endl;

        return *this;
    }

    /** Decrement Postfix Operator [--]. */ 
    Value operator--(int)
    {
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Decrement Postfix Operator [--]" << std::endl;

        Value tmp = *this;
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
    Value& operator+=(const Value& rhs)
    {
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Addition Assignment Operator [+=] with address " << &rhs << " and value = " << rhs.value << std::endl;
        std::cout << &(*this) << " - " << typeid(*this).name() << " - " << this->value << " += ";

        /** actual addition of rhs to *this. */
        this->value += rhs.value;

        std::cout << rhs.value << " = " << *this << std::endl;
        std::cout << std::endl;

        return *this;
    }

    /** Subtraction Assignment Operator [-=]. */
    Value& operator-=(const Value& rhs)
    {
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Subtraction Assignment Operator [-=] with address " << &rhs << " and value = " << rhs.value << std::endl;
        std::cout << &(*this) << " - " << typeid(*this).name() << " - " << this->value << " -= ";

        /** actual subtraction of rhs from *this */
        this->value -= rhs.value;

        std::cout << rhs.value << " = " << *this << std::endl;
        std::cout << std::endl;

        return *this;
    }

    /** Multiplication Assignment Operator [*=]. */
    Value& operator*=(const Value& rhs)
    {
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Multiplication Assignment Operator [*=] with address " << &rhs << " and value = " << rhs.value << std::endl;
        std::cout << &(*this) << " - " << typeid(*this).name() << " - " << this->value << " *= ";

        /** Actual multiplication of rhs with *this */ 
        this->value *= rhs.value;

        std::cout << rhs.value << " = " << *this << std::endl;
        std::cout << std::endl;

        return *this;
    }

    /** Division Assignment Operator [/=]. */
    Value& operator/=(const Value& rhs)
    {
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Division Assignment Operator [/=] with address " << &rhs << " and value = " << rhs.value << std::endl;
        std::cout << &(*this) << " - " << typeid(*this).name() << " - " << this->value << " /= ";

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
    // /** Operator (). */
    // Value operator ()() const noexcept
    // {
    //     return *this;
    // }

    // operator Type() const noexcept
    // {
    //     return *this;
    // }

    /** Opertor int(). */
    operator int() const noexcept
    { 
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Called operator int()" << std::endl;

        return this->value;
    }
    
    /** Operator bool(). */
    operator bool() const noexcept
    {
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Called operator bool()" << std::endl;

        return value;
    }
    
    /** Operator float(). */
    operator float() const noexcept
    { 
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Operator float()" << std::endl;

        return this->value;
    }

    /** Operator double(). */
    operator double() const noexcept
    { 
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Operator double()" << std::endl; 

        return this->value;
    }

    /** Operator double(). */
    operator long double() const noexcept
    { 
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Operator long double()" << std::endl; 

        return this->value;
    }

    //==========================================================================
    //friend std::ostream& operator<<(std::ostream& ostream, Value<Type>& source);
    //friend std::istream& operator>>(std::istream& istream, Value<Type>& source);
    //==========================================================================
    
    //==========================================================================
    //
    //  ACCESSOR FUNCTIONS
    //
    //==========================================================================
    
    //==========================================================================
    /** Returns the current value. */
    // Value val() 
    // {
    //     std::cout << &(*this) << " - " << typeid(*this).name() << " - Called function: Float val() = " << value << std::endl;

    //     return *this;
    // }

    /** Returns a reference to the current value. */
    Value& get() 
    {
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Called function: Float& get() = " << *this << std::endl;

        return *this; 
    }

    /** Returns the address-of the current value. */
    Value* addressOf() 
    {
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Called function: Float* addressOf() = " << &(*this) << std::endl;
        return &(*this);
    }

    /** Returns the size of the current value. */
    int sizeOf() 
    {
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Called function: int sizeOf() = " << sizeof(*this) << std::endl;
        return sizeof(*this);
    }

    const type_info& typeID()
    {
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Called function: const type_info& typeID()" << std::endl;

        return typeid(*this);
    }

    const char* name() const noexcept
    {
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Called function: const char* name() const noexcept = " << typeid(*this).name() << std::endl;

        return typeid(*this).name();
    }

    const char* raw_name() const noexcept
    {
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Called function: const char* raw_name() const noexcept = " << typeid(*this).raw_name() << std::endl;

        return typeid(*this).raw_name();
    }

    size_t hash_code() const noexcept
    {
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Called function: size_t hash_code() const noexcept = " << typeid(*this).hash_code() << std::endl;

        return typeid(*this).hash_code();
    }

    /** typeid().before() Operator. */
    bool before(const type_info &_otherValue)
    {
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Called function: bool before(const type_info &_otherValue) = " << typeid(*this).before(_otherValue) << std::endl;

        return typeid(*this).before(_otherValue);
    }
    
    /** Prints information about this variable. */
    void info()
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
        std::cout << &(*this) << " - member value = " << this->value << std::endl;
        std::cout << &(*this) << " - member &value = " << &(this->value) << std::endl;
        std::cout << &(*this) << " - member size in bytes = " << sizeof(value) << std::endl;
        std::cout << std::endl;
        
        std::cout << std::endl;
    }

    /** Runs and prints a set of data checks on this variable. */
    void dataChecks()
    {
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Data checks:" << std::endl;
        //get();
        addressOf();
        sizeOf();
        std::cout << std::endl;
    }

    void booleanChecks(const Value& comparison = {0.789f})
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
    //==========================================================================

    //==========================================================================
    //
    //  DYNAMIC MEMORY OPERATORS
    //
    //==========================================================================

    //==========================================================================
    /** Operator New. */
    static void* operator new(std::size_t count)
    {
        //std::cout << &(*this) << " - " << typeid(*this).name() << " - Called void* operator new(std::size_t count) = " << count << std::endl;

        std::cout << "custom new for size " << count << '\n';
        return ::operator new(count);
    }

    /** Operator Delete. */
    static void  operator delete(void* ptr)
    {
        ::operator delete(ptr);
    }

    /** Operator New Array. */
    static void* operator new[](std::size_t count)
    {
        std::cout << "custom new[] for size " << count << '\n';
        return ::operator new[](count);
    }

    /** Operator Delete Array. */
    static void  operator delete[](void* ptr)
    {
        ::operator delete[](ptr);
    }

    /** Operator New Placement. */
    static void* operator new(std::size_t count, void* p)
    {
        std::cout << "custom placement new called, p = " << p << '\n';
        return ::operator new(count, p);
    }

    /** Operator Delete Placement. */
    static void  operator delete(void* ptr, void* p)
    {
        std::cout << "custom placement delete called, p = " << p << '\n';
        ::operator delete(ptr, p);
    }

    /** Operator New Array Placement. */
    static void* operator new[](std::size_t count,void* p)
    {
        std::cout << "custom placement new called, p = " << p << '\n';
        return ::operator new[](count, p);
    }

    /** Operator Delete Array Placement. */
    static void  operator delete[](void* ptr, void* p)
    {
        std::cout << "custom placement delete called, p = " << p << '\n';
        ::operator delete(ptr, p);
    }

//protected:
    //==========================================================================
    //
    //  DATA MEMBERS
    //
    //==========================================================================
    /** Value of <Type>. */
    Type value;
};
//==============================================================================

// template class Value<int>;
// template class Value<float>;
// template class Value<double>;
// template class Value<long double>;

//==============================================================================
//
//  BINARY ARITHMETIC OPERATOR NON-MEMBER FUNCTIONS
//
//==============================================================================

//==============================================================================
/** Addition Allocation Operator [+]. */
template <typename Type>
inline Value<Type> operator+(Value<Type> lhs, const Value<Type>& rhs)
{
    std::cout << &lhs << " - " << typeid(&lhs).name() << " - Called Addition Allocation Operator [+] with address " << &rhs << std::endl;

    /** Call to class member function */
    lhs += rhs; 
    return lhs;
}

/** Subtraction Allocation Operator [-]. */
template <typename Type>
inline Value<Type> operator-(Value<Type> lhs, const Value<Type>& rhs)
{
    std::cout << &lhs << " - Called Subtraction Allocation Operator [-] with address " << &rhs << std::endl;

    /** Call to class member function */
    lhs -= rhs; 
    return lhs;
}

/** Multiplication Allocation Operator [*]. */
template <typename Type>
inline Value<Type> operator*(Value<Type> lhs, const Value<Type>& rhs)
{
    std::cout << &lhs << " - Called Mutliplication Allocation Operator [*] with address " << &rhs << std::endl;

    /** Call to class member function */
    lhs *= rhs; 
    return lhs;
}

/** Division Allocation Operator [/]. */
template <typename Type>
inline Value<Type> operator/(Value<Type> lhs, const Value<Type>& rhs)
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
/** Equality Comparison Operator [==]. */
template <typename Type>
inline bool operator==(const Value<Type>& lhs, const Value<Type>& rhs)
{
    /* do actual comparison */
    return (lhs == rhs) ? true : false;
}

/** Inequality Comparison Operator [!=]. */
template <typename Type>
inline bool operator!=(const Value<Type>& lhs, const Value<Type>& rhs)
{
    return !operator==(lhs, rhs);
}

/** Less-Than Comparison Operator [<]. */
template <typename Type>
inline bool operator< (const Value<Type>& lhs, const Value<Type>& rhs)
{
    /* do actual comparison */
    return (lhs < rhs) ? true : false;
}

/** Greater-Than Comparison Operator [>]. */
template <typename Type>
inline bool operator> (const Value<Type>& lhs, const Value<Type>& rhs)
{
    return  operator< (rhs, lhs);
}

/** Less-Than or Equal-To Comparison Operator [<=]. */
template <typename Type>
inline bool operator<=(const Value<Type>& lhs, const Value<Type>& rhs)
{
    return !operator> (lhs,rhs);
}

/** Greater-Than or Equal-To Comparison Operator [>=]. */
template <typename Type>
inline bool operator>=(const Value<Type>& lhs, const Value<Type>& rhs)
{
    return !operator< (lhs,rhs);
}
//==============================================================================

//==============================================================================
//
//  IOSTREAM OPERATOR NON-MEMBER FUNCTIONS
//
//==============================================================================

//==============================================================================
template <typename Type>
inline std::ostream& operator<<(std::ostream& ostream, Value<Type>& source)
{
    ostream << source.value;

    return ostream;
}

template <typename Type>
inline std::istream& operator>>(std::istream& istream, Value<Type>& source)
{
  if(source)
    istream.setstate(std::ios::failbit);

  return istream;
}
//==============================================================================

//==============================================================================

// template class Value<int>;
// template class Value<float>;
// template class Value<double>;
// template class Value<long double>;