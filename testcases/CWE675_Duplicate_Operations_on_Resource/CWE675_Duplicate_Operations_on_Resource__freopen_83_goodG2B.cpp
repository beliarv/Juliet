/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE675_Duplicate_Operations_on_Resource__freopen_83_goodG2B.cpp
Label Definition File: CWE675_Duplicate_Operations_on_Resource.label.xml
Template File: sources-sinks-83_goodG2B.tmpl.cpp
*/
/*
 * @description
 * CWE: 675 Duplicate Operations on Resource
 * BadSource: freopen Open and close a file using freopen() and flose()
 * GoodSource: Open a file using fopen()
 * Sinks:
 *    GoodSink: Do nothing
 *    BadSink : Close the file
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */
#ifndef OMITGOOD

#include "std_testcase.h"
#include "CWE675_Duplicate_Operations_on_Resource__freopen_83.h"

namespace CWE675_Duplicate_Operations_on_Resource__freopen_83
{
CWE675_Duplicate_Operations_on_Resource__freopen_83_goodG2B::CWE675_Duplicate_Operations_on_Resource__freopen_83_goodG2B(FILE * dataCopy)
{
    data = dataCopy;
    /* FIX: Open, but do not close the file in the source */
    data = fopen("GoodSource_fopen.txt", "w+");
}

CWE675_Duplicate_Operations_on_Resource__freopen_83_goodG2B::~CWE675_Duplicate_Operations_on_Resource__freopen_83_goodG2B()
{
    /* POTENTIAL FLAW: Close the file in the sink (it may have been closed in the Source) */
    fclose(data);
}
}
#endif /* OMITGOOD */
