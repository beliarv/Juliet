/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__delete_int64_t_malloc_83_goodB2G.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__delete.label.xml
Template File: sources-sinks-83_goodB2G.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * BadSource: malloc Allocate data using malloc()
 * GoodSource: Allocate data using new
 * Sinks:
 *    GoodSink: Deallocate data using free()
 *    BadSink : Deallocate data using delete
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */
#ifndef OMITGOOD

#include "std_testcase.h"
#include "CWE762_Mismatched_Memory_Management_Routines__delete_int64_t_malloc_83.h"

namespace CWE762_Mismatched_Memory_Management_Routines__delete_int64_t_malloc_83
{
CWE762_Mismatched_Memory_Management_Routines__delete_int64_t_malloc_83_goodB2G::CWE762_Mismatched_Memory_Management_Routines__delete_int64_t_malloc_83_goodB2G(int64_t * dataCopy)
{
    data = dataCopy;
    /* POTENTIAL FLAW: Allocate memory with a function that requires free() to free the memory */
    data = (int64_t *)malloc(100*sizeof(int64_t));
}

CWE762_Mismatched_Memory_Management_Routines__delete_int64_t_malloc_83_goodB2G::~CWE762_Mismatched_Memory_Management_Routines__delete_int64_t_malloc_83_goodB2G()
{
    /* FIX: Deallocate the memory using free() */
    free(data);
}
}
#endif /* OMITGOOD */
