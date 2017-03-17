/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__delete_class_realloc_83_goodG2B.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__delete.label.xml
Template File: sources-sinks-83_goodG2B.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * BadSource: realloc Allocate data using realloc()
 * GoodSource: Allocate data using new
 * Sinks:
 *    GoodSink: Deallocate data using free()
 *    BadSink : Deallocate data using delete
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */
#ifndef OMITGOOD

#include "std_testcase.h"
#include "CWE762_Mismatched_Memory_Management_Routines__delete_class_realloc_83.h"

namespace CWE762_Mismatched_Memory_Management_Routines__delete_class_realloc_83
{
CWE762_Mismatched_Memory_Management_Routines__delete_class_realloc_83_goodG2B::CWE762_Mismatched_Memory_Management_Routines__delete_class_realloc_83_goodG2B(TwoIntsClass * dataCopy)
{
    data = dataCopy;
    /* FIX: Allocate memory from the heap using new */
    data = new TwoIntsClass;
}

CWE762_Mismatched_Memory_Management_Routines__delete_class_realloc_83_goodG2B::~CWE762_Mismatched_Memory_Management_Routines__delete_class_realloc_83_goodG2B()
{
    /* POTENTIAL FLAW: Deallocate memory using delete - the source memory allocation function may
     * require a call to free() to deallocate the memory */
    delete data;
}
}
#endif /* OMITGOOD */
