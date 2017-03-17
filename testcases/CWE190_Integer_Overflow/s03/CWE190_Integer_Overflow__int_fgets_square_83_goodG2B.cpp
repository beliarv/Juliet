/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__int_fgets_square_83_goodG2B.cpp
Label Definition File: CWE190_Integer_Overflow__int.label.xml
Template File: sources-sinks-83_goodG2B.tmpl.cpp
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: fgets Read data from the console using fgets()
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: square
 *    GoodSink: Ensure there will not be an overflow before squaring data
 *    BadSink : Square data, which can lead to overflow
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */
#ifndef OMITGOOD

#include "std_testcase.h"
#include "CWE190_Integer_Overflow__int_fgets_square_83.h"

#define CHAR_ARRAY_SIZE (3 * sizeof(data) + 2)

#include <math.h>

namespace CWE190_Integer_Overflow__int_fgets_square_83
{
CWE190_Integer_Overflow__int_fgets_square_83_goodG2B::CWE190_Integer_Overflow__int_fgets_square_83_goodG2B(int dataCopy)
{
    data = dataCopy;
    /* FIX: Use a small, non-zero value that will not cause an integer overflow in the sinks */
    data = 2;
}

CWE190_Integer_Overflow__int_fgets_square_83_goodG2B::~CWE190_Integer_Overflow__int_fgets_square_83_goodG2B()
{
    {
        /* POTENTIAL FLAW: if (data*data) > INT_MAX, this will overflow */
        int result = data * data;
        printIntLine(result);
    }
}
}
#endif /* OMITGOOD */
