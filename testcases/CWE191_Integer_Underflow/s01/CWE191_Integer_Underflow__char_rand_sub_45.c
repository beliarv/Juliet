/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__char_rand_sub_45.c
Label Definition File: CWE191_Integer_Underflow.label.xml
Template File: sources-sinks-45.tmpl.c
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: rand Set data to result of rand()
 * GoodSource: Set data to a small, non-zero number (negative two)
 * Sinks: sub
 *    GoodSink: Ensure there will not be an underflow before subtracting 1 from data
 *    BadSink : Subtract 1 from data, which can cause an Underflow
 * Flow Variant: 45 Data flow: data passed as a static global variable from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

static char CWE191_Integer_Underflow__char_rand_sub_45_badData;
static char CWE191_Integer_Underflow__char_rand_sub_45_goodG2BData;
static char CWE191_Integer_Underflow__char_rand_sub_45_goodB2GData;

#ifndef OMITBAD

static void badSink()
{
    char data = CWE191_Integer_Underflow__char_rand_sub_45_badData;
    {
        /* POTENTIAL FLAW: Subtracting 1 from data could cause an underflow */
        char result = data - 1;
        printHexCharLine(result);
    }
}

void CWE191_Integer_Underflow__char_rand_sub_45_bad()
{
    char data;
    data = ' ';
    /* POTENTIAL FLAW: Use a random value */
    data = (char)RAND32();
    CWE191_Integer_Underflow__char_rand_sub_45_badData = data;
    badSink();
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2BSink()
{
    char data = CWE191_Integer_Underflow__char_rand_sub_45_goodG2BData;
    {
        /* POTENTIAL FLAW: Subtracting 1 from data could cause an underflow */
        char result = data - 1;
        printHexCharLine(result);
    }
}

static void goodG2B()
{
    char data;
    data = ' ';
    /* FIX: Use a small, non-zero value that will not cause an underflow in the sinks */
    data = -2;
    CWE191_Integer_Underflow__char_rand_sub_45_goodG2BData = data;
    goodG2BSink();
}

/* goodB2G() uses the BadSource with the GoodSink */
static void goodB2GSink()
{
    char data = CWE191_Integer_Underflow__char_rand_sub_45_goodB2GData;
    /* FIX: Add a check to prevent an underflow from occurring */
    if (data > CHAR_MIN)
    {
        char result = data - 1;
        printHexCharLine(result);
    }
    else
    {
        printLine("data value is too large to perform subtraction.");
    }
}

static void goodB2G()
{
    char data;
    data = ' ';
    /* POTENTIAL FLAW: Use a random value */
    data = (char)RAND32();
    CWE191_Integer_Underflow__char_rand_sub_45_goodB2GData = data;
    goodB2GSink();
}

void CWE191_Integer_Underflow__char_rand_sub_45_good()
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
    CWE191_Integer_Underflow__char_rand_sub_45_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE191_Integer_Underflow__char_rand_sub_45_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
