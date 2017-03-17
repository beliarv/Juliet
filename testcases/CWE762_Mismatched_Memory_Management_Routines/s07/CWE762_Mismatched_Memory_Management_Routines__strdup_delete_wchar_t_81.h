/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__strdup_delete_wchar_t_81.h
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__strdup_delete.label.xml
Template File: sources-sinks-81.tmpl.h
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * BadSource:  Allocate data using wcsdup()
 * GoodSource: Allocate data using new
 * Sinks:
 *    GoodSink: Deallocate data using free()
 *    BadSink : Deallocate data using delete
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE762_Mismatched_Memory_Management_Routines__strdup_delete_wchar_t_81
{

class CWE762_Mismatched_Memory_Management_Routines__strdup_delete_wchar_t_81_base
{
public:
    /* pure virtual function */
    virtual void action(wchar_t * data) const = 0;
};

#ifndef OMITBAD

class CWE762_Mismatched_Memory_Management_Routines__strdup_delete_wchar_t_81_bad : public CWE762_Mismatched_Memory_Management_Routines__strdup_delete_wchar_t_81_base
{
public:
    void action(wchar_t * data) const;
};

#endif /* OMITBAD */

#ifndef OMITGOOD

class CWE762_Mismatched_Memory_Management_Routines__strdup_delete_wchar_t_81_goodG2B : public CWE762_Mismatched_Memory_Management_Routines__strdup_delete_wchar_t_81_base
{
public:
    void action(wchar_t * data) const;
};

class CWE762_Mismatched_Memory_Management_Routines__strdup_delete_wchar_t_81_goodB2G : public CWE762_Mismatched_Memory_Management_Routines__strdup_delete_wchar_t_81_base
{
public:
    void action(wchar_t * data) const;
};

#endif /* OMITGOOD */

}
