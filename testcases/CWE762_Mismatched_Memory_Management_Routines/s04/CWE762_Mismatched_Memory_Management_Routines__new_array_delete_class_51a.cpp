/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__new_array_delete_class_51a.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__new_array_delete.label.xml
Template File: sources-sinks-51a.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * BadSource:  Allocate data using new []
 * GoodSource: Allocate data using new
 * Sinks:
 *    GoodSink: Deallocate data using delete []
 *    BadSink : Deallocate data using delete
 * Flow Variant: 51 Data flow: data passed as an argument from one function to another in different source files
 *
 * */

#include "std_testcase.h"

namespace CWE762_Mismatched_Memory_Management_Routines__new_array_delete_class_51
{

#ifndef OMITBAD

/* bad function declaration */
void badSink(TwoIntsClass * data);

void bad()
{
    TwoIntsClass * data;
    /* Initialize data*/
    data = NULL;
    /* POTENTIAL FLAW: Allocate memory with a function that requires delete [] to free the memory */
    data = new TwoIntsClass[100];
    badSink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declarations */
void goodG2BSink(TwoIntsClass * data);
void goodB2GSink(TwoIntsClass * data);

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    TwoIntsClass * data;
    /* Initialize data*/
    data = NULL;
    /* FIX: Allocate memory from the heap using new */
    data = new TwoIntsClass;
    goodG2BSink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
static void goodB2G()
{
    TwoIntsClass * data;
    /* Initialize data*/
    data = NULL;
    /* POTENTIAL FLAW: Allocate memory with a function that requires delete [] to free the memory */
    data = new TwoIntsClass[100];
    goodB2GSink(data);
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

using namespace CWE762_Mismatched_Memory_Management_Routines__new_array_delete_class_51; /* so that we can use good and bad easily */

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
