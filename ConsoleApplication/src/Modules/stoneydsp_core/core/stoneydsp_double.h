/*******************************************************************************
 *
 * @file stoneydsp_double.h
 *
 * @author Nathan J. Hood (nathanjhood@googlemail.com)
 * @version 1.0.0.1
 * @date 2022-08-14
 *
 * @copyright Copyright (c) 2022
 *
 *******************************************************************************
*/

#pragma once

#ifndef DOUBLE_H_INCLUDED
#define DOUBLE_H_INCLUDED

namespace stoneydsp
{

/**
 * \todo
 * 1. FIX - Move Constructor using Copy Assignment operator?
 * 2. ADD - Remaining Binary functions?
 * 3.
 * 4.
 */

//==============================================================================
/** Double value. */
class Double
{
public:
    //==========================================================================
    //
    //  CONSTRUCTORS
    //
    //==========================================================================

    /**
     * Default Constructor.
     * @brief Construct a new Double object
     **/
    inline Double() noexcept : value ( 0.0 )
    {
        std::cout << this << " - " << typeid(*this).name() << " - Called Default Constructor!" << std::endl;
        //*this = value;
        assertion();
        std::cout << this << " - " << typeid(*this).name() << " - Default Constructed!" << std::endl;
        std::cout << this << " - " << typeid(*this).name() << " - Initial Value = " << value << std::endl;
        std::cout << std::endl;
    }

    /**
     * Initialized Constructor.
     * @brief Construct a new Double object
     * @param initialValue double
     */
    inline Double(double initialValue) : value ( initialValue )
    {
        std::cout << this << " - " << typeid(*this).name() << " - Called Initialized Constructor from address " << &initialValue << " = " << initialValue << "!" << std::endl;
        //*this = initialValue;
        assertion();
        std::cout << this << " - " << typeid(*this).name() << " - Initialized Constructed!" << std::endl;
        std::cout << this << " - " << typeid(*this).name() << " - Initial Value = " << value << std::endl;
        std::cout << std::endl;
    }

    /**
     * Initialized Constructor (*).
     * @brief Construct a new Double object
     * @param initialValue double*
     */
    inline Double(double* initialValue) : value ( *initialValue )
    {
        std::cout << this << " - " << typeid(*this).name() << " - Called Initialized Constructor from address " << &initialValue << " = " << initialValue << "!" << std::endl;
        //*this = (*initialValue);
        assertion();
        std::cout << this << " - " << typeid(*this).name() << " - Initialized Constructed!" << std::endl;
        std::cout << this << " - " << typeid(*this).name() << " - Initial Value = " << value << std::endl;
        std::cout << std::endl;
    }

    /**
     * Copy Constructor.
     * @brief Construct a new Double object
     * @param newValue Double&
     */
    inline Double(Double& newValue) : value ( 0.0 )
    {
        std::cout << this << " - " << typeid(*this).name() << " - Called Copy Constructor from address " << &newValue << " = " << newValue.value << "!" << std::endl;
        *this = newValue;
        assertion();
        std::cout << this << " - " << typeid(*this).name() << " - Copy Constructed!" << std::endl;
        std::cout << this << " - " << typeid(*this).name() << " - Initial Value = " << value << std::endl;
        std::cout << std::endl;
    }

    /**
     * Copy Constructor (const).
     * @brief Construct a new Double object
     * @param newValue const Double&
     */
    inline Double(const Double& newValue) : value ( 0.0 )
    {
        std::cout << this << " - " << typeid(*this).name() << " - Called Copy Constructor (const) from address " << &newValue << " = " << newValue.value << "!" << std::endl;
        *this = newValue;
        assertion();
        std::cout << this << " - " << typeid(*this).name() << " - Copy Constructed (const)!" << std::endl;
        std::cout << this << " - " << typeid(*this).name() << " - Initial Value = " << value << std::endl;
        std::cout << std::endl;
    }

    /**
     * Move Constructor.
     * @brief Construct a new Double object
     * @param otherValue Double&&
     */
    inline explicit Double(Double&& otherValue) noexcept : value ( 0.0 )
    {
        std::cout << this << " - " << typeid(*this).name() << " - Called Move Constructor from address " << &otherValue << " = " << otherValue.value << "!" << std::endl;
        *this = otherValue;
        assertion();
        std::cout << this << " - " << typeid(*this).name() << " - Move Constructed!" << std::endl;
        std::cout << this << " - " << typeid(*this).name() << " - Initial Value = " << value << std::endl;
        std::cout << std::endl;
    }

