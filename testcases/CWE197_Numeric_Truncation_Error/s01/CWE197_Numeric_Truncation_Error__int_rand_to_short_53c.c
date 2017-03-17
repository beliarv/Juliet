/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE197_Numeric_Truncation_Error__int_rand_to_short_53c.c
Label Definition File: CWE197_Numeric_Truncation_Error__int.label.xml
Template File: sources-sink-53c.tmpl.c
*/
/*
 * @description
 * CWE: 197 Numeric Truncation Error
 * BadSource: rand Set data to result of rand(), which may be zero
 * GoodSource: Less than CHAR_MAX
 * Sink: to_short
 *    BadSink : Convert data to a short
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

/* bad function declaration */
void CWE197_Numeric_Truncation_Error__int_rand_to_short_53d_badSink(int data);

void CWE197_Numeric_Truncation_Error__int_rand_to_short_53c_badSink(int data)
{
    CWE197_Numeric_Truncation_Error__int_rand_to_short_53d_badSink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declaration */
void CWE197_Numeric_Truncation_Error__int_rand_to_short_53d_goodG2BSink(int data);

/* goodG2B uses the GoodSource with the BadSink */
void CWE197_Numeric_Truncation_Error__int_rand_to_short_53c_goodG2BSink(int data)
{
    CWE197_Numeric_Truncation_Error__int_rand_to_short_53d_goodG2BSink(data);
}

#endif /* OMITGOOD */
