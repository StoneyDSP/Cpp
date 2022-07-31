/**
  ==============================================================================

    BaseClass.h
    Created: 25 Jul 2022 8:42:29am
    Author:  Nathan J. Hood
    Website: github.com/StoneyDSP
    email:   nathanjhood@googlemail.com

  ==============================================================================
*/

#pragma once

#include "AbstractClass.h"
#include "BaseClass.h"

class DerivedClass : public AbstractClass
{
public:
    
    //==========================================================================
    //
    //  CONSTRUCTORS
    //
    //==========================================================================

    /** Default Constructor. */
    DerivedClass();

    /** Initialized Constructor. */
    DerivedClass(float initialValue);

    /** Initialized Constructor. */
    DerivedClass(float* initialValue);

    /** Copy Constructor. */
    DerivedClass(DerivedClass& newValue);

    /** Copy Constructor (const). */
    DerivedClass(const DerivedClass& newValue);

    /** Move Constructor. */
    DerivedClass(DerivedClass&& otherValue);

    /** Destructor. */
    ~DerivedClass() noexcept;

    //==========================================================================
    /** Assertions to check Constructor succeeded */
    void assertion();
	//==========================================================================

    //==========================================================================
    
    //==========================================================================
    //
    //  ACCESSOR FUNCTIONS
    //
    //==========================================================================
    
    //==========================================================================
    /** Returns a reference to the current value. */
    DerivedClass& get();

    /** Returns the address-of the current value. */
    DerivedClass* addressOf();

    /** Returns the size of the current value. */
    int sizeOf();

    const type_info& typeID();

    const char* name() const noexcept;

    const char* raw_name() const noexcept;

    size_t hash_code() const noexcept;

    /** typeid().before() Operator. */
    bool before(const type_info &_otherValue);

    /** Prints information about this variable. */
    void info();

    /** Operator bool(). */
    operator bool() const noexcept
    {
        std::cout << &(*this) << " - " << typeid(*this).name() << " - Called operator bool()" << std::endl;

        return this->value;
    }

	float getValue() override
    {
        return value;
    }
};

//==========================================================================

//==========================================================================
//
//  CONSTRUCTORS
//
//==========================================================================

DerivedClass::DerivedClass() : AbstractClass()
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
DerivedClass::DerivedClass(float initialValue) : AbstractClass(initialValue)
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
DerivedClass::DerivedClass(float* initialValue) : AbstractClass(initialValue)
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
DerivedClass::DerivedClass(DerivedClass& newValue) : AbstractClass(newValue)
{
	std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Copy Constructor from address " << &newValue << " = " << newValue.value << "!" << std::endl;
	assertion();
	std::cout << &(*this) << " - " << typeid(*this).name() << " - Copy Constructed!" << std::endl;
	std::cout << &(*this) << " - " << typeid(*this).name() << " - newValue = " << *this << std::endl;
	std::cout << std::endl;
	info();
	std::cout << std::endl;
}

DerivedClass::DerivedClass(const DerivedClass& newValue) : AbstractClass(newValue)
{
	std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Copy Constructor (const) from address " << &newValue << " = " << newValue.value << "!" << std::endl;
	assertion();
	std::cout << &(*this) << " - " << typeid(*this).name() << " - Copy Constructed (const)!" << std::endl;
	std::cout << &(*this) << " - " << typeid(*this).name() << " - newValue = " << *this << std::endl;
	std::cout << std::endl;
	info();
	std::cout << std::endl;
}

/** Move Constructor. */
DerivedClass::DerivedClass(DerivedClass&& otherValue) : AbstractClass()
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
DerivedClass::~DerivedClass() noexcept
{
	std::cout << &(*this) << " - " << typeid(*this).name() << " - Called Destructor!" << std::endl;
	std::cout << &(*this) << " - " << typeid(*this).name() << " - Destroyed!" << std::endl;
	std::cout << &(*this) << " - " << typeid(*this).name() << " = " << *this << std::endl;
	std::cout << std::endl;
	info();
	std::cout << std::endl;
}

//==========================================================================
/** Assertions to check Constructor succeeded */
void DerivedClass::assertion()
{ 
	assert(this);
	std::cout << &(*this) << " - " << typeid(*this).name() << " - Passed assertion check!" << std::endl;
}

//==============================================================================
//
//  ACCESSOR FUNCTIONS
//
//==============================================================================

DerivedClass& DerivedClass::get() 
{
	std::cout << &(*this) << " - " << typeid(*this).name() << " - Called function: Float& get() = " << *this << std::endl;

	return *this; 
}

DerivedClass* DerivedClass::addressOf() 
{
	std::cout << &(*this) << " - " << typeid(*this).name() << " - Called function: Float* addressOf() = " << &(*this) << std::endl;
	return &(*this);
}

int DerivedClass::sizeOf() 
{
	std::cout << &(*this) << " - " << typeid(*this).name() << " - Called function: int sizeOf() = " << sizeof(*this) << std::endl;
	return sizeof(*this);
}

const type_info& DerivedClass::typeID()
{
	std::cout << &(*this) << " - " << typeid(*this).name() << " - Called function: const type_info& typeID()" << std::endl;

	return typeid(*this);
}

const char* DerivedClass::name() const noexcept
{
	std::cout << &(*this) << " - " << typeid(*this).name() << " - Called function: const char* name() const noexcept = " << typeid(*this).name() << std::endl;

	return typeid(*this).name();
}

const char* DerivedClass::raw_name() const noexcept
{
	std::cout << &(*this) << " - " << typeid(*this).name() << " - Called function: const char* raw_name() const noexcept = " << typeid(*this).raw_name() << std::endl;

	return typeid(*this).raw_name();
}

size_t DerivedClass::hash_code() const noexcept
{
	std::cout << &(*this) << " - " << typeid(*this).name() << " - Called function: size_t hash_code() const noexcept = " << typeid(*this).hash_code() << std::endl;

	return typeid(*this).hash_code();
}

bool DerivedClass::before(const type_info &_otherValue)
{
	std::cout << &(*this) << " - " << typeid(*this).name() << " - Called function: bool before(const type_info &_otherValue) = " << typeid(*this).before(_otherValue) << std::endl;

	return typeid(*this).before(_otherValue);
}

void DerivedClass::info()
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
	std::cout << &(*this) << " - member &value = " << &(value) << std::endl;
	std::cout << &(*this) << " - member size in bytes = " << sizeof(value) << std::endl;
	std::cout << std::endl;
}
