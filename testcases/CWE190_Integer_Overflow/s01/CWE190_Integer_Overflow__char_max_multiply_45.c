/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__char_max_multiply_45.c
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-45.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: max Set data to the max value for char
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: multiply
 *    GoodSink: Ensure there will not be an overflow before multiplying data by 2
 *    BadSink : If data is positive, multiply by 2, which can cause an overflow
 * Flow Variant: 45 Data flow: data passed as a static global variable from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

static char CWE190_Integer_Overflow__char_max_multiply_45_badData;
static char CWE190_Integer_Overflow__char_max_multiply_45_goodG2BData;
static char CWE190_Integer_Overflow__char_max_multiply_45_goodB2GData;

#ifndef OMITBAD

static void badSink()
{
    char data = CWE190_Integer_Overflow__char_max_multiply_45_badData;
    if(data > 0) /* ensure we won't have an underflow */
    {
        /* POTENTIAL FLAW: if (data*2) > CHAR_MAX, this will overflow */
        char result = data * 2;
        printHexCharLine(result);
    }
}

void CWE190_Integer_Overflow__char_max_multiply_45_bad()
{
    char data;
    data = ' ';
    /* POTENTIAL FLAW: Use the maximum size of the data type */
    data = CHAR_MAX;
    CWE190_Integer_Overflow__char_max_multiply_45_badData = data;
    badSink();
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2BSink()
{
    char data = CWE190_Integer_Overflow__char_max_multiply_45_goodG2BData;
    if(data > 0) /* ensure we won't have an underflow */
    {
        /* POTENTIAL FLAW: if (data*2) > CHAR_MAX, this will overflow */
        char result = data * 2;
        printHexCharLine(result);
    }
}

static void goodG2B()
{
    char data;
    data = ' ';
    /* FIX: Use a small, non-zero value that will not cause an overflow in the sinks */
    data = 2;
    CWE190_Integer_Overflow__char_max_multiply_45_goodG2BData = data;
    goodG2BSink();
}

/* goodB2G() uses the BadSource with the GoodSink */
static void goodB2GSink()
{
    char data = CWE190_Integer_Overflow__char_max_multiply_45_goodB2GData;
    if(data > 0) /* ensure we won't have an underflow */
    {
        /* FIX: Add a check to prevent an overflow from occurring */
        if (data < (CHAR_MAX/2))
        {
            char result = data * 2;
            printHexCharLine(result);
        }
        else
        {
            printLine("data value is too large to perform arithmetic safely.");
        }
    }
}

static void goodB2G()
{
    char data;
    data = ' ';
    /* POTENTIAL FLAW: Use the maximum size of the data type */
    data = CHAR_MAX;
    CWE190_Integer_Overflow__char_max_multiply_45_goodB2GData = data;
    goodB2GSink();
}

void CWE190_Integer_Overflow__char_max_multiply_45_good()
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
    CWE190_Integer_Overflow__char_max_multiply_45_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE190_Integer_Overflow__char_max_multiply_45_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