    /**
     * Destructor.
     * @brief Destroy the Double object
     */
    inline ~Double() noexcept
    {
        std::cout << this << " - " << typeid(*this).name() << " - Called Destructor!" << std::endl;

        if (value == 0.0)
        {
            std::cout << this << " - " << typeid(*this).name() << " - Final Value = 0" << std::endl;
        }

        else
        {
            std::cout << this << " - " << typeid(*this).name() << " - Final Value = " << value << std::endl;

            value = 0.0;
        }

        std::cout << this << " - " << typeid(*this).name() << " - Destroyed!" << std::endl;
        std::cout << std::endl;
    }

    /**
     * Copy Assignment Operator [=].
     * @brief Copies data from one object instance to this one.
     * @param newValue Double&
     * @return Double&
     **/
    inline Double& operator=(Double& newValue)
    {
        std::cout << this << " - " << typeid(*this).name() << " - Called Copy Assignment Operator [=] from address " << &newValue << " = " << newValue.value << std::endl;

        if (this == &newValue) return *this; // Performs no operation if you try to assign the object to itself.
        value = 0.0; // Free the resource
        value = newValue.value; // Copy the data from the source object.
        return *this;
    }

    /**
     * Copy Assignment Operator [=] (const).
     * @brief Copies data from one object instance to this one.
     * @param newValue const Double&
     * @return Double&
     **/
    inline Double& operator=(const Double& newValue)
    {
        std::cout << this << " - " << typeid(*this).name() << " - Called Copy Assignment Operator [=] from address " << &newValue << " = " << newValue.value << std::endl;

        if (this == &newValue) return *this; //* Performs no operation if you try to assign the object to itself. */
        value = 0.0; // Free the resource
        value = newValue.value; // Copy the data from the source object.
        return *this;
    }

    /**
     * Move Assignment Operator [=].
     * @brief Moves data from one object instance to this one.
     * @param otherValue Double&&
     * @return Double&
     **/
    inline Double& operator=(Double&& otherValue) noexcept
    {
        std::cout << this << " - " << typeid(*this).name() << " - Called Move Assignment Operator [=] from address " << &otherValue << " = " << otherValue.value;

        if (this == &otherValue)
        {
            std::cout << " - Move failed!" << std::endl;
            std::cout << std::endl;

            return *this;
        }

        else // Performs no operation if you try to assign the object to itself.
        {
            value = 0.0; // Free the resource
            value = otherValue.value; // Copy the data from the source object.
            otherValue.value = 0.0; // Release the data from the source object so that  the destructor does not free the memory multiple times.

            std::cout << " - Move successfull!" << std::endl;
            std::cout << std::endl;
        }

        return *this;
    }

    //==========================================================================
    //
    //  BINARY ARITHMETIC OPERATORS
    //
    //==========================================================================

    /**
     * Addition Assignment Operator [+=].
     * @brief Adds rhs to *this.
     * @param rhs const Double&
     * @return Double&
     */
    inline Double& operator+=(const Double& rhs)
    {
        std::cout << this << " - " << typeid(*this).name() << " - Called " __FUNCTION__ " with address " << &rhs << " = " << rhs.value << std::endl;
        std::cout << this << " - " << typeid(*this).name() << " - " << value << " += " << rhs.value << " = ";

        value = value + rhs.value; // Actual addition of rhs to *this.

        std::cout << value << std::endl;
        std::cout << std::endl;

        return *this;
    }

    /**
     * Subtraction Assignment Operator [-=].
     * @brief Subtracts rhs from *this.
     * @param rhs const Double&
     * @return Double&
     */
    inline Double& operator-=(const Double& rhs)
    {
        std::cout << this << " - " << typeid(*this).name() << " - Called " __FUNCTION__ " with address " << &rhs << " = " << rhs.value << std::endl;
        std::cout << this << " - " << typeid(*this).name() << " - " << value << " -= " << rhs.value << " = ";

        value = value - rhs.value; // Actual subtraction of rhs from *this.

        std::cout << value << std::endl;
        std::cout << std::endl;

        return *this;
    }

    /**
     * Multiplication Assignment Operator [*=].
     * @brief Multiplies rhs with *this.
     * @param rhs const Double&
     * @return Double&
     */
    inline Double& operator*=(const Double& rhs)
    {
        std::cout << this << " - " << typeid(*this).name() << " - Called " __FUNCTION__ " with address " << &rhs << " = " << rhs.value << std::endl;
        std::cout << this << " - " << typeid(*this).name() << " - " << value << " *= " << rhs.value << " = ";

        value = value * rhs.value; // Actual multiplication of rhs with *this.

        std::cout << value << std::endl;
        std::cout << std::endl;

        return *this;
    }

