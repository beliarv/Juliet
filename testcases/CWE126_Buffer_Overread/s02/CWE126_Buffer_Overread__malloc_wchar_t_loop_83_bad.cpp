/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE126_Buffer_Overread__malloc_wchar_t_loop_83_bad.cpp
Label Definition File: CWE126_Buffer_Overread__malloc.label.xml
Template File: sources-sink-83_bad.tmpl.cpp
*/
/*
 * @description
 * CWE: 126 Buffer Over-read
 * BadSource:  Use a small buffer
 * GoodSource: Use a large buffer
 * Sinks: loop
 *    BadSink : Copy data to string using a loop
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */
#ifndef OMITBAD

#include "std_testcase.h"
#include "CWE126_Buffer_Overread__malloc_wchar_t_loop_83.h"

namespace CWE126_Buffer_Overread__malloc_wchar_t_loop_83
{
CWE126_Buffer_Overread__malloc_wchar_t_loop_83_bad::CWE126_Buffer_Overread__malloc_wchar_t_loop_83_bad(wchar_t * dataCopy)
{
    data = dataCopy;
    /* FLAW: Use a small buffer */
    data = (wchar_t *)malloc(50*sizeof(wchar_t));
    wmemset(data, L'A', 50-1); /* fill with 'A's */
    data[50-1] = L'\0'; /* null terminate */
}

CWE126_Buffer_Overread__malloc_wchar_t_loop_83_bad::~CWE126_Buffer_Overread__malloc_wchar_t_loop_83_bad()
{
    {
        size_t i, destLen;
        wchar_t dest[100];
        wmemset(dest, L'C', 100-1);
        dest[100-1] = L'\0'; /* null terminate */
        destLen = wcslen(dest);
        /* POTENTIAL FLAW: using length of the dest where data
         * could be smaller than dest causing buffer overread */
        for (i = 0; i < destLen; i++)
        {
            dest[i] = data[i];
        }
        dest[100-1] = L'\0';
        printWLine(dest);
        free(data);
    }
}
}
#endif /* OMITBAD */
