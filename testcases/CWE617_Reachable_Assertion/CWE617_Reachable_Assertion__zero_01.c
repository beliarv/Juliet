/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE617_Reachable_Assertion__zero_01.c
Label Definition File: CWE617_Reachable_Assertion__zero.label.xml
Template File: point-flaw-01.tmpl.c
*/
/*
 * @description
 * CWE: 617 Reachable Assertion
 * Sinks:
 *    GoodSink: assert(true), which will never trigger
 *    BadSink : assert(false), which will always trigger
 * Flow Variant: 01 Baseline
 *
 * */

#include "std_testcase.h"

#include <assert.h>

#ifndef OMITBAD

void CWE617_Reachable_Assertion__zero_01_bad()
{
    /* FLAW: this assertion can be reached, and will always trigger */
    assert(0); /* INCIDENTAL: CWE 571 - expression is always true - it's "true" because assert(e) basically does if (!(e)) */
}

#endif /* OMITBAD */

#ifndef OMITGOOD

static void good1()
{
    /* FIX: ensure assertions cannot be triggered, in this case, to avoid an empty
    * function, assert(1)
    */
    assert(1); /* INCIDENTAL: CWE 570 - expression is always false - it's "false" because assert(e) basically does if (!(e)) */
}

void CWE617_Reachable_Assertion__zero_01_good()
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
    CWE617_Reachable_Assertion__zero_01_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE617_Reachable_Assertion__zero_01_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
