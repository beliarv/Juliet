/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__int_fscanf_square_83_goodB2G.cpp
Label Definition File: CWE190_Integer_Overflow__int.label.xml
Template File: sources-sinks-83_goodB2G.tmpl.cpp
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: square
 *    GoodSink: Ensure there will not be an overflow before squaring data
 *    BadSink : Square data, which can lead to overflow
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */
#ifndef OMITGOOD

#include "std_testcase.h"
#include "CWE190_Integer_Overflow__int_fscanf_square_83.h"

#include <math.h>

namespace CWE190_Integer_Overflow__int_fscanf_square_83
{
CWE190_Integer_Overflow__int_fscanf_square_83_goodB2G::CWE190_Integer_Overflow__int_fscanf_square_83_goodB2G(int dataCopy)
{
    data = dataCopy;
    /* POTENTIAL FLAW: Read data from the console using fscanf() */
    fscanf(stdin, "%d", &data);
}

CWE190_Integer_Overflow__int_fscanf_square_83_goodB2G::~CWE190_Integer_Overflow__int_fscanf_square_83_goodB2G()
{
    /* FIX: Add a check to prevent an overflow from occurring */
    if (abs((long)data) <= (long)sqrt((double)INT_MAX))
    {
        int result = data * data;
        printIntLine(result);
    }
    else
    {
        printLine("data value is too large to perform arithmetic safely.");
    }
}
}
#endif /* OMITGOOD */
