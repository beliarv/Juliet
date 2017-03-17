/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE563_Unused_Variable__unused_init_variable_int_82.h
Label Definition File: CWE563_Unused_Variable__unused_init_variable.label.xml
Template File: source-sinks-82.tmpl.h
*/
/*
 * @description
 * CWE: 563 Unused Variable
 * BadSource:  Initialize data
 * Sinks:
 *    GoodSink: Use data
 *    BadSink : do nothing
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE563_Unused_Variable__unused_init_variable_int_82
{

class CWE563_Unused_Variable__unused_init_variable_int_82_base
{
public:
    /* pure virtual function */
    virtual void action(int data) = 0;
};

#ifndef OMITBAD

class CWE563_Unused_Variable__unused_init_variable_int_82_bad : public CWE563_Unused_Variable__unused_init_variable_int_82_base
{
public:
    void action(int data);
};

#endif /* OMITBAD */

#ifndef OMITGOOD

class CWE563_Unused_Variable__unused_init_variable_int_82_goodB2G : public CWE563_Unused_Variable__unused_init_variable_int_82_base
{
public:
    void action(int data);
};

#endif /* OMITGOOD */

}
