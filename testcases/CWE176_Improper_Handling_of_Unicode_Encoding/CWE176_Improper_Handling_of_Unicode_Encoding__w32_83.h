/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE176_Improper_Handling_of_Unicode_Encoding__w32_83.h
Label Definition File: CWE176_Improper_Handling_of_Unicode_Encoding__w32.label.xml
Template File: sources-sinks-83.tmpl.h
*/
/*
 * @description
 * CWE: 176 Improper Handling of Unicode Encoding
 * BadSource:  Initialize data as a large unicode string
 * GoodSource: Initialize data as a small unicode string
 * Sinks:
 *    GoodSink: Ensure the array index is valid
 *    BadSink : Improperly check the array index by not checking the upper bound
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */

#include "std_testcase.h"

#include <windows.h>
#include <stdio.h>
#include <wchar.h>
#include <string.h>
#pragma comment( lib, "advapi32" )

namespace CWE176_Improper_Handling_of_Unicode_Encoding__w32_83
{

#ifndef OMITBAD

class CWE176_Improper_Handling_of_Unicode_Encoding__w32_83_bad
{
public:
    CWE176_Improper_Handling_of_Unicode_Encoding__w32_83_bad(wchar_t * dataCopy);
    ~CWE176_Improper_Handling_of_Unicode_Encoding__w32_83_bad();

private:
    wchar_t * data;
};

#endif /* OMITBAD */

#ifndef OMITGOOD

class CWE176_Improper_Handling_of_Unicode_Encoding__w32_83_goodG2B
{
public:
    CWE176_Improper_Handling_of_Unicode_Encoding__w32_83_goodG2B(wchar_t * dataCopy);
    ~CWE176_Improper_Handling_of_Unicode_Encoding__w32_83_goodG2B();

private:
    wchar_t * data;
};

class CWE176_Improper_Handling_of_Unicode_Encoding__w32_83_goodB2G
{
public:
    CWE176_Improper_Handling_of_Unicode_Encoding__w32_83_goodB2G(wchar_t * dataCopy);
    ~CWE176_Improper_Handling_of_Unicode_Encoding__w32_83_goodB2G();

private:
    wchar_t * data;
};

#endif /* OMITGOOD */

}
