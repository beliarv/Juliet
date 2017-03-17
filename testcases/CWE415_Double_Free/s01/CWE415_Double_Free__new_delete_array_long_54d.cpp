/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__new_delete_array_long_54d.cpp
Label Definition File: CWE415_Double_Free__new_delete_array.label.xml
Template File: sources-sinks-54d.tmpl.cpp
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

namespace CWE415_Double_Free__new_delete_array_long_54
{

#ifndef OMITBAD

/* bad function declaration */
void badSink_e(long * data);

void badSink_d(long * data)
{
    badSink_e(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSink_e(long * data);

void goodG2BSink_d(long * data)
{
    goodG2BSink_e(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void goodB2GSink_e(long * data);

void goodB2GSink_d(long * data)
{
    goodB2GSink_e(data);
}

#endif /* OMITGOOD */

} /* close namespace */
