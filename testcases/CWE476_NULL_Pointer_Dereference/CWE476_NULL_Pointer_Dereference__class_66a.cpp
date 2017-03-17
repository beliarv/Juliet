/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE476_NULL_Pointer_Dereference__class_66a.cpp
Label Definition File: CWE476_NULL_Pointer_Dereference__class.label.xml
Template File: sources-sinks-66a.tmpl.cpp
*/
/*
 * @description
 * CWE: 476 NULL Pointer Dereference
 * BadSource:  Set data to NULL
 * GoodSource: Initialize data
 * Sinks:
 *    GoodSink: Check data for NULL before attempting to print data->a
 *    BadSink : Print data->a
 * Flow Variant: 66 Data flow: data passed in an array from one function to another in different source files
 *
 * */

#include "std_testcase.h"

namespace CWE476_NULL_Pointer_Dereference__class_66
{

#ifndef OMITBAD

/* bad function declaration */
void badSink(TwoIntsClass * dataArray[]);

void bad()
{
    TwoIntsClass * data;
    TwoIntsClass * dataArray[5];
    /* POTENTIAL FLAW: Set data to NULL */
    data = NULL;
    /* put data in array */
    dataArray[2] = data;
    badSink(dataArray);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSink(TwoIntsClass * dataArray[]);

static void goodG2B()
{
    TwoIntsClass * data;
    TwoIntsClass * dataArray[5];
    {
        TwoIntsClass * tmpData = new TwoIntsClass;
        tmpData->intOne = 0;
        tmpData->intOne = 0;
        /* FIX: Initialize data */
        data = tmpData;
    }
    dataArray[2] = data;
    goodG2BSink(dataArray);
}

/* goodB2G uses the BadSource with the GoodSink */
void goodB2GSink(TwoIntsClass * dataArray[]);

static void goodB2G()
{
    TwoIntsClass * data;
    TwoIntsClass * dataArray[5];
    /* POTENTIAL FLAW: Set data to NULL */
    data = NULL;
    dataArray[2] = data;
    goodB2GSink(dataArray);
}

void good()
{
    goodG2B();
    goodB2G();
}

#endif /* OMITGOOD */

} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE476_NULL_Pointer_Dereference__class_66; /* so that we can use good and bad easily */

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
