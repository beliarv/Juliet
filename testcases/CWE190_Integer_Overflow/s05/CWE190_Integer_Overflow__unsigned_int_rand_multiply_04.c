/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__unsigned_int_rand_multiply_04.c
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-04.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: rand Set data to result of rand()
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: multiply
 *    GoodSink: Ensure there will not be an overflow before multiplying data by 2
 *    BadSink : If data is positive, multiply by 2, which can cause an overflow
 * Flow Variant: 04 Control flow: if(STATIC_CONST_TRUE) and if(STATIC_CONST_FALSE)
 *
 * */

#include "std_testcase.h"

/* The two variables below are declared "const", so a tool should
   be able to identify that reads of these will always return their
   initialized values. */
static const int STATIC_CONST_TRUE = 1; /* true */
static const int STATIC_CONST_FALSE = 0; /* false */

#ifndef OMITBAD

void CWE190_Integer_Overflow__unsigned_int_rand_multiply_04_bad()
{
    unsigned int data;
    data = 0;
    if(STATIC_CONST_TRUE)
    {
        /* POTENTIAL FLAW: Use a random value */
        data = (unsigned int)RAND32();
    }
    if(STATIC_CONST_TRUE)
    {
        if(data > 0) /* ensure we won't have an underflow */
        {
            /* POTENTIAL FLAW: if (data*2) > UINT_MAX, this will overflow */
            unsigned int result = data * 2;
            printUnsignedLine(result);
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G1() - use badsource and goodsink by changing the second STATIC_CONST_TRUE to STATIC_CONST_FALSE */
static void goodB2G1()
{
    unsigned int data;
    data = 0;
    if(STATIC_CONST_TRUE)
    {
        /* POTENTIAL FLAW: Use a random value */
        data = (unsigned int)RAND32();
    }
    if(STATIC_CONST_FALSE)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        if(data > 0) /* ensure we won't have an underflow */
        {
            /* FIX: Add a check to prevent an overflow from occurring */
            if (data < (UINT_MAX/2))
            {
                unsigned int result = data * 2;
                printUnsignedLine(result);
            }
            else
            {
                printLine("data value is too large to perform arithmetic safely.");
            }
        }
    }
}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the second if */
static void goodB2G2()
{
    unsigned int data;
    data = 0;
    if(STATIC_CONST_TRUE)
    {
        /* POTENTIAL FLAW: Use a random value */
        data = (unsigned int)RAND32();
    }
    if(STATIC_CONST_TRUE)
    {
        if(data > 0) /* ensure we won't have an underflow */
        {
            /* FIX: Add a check to prevent an overflow from occurring */
            if (data < (UINT_MAX/2))
            {
                unsigned int result = data * 2;
                printUnsignedLine(result);
            }
            else
            {
                printLine("data value is too large to perform arithmetic safely.");
            }
        }
    }
}

/* goodG2B1() - use goodsource and badsink by changing the first STATIC_CONST_TRUE to STATIC_CONST_FALSE */
static void goodG2B1()
{
    unsigned int data;
    data = 0;
    if(STATIC_CONST_FALSE)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* FIX: Use a small, non-zero value that will not cause an overflow in the sinks */
        data = 2;
    }
    if(STATIC_CONST_TRUE)
    {
        if(data > 0) /* ensure we won't have an underflow */
        {
            /* POTENTIAL FLAW: if (data*2) > UINT_MAX, this will overflow */
            unsigned int result = data * 2;
            printUnsignedLine(result);
        }
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the first if */
static void goodG2B2()
{
    unsigned int data;
    data = 0;
    if(STATIC_CONST_TRUE)
    {
        /* FIX: Use a small, non-zero value that will not cause an overflow in the sinks */
        data = 2;
    }
    if(STATIC_CONST_TRUE)
    {
        if(data > 0) /* ensure we won't have an underflow */
        {
            /* POTENTIAL FLAW: if (data*2) > UINT_MAX, this will overflow */
            unsigned int result = data * 2;
            printUnsignedLine(result);
        }
    }
}

void CWE190_Integer_Overflow__unsigned_int_rand_multiply_04_good()
{
    goodB2G1();
    goodB2G2();
    goodG2B1();
    goodG2B2();
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
    CWE190_Integer_Overflow__unsigned_int_rand_multiply_04_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE190_Integer_Overflow__unsigned_int_rand_multiply_04_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
