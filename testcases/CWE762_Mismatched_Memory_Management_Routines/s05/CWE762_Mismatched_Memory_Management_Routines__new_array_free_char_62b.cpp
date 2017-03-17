/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__new_array_free_char_62b.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__new_array_free.label.xml
Template File: sources-sinks-62b.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * BadSource:  Allocate data using new []
 * GoodSource: Allocate data using malloc()
 * Sinks:
 *    GoodSink: Deallocate data using delete []
 *    BadSink : Deallocate data using free()
 * Flow Variant: 62 Data flow: data flows using a C++ reference from one function to another in different source files
 *
 * */

#include "std_testcase.h"

namespace CWE762_Mismatched_Memory_Management_Routines__new_array_free_char_62
{

#ifndef OMITBAD

void badSource(char * &data)
{
    /* POTENTIAL FLAW: Allocate memory with a function that requires delete [] to free the memory */
    data = new char[100];
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
void goodG2BSource(char * &data)
{
    /* FIX: Allocate memory from the heap using malloc() */
    data = (char *)malloc(100*sizeof(char));
}

/* goodB2G() uses the BadSource with the GoodSink */
void goodB2GSource(char * &data)
{
    /* POTENTIAL FLAW: Allocate memory with a function that requires delete [] to free the memory */
    data = new char[100];
}

#endif /* OMITGOOD */

} /* close namespace */
