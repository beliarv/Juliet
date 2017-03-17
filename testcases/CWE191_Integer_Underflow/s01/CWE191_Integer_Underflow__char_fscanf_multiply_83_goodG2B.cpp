/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__char_fscanf_multiply_83_goodG2B.cpp
Label Definition File: CWE191_Integer_Underflow.label.xml
Template File: sources-sinks-83_goodG2B.tmpl.cpp
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Set data to a small, non-zero number (negative two)
 * Sinks: multiply
 *    GoodSink: Ensure there will not be an underflow before multiplying data by 2
 *    BadSink : If data is negative, multiply by 2, which can cause an underflow
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */
#ifndef OMITGOOD

#include "std_testcase.h"
#include "CWE191_Integer_Underflow__char_fscanf_multiply_83.h"

namespace CWE191_Integer_Underflow__char_fscanf_multiply_83
{
CWE191_Integer_Underflow__char_fscanf_multiply_83_goodG2B::CWE191_Integer_Underflow__char_fscanf_multiply_83_goodG2B(char dataCopy)
{
    data = dataCopy;
    /* FIX: Use a small, non-zero value that will not cause an underflow in the sinks */
    data = -2;
}

CWE191_Integer_Underflow__char_fscanf_multiply_83_goodG2B::~CWE191_Integer_Underflow__char_fscanf_multiply_83_goodG2B()
{
    if(data < 0) /* ensure we won't have an overflow */
    {
        /* POTENTIAL FLAW: if (data * 2) < CHAR_MIN, this will underflow */
        char result = data * 2;
        printHexCharLine(result);
    }
}
}
#endif /* OMITGOOD */
