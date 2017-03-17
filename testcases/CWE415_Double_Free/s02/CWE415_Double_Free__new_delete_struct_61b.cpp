/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__new_delete_struct_61b.cpp
Label Definition File: CWE415_Double_Free__new_delete.label.xml
Template File: sources-sinks-61b.tmpl.cpp
*/
/*
 * @description
 * CWE: 415 Double Free
 * BadSource:  Allocate data using new and Deallocae data using delete
 * GoodSource: Allocate data using new
 * Sinks:
 *    GoodSink: do nothing
 *    BadSink : Deallocate data using delete
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE415_Double_Free__new_delete_struct_61
{

#ifndef OMITBAD

twoIntsStruct * badSource(twoIntsStruct * data)
{
    data = new twoIntsStruct;
    /* POTENTIAL FLAW: delete data in the source - the bad sink deletes data as well */
    delete data;
    return data;
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
twoIntsStruct * goodG2BSource(twoIntsStruct * data)
{
    data = new twoIntsStruct;
    /* FIX: Do NOT delete data in the source - the bad sink deletes data */
    return data;
}

/* goodB2G() uses the BadSource with the GoodSink */
twoIntsStruct * goodB2GSource(twoIntsStruct * data)
{
    data = new twoIntsStruct;
    /* POTENTIAL FLAW: delete data in the source - the bad sink deletes data as well */
    delete data;
    return data;
}

#endif /* OMITGOOD */

} /* close namespace */
