/*******************************************************************************
 * 
 * @file Logger.h
 * 
 * @author Nathan J. Hood (nathanjhood@googlemail.com)
 * @version 1.0.0.1
 * @date 2022-08-13
 * 
 * @copyright Copyright (c) 2022
 * 
 *******************************************************************************
*/

#pragma once

#ifndef LOGGER_H_INCLUDED
#define LOGGER_H_INCLUDED

namespace stoneydsp {

/** Logger class. */
class Logger
{
public:
    inline Logger() {}
    inline ~Logger() noexcept {}

    inline std::string convertToString(char* a)
    {
        std::string s = a;
        return s;
    }

    inline std::string convertToString(char* a, int size)
    {
        int i;
        std::string s = "";
        for (i = 0; i < size; i++) 
        {
            s = s + a[i];
        }
        return s;
    }

    inline friend std::ostream& operator<<(std::ostream& ostream, Logger& source)
    {
        ostream << source.charArray;

        return ostream;
    }

    inline friend std::istream& operator>>(std::istream& istream, Logger& source)
    {
        if(source.charArray != nullptr)
            istream.setstate(std::ios::failbit);

        return istream;
    }

private:
    const char* charArray[40];
};

} // namespace stoneydsp 

#endif // LOGGER_H_INCLUDED
