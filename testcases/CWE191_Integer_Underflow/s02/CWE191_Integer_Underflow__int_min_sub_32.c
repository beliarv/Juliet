/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__int_min_sub_32.c
Label Definition File: CWE191_Integer_Underflow__int.label.xml
Template File: sources-sinks-32.tmpl.c
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: min Set data to the minimum value for int
 * GoodSource: Set data to a small, non-zero number (negative two)
 * Sinks: sub
 *    GoodSink: Ensure there will not be an underflow before subtracting 1 from data
 *    BadSink : Subtract 1 from data, which can cause an Underflow
 * Flow Variant: 32 Data flow using two pointers to the same value within the same function
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE191_Integer_Underflow__int_min_sub_32_bad()
{
    int data;
    int *dataPtr1 = &data;
    int *dataPtr2 = &data;
    /* Initialize data */
    data = 0;
    {
        int data = *dataPtr1;
        /* POTENTIAL FLAW: Use the minimum value for this type */
        data = INT_MIN;
        *dataPtr1 = data;
    }
    {
        int data = *dataPtr2;
        {
            /* POTENTIAL FLAW: Subtracting 1 from data could cause an underflow */
            int result = data - 1;
            printIntLine(result);
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    int data;
    int *dataPtr1 = &data;
    int *dataPtr2 = &data;
    /* Initialize data */
    data = 0;
    {
        int data = *dataPtr1;
        /* FIX: Use a small, non-zero value that will not cause an integer underflow in the sinks */
        data = -2;
        *dataPtr1 = data;
    }
    {
        int data = *dataPtr2;
        {
            /* POTENTIAL FLAW: Subtracting 1 from data could cause an underflow */
            int result = data - 1;
            printIntLine(result);
        }
    }
}

/* goodB2G() uses the BadSource with the GoodSink */
static void goodB2G()
{
    int data;
    int *dataPtr1 = &data;
    int *dataPtr2 = &data;
    /* Initialize data */
    data = 0;
    {
        int data = *dataPtr1;
        /* POTENTIAL FLAW: Use the minimum value for this type */
        data = INT_MIN;
        *dataPtr1 = data;
    }
    {
        int data = *dataPtr2;
        /* FIX: Add a check to prevent an underflow from occurring */
        if (data > INT_MIN)
        {
            int result = data - 1;
            printIntLine(result);
        }
        else
        {
            printLine("data value is too large to perform subtraction.");
        }
    }
}

void CWE191_Integer_Underflow__int_min_sub_32_good()
{
    goodG2B();
    goodB2G();
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
    CWE191_Integer_Underflow__int_min_sub_32_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE191_Integer_Underflow__int_min_sub_32_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
