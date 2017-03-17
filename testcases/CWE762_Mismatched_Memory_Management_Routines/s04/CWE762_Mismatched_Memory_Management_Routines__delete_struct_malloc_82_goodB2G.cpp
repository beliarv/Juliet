/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__delete_struct_malloc_82_goodB2G.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__delete.label.xml
Template File: sources-sinks-82_goodB2G.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * BadSource: malloc Allocate data using malloc()
 * GoodSource: Allocate data using new
 * Sinks:
 *    GoodSink: Deallocate data using free()
 *    BadSink : Deallocate data using delete
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
 *
 * */
#ifndef OMITGOOD

#include "std_testcase.h"
#include "CWE762_Mismatched_Memory_Management_Routines__delete_struct_malloc_82.h"

namespace CWE762_Mismatched_Memory_Management_Routines__delete_struct_malloc_82
{

void CWE762_Mismatched_Memory_Management_Routines__delete_struct_malloc_82_goodB2G::action(twoIntsStruct * data)
{
    /* FIX: Deallocate the memory using free() */
    free(data);
}

}
#endif /* OMITGOOD */
