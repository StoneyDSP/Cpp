/*******************************************************************************
 * 
 * @file stoneydsp_core.h
 * 
 * @author Nathan J. Hood (nathanjhood@googlemail.com)
 * @version 1.0.0.1
 * @date 2022-08-13
 * 
 * @copyright Copyright (c) 2022 @StoneyDSP
 * 
 *******************************************************************************
*/

/** BEGIN_JUCE_MODULE_DECLARATION

    ID:             stoneydsp_core
    vendor:         stoneydsp
    version:        1.0.0
    name:           StoneyDSP Core classes
    description:    Lightweight core parts as classes
    website:        github.com/StoneyDSP
    license:        Proprietary  

    END_JUCE_MODULE_DECLARATION
*/

#pragma once

#define STONEYDSP_CORE_H_INCLUDED

#include <assert.h>
#include <iostream>
#include <string.h>
#include <typeinfo>

#include "core/stoneydsp_bit.h"
#include "core/stoneydsp_const.h"
#include "core/stoneydsp_float.h"
#include "core/stoneydsp_double.h"
#include "core/stoneydsp_int.h"
#include "core/stoneydsp_logger.h"
#include "core/stoneydsp_terminal.h"
#include "core/stoneydsp_unique_ptr.h"
#include "core/stoneydsp_value.h"
