/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE369_Divide_by_Zero__float_zero_83_goodB2G.cpp
Label Definition File: CWE369_Divide_by_Zero__float.label.xml
Template File: sources-sinks-83_goodB2G.tmpl.cpp
*/
/*
 * @description
 * CWE: 369 Divide by Zero
 * BadSource: zero Fixed value of zero
 * GoodSource: A hardcoded non-zero number (two)
 * Sinks:
 *    GoodSink: Check value of or near zero before dividing
 *    BadSink : Divide a constant by data
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */
#ifndef OMITGOOD

#include "std_testcase.h"
#include "CWE369_Divide_by_Zero__float_zero_83.h"

namespace CWE369_Divide_by_Zero__float_zero_83
{
CWE369_Divide_by_Zero__float_zero_83_goodB2G::CWE369_Divide_by_Zero__float_zero_83_goodB2G(float dataCopy)
{
    data = dataCopy;
    /* POTENTIAL FLAW: Set data to zero */
    data = 0.0F;
}

CWE369_Divide_by_Zero__float_zero_83_goodB2G::~CWE369_Divide_by_Zero__float_zero_83_goodB2G()
{
    /* FIX: Check for value of or near zero before dividing */
    if(fabs(data) > 0.000001)
    {
        int result = (int)(100.0 / data);
        printIntLine(result);
    }
    else
    {
        printLine("This would result in a divide by zero");
    }
}
}
#endif /* OMITGOOD */
