/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__delete_array_struct_realloc_81.h
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__delete_array.label.xml
Template File: sources-sinks-81.tmpl.h
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * BadSource: realloc Allocate data using realloc()
 * GoodSource: Allocate data using new []
 * Sinks:
 *    GoodSink: Deallocate data using free()
 *    BadSink : Deallocate data using delete []
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */

#include "std_testcase.h"

namespace CWE762_Mismatched_Memory_Management_Routines__delete_array_struct_realloc_81
{

class CWE762_Mismatched_Memory_Management_Routines__delete_array_struct_realloc_81_base
{
public:
    /* pure virtual function */
    virtual void action(twoIntsStruct * data) const = 0;
};

#ifndef OMITBAD

class CWE762_Mismatched_Memory_Management_Routines__delete_array_struct_realloc_81_bad : public CWE762_Mismatched_Memory_Management_Routines__delete_array_struct_realloc_81_base
{
public:
    void action(twoIntsStruct * data) const;
};

#endif /* OMITBAD */

#ifndef OMITGOOD

class CWE762_Mismatched_Memory_Management_Routines__delete_array_struct_realloc_81_goodG2B : public CWE762_Mismatched_Memory_Management_Routines__delete_array_struct_realloc_81_base
{
public:
    void action(twoIntsStruct * data) const;
};

class CWE762_Mismatched_Memory_Management_Routines__delete_array_struct_realloc_81_goodB2G : public CWE762_Mismatched_Memory_Management_Routines__delete_array_struct_realloc_81_base
{
public:
    void action(twoIntsStruct * data) const;
};

#endif /* OMITGOOD */

}
