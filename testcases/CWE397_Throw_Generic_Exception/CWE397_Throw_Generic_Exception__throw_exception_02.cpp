/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE397_Throw_Generic_Exception__throw_exception_02.cpp
Label Definition File: CWE397_Throw_Generic_Exception__throw_exception.label.xml
Template File: point-flaw-02.tmpl.cpp
*/
/*
 * @description
 * CWE: 397 Declaration of Throws for Generic Exception.  In this functional variant, we actually throw a generic exception.
 * Sinks: throw_exception
 *    GoodSink: Throw a specific exception (range_error)
 *    BadSink : Throw std::exception class, which is very generic
 * Flow Variant: 02 Control flow: if(1) and if(0)
 *
 * */

#include "std_testcase.h"

#include <string>
#include <iostream>
#include <stdexcept>

using namespace std; /* To use exception and range_error easily */

namespace CWE397_Throw_Generic_Exception__throw_exception_02
{

#ifndef OMITBAD

void bad()
{
    if(1)
    {
        /* FLAW: throw std::exception class, which is very generic */
        throw exception();
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() uses if(0) instead of if(1) */
static void good1()
{
    if(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* FIX: Throw a specific exception */
        throw range_error("Test");
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(1)
    {
        /* FIX: Throw a specific exception */
        throw range_error("Test");
    }
}

void good()
{
    good1();
    good2();
}

#endif /* OMITGOOD */

} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE397_Throw_Generic_Exception__throw_exception_02; /* so that we can use good and bad easily */

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
