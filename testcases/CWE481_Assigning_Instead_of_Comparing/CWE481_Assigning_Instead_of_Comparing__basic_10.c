/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE481_Assigning_Instead_of_Comparing__basic_10.c
Label Definition File: CWE481_Assigning_Instead_of_Comparing__basic.label.xml
Template File: point-flaw-10.tmpl.c
*/
/*
 * @description
 * CWE: 481 Assigning Instead of Comparing
 * Sinks:
 *    GoodSink: Comparing
 *    BadSink : Assigning instead of comparing
 * Flow Variant: 10 Control flow: if(globalTrue) and if(globalFalse)
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE481_Assigning_Instead_of_Comparing__basic_10_bad()
{
    if(globalTrue)
    {
        {
            int intRand = rand();
            /* FLAW: should be == and INCIDENTIAL CWE 571 Expression Is Always True */
            if(intRand = 5)
            {
                printLine("i was 5");
            }
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() uses if(globalFalse) instead of if(globalTrue) */
static void good1()
{
    if(globalFalse)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        {
            int intRand = rand();
            /* FIX: used == instead of = */
            if(intRand == 5)
            {
                printLine("i was 5");
            }
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(globalTrue)
    {
        {
            int intRand = rand();
            /* FIX: used == instead of = */
            if(intRand == 5)
            {
                printLine("i was 5");
            }
        }
    }
}

void CWE481_Assigning_Instead_of_Comparing__basic_10_good()
{
    good1();
    good2();
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
    CWE481_Assigning_Instead_of_Comparing__basic_10_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE481_Assigning_Instead_of_Comparing__basic_10_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
