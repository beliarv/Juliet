/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__short_rand_sub_16.c
Label Definition File: CWE191_Integer_Underflow.label.xml
Template File: sources-sinks-16.tmpl.c
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: rand Set data to result of rand()
 * GoodSource: Set data to a small, non-zero number (negative two)
 * Sinks: sub
 *    GoodSink: Ensure there will not be an underflow before subtracting 1 from data
 *    BadSink : Subtract 1 from data, which can cause an Underflow
 * Flow Variant: 16 Control flow: while(1)
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE191_Integer_Underflow__short_rand_sub_16_bad()
{
    short data;
    data = 0;
    while(1)
    {
        /* POTENTIAL FLAW: Use a random value */
        data = (short)RAND32();
        break;
    }
    while(1)
    {
        {
            /* POTENTIAL FLAW: Subtracting 1 from data could cause an underflow */
            short result = data - 1;
            printIntLine(result);
        }
        break;
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G() - use badsource and goodsink by changing the sinks in the second while statement */
static void goodB2G()
{
    short data;
    data = 0;
    while(1)
    {
        /* POTENTIAL FLAW: Use a random value */
        data = (short)RAND32();
        break;
    }
    while(1)
    {
        /* FIX: Add a check to prevent an underflow from occurring */
        if (data > SHRT_MIN)
        {
            short result = data - 1;
            printIntLine(result);
        }
        else
        {
            printLine("data value is too large to perform subtraction.");
        }
        break;
    }
}

/* goodG2B() - use goodsource and badsink by changing the sources in the first while statement */
static void goodG2B()
{
    short data;
    data = 0;
    while(1)
    {
        /* FIX: Use a small, non-zero value that will not cause an underflow in the sinks */
        data = -2;
        break;
    }
    while(1)
    {
        {
            /* POTENTIAL FLAW: Subtracting 1 from data could cause an underflow */
            short result = data - 1;
            printIntLine(result);
        }
        break;
    }
}

void CWE191_Integer_Underflow__short_rand_sub_16_good()
{
    goodB2G();
    goodG2B();
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
    CWE191_Integer_Underflow__short_rand_sub_16_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE191_Integer_Underflow__short_rand_sub_16_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
