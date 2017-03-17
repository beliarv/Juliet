/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__int64_t_rand_square_68b.c
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-68b.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: rand Set data to result of rand()
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: square
 *    GoodSink: Ensure there will not be an overflow before squaring data
 *    BadSink : Square data, which can lead to overflow
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <math.h>

extern int64_t CWE190_Integer_Overflow__int64_t_rand_square_68_badData;
extern int64_t CWE190_Integer_Overflow__int64_t_rand_square_68_goodG2BData;
extern int64_t CWE190_Integer_Overflow__int64_t_rand_square_68_goodB2GData;

#ifndef OMITBAD

void CWE190_Integer_Overflow__int64_t_rand_square_68b_badSink()
{
    int64_t data = CWE190_Integer_Overflow__int64_t_rand_square_68_badData;
    {
        /* POTENTIAL FLAW: if (data*data) > LLONG_MAX, this will overflow */
        int64_t result = data * data;
        printLongLongLine(result);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE190_Integer_Overflow__int64_t_rand_square_68b_goodG2BSink()
{
    int64_t data = CWE190_Integer_Overflow__int64_t_rand_square_68_goodG2BData;
    {
        /* POTENTIAL FLAW: if (data*data) > LLONG_MAX, this will overflow */
        int64_t result = data * data;
        printLongLongLine(result);
    }
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE190_Integer_Overflow__int64_t_rand_square_68b_goodB2GSink()
{
    int64_t data = CWE190_Integer_Overflow__int64_t_rand_square_68_goodB2GData;
    /* FIX: Add a check to prevent an overflow from occurring */
    if (abs((long)data) <= (long)sqrt((double)LLONG_MAX))
    {
        int64_t result = data * data;
        printLongLongLine(result);
    }
    else
    {
        printLine("data value is too large to perform arithmetic safely.");
    }
}

#endif /* OMITGOOD */
