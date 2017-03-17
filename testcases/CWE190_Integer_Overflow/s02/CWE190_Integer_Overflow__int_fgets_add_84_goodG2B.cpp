/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__int_fgets_add_84_goodG2B.cpp
Label Definition File: CWE190_Integer_Overflow__int.label.xml
Template File: sources-sinks-84_goodG2B.tmpl.cpp
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: fgets Read data from the console using fgets()
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: add
 *    GoodSink: Ensure there will not be an overflow before adding 1 to data
 *    BadSink : Add 1 to data, which can cause an overflow
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */
#ifndef OMITGOOD

#include "std_testcase.h"
#include "CWE190_Integer_Overflow__int_fgets_add_84.h"

#define CHAR_ARRAY_SIZE (3 * sizeof(data) + 2)

namespace CWE190_Integer_Overflow__int_fgets_add_84
{
CWE190_Integer_Overflow__int_fgets_add_84_goodG2B::CWE190_Integer_Overflow__int_fgets_add_84_goodG2B(int dataCopy)
{
    data = dataCopy;
    /* FIX: Use a small, non-zero value that will not cause an integer overflow in the sinks */
    data = 2;
}

CWE190_Integer_Overflow__int_fgets_add_84_goodG2B::~CWE190_Integer_Overflow__int_fgets_add_84_goodG2B()
{
    {
        /* POTENTIAL FLAW: Adding 1 to data could cause an overflow */
        int result = data + 1;
        printIntLine(result);
    }
}
}
#endif /* OMITGOOD */
