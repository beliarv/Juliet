/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__sizeof_double_68b.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__sizeof.label.xml
Template File: sources-sink-68b.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Initialize the source buffer using the size of a pointer
 * GoodSource: Initialize the source buffer using the size of the DataElementType
 * Sink:
 *    BadSink : Print then free data
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

extern double * CWE122_Heap_Based_Buffer_Overflow__sizeof_double_68_badData;
extern double * CWE122_Heap_Based_Buffer_Overflow__sizeof_double_68_goodG2BData;

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

void CWE122_Heap_Based_Buffer_Overflow__sizeof_double_68b_badSink()
{
    double * data = CWE122_Heap_Based_Buffer_Overflow__sizeof_double_68_badData;
    /* POTENTIAL FLAW: Attempt to use data, which may not have enough memory allocated */
    printDoubleLine(*data);
    free(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE122_Heap_Based_Buffer_Overflow__sizeof_double_68b_goodG2BSink()
{
    double * data = CWE122_Heap_Based_Buffer_Overflow__sizeof_double_68_goodG2BData;
    /* POTENTIAL FLAW: Attempt to use data, which may not have enough memory allocated */
    printDoubleLine(*data);
    free(data);
}

#endif /* OMITGOOD */
