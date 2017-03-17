/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__malloc_free_int_81.h
Label Definition File: CWE415_Double_Free__malloc_free.label.xml
Template File: sources-sinks-81.tmpl.h
*/
/*
 * @description
 * CWE: 415 Double Free
 * BadSource:  Allocate data using malloc() and Deallocate data using free()
 * GoodSource: Allocate data using malloc()
 * Sinks:
 *    GoodSink: do nothing
 *    BadSink : Deallocate data using free()
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE415_Double_Free__malloc_free_int_81
{

class CWE415_Double_Free__malloc_free_int_81_base
{
public:
    /* pure virtual function */
    virtual void action(int * data) const = 0;
};

#ifndef OMITBAD

class CWE415_Double_Free__malloc_free_int_81_bad : public CWE415_Double_Free__malloc_free_int_81_base
{
public:
    void action(int * data) const;
};

#endif /* OMITBAD */

#ifndef OMITGOOD

class CWE415_Double_Free__malloc_free_int_81_goodG2B : public CWE415_Double_Free__malloc_free_int_81_base
{
public:
    void action(int * data) const;
};

class CWE415_Double_Free__malloc_free_int_81_goodB2G : public CWE415_Double_Free__malloc_free_int_81_base
{
public:
    void action(int * data) const;
};

#endif /* OMITGOOD */

}
