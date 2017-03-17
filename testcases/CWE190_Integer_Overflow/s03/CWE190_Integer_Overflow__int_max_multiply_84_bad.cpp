/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__int_max_multiply_84_bad.cpp
Label Definition File: CWE190_Integer_Overflow__int.label.xml
Template File: sources-sinks-84_bad.tmpl.cpp
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: max Set data to the max value for int
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: multiply
 *    GoodSink: Ensure there will not be an overflow before multiplying data by 2
 *    BadSink : If data is positive, multiply by 2, which can cause an overflow
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */
#ifndef OMITBAD

#include "std_testcase.h"
#include "CWE190_Integer_Overflow__int_max_multiply_84.h"

namespace CWE190_Integer_Overflow__int_max_multiply_84
{
CWE190_Integer_Overflow__int_max_multiply_84_bad::CWE190_Integer_Overflow__int_max_multiply_84_bad(int dataCopy)
{
    data = dataCopy;
    /* POTENTIAL FLAW: Use the maximum value for this type */
    data = INT_MAX;
}

CWE190_Integer_Overflow__int_max_multiply_84_bad::~CWE190_Integer_Overflow__int_max_multiply_84_bad()
{
    if(data > 0) /* ensure we won't have an underflow */
    {
        /* POTENTIAL FLAW: if (data*2) > INT_MAX, this will overflow */
        int result = data * 2;
        printIntLine(result);
    }
}
}
#endif /* OMITBAD */
