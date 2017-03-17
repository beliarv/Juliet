/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__delete_array_class_realloc_61b.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__delete_array.label.xml
Template File: sources-sinks-61b.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * BadSource: realloc Allocate data using realloc()
 * GoodSource: Allocate data using new []
 * Sinks:
 *    GoodSink: Deallocate data using free()
 *    BadSink : Deallocate data using delete []
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

namespace CWE762_Mismatched_Memory_Management_Routines__delete_array_class_realloc_61
{

#ifndef OMITBAD

TwoIntsClass * badSource(TwoIntsClass * data)
{
    data = NULL;
    /* POTENTIAL FLAW: Allocate memory with a function that requires free() to free the memory */
    data = (TwoIntsClass *)realloc(data, 100*sizeof(TwoIntsClass));
    return data;
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
TwoIntsClass * goodG2BSource(TwoIntsClass * data)
{
    /* FIX: Allocate memory using new [] */
    data = new TwoIntsClass[100];
    return data;
}

/* goodB2G() uses the BadSource with the GoodSink */
TwoIntsClass * goodB2GSource(TwoIntsClass * data)
{
    data = NULL;
    /* POTENTIAL FLAW: Allocate memory with a function that requires free() to free the memory */
    data = (TwoIntsClass *)realloc(data, 100*sizeof(TwoIntsClass));
    return data;
}

#endif /* OMITGOOD */

} /* close namespace */
