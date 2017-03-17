/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__int64_t_max_add_83_goodG2B.cpp
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-83_goodG2B.tmpl.cpp
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: max Set data to the max value for int64_t
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: add
 *    GoodSink: Ensure there will not be an overflow before adding 1 to data
 *    BadSink : Add 1 to data, which can cause an overflow
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */
#ifndef OMITGOOD

#include "std_testcase.h"
#include "CWE190_Integer_Overflow__int64_t_max_add_83.h"

namespace CWE190_Integer_Overflow__int64_t_max_add_83
{
CWE190_Integer_Overflow__int64_t_max_add_83_goodG2B::CWE190_Integer_Overflow__int64_t_max_add_83_goodG2B(int64_t dataCopy)
{
    data = dataCopy;
    /* FIX: Use a small, non-zero value that will not cause an overflow in the sinks */
    data = 2;
}

CWE190_Integer_Overflow__int64_t_max_add_83_goodG2B::~CWE190_Integer_Overflow__int64_t_max_add_83_goodG2B()
{
    {
        /* POTENTIAL FLAW: Adding 1 to data could cause an overflow */
        int64_t result = data + 1;
        printLongLongLine(result);
    }
}
}
#endif /* OMITGOOD */
