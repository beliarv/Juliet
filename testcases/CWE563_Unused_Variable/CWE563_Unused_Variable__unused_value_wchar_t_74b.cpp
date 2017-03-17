/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE563_Unused_Variable__unused_value_wchar_t_74b.cpp
Label Definition File: CWE563_Unused_Variable__unused_value.label.xml
Template File: sources-sinks-74b.tmpl.cpp
*/
/*
 * @description
 * CWE: 563 Unused Variable
 * BadSource:  Initialize data
 * GoodSource: Initialize and use data
 * Sinks:
 *    GoodSink: Use data
 *    BadSink : Initialize and use data
 * Flow Variant: 74 Data flow: data passed in a map from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <map>

#include <wchar.h>

using namespace std;

namespace CWE563_Unused_Variable__unused_value_wchar_t_74
{

#ifndef OMITBAD

void badSink(map<int, wchar_t> dataMap)
{
    /* copy data out of dataMap */
    wchar_t data = dataMap[2];
    /* POTENTIAL FLAW: Possibly over-write the initial value of data before using it */
    data = L'Z';
    printf("%02lx\n", data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSink(map<int, wchar_t> dataMap)
{
    wchar_t data = dataMap[2];
    /* POTENTIAL FLAW: Possibly over-write the initial value of data before using it */
    data = L'Z';
    printf("%02lx\n", data);
}

/* goodB2G uses the BadSource with the GoodSink */
void goodB2GSink(map<int, wchar_t> dataMap)
{
    wchar_t data = dataMap[2];
    /* FIX: Use data without over-writing its value */
    printf("%02lx\n", data);
}

#endif /* OMITGOOD */

} /* close namespace */
