/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__int64_t_rand_add_82_bad.cpp
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-82_bad.tmpl.cpp
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: rand Set data to result of rand()
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: add
 *    GoodSink: Ensure there will not be an overflow before adding 1 to data
 *    BadSink : Add 1 to data, which can cause an overflow
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
 *
 * */
#ifndef OMITBAD

#include "std_testcase.h"
#include "CWE190_Integer_Overflow__int64_t_rand_add_82.h"

namespace CWE190_Integer_Overflow__int64_t_rand_add_82
{

void CWE190_Integer_Overflow__int64_t_rand_add_82_bad::action(int64_t data)
{
    {
        /* POTENTIAL FLAW: Adding 1 to data could cause an overflow */
        int64_t result = data + 1;
        printLongLongLine(result);
    }
}

}
#endif /* OMITBAD */
