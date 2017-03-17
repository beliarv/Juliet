/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__malloc_free_int64_t_83_bad.cpp
Label Definition File: CWE415_Double_Free__malloc_free.label.xml
Template File: sources-sinks-83_bad.tmpl.cpp
*/
/*
 * @description
 * CWE: 415 Double Free
 * BadSource:  Allocate data using malloc() and Deallocate data using free()
 * GoodSource: Allocate data using malloc()
 * Sinks:
 *    GoodSink: do nothing
 *    BadSink : Deallocate data using free()
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */
#ifndef OMITBAD

#include "std_testcase.h"
#include "CWE415_Double_Free__malloc_free_int64_t_83.h"

namespace CWE415_Double_Free__malloc_free_int64_t_83
{
CWE415_Double_Free__malloc_free_int64_t_83_bad::CWE415_Double_Free__malloc_free_int64_t_83_bad(int64_t * dataCopy)
{
    data = dataCopy;
    data = (int64_t *)malloc(100*sizeof(int64_t));
    /* POTENTIAL FLAW: Free data in the source - the bad sink frees data as well */
    free(data);
}

CWE415_Double_Free__malloc_free_int64_t_83_bad::~CWE415_Double_Free__malloc_free_int64_t_83_bad()
{
    /* POTENTIAL FLAW: Possibly freeing memory twice */
    free(data);
}
}
#endif /* OMITBAD */
