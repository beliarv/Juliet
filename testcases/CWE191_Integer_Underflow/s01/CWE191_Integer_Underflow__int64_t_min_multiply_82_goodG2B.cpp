/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__int64_t_min_multiply_82_goodG2B.cpp
Label Definition File: CWE191_Integer_Underflow.label.xml
Template File: sources-sinks-82_goodG2B.tmpl.cpp
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: min Set data to the min value for int64_t
 * GoodSource: Set data to a small, non-zero number (negative two)
 * Sinks: multiply
 *    GoodSink: Ensure there will not be an underflow before multiplying data by 2
 *    BadSink : If data is negative, multiply by 2, which can cause an underflow
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
 *
 * */
#ifndef OMITGOOD

#include "std_testcase.h"
#include "CWE191_Integer_Underflow__int64_t_min_multiply_82.h"

namespace CWE191_Integer_Underflow__int64_t_min_multiply_82
{

void CWE191_Integer_Underflow__int64_t_min_multiply_82_goodG2B::action(int64_t data)
{
    if(data < 0) /* ensure we won't have an overflow */
    {
        /* POTENTIAL FLAW: if (data * 2) < LLONG_MIN, this will underflow */
        int64_t result = data * 2;
        printLongLongLine(result);
    }
}

}
#endif /* OMITGOOD */
