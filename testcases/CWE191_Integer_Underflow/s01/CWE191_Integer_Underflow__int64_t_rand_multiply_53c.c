/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__int64_t_rand_multiply_53c.c
Label Definition File: CWE191_Integer_Underflow.label.xml
Template File: sources-sinks-53c.tmpl.c
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: rand Set data to result of rand()
 * GoodSource: Set data to a small, non-zero number (negative two)
 * Sinks: multiply
 *    GoodSink: Ensure there will not be an underflow before multiplying data by 2
 *    BadSink : If data is negative, multiply by 2, which can cause an underflow
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

/* bad function declaration */
void CWE191_Integer_Underflow__int64_t_rand_multiply_53d_badSink(int64_t data);

void CWE191_Integer_Underflow__int64_t_rand_multiply_53c_badSink(int64_t data)
{
    CWE191_Integer_Underflow__int64_t_rand_multiply_53d_badSink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE191_Integer_Underflow__int64_t_rand_multiply_53d_goodG2BSink(int64_t data);

void CWE191_Integer_Underflow__int64_t_rand_multiply_53c_goodG2BSink(int64_t data)
{
    CWE191_Integer_Underflow__int64_t_rand_multiply_53d_goodG2BSink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE191_Integer_Underflow__int64_t_rand_multiply_53d_goodB2GSink(int64_t data);

void CWE191_Integer_Underflow__int64_t_rand_multiply_53c_goodB2GSink(int64_t data)
{
    CWE191_Integer_Underflow__int64_t_rand_multiply_53d_goodB2GSink(data);
}

#endif /* OMITGOOD */
