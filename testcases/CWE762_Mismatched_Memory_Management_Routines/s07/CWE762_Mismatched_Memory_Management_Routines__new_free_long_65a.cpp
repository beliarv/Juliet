/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__new_free_long_65a.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__new_free.label.xml
Template File: sources-sinks-65a.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * BadSource:  Allocate data using new
 * GoodSource: Allocate data using malloc()
 * Sinks:
 *    GoodSink: Deallocate data using delete
 *    BadSink : Deallocate data using free()
 * Flow Variant: 65 Data/control flow: data passed as an argument from one function to a function in a different source file called via a function pointer
 *
 * */

#include "std_testcase.h"

namespace CWE762_Mismatched_Memory_Management_Routines__new_free_long_65
{

#ifndef OMITBAD

/* bad function declaration */
void badSink(long * data);

void bad()
{
    long * data;
    /* define a function pointer */
    void (*funcPtr) (long *) = badSink;
    /* Initialize data*/
    data = NULL;
    /* POTENTIAL FLAW: Allocate memory with a function that requires delete to free the memory */
    data = new long;
    /* use the function pointer */
    funcPtr(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSink(long * data);

static void goodG2B()
{
    long * data;
    void (*funcPtr) (long *) = goodG2BSink;
    /* Initialize data*/
    data = NULL;
    /* FIX: Allocate memory from the heap using malloc() */
    data = (long *)malloc(100*sizeof(long));
    funcPtr(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void goodB2GSink(long * data);

static void goodB2G()
{
    long * data;
    void (*funcPtr) (long *) = goodB2GSink;
    /* Initialize data*/
    data = NULL;
    /* POTENTIAL FLAW: Allocate memory with a function that requires delete to free the memory */
    data = new long;
    funcPtr(data);
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

using namespace CWE762_Mismatched_Memory_Management_Routines__new_free_long_65; /* so that we can use good and bad easily */

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
