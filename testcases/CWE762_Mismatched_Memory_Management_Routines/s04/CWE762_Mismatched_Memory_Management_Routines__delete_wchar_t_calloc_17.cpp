/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__delete_wchar_t_calloc_17.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__delete.label.xml
Template File: sources-sinks-17.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * BadSource: calloc Allocate data using calloc()
 * GoodSource: Allocate data using new
 * Sinks:
 *    GoodSink: Deallocate data using free()
 *    BadSink : Deallocate data using delete
 * Flow Variant: 17 Control flow: for loops
 * */

#include "std_testcase.h"

namespace CWE762_Mismatched_Memory_Management_Routines__delete_wchar_t_calloc_17
{

#ifndef OMITBAD

void bad()
{
    int i,j;
    wchar_t * data;
    /* Initialize data*/
    data = NULL;
    for(i = 0; i < 1; i++)
    {
        /* POTENTIAL FLAW: Allocate memory with a function that requires free() to free the memory */
        data = (wchar_t *)calloc(100, sizeof(wchar_t));
    }
    for(j = 0; j < 1; j++)
    {
        /* POTENTIAL FLAW: Deallocate memory using delete - the source memory allocation function may
         * require a call to free() to deallocate the memory */
        delete data;
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G() - use badsource and goodsink in the for statements */
static void goodB2G()
{
    int i,k;
    wchar_t * data;
    /* Initialize data*/
    data = NULL;
    for(i = 0; i < 1; i++)
    {
        /* POTENTIAL FLAW: Allocate memory with a function that requires free() to free the memory */
        data = (wchar_t *)calloc(100, sizeof(wchar_t));
    }
    for(k = 0; k < 1; k++)
    {
        /* FIX: Deallocate the memory using free() */
        free(data);
    }
}

/* goodG2B() - use goodsource and badsink in the for statements */
static void goodG2B()
{
    int h,j;
    wchar_t * data;
    /* Initialize data*/
    data = NULL;
    for(h = 0; h < 1; h++)
    {
        /* FIX: Allocate memory from the heap using new */
        data = new wchar_t;
    }
    for(j = 0; j < 1; j++)
    {
        /* POTENTIAL FLAW: Deallocate memory using delete - the source memory allocation function may
         * require a call to free() to deallocate the memory */
        delete data;
    }
}

void good()
{
    goodB2G();
    goodG2B();
}

#endif /* OMITGOOD */

} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE762_Mismatched_Memory_Management_Routines__delete_wchar_t_calloc_17; /* so that we can use good and bad easily */

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
