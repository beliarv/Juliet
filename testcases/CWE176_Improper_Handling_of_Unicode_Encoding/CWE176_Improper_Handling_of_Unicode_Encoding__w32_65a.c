/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE176_Improper_Handling_of_Unicode_Encoding__w32_65a.c
Label Definition File: CWE176_Improper_Handling_of_Unicode_Encoding__w32.label.xml
Template File: sources-sinks-65a.tmpl.c
*/
/*
 * @description
 * CWE: 176 Improper Handling of Unicode Encoding
 * BadSource:  Initialize data as a large unicode string
 * GoodSource: Initialize data as a small unicode string
 * Sinks:
 *    GoodSink: Ensure the array index is valid
 *    BadSink : Improperly check the array index by not checking the upper bound
 * Flow Variant: 65 Data/control flow: data passed as an argument from one function to a function in a different source file called via a function pointer
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
void CWE176_Improper_Handling_of_Unicode_Encoding__w32_65b_badSink(wchar_t * data);

void CWE176_Improper_Handling_of_Unicode_Encoding__w32_65_bad()
{
    wchar_t * data;
    /* define a function pointer */
    void (*funcPtr) (wchar_t *) = CWE176_Improper_Handling_of_Unicode_Encoding__w32_65b_badSink;
    wchar_t dataBuffer[100];
    data = dataBuffer;
    /* POTENTIAL FLAW: Initialize data as a large unicode string that will cause a buffer overflow in the bad sink */
    wcscpy(data, L"\\u9580\\u961c\\u9640\\u963f\\u963b\\u9644\\u9580\\u961c\\u9640\\u963f\\u963b\\u9644");
    /* use the function pointer */
    funcPtr(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE176_Improper_Handling_of_Unicode_Encoding__w32_65b_goodG2BSink(wchar_t * data);

static void goodG2B()
{
    wchar_t * data;
    void (*funcPtr) (wchar_t *) = CWE176_Improper_Handling_of_Unicode_Encoding__w32_65b_goodG2BSink;
    wchar_t dataBuffer[100];
    data = dataBuffer;
    /* FIX: Initialize data as a small unicode string that will NOT cause a buffer overflow in the bad sink */
    wcscpy(data, L"\\u9580");
    funcPtr(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE176_Improper_Handling_of_Unicode_Encoding__w32_65b_goodB2GSink(wchar_t * data);

static void goodB2G()
{
    wchar_t * data;
    void (*funcPtr) (wchar_t *) = CWE176_Improper_Handling_of_Unicode_Encoding__w32_65b_goodB2GSink;
    wchar_t dataBuffer[100];
    data = dataBuffer;
    /* POTENTIAL FLAW: Initialize data as a large unicode string that will cause a buffer overflow in the bad sink */
    wcscpy(data, L"\\u9580\\u961c\\u9640\\u963f\\u963b\\u9644\\u9580\\u961c\\u9640\\u963f\\u963b\\u9644");
    funcPtr(data);
}

void CWE176_Improper_Handling_of_Unicode_Encoding__w32_65_good()
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
    CWE176_Improper_Handling_of_Unicode_Encoding__w32_65_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE176_Improper_Handling_of_Unicode_Encoding__w32_65_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
