/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__new_delete_array_class_33.cpp
Label Definition File: CWE415_Double_Free__new_delete_array.label.xml
Template File: sources-sinks-33.tmpl.cpp
*/
/*
 * @description
 * CWE: 415 Double Free
 * BadSource:  Allocate data using new and Deallocae data using delete
 * GoodSource: Allocate data using new
 * Sinks:
 *    GoodSink: do nothing
 *    BadSink : Deallocate data using delete
 * Flow Variant: 33 Data flow: use of a C++ reference to data within the same function
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE415_Double_Free__new_delete_array_class_33
{

#ifndef OMITBAD

void bad()
{
    TwoIntsClass * data;
    TwoIntsClass * &dataRef = data;
    /* Initialize data */
    data = NULL;
    data = new TwoIntsClass[100];
    /* POTENTIAL FLAW: delete the array data in the source - the bad sink deletes the array data as well */
    delete [] data;
    {
        TwoIntsClass * data = dataRef;
        /* POTENTIAL FLAW: Possibly deleting memory twice */
        delete [] data;
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    TwoIntsClass * data;
    TwoIntsClass * &dataRef = data;
    /* Initialize data */
    data = NULL;
    data = new TwoIntsClass[100];
    /* FIX: Do NOT delete the array data in the source - the bad sink deletes the array data */
    {
        TwoIntsClass * data = dataRef;
        /* POTENTIAL FLAW: Possibly deleting memory twice */
        delete [] data;
    }
}

/* goodB2G() uses the BadSource with the GoodSink */
static void goodB2G()
{
    TwoIntsClass * data;
    TwoIntsClass * &dataRef = data;
    /* Initialize data */
    data = NULL;
    data = new TwoIntsClass[100];
    /* POTENTIAL FLAW: delete the array data in the source - the bad sink deletes the array data as well */
    delete [] data;
    {
        TwoIntsClass * data = dataRef;
        /* do nothing */
        /* FIX: Don't attempt to delete the memory */
        ; /* empty statement needed for some flow variants */
    }
}

void good()
{
    goodG2B();
    goodB2G();
}

#endif /* OMITGOOD */

} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */
#ifdef INCLUDEMAIN

using namespace CWE415_Double_Free__new_delete_array_class_33; /* so that we can use good and bad easily */

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
