/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__malloc_free_wchar_t_62b.cpp
Label Definition File: CWE415_Double_Free__malloc_free.label.xml
Template File: sources-sinks-62b.tmpl.cpp
*/
/*
 * @description
 * CWE: 415 Double Free
 * BadSource:  Allocate data using malloc() and Deallocate data using free()
 * GoodSource: Allocate data using malloc()
 * Sinks:
 *    GoodSink: do nothing
 *    BadSink : Deallocate data using free()
 * Flow Variant: 62 Data flow: data flows using a C++ reference from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE415_Double_Free__malloc_free_wchar_t_62
{

#ifndef OMITBAD

void badSource(wchar_t * &data)
{
    data = (wchar_t *)malloc(100*sizeof(wchar_t));
    /* POTENTIAL FLAW: Free data in the source - the bad sink frees data as well */
    free(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
void goodG2BSource(wchar_t * &data)
{
    data = (wchar_t *)malloc(100*sizeof(wchar_t));
    /* FIX: Do NOT free data in the source - the bad sink frees data */
}

/* goodB2G() uses the BadSource with the GoodSink */
void goodB2GSource(wchar_t * &data)
{
    data = (wchar_t *)malloc(100*sizeof(wchar_t));
    /* POTENTIAL FLAW: Free data in the source - the bad sink frees data as well */
    free(data);
}

#endif /* OMITGOOD */

} /* close namespace */
