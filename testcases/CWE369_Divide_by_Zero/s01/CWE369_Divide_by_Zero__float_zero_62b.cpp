/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE369_Divide_by_Zero__float_zero_62b.cpp
Label Definition File: CWE369_Divide_by_Zero__float.label.xml
Template File: sources-sinks-62b.tmpl.cpp
*/
/*
 * @description
 * CWE: 369 Divide by Zero
 * BadSource: zero Fixed value of zero
 * GoodSource: A hardcoded non-zero number (two)
 * Sinks:
 *    GoodSink: Check value of or near zero before dividing
 *    BadSink : Divide a constant by data
 * Flow Variant: 62 Data flow: data flows using a C++ reference from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <math.h>

namespace CWE369_Divide_by_Zero__float_zero_62
{

#ifndef OMITBAD

void badSource(float &data)
{
    /* POTENTIAL FLAW: Set data to zero */
    data = 0.0F;
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
void goodG2BSource(float &data)
{
    /* FIX: Use a hardcoded number that won't a divide by zero */
    data = 2.0F;
}

/* goodB2G() uses the BadSource with the GoodSink */
void goodB2GSource(float &data)
{
    /* POTENTIAL FLAW: Set data to zero */
    data = 0.0F;
}

#endif /* OMITGOOD */

} /* close namespace */
