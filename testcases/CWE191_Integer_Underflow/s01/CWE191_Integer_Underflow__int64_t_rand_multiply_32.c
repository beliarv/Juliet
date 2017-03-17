/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__int64_t_rand_multiply_32.c
Label Definition File: CWE191_Integer_Underflow.label.xml
Template File: sources-sinks-32.tmpl.c
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: rand Set data to result of rand()
 * GoodSource: Set data to a small, non-zero number (negative two)
 * Sinks: multiply
 *    GoodSink: Ensure there will not be an underflow before multiplying data by 2
 *    BadSink : If data is negative, multiply by 2, which can cause an underflow
 * Flow Variant: 32 Data flow using two pointers to the same value within the same function
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE191_Integer_Underflow__int64_t_rand_multiply_32_bad()
{
    int64_t data;
    int64_t *dataPtr1 = &data;
    int64_t *dataPtr2 = &data;
    data = 0LL;
    {
        int64_t data = *dataPtr1;
        /* POTENTIAL FLAW: Use a random value */
        data = (int64_t)RAND64();
        *dataPtr1 = data;
    }
    {
        int64_t data = *dataPtr2;
        if(data < 0) /* ensure we won't have an overflow */
        {
            /* POTENTIAL FLAW: if (data * 2) < LLONG_MIN, this will underflow */
            int64_t result = data * 2;
            printLongLongLine(result);
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    int64_t data;
    int64_t *dataPtr1 = &data;
    int64_t *dataPtr2 = &data;
    data = 0LL;
    {
        int64_t data = *dataPtr1;
        /* FIX: Use a small, non-zero value that will not cause an underflow in the sinks */
        data = -2;
        *dataPtr1 = data;
    }
    {
        int64_t data = *dataPtr2;
        if(data < 0) /* ensure we won't have an overflow */
        {
            /* POTENTIAL FLAW: if (data * 2) < LLONG_MIN, this will underflow */
            int64_t result = data * 2;
            printLongLongLine(result);
        }
    }
}

/* goodB2G() uses the BadSource with the GoodSink */
static void goodB2G()
{
    int64_t data;
    int64_t *dataPtr1 = &data;
    int64_t *dataPtr2 = &data;
    data = 0LL;
    {
        int64_t data = *dataPtr1;
        /* POTENTIAL FLAW: Use a random value */
        data = (int64_t)RAND64();
        *dataPtr1 = data;
    }
    {
        int64_t data = *dataPtr2;
        if(data < 0) /* ensure we won't have an overflow */
        {
            /* FIX: Add a check to prevent an underflow from occurring */
            if (data > (LLONG_MIN/2))
            {
                int64_t result = data * 2;
                printLongLongLine(result);
            }
            else
            {
                printLine("data value is too small to perform multiplication.");
            }
        }
    }
}

void CWE191_Integer_Underflow__int64_t_rand_multiply_32_good()
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
    CWE191_Integer_Underflow__int64_t_rand_multiply_32_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE191_Integer_Underflow__int64_t_rand_multiply_32_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
