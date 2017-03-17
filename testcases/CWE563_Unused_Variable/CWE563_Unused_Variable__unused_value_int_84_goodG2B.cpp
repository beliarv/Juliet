/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE563_Unused_Variable__unused_value_int_84_goodG2B.cpp
Label Definition File: CWE563_Unused_Variable__unused_value.label.xml
Template File: sources-sinks-84_goodG2B.tmpl.cpp
*/
/*
 * @description
 * CWE: 563 Unused Variable
 * BadSource:  Initialize data
 * GoodSource: Initialize and use data
 * Sinks:
 *    GoodSink: Use data
 *    BadSink : Initialize and use data
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */
#ifndef OMITGOOD

#include "std_testcase.h"
#include "CWE563_Unused_Variable__unused_value_int_84.h"

namespace CWE563_Unused_Variable__unused_value_int_84
{
CWE563_Unused_Variable__unused_value_int_84_goodG2B::CWE563_Unused_Variable__unused_value_int_84_goodG2B(int dataCopy)
{
    data = dataCopy;
    /* FIX: Initialize and use data before it is overwritten */
    data = 5;
    printIntLine(data);
}

CWE563_Unused_Variable__unused_value_int_84_goodG2B::~CWE563_Unused_Variable__unused_value_int_84_goodG2B()
{
    /* POTENTIAL FLAW: Possibly over-write the initial value of data before using it */
    data = 10;
    printIntLine(data);
}
}
#endif /* OMITGOOD */
