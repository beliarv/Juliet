/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__strdup_delete_array_char_61b.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__strdup_delete_array.label.xml
Template File: sources-sinks-61b.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * BadSource:  Allocate data using strdup()
 * GoodSource: Allocate data using new []
 * Sinks:
 *    GoodSink: Deallocate data using free()
 *    BadSink : Deallocate data using delete []
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE762_Mismatched_Memory_Management_Routines__strdup_delete_array_char_61
{

#ifndef OMITBAD

char * badSource(char * data)
{
    {
        char myString[] = "myString";
        /* POTENTIAL FLAW: Allocate memory with a function that requires free() to free the memory */
        data = strdup(myString);
    }
    return data;
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
char * goodG2BSource(char * data)
{
    /* FIX: Allocate memory from the heap using new [] */
    data = new char[100];
    return data;
}

/* goodB2G() uses the BadSource with the GoodSink */
char * goodB2GSource(char * data)
{
    {
        char myString[] = "myString";
        /* POTENTIAL FLAW: Allocate memory with a function that requires free() to free the memory */
        data = strdup(myString);
    }
    return data;
}

#endif /* OMITGOOD */

} /* close namespace */
