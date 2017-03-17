/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__new_delete_int_83_goodB2G.cpp
Label Definition File: CWE415_Double_Free__new_delete.label.xml
Template File: sources-sinks-83_goodB2G.tmpl.cpp
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
#ifndef OMITGOOD

#include "std_testcase.h"
#include "CWE415_Double_Free__new_delete_int_83.h"

namespace CWE415_Double_Free__new_delete_int_83
{
CWE415_Double_Free__new_delete_int_83_goodB2G::CWE415_Double_Free__new_delete_int_83_goodB2G(int * dataCopy)
{
    data = dataCopy;
    data = new int;
    /* POTENTIAL FLAW: delete data in the source - the bad sink deletes data as well */
    delete data;
}

CWE415_Double_Free__new_delete_int_83_goodB2G::~CWE415_Double_Free__new_delete_int_83_goodB2G()
{
    /* do nothing */
    /* FIX: Don't attempt to delete the memory */
    ; /* empty statement needed for some flow variants */
}
}
#endif /* OMITGOOD */
