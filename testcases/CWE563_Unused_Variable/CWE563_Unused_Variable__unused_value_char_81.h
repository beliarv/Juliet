/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE563_Unused_Variable__unused_value_char_81.h
Label Definition File: CWE563_Unused_Variable__unused_value.label.xml
Template File: sources-sinks-81.tmpl.h
*/
/*
 * @description
 * CWE: 563 Unused Variable
 * BadSource:  Initialize data
 * GoodSource: Initialize and use data
 * Sinks:
 *    GoodSink: Use data
 *    BadSink : Initialize and use data
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE563_Unused_Variable__unused_value_char_81
{

class CWE563_Unused_Variable__unused_value_char_81_base
{
public:
    /* pure virtual function */
    virtual void action(char data) const = 0;
};

#ifndef OMITBAD

class CWE563_Unused_Variable__unused_value_char_81_bad : public CWE563_Unused_Variable__unused_value_char_81_base
{
public:
    void action(char data) const;
};

#endif /* OMITBAD */

#ifndef OMITGOOD

class CWE563_Unused_Variable__unused_value_char_81_goodG2B : public CWE563_Unused_Variable__unused_value_char_81_base
{
public:
    void action(char data) const;
};

class CWE563_Unused_Variable__unused_value_char_81_goodB2G : public CWE563_Unused_Variable__unused_value_char_81_base
{
public:
    void action(char data) const;
};

#endif /* OMITGOOD */

}
