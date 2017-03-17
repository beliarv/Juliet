/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE176_Improper_Handling_of_Unicode_Encoding__w32_34.c
Label Definition File: CWE176_Improper_Handling_of_Unicode_Encoding__w32.label.xml
Template File: sources-sinks-34.tmpl.c
*/
/*
 * @description
 * CWE: 176 Improper Handling of Unicode Encoding
 * BadSource:  Initialize data as a large unicode string
 * GoodSource: Initialize data as a small unicode string
 * Sinks:
 *    GoodSink: Ensure the array index is valid
 *    BadSink : Improperly check the array index by not checking the upper bound
 * Flow Variant: 34 Data flow: use of a union containing two methods of accessing the same data (within the same function)
 *
 * */

#include "std_testcase.h"

#include <windows.h>
#include <stdio.h>
#include <wchar.h>
#include <string.h>
#pragma comment( lib, "advapi32" )

typedef union
{
    wchar_t * unionFirst;
    wchar_t * unionSecond;
} CWE176_Improper_Handling_of_Unicode_Encoding__w32_34_unionType;

#ifndef OMITBAD

void CWE176_Improper_Handling_of_Unicode_Encoding__w32_34_bad()
{
    wchar_t * data;
    CWE176_Improper_Handling_of_Unicode_Encoding__w32_34_unionType myUnion;
    wchar_t dataBuffer[100];
    data = dataBuffer;
    /* POTENTIAL FLAW: Initialize data as a large unicode string that will cause a buffer overflow in the bad sink */
    wcscpy(data, L"\\u9580\\u961c\\u9640\\u963f\\u963b\\u9644\\u9580\\u961c\\u9640\\u963f\\u963b\\u9644");
    myUnion.unionFirst = data;
    {
        wchar_t * data = myUnion.unionSecond;
        {
            char convertedText[10] = "";
            int requiredSize;
            requiredSize = WideCharToMultiByte(CP_ACP, WC_COMPOSITECHECK, data, -1, convertedText, 0, 0, 0);
            /* POTENTIAL FLAW: Do not check that the size of the destination buffer for the conversion is large enough. */
            WideCharToMultiByte(CP_ACP, WC_COMPOSITECHECK, data, -1, convertedText, requiredSize , 0, 0);
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    wchar_t * data;
    CWE176_Improper_Handling_of_Unicode_Encoding__w32_34_unionType myUnion;
    wchar_t dataBuffer[100];
    data = dataBuffer;
    /* FIX: Initialize data as a small unicode string that will NOT cause a buffer overflow in the bad sink */
    wcscpy(data, L"\\u9580");
    myUnion.unionFirst = data;
    {
        wchar_t * data = myUnion.unionSecond;
        {
            char convertedText[10] = "";
            int requiredSize;
            requiredSize = WideCharToMultiByte(CP_ACP, WC_COMPOSITECHECK, data, -1, convertedText, 0, 0, 0);
            /* POTENTIAL FLAW: Do not check that the size of the destination buffer for the conversion is large enough. */
            WideCharToMultiByte(CP_ACP, WC_COMPOSITECHECK, data, -1, convertedText, requiredSize , 0, 0);
        }
    }
}

/* goodB2G() uses the BadSource with the GoodSink */
static void goodB2G()
{
    wchar_t * data;
    CWE176_Improper_Handling_of_Unicode_Encoding__w32_34_unionType myUnion;
    wchar_t dataBuffer[100];
    data = dataBuffer;
    /* POTENTIAL FLAW: Initialize data as a large unicode string that will cause a buffer overflow in the bad sink */
    wcscpy(data, L"\\u9580\\u961c\\u9640\\u963f\\u963b\\u9644\\u9580\\u961c\\u9640\\u963f\\u963b\\u9644");
    myUnion.unionFirst = data;
    {
        wchar_t * data = myUnion.unionSecond;
        {
            char convertedText[10] = "";
            int requiredSize;
            requiredSize = WideCharToMultiByte(CP_ACP, WC_COMPOSITECHECK, data, -1, convertedText, 0, 0, 0);
            /* FIX: Check that the size of the destination buffer for the conversion is large enough. */
            if (requiredSize < 10)
            {
                WideCharToMultiByte(CP_ACP, WC_COMPOSITECHECK, data, -1, convertedText, requiredSize , 0, 0);
            }
            else
            {
                printLine("Destination buffer not large enough to perform conversion.");
            }
        }
    }
}

void CWE176_Improper_Handling_of_Unicode_Encoding__w32_34_good()
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
    CWE176_Improper_Handling_of_Unicode_Encoding__w32_34_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE176_Improper_Handling_of_Unicode_Encoding__w32_34_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
