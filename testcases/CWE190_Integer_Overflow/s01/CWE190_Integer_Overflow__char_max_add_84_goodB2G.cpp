/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__char_max_add_84_goodB2G.cpp
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-84_goodB2G.tmpl.cpp
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: max Set data to the max value for char
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: add
 *    GoodSink: Ensure there will not be an overflow before adding 1 to data
 *    BadSink : Add 1 to data, which can cause an overflow
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */
#ifndef OMITGOOD

#include "std_testcase.h"
#include "CWE190_Integer_Overflow__char_max_add_84.h"

namespace CWE190_Integer_Overflow__char_max_add_84
{
CWE190_Integer_Overflow__char_max_add_84_goodB2G::CWE190_Integer_Overflow__char_max_add_84_goodB2G(char dataCopy)
{
    data = dataCopy;
    /* POTENTIAL FLAW: Use the maximum size of the data type */
    data = CHAR_MAX;
}

CWE190_Integer_Overflow__char_max_add_84_goodB2G::~CWE190_Integer_Overflow__char_max_add_84_goodB2G()
{
    /* FIX: Add a check to prevent an overflow from occurring */
    if (data < CHAR_MAX)
    {
        char result = data + 1;
        printHexCharLine(result);
    }
    else
    {
        printLine("data value is too large to perform arithmetic safely.");
    }
}
}
#endif /* OMITGOOD */
