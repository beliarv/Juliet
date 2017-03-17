/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__delete_array_int64_t_calloc_62b.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__delete_array.label.xml
Template File: sources-sinks-62b.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * BadSource: calloc Allocate data using calloc()
 * GoodSource: Allocate data using new []
 * Sinks:
 *    GoodSink: Deallocate data using free()
 *    BadSink : Deallocate data using delete []
 * Flow Variant: 62 Data flow: data flows using a C++ reference from one function to another in different source files
 *
 * */

#include "std_testcase.h"

namespace CWE762_Mismatched_Memory_Management_Routines__delete_array_int64_t_calloc_62
{

#ifndef OMITBAD

void badSource(int64_t * &data)
{
    /* POTENTIAL FLAW: Allocate memory with a function that requires free() to free the memory */
    data = (int64_t *)calloc(100, sizeof(int64_t));
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
void goodG2BSource(int64_t * &data)
{
    /* FIX: Allocate memory using new [] */
    data = new int64_t[100];
}

/* goodB2G() uses the BadSource with the GoodSink */
void goodB2GSource(int64_t * &data)
{
    /* POTENTIAL FLAW: Allocate memory with a function that requires free() to free the memory */
    data = (int64_t *)calloc(100, sizeof(int64_t));
}

#endif /* OMITGOOD */

} /* close namespace */
