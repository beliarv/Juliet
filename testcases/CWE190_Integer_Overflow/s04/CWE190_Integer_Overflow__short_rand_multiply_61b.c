/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__short_rand_multiply_61b.c
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-61b.tmpl.c
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

short CWE190_Integer_Overflow__short_rand_multiply_61b_badSource(short data)
{
    /* POTENTIAL FLAW: Use a random value */
    data = (short)RAND32();
    return data;
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
short CWE190_Integer_Overflow__short_rand_multiply_61b_goodG2BSource(short data)
{
    /* FIX: Use a small, non-zero value that will not cause an overflow in the sinks */
    data = 2;
    return data;
}

/* goodB2G() uses the BadSource with the GoodSink */
short CWE190_Integer_Overflow__short_rand_multiply_61b_goodB2GSource(short data)
{
    /* POTENTIAL FLAW: Use a random value */
    data = (short)RAND32();
    return data;
}

#endif /* OMITGOOD */