    /**
     * Division Assignment Operator [/=].
     * @brief Divides *this by rhs.
     * @param rhs const Double&
     * @return Double&
     */
    inline Double& operator/=(const Double& rhs)
    {
        std::cout << this << " - " << typeid(*this).name() << " - Called " __FUNCTION__ " with address " << &rhs << " = " << rhs.value << std::endl;
        std::cout << this << " - " << typeid(*this).name() << " - " << value << " /= " << rhs.value << " = ";

        value = value / rhs.value; // Actual division of *this by rhs.

        std::cout << value << std::endl;
        std::cout << std::endl;

        return *this;
    }

    //==========================================================================
    //
    //  BINARY ARITHMETIC OPERATOR NON-MEMBER FUNCTIONS
    //
    //==========================================================================

    /**
     * @brief Addition Allocation Operator [+].
     * @brief Creates a new Double object with the intial value of lhs + rhs.
     * @param lhs Double
     * @param rhs const Double&
     * @return Double
     */
    friend inline Double operator+(Double lhs, const Double& rhs) // passing lhs by value helps optimize chained a+b+c, otherwise, both parameters may be const references
    {
        std::cout << &lhs << " - " << typeid(lhs).name() << " - Called " __FUNCTION__ "() with address " << &rhs << " = " << rhs.value << std::endl;

        lhs += rhs; // reuse compound assignment
        return { lhs }; // return the result by value (uses move constructor)
    }

    /**
     * @brief Subtraction Allocation Operator [-].
     * @brief Creates a new Double object with the intial value of lhs - rhs.
     * @param lhs Double
     * @param rhs const Double&
     * @return Double
     */
    friend inline Double operator-(Double lhs, const Double& rhs) // passing lhs by value helps optimize chained a-b-c, otherwise, both parameters may be const references
    {
        std::cout << &lhs << " - " << typeid(lhs).name() << " - Called " __FUNCTION__ "() with address " << &rhs << " = " << rhs.value << std::endl;

        lhs -= rhs; // reuse compound assignment
        return { lhs }; // return the result by value (uses move constructor)
    }

    /**
     * Multiplication Allocation Operator [*].
     * @brief Creates a new Double object with the intial value = (lhs * rhs).
     * @param lhs Double
     * @param rhs const Double&
     * @return Double
     */
    friend inline Double operator*(Double lhs, const Double& rhs)
    {
        std::cout << &lhs << " - " << typeid(lhs).name() << " - Called " __FUNCTION__ "() with address " << &rhs << " = " << rhs.value << std::endl;

        lhs *= rhs; // reuse compound assignment
        return { lhs }; // return the result by value (uses move constructor)
    }

    /**
     * Division Allocation Operator [/].
     * @brief Creates a new Double object with the intial value = (lhs / rhs).
     * @param lhs Double
     * @param rhs const Double&
     * @return Double
     */
    friend inline Double operator/(Double lhs, const Double& rhs)
    {
        std::cout << &lhs << " - " << typeid(lhs).name() << " - Called " __FUNCTION__ "() with address " << &rhs << " = " << rhs.value << std::endl;

        lhs /= rhs; // reuse compound assignment
        return { lhs }; // return the result by value (uses move constructor)
    }

    //==========================================================================
    //
    //  COMPARISON OPERATOR NON-MEMBER FUNCTIONS
    //
    //==========================================================================

    /**
     * Equality Comparison Operator [==].
     * @brief Returns "true" if lhs is EQUAL TO rhs, otherwise returns false.
     * @param lhs const Double&
     * @param rhs const Double&
     * @return bool
     */
    friend inline bool operator==(const Double& lhs, const Double& rhs)
    {
        std::cout << &lhs << " - " << typeid(lhs).name() << " - Called Equality Comparison Operator [==] with address " << &rhs << " = " << rhs.value << std::endl;

        return (lhs.value == rhs.value) ? true : false; // do actual comparison
    }

    /**
     * Inequality Comparison Operator [!=].
     * @brief Returns "true" if lhs is NOT EQUAL to rhs, otherwise returns false.
     * @param lhs const Double&
     * @param rhs const Double&
     * @return bool
     */
    friend inline bool operator!=(const Double& lhs, const Double& rhs)
    {
        std::cout << &lhs << " - " << typeid(lhs).name() << " - Called Inequality Comparison Operator [!=] with address " << &rhs << " = " << rhs.value << std::endl;

        return !operator==(lhs, rhs);
    }

