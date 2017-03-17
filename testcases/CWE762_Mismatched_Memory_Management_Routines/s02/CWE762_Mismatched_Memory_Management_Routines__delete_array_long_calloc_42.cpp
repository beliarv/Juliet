/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__delete_array_long_calloc_42.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__delete_array.label.xml
Template File: sources-sinks-42.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * BadSource: calloc Allocate data using calloc()
 * GoodSource: Allocate data using new []
 * Sinks:
 *    GoodSink: Deallocate data using free()
 *    BadSink : Deallocate data using delete []
 * Flow Variant: 42 Data flow: data returned from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

namespace CWE762_Mismatched_Memory_Management_Routines__delete_array_long_calloc_42
{

#ifndef OMITBAD

static long * badSource(long * data)
{
    /* POTENTIAL FLAW: Allocate memory with a function that requires free() to free the memory */
    data = (long *)calloc(100, sizeof(long));
    return data;
}

void bad()
{
    long * data;
    /* Initialize data*/
    data = NULL;
    data = badSource(data);
    /* POTENTIAL FLAW: Deallocate memory using delete [] - the source memory allocation function may
     * require a call to free() to deallocate the memory */
    delete [] data;
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static long * goodG2BSource(long * data)
{
    /* FIX: Allocate memory using new [] */
    data = new long[100];
    return data;
}

static void goodG2B()
{
    long * data;
    /* Initialize data*/
    data = NULL;
    data = goodG2BSource(data);
    /* POTENTIAL FLAW: Deallocate memory using delete [] - the source memory allocation function may
     * require a call to free() to deallocate the memory */
    delete [] data;
}

/* goodB2G() uses the BadSource with the GoodSink */
static long * goodB2GSource(long * data)
{
    /* POTENTIAL FLAW: Allocate memory with a function that requires free() to free the memory */
    data = (long *)calloc(100, sizeof(long));
    return data;
}

static void goodB2G()
{
    long * data;
    /* Initialize data*/
    data = NULL;
    data = goodB2GSource(data);
    /* FIX: Free memory using free() */
    free(data);
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

using namespace CWE762_Mismatched_Memory_Management_Routines__delete_array_long_calloc_42; /* so that we can use good and bad easily */

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
