/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE197_Numeric_Truncation_Error__int_large_to_char_84_bad.cpp
Label Definition File: CWE197_Numeric_Truncation_Error__int.label.xml
Template File: sources-sink-84_bad.tmpl.cpp
*/
/*
 * @description
 * CWE: 197 Numeric Truncation Error
 * BadSource: large Set data to a number larger than SHRT_MAX
 * GoodSource: Less than CHAR_MAX
 * Sinks: to_char
 *    BadSink : Convert data to a char
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */
#ifndef OMITBAD

#include "std_testcase.h"
#include "CWE197_Numeric_Truncation_Error__int_large_to_char_84.h"

namespace CWE197_Numeric_Truncation_Error__int_large_to_char_84
{
CWE197_Numeric_Truncation_Error__int_large_to_char_84_bad::CWE197_Numeric_Truncation_Error__int_large_to_char_84_bad(int dataCopy)
{
    data = dataCopy;
    /* FLAW: Use a number larger than SHRT_MAX */
    data = SHRT_MAX + 5;
}

CWE197_Numeric_Truncation_Error__int_large_to_char_84_bad::~CWE197_Numeric_Truncation_Error__int_large_to_char_84_bad()
{
    {
        /* POTENTIAL FLAW: Convert data to a char, possibly causing a truncation error */
        char charData = (char)data;
        printHexCharLine(charData);
    }
}
}
#endif /* OMITBAD */
