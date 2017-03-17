/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE369_Divide_by_Zero__float_zero_84_bad.cpp
Label Definition File: CWE369_Divide_by_Zero__float.label.xml
Template File: sources-sinks-84_bad.tmpl.cpp
*/
/*
 * @description
 * CWE: 369 Divide by Zero
 * BadSource: zero Fixed value of zero
 * GoodSource: A hardcoded non-zero number (two)
 * Sinks:
 *    GoodSink: Check value of or near zero before dividing
 *    BadSink : Divide a constant by data
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */
#ifndef OMITBAD

#include "std_testcase.h"
#include "CWE369_Divide_by_Zero__float_zero_84.h"

namespace CWE369_Divide_by_Zero__float_zero_84
{
CWE369_Divide_by_Zero__float_zero_84_bad::CWE369_Divide_by_Zero__float_zero_84_bad(float dataCopy)
{
    data = dataCopy;
    /* POTENTIAL FLAW: Set data to zero */
    data = 0.0F;
}

CWE369_Divide_by_Zero__float_zero_84_bad::~CWE369_Divide_by_Zero__float_zero_84_bad()
{
    {
        /* POTENTIAL FLAW: Possibly divide by zero */
        int result = (int)(100.0 / data);
        printIntLine(result);
    }
}
}
#endif /* OMITBAD */
