/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__delete_char_malloc_82.h
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__delete.label.xml
Template File: sources-sinks-82.tmpl.h
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

#include "std_testcase.h"

namespace CWE762_Mismatched_Memory_Management_Routines__delete_char_malloc_82
{

class CWE762_Mismatched_Memory_Management_Routines__delete_char_malloc_82_base
{
public:
    /* pure virtual function */
    virtual void action(char * data) = 0;
};

#ifndef OMITBAD

class CWE762_Mismatched_Memory_Management_Routines__delete_char_malloc_82_bad : public CWE762_Mismatched_Memory_Management_Routines__delete_char_malloc_82_base
{
public:
    void action(char * data);
};

#endif /* OMITBAD */

#ifndef OMITGOOD

class CWE762_Mismatched_Memory_Management_Routines__delete_char_malloc_82_goodG2B : public CWE762_Mismatched_Memory_Management_Routines__delete_char_malloc_82_base
{
public:
    void action(char * data);
};

class CWE762_Mismatched_Memory_Management_Routines__delete_char_malloc_82_goodB2G : public CWE762_Mismatched_Memory_Management_Routines__delete_char_malloc_82_base
{
public:
    void action(char * data);
};

#endif /* OMITGOOD */

}
