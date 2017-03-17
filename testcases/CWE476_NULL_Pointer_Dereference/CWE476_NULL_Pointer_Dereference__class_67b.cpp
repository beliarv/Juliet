/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE476_NULL_Pointer_Dereference__class_67b.cpp
Label Definition File: CWE476_NULL_Pointer_Dereference__class.label.xml
Template File: sources-sinks-67b.tmpl.cpp
*/
/*
 * @description
 * CWE: 476 NULL Pointer Dereference
 * BadSource:  Set data to NULL
 * GoodSource: Initialize data
 * Sinks:
 *    GoodSink: Check data for NULL before attempting to print data->a
 *    BadSink : Print data->a
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

namespace CWE476_NULL_Pointer_Dereference__class_67
{

typedef struct _structType
{
    TwoIntsClass * structFirst;
} structType;

#ifndef OMITBAD

void badSink(structType myStruct)
{
    TwoIntsClass * data = myStruct.structFirst;
    /* POTENTIAL FLAW: Attempt to use data, which may be NULL */
    printIntLine(data->intOne);
    /* avoid memory leak - deleting a NULL pointer is a no-op in C++ so no need to check for NULL */
    delete data;
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSink(structType myStruct)
{
    TwoIntsClass * data = myStruct.structFirst;
    /* POTENTIAL FLAW: Attempt to use data, which may be NULL */
    printIntLine(data->intOne);
    /* avoid memory leak - deleting a NULL pointer is a no-op in C++ so no need to check for NULL */
    delete data;
}

/* goodB2G uses the BadSource with the GoodSink */
void goodB2GSink(structType myStruct)
{
    TwoIntsClass * data = myStruct.structFirst;
    /* FIX: Check for NULL before attempting to print data */
    if (data != NULL)
    {
        printIntLine(data->intOne);
        delete data;
    }
    else
    {
        printLine("data is NULL");
    }
}

#endif /* OMITGOOD */

} /* close namespace */
