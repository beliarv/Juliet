/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__new_delete_int64_t_62b.cpp
Label Definition File: CWE415_Double_Free__new_delete.label.xml
Template File: sources-sinks-62b.tmpl.cpp
*/
/*
 * @description
 * CWE: 415 Double Free
 * BadSource:  Allocate data using new and Deallocae data using delete
 * GoodSource: Allocate data using new
 * Sinks:
 *    GoodSink: do nothing
 *    BadSink : Deallocate data using delete
 * Flow Variant: 62 Data flow: data flows using a C++ reference from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE415_Double_Free__new_delete_int64_t_62
{

#ifndef OMITBAD

void badSource(int64_t * &data)
{
    data = new int64_t;
    /* POTENTIAL FLAW: delete data in the source - the bad sink deletes data as well */
    delete data;
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
void goodG2BSource(int64_t * &data)
{
    data = new int64_t;
    /* FIX: Do NOT delete data in the source - the bad sink deletes data */
}

/* goodB2G() uses the BadSource with the GoodSink */
void goodB2GSource(int64_t * &data)
{
    data = new int64_t;
    /* POTENTIAL FLAW: delete data in the source - the bad sink deletes data as well */
    delete data;
}

#endif /* OMITGOOD */

} /* close namespace */
