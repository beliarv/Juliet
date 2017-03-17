/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE563_Unused_Variable__unused_uninit_variable_int64_t_74b.cpp
Label Definition File: CWE563_Unused_Variable__unused_uninit_variable.label.xml
Template File: source-sinks-74b.tmpl.cpp
*/
/*
 * @description
 * CWE: 563 Unused Variable
 * BadSource:  Initialize data
 * Sinks:
 *    GoodSink: Initialize, then use data
 *    BadSink : Do nothing
 * Flow Variant: 74 Data flow: data passed in a map from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <map>

#include <wchar.h>

using namespace std;

namespace CWE563_Unused_Variable__unused_uninit_variable_int64_t_74
{

#ifndef OMITBAD

void badSink(map<int, int64_t> dataMap)
{
    /* copy data out of dataMap */
    int64_t data = dataMap[2];
    /* FLAW: Do not use the variable */
    /* do nothing */
    ; /* empty statement needed for some flow variants */
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G uses the BadSource with the GoodSink */
void goodB2GSink(map<int, int64_t> dataMap)
{
    int64_t data = dataMap[2];
    /* FIX: Initialize then use data */
    data = 5LL;
    printLongLongLine(data);
}

#endif /* OMITGOOD */

} /* close namespace */
