/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE127_Buffer_Underread__new_wchar_t_memcpy_65b.cpp
Label Definition File: CWE127_Buffer_Underread__new.label.xml
Template File: sources-sink-65b.tmpl.cpp
*/
/*
 * @description
 * CWE: 127 Buffer Under-read
 * BadSource:  Set data pointer to before the allocated memory buffer
 * GoodSource: Set data pointer to the allocated memory buffer
 * Sinks: memcpy
 *    BadSink : Copy data to string using memcpy
 * Flow Variant: 65 Data/control flow: data passed as an argument from one function to a function in a different source file called via a function pointer
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE127_Buffer_Underread__new_wchar_t_memcpy_65
{

#ifndef OMITBAD

void badSink(wchar_t * data)
{
    {
        wchar_t dest[100];
        wmemset(dest, L'C', 100-1); /* fill with 'C's */
        dest[100-1] = L'\0'; /* null terminate */
        /* POTENTIAL FLAW: Possibly copy from a memory location located before the source buffer */
        memcpy(dest, data, 100*sizeof(wchar_t));
        /* Ensure null termination */
        dest[100-1] = L'\0';
        printWLine(dest);
        /* INCIDENTAL CWE-401: Memory Leak - data may not point to location
         * returned by new [] so can't safely call delete [] on it */
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSink(wchar_t * data)
{
    {
        wchar_t dest[100];
        wmemset(dest, L'C', 100-1); /* fill with 'C's */
        dest[100-1] = L'\0'; /* null terminate */
        /* POTENTIAL FLAW: Possibly copy from a memory location located before the source buffer */
        memcpy(dest, data, 100*sizeof(wchar_t));
        /* Ensure null termination */
        dest[100-1] = L'\0';
        printWLine(dest);
        /* INCIDENTAL CWE-401: Memory Leak - data may not point to location
         * returned by new [] so can't safely call delete [] on it */
    }
}

#endif /* OMITGOOD */

} /* close namespace */
