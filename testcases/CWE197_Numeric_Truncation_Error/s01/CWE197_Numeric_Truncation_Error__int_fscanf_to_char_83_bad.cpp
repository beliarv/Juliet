/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE197_Numeric_Truncation_Error__int_fscanf_to_char_83_bad.cpp
Label Definition File: CWE197_Numeric_Truncation_Error__int.label.xml
Template File: sources-sink-83_bad.tmpl.cpp
*/
/*
 * @description
 * CWE: 197 Numeric Truncation Error
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Less than CHAR_MAX
 * Sinks: to_char
 *    BadSink : Convert data to a char
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */
#ifndef OMITBAD

#include "std_testcase.h"
#include "CWE197_Numeric_Truncation_Error__int_fscanf_to_char_83.h"

namespace CWE197_Numeric_Truncation_Error__int_fscanf_to_char_83
{
CWE197_Numeric_Truncation_Error__int_fscanf_to_char_83_bad::CWE197_Numeric_Truncation_Error__int_fscanf_to_char_83_bad(int dataCopy)
{
    data = dataCopy;
    /* POTENTIAL FLAW: Read data from the console using fscanf() */
    fscanf(stdin, "%d", &data);
}

CWE197_Numeric_Truncation_Error__int_fscanf_to_char_83_bad::~CWE197_Numeric_Truncation_Error__int_fscanf_to_char_83_bad()
{
    {
        /* POTENTIAL FLAW: Convert data to a char, possibly causing a truncation error */
        char charData = (char)data;
        printHexCharLine(charData);
    }
}
}
#endif /* OMITBAD */
