/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE369_Divide_by_Zero__float_rand_33.cpp
Label Definition File: CWE369_Divide_by_Zero__float.label.xml
Template File: sources-sinks-33.tmpl.cpp
*/
/*
 * @description
 * CWE: 369 Divide by Zero
 * BadSource: rand Set data to result of RAND32(), which may be zero
 * GoodSource: A hardcoded non-zero number (two)
 * Sinks:
 *    GoodSink: Check value of or near zero before dividing
 *    BadSink : Divide a constant by data
 * Flow Variant: 33 Data flow: use of a C++ reference to data within the same function
 *
 * */

#include "std_testcase.h"

#include <math.h>

namespace CWE369_Divide_by_Zero__float_rand_33
{

#ifndef OMITBAD

void bad()
{
    float data;
    float &dataRef = data;
    /* Initialize data */
    data = 0.0F;
    /* POTENTIAL FLAW: Use a random number that could possibly equal zero */
    data = (float)RAND32();
    {
        float data = dataRef;
        {
            /* POTENTIAL FLAW: Possibly divide by zero */
            int result = (int)(100.0 / data);
            printIntLine(result);
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    float data;
    float &dataRef = data;
    /* Initialize data */
    data = 0.0F;
    /* FIX: Use a hardcoded number that won't a divide by zero */
    data = 2.0F;
    {
        float data = dataRef;
        {
            /* POTENTIAL FLAW: Possibly divide by zero */
            int result = (int)(100.0 / data);
            printIntLine(result);
        }
    }
}

/* goodB2G() uses the BadSource with the GoodSink */
static void goodB2G()
{
    float data;
    float &dataRef = data;
    /* Initialize data */
    data = 0.0F;
    /* POTENTIAL FLAW: Use a random number that could possibly equal zero */
    data = (float)RAND32();
    {
        float data = dataRef;
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

void good()
{
    goodG2B();
    goodB2G();
}

#endif /* OMITGOOD */

} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */
#ifdef INCLUDEMAIN

using namespace CWE369_Divide_by_Zero__float_rand_33; /* so that we can use good and bad easily */

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
