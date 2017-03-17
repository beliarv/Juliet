/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE476_NULL_Pointer_Dereference__wchar_t_31.c
Label Definition File: CWE476_NULL_Pointer_Dereference.label.xml
Template File: sources-sinks-31.tmpl.c
*/
/*
 * @description
 * CWE: 476 NULL Pointer Dereference
 * BadSource:  Set data to NULL
 * GoodSource: Initialize data
 * Sinks:
 *    GoodSink: Check for NULL before attempting to print data
 *    BadSink : Print data
 * Flow Variant: 31 Data flow using a copy of data within the same function
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE476_NULL_Pointer_Dereference__wchar_t_31_bad()
{
    wchar_t * data;
    /* POTENTIAL FLAW: Set data to NULL */
    data = NULL;
    {
        wchar_t * dataCopy = data;
        wchar_t * data = dataCopy;
        /* POTENTIAL FLAW: Attempt to use data, which may be NULL */
        /* printWLine() checks for NULL, so we cannot use it here */
        printWcharLine(data[0]);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    wchar_t * data;
    /* FIX: Initialize data */
    data = L"Good";
    {
        wchar_t * dataCopy = data;
        wchar_t * data = dataCopy;
        /* POTENTIAL FLAW: Attempt to use data, which may be NULL */
        /* printWLine() checks for NULL, so we cannot use it here */
        printWcharLine(data[0]);
    }
}

/* goodB2G() uses the BadSource with the GoodSink */
static void goodB2G()
{
    wchar_t * data;
    /* POTENTIAL FLAW: Set data to NULL */
    data = NULL;
    {
        wchar_t * dataCopy = data;
        wchar_t * data = dataCopy;
        /* FIX: Check for NULL before attempting to print data */
        if (data != NULL)
        {
            /* printWLine() checks for NULL, so we cannot use it here */
            printWcharLine(data[0]);
        }
        else
        {
            printLine("data is NULL");
        }
    }
}

void CWE476_NULL_Pointer_Dereference__wchar_t_31_good()
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
    CWE476_NULL_Pointer_Dereference__wchar_t_31_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE476_NULL_Pointer_Dereference__wchar_t_31_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
