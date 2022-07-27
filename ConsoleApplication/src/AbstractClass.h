/**
  ==============================================================================

    AbstractClass.h
    Created: 25 Jul 2022 8:42:29am
    Author:  Nathan J. Hood
    Website: github.com/StoneyDSP
    email:   nathanjhood@googlemail.com

  ==============================================================================
*/

#pragma once

#include <assert.h>
#include <iostream>
#include <typeinfo>

class AbstractClass
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
    AbstractClass() : value()
    {
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Default Constructor!" << std::endl;
        assertion();
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Default Constructed!" << std::endl;
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Value = " << value << std::endl;
        std::cout << std::endl;
        info();
        std::cout << std::endl;
    }

    /** Initialized Constructor. */
    AbstractClass(float initialValue) : value(initialValue)
    {
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Initialized Constructor from address " << &initialValue << " = " << initialValue << "!" << std::endl;
        assertion();
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Initialized Constructed!" << std::endl;
        std::cout << &(*this) << " - " << typeid(*this).name() << " - initialValue = " << value << std::endl;
        std::cout << std::endl;
        info();
        std::cout << std::endl;
    }

    /** Initialized Constructor. */
    AbstractClass(float* initialValue) : value(*(initialValue))
    {
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Initialized Constructor from address " << &initialValue << " = " << initialValue << "!" << std::endl;
        assertion();
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Initialized Constructed!" << std::endl;
        std::cout << &(*this) << " - " << typeid(*this).name() << " - initialValue = " << value << std::endl;
        std::cout << std::endl;
        info();
        std::cout << std::endl;
    }

    /** Copy Constructor. */
    AbstractClass(AbstractClass& newValue) : value(newValue.value)
    {
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Copy Constructor from address " << &newValue << " = " << newValue.value << "!" << std::endl;
        assertion();
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Copy Constructed!" << std::endl;
        std::cout << &(*this) << " - " << typeid(*this).name() << " - newValue = " << value << std::endl;
        std::cout << std::endl;
        info();
        std::cout << std::endl;
    }

    /** Copy Constructor (const). */
    AbstractClass(const AbstractClass& newValue) : value(newValue.value)
    {
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Copy Constructor (const) from address " << &newValue << " = " << newValue.value << "!" << std::endl;
        assertion();
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Copy Constructed (const)!" << std::endl;
        std::cout << &(*this) << " - " << typeid(*this).name() << " - newValue = " << value << std::endl;
        std::cout << std::endl;
        info();
        std::cout << std::endl;
    }

    /** Move Constructor. */
    AbstractClass(AbstractClass&& otherValue) : value()
    {
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Move Constructor from address " << &otherValue << " = " << otherValue.value << "!" << std::endl;

        // Assign the class data members from the source object to the 
        // object that is being constructed:
        value = otherValue.value;

        // Assign the data members of the source object to default values. 
        // This prevents the destructor from freeing resources (such as memory) 
        // multiple times:
        otherValue.value = 0.0f;

        assertion();
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Move Constructed!" << std::endl;
        std::cout << &(*this) << " - " << typeid(*this).name() << " = " << value << std::endl;
        std::cout << std::endl;
        info();
        std::cout << std::endl;
    }

    /** Destructor. */
    virtual ~AbstractClass() noexcept = 0;

    //==========================================================================
    /** Assertions to check Constructor succeeded */
    virtual void assertion()
    {
        assert(this);
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Passed assertion check!" << std::endl;
    }
    //==========================================================================

    //==========================================================================
    
    //==========================================================================
    //
    //  ACCESSOR FUNCTIONS
    //
    //==========================================================================
    
    //==========================================================================
    /** Returns a reference to the current value. */
    virtual AbstractClass& get()
    {
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Called function: AbstractClass& get() = " << this << std::endl;

        return *this;
    }

    /** Returns the address-of the current value. */
    virtual AbstractClass* addressOf() 
    {
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Called function: Float* addressOf() = " << &(*this) << std::endl;
        return &(*this);
    }

    /** Returns the size of the current value. */
    virtual int sizeOf() 
    {
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Called function: int sizeOf() = " << sizeof(*this) << std::endl;
        return sizeof(*this);
    }

    virtual const type_info& typeID()
    {
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Called function: const type_info& typeID()" << std::endl;

        return typeid(*this);
    }

    virtual const char* name() const noexcept
    {
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Called function: const char* name() const noexcept = " << typeid(*this).name() << std::endl;

        return typeid(*this).name();
    }

    virtual const char* raw_name() const noexcept
    {
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Called function: const char* raw_name() const noexcept = " << typeid(*this).raw_name() << std::endl;

        return typeid(*this).raw_name();
    }

    virtual size_t hash_code() const noexcept
    {
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Called function: size_t hash_code() const noexcept = " << typeid(*this).hash_code() << std::endl;

        return typeid(*this).hash_code();
    }

    /** typeid().before() Operator. */
    virtual bool before(const type_info &_otherValue)
    {
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Called function: bool before(const type_info &_otherValue) = " << typeid(*this).before(_otherValue) << std::endl;

        return typeid(*this).before(_otherValue);
    }

    /** Prints information about this variable. */
    virtual void info()
    {
        std::cout << &(*this) << " - " << typeid(*this).name() << " - info:" << std::endl;
        std::cout << std::endl;
        std::cout << &(*this) << " - name - " << typeid(*this).name() << std::endl;
        std::cout << &(*this) << " - raw name - " << typeid(*this).raw_name() << std::endl;
        std::cout << &(*this) << " - hash code - " << typeid(*this).hash_code() << std::endl;
        std::cout << &(*this) << " - value = " << value << std::endl;
        std::cout << &(*this) << " - &value = " << &(*this) << std::endl;
        std::cout << &(*this) << " - size in bytes = " << sizeof(*this) << std::endl;
        std::cout << std::endl;
        std::cout << &(*this) << " - member type - " << typeid(value).name() << std::endl;
        std::cout << &(*this) << " - member raw name - " << typeid(value).raw_name() << std::endl;
        std::cout << &(*this) << " - member hash code - " << typeid(value).hash_code() << std::endl;
        std::cout << &(*this) << " - member value = " << value << std::endl;
        std::cout << &(*this) << " - member &value = " << &(value) << std::endl;
        std::cout << &(*this) << " - member size in bytes = " << sizeof(value) << std::endl;
        std::cout << std::endl;
    }

    //==========================================================================

    //==========================================================================
    //
    //  TYPE CONVERSION OPERATORS
    //
    //==========================================================================

    //==========================================================================
    /** Opertor int(). */
    virtual operator int() const noexcept
    { 
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Called operator int()" << std::endl;

        return this->value;
    }
    
    /** Operator bool(). */
    virtual operator bool() const noexcept
    {
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Called operator bool()" << std::endl;

        return this->value;
    }
    
    /** Operator float(). */
    virtual operator float() const noexcept
    { 
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Operator float()" << std::endl;

        return this->value;
    }

    /** Operator double(). */
    virtual operator double() const noexcept
    { 
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Operator double()" << std::endl; 

        return this->value;
    }
    //==========================================================================

    virtual float getValue() = 0;

    float value {};
};

AbstractClass::~AbstractClass() noexcept
{
    std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Destructor!" << std::endl;
    std::cout << &(*this) << " - " << typeid(*this).name() << " - Destroyed!" << std::endl;
    std::cout << &(*this) << " - " << typeid(*this).name() << " = " << value << std::endl;
    std::cout << std::endl;
    info();
    std::cout << std::endl;
}

float AbstractClass::getValue()
{
    return value;
}


//==============================================================================

//==============================================================================
//
//  IOSTREAM OPERATOR NON-MEMBER FUNCTIONS
//
//==============================================================================

//==============================================================================
inline std::ostream& operator<<(std::ostream& ostream, AbstractClass& source)
{
    ostream << source.value;

    return ostream;
}

inline std::istream& operator>>(std::istream& istream, AbstractClass& source)
{
  if(source.sizeOf() == 0)
    istream.setstate(std::ios::failbit);

  return istream;
}
//==============================================================================