    /**
     * Less-Than Comparison Operator [<].
     * @brief Returns "true" if lhs is LESS THAN rhs, otherwise returns false.
     * @param lhs const Double&
     * @param rhs const Double&
     * @return bool
     */
    friend inline bool operator< (const Double& lhs, const Double& rhs)
    {
        std::cout << &lhs << " - " << typeid(lhs).name() << " - Less-Than Comparison Operator [<] with address " << &rhs << " = " << rhs.value << std::endl;

        return (lhs.value < rhs.value) ? true : false; // do actual comparison
    }

    /**
     * Greater-Than Comparison Operator [>].
     * @brief Returns "true" if lhs is GREATER THAN rhs, otherwise returns false.
     * @param lhs const Double&
     * @param rhs const Double&
     * @return bool
     */
    friend inline bool operator> (const Double& lhs, const Double& rhs)
    {
        std::cout << &lhs << " - " << typeid(lhs).name() << " - Called Greater-Than Comparison Operator [>] with address " << &rhs << " = " << rhs.value << std::endl;

        return  operator< (rhs, lhs);
    }

    /**
     * Less-Than or Equal-To Comparison Operator [<=].
     * @brief Returns "true" if lhs is LESS THAN or EQUAL TO rhs, otherwise returns false.
     * @param lhs const Double&
     * @param rhs const Double&
     * @return bool
     */
    friend inline bool operator<=(const Double& lhs, const Double& rhs)
    {
        std::cout << &lhs << " - " << typeid(lhs).name() << " - Called Less-Than or Equal-To Comparison Operator [<=] with address " << &rhs << " = " << rhs.value << std::endl;

        return !operator> (lhs,rhs);
    }

    /**
     *  Greater-Than or Equal-To Comparison Operator [>=].
     * @brief Returns "true" if lhs is GREATER THAN or EQUAL TO rhs, otherwise returns false.
     * @param lhs const Double&
     * @param rhs const Double&
     * @return bool
     */
    friend inline bool operator>=(const Double& lhs, const Double& rhs)
    {
        std::cout << &lhs << " - " << typeid(lhs).name() << " - Called Greater-Than or Equal-To Comparison Operator [>=] with address " << &rhs << " = " << rhs.value << std::endl;

        return !operator< (lhs,rhs);
    }

    //==========================================================================
    //
    //  TYPE CONVERSION OPERATORS
    //
    //==========================================================================

    /** Conversion Operator int(). */
    inline explicit operator int() const noexcept
    {
        std::cout << this << " - " << typeid(*this).name() << " - Called " __FUNCTION__ "()" << std::endl;
        std::cout << std::endl;

        return int(value);
    }

    /** Conversion Operator float(). */
    inline explicit operator float() const noexcept
    {
        std::cout << this << " - " << typeid(*this).name() << " - Called " __FUNCTION__ "()" << std::endl;
        std::cout << std::endl;

        return float(value);
    }

    /** Conversion Operator double(). */
    inline explicit operator double() const noexcept
    {
        std::cout << this << " - " << typeid(*this).name() << " - Called " __FUNCTION__ "()" << std::endl;
        std::cout << std::endl;

        return double(value);
    }

    //==========================================================================
    //
    //  ACCESSOR FUNCTIONS
    //
    //==========================================================================

    /**
     * Assertion.
     * @brief Assertions to check Constructor succeeded.
     */
    inline void assertion()
    {
        assert(this != nullptr);
        std::cout << this << " - " << typeid(*this).name() << " - Passed assertion check!" << std::endl;
    }

    /**
     * Boolean Checks.
     * @brief Runs and prints a set of boolean checks against a variable.
     * @param lhs Double
     * @param rhs Double&
     */
    inline void booleanChecks(const Double& rhs)
    {
        std::cout << this << " - " << typeid(*this).name() << " - Boolean checks:" << std::endl;
        std::cout << std::endl;
        std::cout << "(value < "  << rhs.value << ") = " << (*this < rhs) << std::endl;
        std::cout << "(value > "  << rhs.value << ") = " << (*this > rhs) << std::endl;
        std::cout << "(value <= " << rhs.value << ") = " << (*this <= rhs) << std::endl;
        std::cout << "(value >= " << rhs.value << ") = " << (*this >= rhs) << std::endl;
        std::cout << "(value == " << rhs.value << ") = " << (*this == rhs) << std::endl;
        std::cout << "(value != " << rhs.value << ") = " << (*this != rhs) << std::endl;
        std::cout << std::endl;
    }

