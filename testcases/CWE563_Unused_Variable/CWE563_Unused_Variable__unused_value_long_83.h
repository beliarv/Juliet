/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE563_Unused_Variable__unused_value_long_83.h
Label Definition File: CWE563_Unused_Variable__unused_value.label.xml
Template File: sources-sinks-83.tmpl.h
*/
/*
 * @description
 * CWE: 563 Unused Variable
 * BadSource:  Initialize data
 * GoodSource: Initialize and use data
 * Sinks:
 *    GoodSink: Use data
 *    BadSink : Initialize and use data
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE563_Unused_Variable__unused_value_long_83
{

#ifndef OMITBAD

class CWE563_Unused_Variable__unused_value_long_83_bad
{
public:
    CWE563_Unused_Variable__unused_value_long_83_bad(long dataCopy);
    ~CWE563_Unused_Variable__unused_value_long_83_bad();

private:
    long data;
};

#endif /* OMITBAD */

#ifndef OMITGOOD

class CWE563_Unused_Variable__unused_value_long_83_goodG2B
{
public:
    CWE563_Unused_Variable__unused_value_long_83_goodG2B(long dataCopy);
    ~CWE563_Unused_Variable__unused_value_long_83_goodG2B();

private:
    long data;
};

class CWE563_Unused_Variable__unused_value_long_83_goodB2G
{
public:
    CWE563_Unused_Variable__unused_value_long_83_goodB2G(long dataCopy);
    ~CWE563_Unused_Variable__unused_value_long_83_goodB2G();

private:
    long data;
};

#endif /* OMITGOOD */

}
