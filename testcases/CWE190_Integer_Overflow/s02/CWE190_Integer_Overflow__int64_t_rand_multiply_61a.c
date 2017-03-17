/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__int64_t_rand_multiply_61a.c
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-61a.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: rand Set data to result of rand()
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: multiply
 *    GoodSink: Ensure there will not be an overflow before multiplying data by 2
 *    BadSink : If data is positive, multiply by 2, which can cause an overflow
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

/* bad function declaration */
int64_t CWE190_Integer_Overflow__int64_t_rand_multiply_61b_badSource(int64_t data);

void CWE190_Integer_Overflow__int64_t_rand_multiply_61_bad()
{
    int64_t data;
    data = 0LL;
    data = CWE190_Integer_Overflow__int64_t_rand_multiply_61b_badSource(data);
    if(data > 0) /* ensure we won't have an underflow */
    {
        /* POTENTIAL FLAW: if (data*2) > LLONG_MAX, this will overflow */
        int64_t result = data * 2;
        printLongLongLine(result);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
int64_t CWE190_Integer_Overflow__int64_t_rand_multiply_61b_goodG2BSource(int64_t data);

static void goodG2B()
{
    int64_t data;
    data = 0LL;
    data = CWE190_Integer_Overflow__int64_t_rand_multiply_61b_goodG2BSource(data);
    if(data > 0) /* ensure we won't have an underflow */
    {
        /* POTENTIAL FLAW: if (data*2) > LLONG_MAX, this will overflow */
        int64_t result = data * 2;
        printLongLongLine(result);
    }
}

/* goodB2G uses the BadSource with the GoodSink */
int64_t CWE190_Integer_Overflow__int64_t_rand_multiply_61b_goodB2GSource(int64_t data);

static void goodB2G()
{
    int64_t data;
    data = 0LL;
    data = CWE190_Integer_Overflow__int64_t_rand_multiply_61b_goodB2GSource(data);
    if(data > 0) /* ensure we won't have an underflow */
    {
        /* FIX: Add a check to prevent an overflow from occurring */
        if (data < (LLONG_MAX/2))
        {
            int64_t result = data * 2;
            printLongLongLine(result);
        }
        else
        {
            printLine("data value is too large to perform arithmetic safely.");
        }
    }
}

void CWE190_Integer_Overflow__int64_t_rand_multiply_61_good()
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
    CWE190_Integer_Overflow__int64_t_rand_multiply_61_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE190_Integer_Overflow__int64_t_rand_multiply_61_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
