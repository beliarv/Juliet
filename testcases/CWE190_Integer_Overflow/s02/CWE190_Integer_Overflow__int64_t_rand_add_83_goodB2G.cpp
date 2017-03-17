/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__int64_t_rand_add_83_goodB2G.cpp
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-83_goodB2G.tmpl.cpp
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: rand Set data to result of rand()
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: add
 *    GoodSink: Ensure there will not be an overflow before adding 1 to data
 *    BadSink : Add 1 to data, which can cause an overflow
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */
#ifndef OMITGOOD

#include "std_testcase.h"
#include "CWE190_Integer_Overflow__int64_t_rand_add_83.h"

namespace CWE190_Integer_Overflow__int64_t_rand_add_83
{
CWE190_Integer_Overflow__int64_t_rand_add_83_goodB2G::CWE190_Integer_Overflow__int64_t_rand_add_83_goodB2G(int64_t dataCopy)
{
    data = dataCopy;
    /* POTENTIAL FLAW: Use a random value */
    data = (int64_t)RAND64();
}

CWE190_Integer_Overflow__int64_t_rand_add_83_goodB2G::~CWE190_Integer_Overflow__int64_t_rand_add_83_goodB2G()
{
    /* FIX: Add a check to prevent an overflow from occurring */
    if (data < LLONG_MAX)
    {
        int64_t result = data + 1;
        printLongLongLine(result);
    }
    else
    {
        printLine("data value is too large to perform arithmetic safely.");
    }
}
}
#endif /* OMITGOOD */
