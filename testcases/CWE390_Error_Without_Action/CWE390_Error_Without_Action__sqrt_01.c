/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE390_Error_Without_Action__sqrt_01.c
Label Definition File: CWE390_Error_Without_Action.label.xml
Template File: point-flaw-01.tmpl.c
*/
/*
 * @description
 * CWE: 390 Detection of Error Condition Without Action
 * Sinks: sqrt
 *    GoodSink: Check to see if sqrt() failed and handle errors properly
 *    BadSink : Check to see if sqrt() failed, but fail to handle errors
 * Flow Variant: 01 Baseline
 *
 * */

#include "std_testcase.h"

#include <math.h>
#include <errno.h>

#ifndef OMITBAD

void CWE390_Error_Without_Action__sqrt_01_bad()
{
    {
        double doubleNumber;
        errno = 0; /* set errno to zero before calling sqrt(), which can change its value */
        doubleNumber = (double)sqrt((double)-1);
        /* FLAW: Check errno to see if sqrt() failed, but do not handle errors */
        if (errno == EDOM)
        {
            /* do nothing */
        }
        printDoubleLine(doubleNumber);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

static void good1()
{
    {
        double doubleNumber;
        errno = 0; /* set errno to zero before calling sqrt(), which can change its value */
        doubleNumber = (double)sqrt((double)-1);
        /* FIX: Check errno to see if sqrt() failed and handle errors properly */
        if (errno == EDOM)
        {
            printLine("sqrt() failed");
            exit(1);
        }
        printDoubleLine(doubleNumber);
    }
}

void CWE390_Error_Without_Action__sqrt_01_good()
{
    good1();
}

#endif /* OMITGOOD */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE390_Error_Without_Action__sqrt_01_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE390_Error_Without_Action__sqrt_01_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