    /**
     * Info.
     * @brief Prints information about this variable.
     */
    inline void info()
    {
        std::cout << this << " - " << typeid(*this).name() << " " __FUNCTION__ ";" << std::endl;
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

    /**
     * Operator<<.
     * @brief prints information about this variable to Terminal.
     * @param ostream std::ostream&
     * @param source Double&
     * @return std::ostream&
     */
    friend inline std::ostream& operator<<(std::ostream& ostream, Double& source)
    {
        ostream << source.value;

        return ostream;
    }

    /**
     * Operator>>.
     * @brief Passes in user input from the Terminal.
     * @param istream std::istream&
     * @param source Double&
     * @return std::istream&
     */
    friend inline std::istream& operator>>(std::istream& istream, Double& source)
    {
        if(&source == nullptr)
        istream.setstate(std::ios::failbit);

        return istream;
    }

    //==========================================================================
    //
    //  DATA MEMBERS
    //
    //==========================================================================
private:
    /**
     * Value.
     * @brief A value with double (i.e., 64 bit) precision.
     */
    double value {};
};
//==============================================================================

//==============================================================================

} // namespace stoneydsp

#endif // DOUBLE_H_INCLUDED

#undef DBL_DECIMAL_DIG
#undef DBL_DIG
#undef DBL_EPSILON
#undef DBL_HAS_SUBNORM
#undef DBL_MANT_DIG
#undef DBL_MAX
#undef DBL_MAX_10_EXP
#undef DBL_MIN
#undef DBL_MIN_10_EXP
#undef DBL_MIN_EXP
#undef _DBL_RADIX
#undef DBL_TRUE_MIN

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//
// Constants
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
#define DBL_DECIMAL_DIG  17                      // # of decimal digits of rounding precision
#define DBL_DIG          15                      // # of decimal digits of precision
#define DBL_EPSILON      2.2204460492503131e-016 // smallest such that 1.0+DBL_EPSILON != 1.0
#define DBL_HAS_SUBNORM  1                       // type does support subnormal numbers
#define DBL_MANT_DIG     53                      // # of bits in mantissa
#define DBL_MAX          1.7976931348623158e+308 // max value
#define DBL_MAX_10_EXP   308                     // max decimal exponent
#define DBL_MAX_EXP      1024                    // max binary exponent
#define DBL_MIN          2.2250738585072014e-308 // min positive value
#define DBL_MIN_10_EXP   (-307)                  // min decimal exponent
#define DBL_MIN_EXP      (-1021)                 // min binary exponent
#define _DBL_RADIX       2                       // exponent radix
#define DBL_TRUE_MIN     4.9406564584124654e-324 // min positive value

// #define FLT_DECIMAL_DIG  9                       // # of decimal digits of rounding precision
// #define FLT_DIG          6                       // # of decimal digits of precision
// #define FLT_EPSILON      1.192092896e-07F        // smallest such that 1.0+FLT_EPSILON != 1.0
// #define FLT_HAS_SUBNORM  1                       // type does support subnormal numbers
// #define FLT_GUARD        0
// #define FLT_MANT_DIG     24                      // # of bits in mantissa
// #define FLT_MAX          3.402823466e+38F        // max value
// #define FLT_MAX_10_EXP   38                      // max decimal exponent
// #define FLT_MAX_EXP      128                     // max binary exponent
// #define FLT_MIN          1.175494351e-38F        // min normalized positive value
// #define FLT_MIN_10_EXP   (-37)                   // min decimal exponent
// #define FLT_MIN_EXP      (-125)                  // min binary exponent
// #define FLT_NORMALIZE    0
// #define FLT_RADIX        2                       // exponent radix
// #define FLT_TRUE_MIN     1.401298464e-45F        // min positive value

// #define LDBL_DIG         DBL_DIG                 // # of decimal digits of precision
// #define LDBL_EPSILON     DBL_EPSILON             // smallest such that 1.0+LDBL_EPSILON != 1.0
// #define LDBL_HAS_SUBNORM DBL_HAS_SUBNORM         // type does support subnormal numbers
// #define LDBL_MANT_DIG    DBL_MANT_DIG            // # of bits in mantissa
// #define LDBL_MAX         DBL_MAX                 // max value
// #define LDBL_MAX_10_EXP  DBL_MAX_10_EXP          // max decimal exponent
// #define LDBL_MAX_EXP     DBL_MAX_EXP             // max binary exponent
// #define LDBL_MIN         DBL_MIN                 // min normalized positive value
// #define LDBL_MIN_10_EXP  DBL_MIN_10_EXP          // min decimal exponent
// #define LDBL_MIN_EXP     DBL_MIN_EXP             // min binary exponent
// #define _LDBL_RADIX      _DBL_RADIX              // exponent radix
// #define LDBL_TRUE_MIN    DBL_TRUE_MIN            // min positive value

// #define DECIMAL_DIG      DBL_DECIMAL_DIG
