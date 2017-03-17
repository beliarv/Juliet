/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__new_delete_long_54e.cpp
Label Definition File: CWE415_Double_Free__new_delete.label.xml
Template File: sources-sinks-54e.tmpl.cpp
*/
/*
 * @description
 * CWE: 415 Double Free
 * BadSource:  Allocate data using new and Deallocae data using delete
 * GoodSource: Allocate data using new
 * Sinks:
 *    GoodSink: do nothing
 *    BadSink : Deallocate data using delete
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE415_Double_Free__new_delete_long_54
{

#ifndef OMITBAD

void badSink_e(long * data)
{
    /* POTENTIAL FLAW: Possibly deleting memory twice */
    delete data;
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSink_e(long * data)
{
    /* POTENTIAL FLAW: Possibly deleting memory twice */
    delete data;
}

/* goodB2G uses the BadSource with the GoodSink */
void goodB2GSink_e(long * data)
{
    /* do nothing */
    /* FIX: Don't attempt to delete the memory */
    ; /* empty statement needed for some flow variants */
}

#endif /* OMITGOOD */

} /* close namespace */
