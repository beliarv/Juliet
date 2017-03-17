/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE457_Use_of_Uninitialized_Variable__twointsclass_43.cpp
Label Definition File: CWE457_Use_of_Uninitialized_Variable__twointsclass.label.xml
Template File: sources-sinks-43.tmpl.cpp
*/
/*
 * @description
 * CWE: 457 Use of Uninitialized Variable
 * BadSource:  Don't initialize data
 * GoodSource: Initialize data
 * Sinks:
 *    GoodSink: Initialize then use data
 *    BadSink : Use data
 * Flow Variant: 43 Data flow: data flows using a C++ reference from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

namespace CWE457_Use_of_Uninitialized_Variable__twointsclass_43
{

#ifndef OMITBAD

void badSource(TwoIntsClass &data)
{
    /* POTENTIAL FLAW: Don't initialize data */
    ; /* empty statement needed for some flow variants */
}

void bad()
{
    TwoIntsClass data;
    badSource(data);
    /* POTENTIAL FLAW: Use data without initializing it */
    printIntLine(data.intOne);
    printIntLine(data.intTwo);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2BSource(TwoIntsClass &data)
{
    /* FIX: Initialize data */
    data.intOne = 1;
    data.intTwo = 2;
}

static void goodG2B()
{
    TwoIntsClass data;
    goodG2BSource(data);
    /* POTENTIAL FLAW: Use data without initializing it */
    printIntLine(data.intOne);
    printIntLine(data.intTwo);
}

/* goodB2G() uses the BadSource with the GoodSink */
static void goodB2GSource(TwoIntsClass &data)
{
    /* POTENTIAL FLAW: Don't initialize data */
    ; /* empty statement needed for some flow variants */
}

static void goodB2G()
{
    TwoIntsClass data;
    goodB2GSource(data);
    /* FIX: Ensure data is initialized before use */
    data.intOne = 1;
    data.intTwo = 2;
    printIntLine(data.intOne);
    printIntLine(data.intTwo);
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

using namespace CWE457_Use_of_Uninitialized_Variable__twointsclass_43; /* so that we can use good and bad easily */

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
