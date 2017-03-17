/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__new_delete_array_int_83_bad.cpp
Label Definition File: CWE415_Double_Free__new_delete_array.label.xml
Template File: sources-sinks-83_bad.tmpl.cpp
*/
/*
 * @description
 * CWE: 415 Double Free
 * BadSource:  Allocate data using new and Deallocae data using delete
 * GoodSource: Allocate data using new
 * Sinks:
 *    GoodSink: do nothing
 *    BadSink : Deallocate data using delete
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */
#ifndef OMITBAD

#include "std_testcase.h"
#include "CWE415_Double_Free__new_delete_array_int_83.h"

namespace CWE415_Double_Free__new_delete_array_int_83
{
CWE415_Double_Free__new_delete_array_int_83_bad::CWE415_Double_Free__new_delete_array_int_83_bad(int * dataCopy)
{
    data = dataCopy;
    data = new int[100];
    /* POTENTIAL FLAW: delete the array data in the source - the bad sink deletes the array data as well */
    delete [] data;
}

CWE415_Double_Free__new_delete_array_int_83_bad::~CWE415_Double_Free__new_delete_array_int_83_bad()
{
    /* POTENTIAL FLAW: Possibly deleting memory twice */
    delete [] data;
}
}
#endif /* OMITBAD */
