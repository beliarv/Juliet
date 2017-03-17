/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE176_Improper_Handling_of_Unicode_Encoding__w32_52b.c
Label Definition File: CWE176_Improper_Handling_of_Unicode_Encoding__w32.label.xml
Template File: sources-sinks-52b.tmpl.c
*/
/*
 * @description
 * CWE: 176 Improper Handling of Unicode Encoding
 * BadSource:  Initialize data as a large unicode string
 * GoodSource: Initialize data as a small unicode string
 * Sinks:
 *    GoodSink: Ensure the array index is valid
 *    BadSink : Improperly check the array index by not checking the upper bound
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

#include <windows.h>
#include <stdio.h>
#include <wchar.h>
#include <string.h>
#pragma comment( lib, "advapi32" )

#ifndef OMITBAD

/* bad function declaration */
void CWE176_Improper_Handling_of_Unicode_Encoding__w32_52c_badSink(wchar_t * data);

void CWE176_Improper_Handling_of_Unicode_Encoding__w32_52b_badSink(wchar_t * data)
{
    CWE176_Improper_Handling_of_Unicode_Encoding__w32_52c_badSink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE176_Improper_Handling_of_Unicode_Encoding__w32_52c_goodG2BSink(wchar_t * data);

void CWE176_Improper_Handling_of_Unicode_Encoding__w32_52b_goodG2BSink(wchar_t * data)
{
    CWE176_Improper_Handling_of_Unicode_Encoding__w32_52c_goodG2BSink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE176_Improper_Handling_of_Unicode_Encoding__w32_52c_goodB2GSink(wchar_t * data);

void CWE176_Improper_Handling_of_Unicode_Encoding__w32_52b_goodB2GSink(wchar_t * data)
{
    CWE176_Improper_Handling_of_Unicode_Encoding__w32_52c_goodB2GSink(data);
}

#endif /* OMITGOOD */
