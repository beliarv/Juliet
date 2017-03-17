/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__char_max_square_54a.c
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-54a.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: max Set data to the max value for char
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: square
 *    GoodSink: Ensure there will not be an overflow before squaring data
 *    BadSink : Square data, which can lead to overflow
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <math.h>

#ifndef OMITBAD

/* bad function declaration */
void CWE190_Integer_Overflow__char_max_square_54b_badSink(char data);

void CWE190_Integer_Overflow__char_max_square_54_bad()
{
    char data;
    data = ' ';
    /* POTENTIAL FLAW: Use the maximum size of the data type */
    data = CHAR_MAX;
    CWE190_Integer_Overflow__char_max_square_54b_badSink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE190_Integer_Overflow__char_max_square_54b_goodG2BSink(char data);

static void goodG2B()
{
    char data;
    data = ' ';
    /* FIX: Use a small, non-zero value that will not cause an overflow in the sinks */
    data = 2;
    CWE190_Integer_Overflow__char_max_square_54b_goodG2BSink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE190_Integer_Overflow__char_max_square_54b_goodB2GSink(char data);

static void goodB2G()
{
    char data;
    data = ' ';
    /* POTENTIAL FLAW: Use the maximum size of the data type */
    data = CHAR_MAX;
    CWE190_Integer_Overflow__char_max_square_54b_goodB2GSink(data);
}

void CWE190_Integer_Overflow__char_max_square_54_good()
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
    CWE190_Integer_Overflow__char_max_square_54_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE190_Integer_Overflow__char_max_square_54_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
