/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE476_NULL_Pointer_Dereference__struct_72b.cpp
Label Definition File: CWE476_NULL_Pointer_Dereference.label.xml
Template File: sources-sinks-72b.tmpl.cpp
*/
/*
 * @description
 * CWE: 476 NULL Pointer Dereference
 * BadSource:  Set data to NULL
 * GoodSource: Initialize data
 * Sinks:
 *    GoodSink: Check for NULL before attempting to print data
 *    BadSink : Print data
 * Flow Variant: 72 Data flow: data passed in a vector from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <vector>

#include <wchar.h>

using namespace std;

namespace CWE476_NULL_Pointer_Dereference__struct_72
{

#ifndef OMITBAD

void badSink(vector<twoIntsStruct *> dataVector)
{
    /* copy data out of dataVector */
    twoIntsStruct * data = dataVector[2];
    /* POTENTIAL FLAW: Attempt to use data, which may be NULL */
    printIntLine(data->intOne);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSink(vector<twoIntsStruct *> dataVector)
{
    twoIntsStruct * data = dataVector[2];
    /* POTENTIAL FLAW: Attempt to use data, which may be NULL */
    printIntLine(data->intOne);
}

/* goodB2G uses the BadSource with the GoodSink */
void goodB2GSink(vector<twoIntsStruct *> dataVector)
{
    twoIntsStruct * data = dataVector[2];
    /* FIX: Check for NULL before attempting to print data */
    if (data != NULL)
    {
        printIntLine(data->intOne);
    }
    else
    {
        printLine("data is NULL");
    }
}

#endif /* OMITGOOD */

} /* close namespace */
