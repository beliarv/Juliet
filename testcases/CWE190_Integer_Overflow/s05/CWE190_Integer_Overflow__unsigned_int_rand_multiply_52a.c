/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__unsigned_int_rand_multiply_52a.c
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-52a.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: rand Set data to result of rand()
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: multiply
 *    GoodSink: Ensure there will not be an overflow before multiplying data by 2
 *    BadSink : If data is positive, multiply by 2, which can cause an overflow
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

/* bad function declaration */
void CWE190_Integer_Overflow__unsigned_int_rand_multiply_52b_badSink(unsigned int data);

void CWE190_Integer_Overflow__unsigned_int_rand_multiply_52_bad()
{
    unsigned int data;
    data = 0;
    /* POTENTIAL FLAW: Use a random value */
    data = (unsigned int)RAND32();
    CWE190_Integer_Overflow__unsigned_int_rand_multiply_52b_badSink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE190_Integer_Overflow__unsigned_int_rand_multiply_52b_goodG2BSink(unsigned int data);

static void goodG2B()
{
    unsigned int data;
    data = 0;
    /* FIX: Use a small, non-zero value that will not cause an overflow in the sinks */
    data = 2;
    CWE190_Integer_Overflow__unsigned_int_rand_multiply_52b_goodG2BSink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE190_Integer_Overflow__unsigned_int_rand_multiply_52b_goodB2GSink(unsigned int data);

static void goodB2G()
{
    unsigned int data;
    data = 0;
    /* POTENTIAL FLAW: Use a random value */
    data = (unsigned int)RAND32();
    CWE190_Integer_Overflow__unsigned_int_rand_multiply_52b_goodB2GSink(data);
}

void CWE190_Integer_Overflow__unsigned_int_rand_multiply_52_good()
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
    CWE190_Integer_Overflow__unsigned_int_rand_multiply_52_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE190_Integer_Overflow__unsigned_int_rand_multiply_52_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
