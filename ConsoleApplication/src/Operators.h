/**
  ==============================================================================

    Operators.h
    Created: 29 Jul 2022 10:37:29am
    Author:  Nathan J. Hood
    Website: github.com/StoneyDSP
    email:   nathanjhood@googlemail.com

  ==============================================================================
*/

// namespace stoneydsp
// {

#include <assert.h>
#include <iostream>
#include <typeinfo>

//#include "UniquePointer.h"

//==============================================================================
/** Overloaded Operators. */

// To-do...

// 1. Modulus Operator
// 2. Binary Bitwise Operators
// 3. Overhaul "typeID()" Operator(s) (how?)

//==============================================================================

//==============================================================================
//
//  DECLARATIONS
//
//==============================================================================

//==============================================================================
/** Integer value. */
class Int final
{
public:
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
    Int(Int&& otherValue) noexcept;

    /** Destructor. */
    ~Int() noexcept;

    //==========================================================================
    /** Assertions to check Constructor succeeded */
    void assertion();

	//==========================================================================
	/** Copy Assignment Operator [=]. */
    Int& operator=(Int& newValue);

    /** Copy Assignment Operator (const) [=]. */
    Int& operator=(const Int& newValue);

    /** Move Assignment Operator [=]. */
    Int& operator=(Int&& otherValue) noexcept;

	//==========================================================================
	/** Addition Assignment Operator [+=]. */
    Int& operator+=(const Int& rhs);

	//==========================================================================
	/** Prints information about this variable to Terminal. */
    friend std::ostream& operator<<(std::ostream& ostream, Int& source);

    /** Prints information about this variable to Terminal. */
    friend std::istream& operator>>(std::istream& istream, Int& source);

	int value{};
};
//==============================================================================

//==============================================================================
/** Addition Allocation Operator [+]. */
inline Int operator+(const Int& lhs, const Int& rhs);

//==============================================================================
/** Prints information about this variable to Terminal. */
inline std::ostream& operator<<(std::ostream& ostream, Int& source);

/** Prints information about this variable to Terminal. */
inline std::istream& operator>>(std::istream& istream, Int& source);
//==============================================================================

//==============================================================================
//
//  DEFINITIONS
//
//==============================================================================

//==============================================================================
/** Default Constructor. */
inline Int::Int() : value()
{
    assertion();
}

/** Initialized Constructor. */
inline Int::Int(int initialValue) : value(initialValue)
{
    assertion();
}

/** Initialized Pointer Constructor. */
inline Int::Int(int* initialValue) : value(*initialValue)
{
    assertion();
}

/** Copy Constructor. */
inline Int::Int(Int& newValue) : value()
{
    *this = newValue;
    assertion();
}

/** Copy Constructor (const). */
inline Int::Int(const Int& newValue) : value()
{
    *this = newValue;
    assertion();
}

/** Move Constructor. */
inline Int::Int(Int&& otherValue) noexcept : value(otherValue.value)
{
    // Assign the class data members from the source object to the 
    // object that is being constructed:
    //value = otherValue.value;

    // Assign the data members of the source object to default values. 
    // This prevents the destructor from freeing resources (such as memory) 
    // multiple times:
    otherValue = 0;

    assertion();
}

/** Destructor. */
inline Int::~Int() noexcept
{
}
//==============================================================================
/** Assertions to check Constructor succeeded */
inline void Int::assertion()
{ 
    assert(this != nullptr);
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
    // Copy the data from the source object.
    value = newValue.value;
    return *this;
}

/** Copy Assignment Operator (const) [=]. */
inline Int& Int::operator=(const Int& newValue)
{
    // Copy the data from the source object.
    value = newValue.value;
    return *this;
}

/** Move Assignment Operator [=]. */
inline Int& Int::operator=(Int&& otherValue) noexcept
{
    //* Performs no operation if you try to assign the object to itself. */
    if (&otherValue != this)
    {
        // Free the resource
        //*this = 0;

        // Copy the data from the source object.
        value = otherValue.value;

        // Release the data from the source object so that
        // the destructor does not free the memory multiple times.
        //otherValue = 0;
    }

    return *this;
}
//==============================================================================
/** Addition Assignment Operator [+=]. */
inline Int& Int::operator+=(const Int& rhs)
{
    /** actual addition of rhs to *this. */ 
    value += rhs.value;

    return *this;
}

/** Addition Allocation Operator [+]. */
inline Int operator+(const Int& lhs, const Int& rhs)
{
    /** Call to class member function */
    //lhs += rhs; 
    return lhs.value + rhs.value;
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
    ostream << source;

    return ostream;
}

/** Prints information about this variable to Terminal. */
inline std::istream& operator>>(std::istream& istream, Int& source)
{
//   if(source)
//     istream.setstate(std::ios::failbit);

  return istream;
}
//==============================================================================

//==============================================================================

//} // namespace stoneydsp
