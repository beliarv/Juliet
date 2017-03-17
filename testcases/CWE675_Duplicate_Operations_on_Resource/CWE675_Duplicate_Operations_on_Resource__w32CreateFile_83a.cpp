/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE675_Duplicate_Operations_on_Resource__w32CreateFile_83a.cpp
Label Definition File: CWE675_Duplicate_Operations_on_Resource__w32CreateFile.label.xml
Template File: sources-sinks-83a.tmpl.cpp
*/
/*
 * @description
 * CWE: 675 Duplicate Operations on Resource
 * BadSource:  Open and close a file using CreateFile() and CloseHandle()
 * GoodSource: Open a file using CreateFile()
 * Sinks:
 *    GoodSink: Do nothing
 *    BadSink : Close the file
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */

#include "std_testcase.h"
#include "CWE675_Duplicate_Operations_on_Resource__w32CreateFile_83.h"

namespace CWE675_Duplicate_Operations_on_Resource__w32CreateFile_83
{

#ifndef OMITBAD

void bad()
{
    HANDLE data;
    data = INVALID_HANDLE_VALUE; /* Initialize data */
    CWE675_Duplicate_Operations_on_Resource__w32CreateFile_83_bad badObject(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    HANDLE data;
    data = INVALID_HANDLE_VALUE; /* Initialize data */
    CWE675_Duplicate_Operations_on_Resource__w32CreateFile_83_goodG2B goodG2BObject(data);
}

/* goodG2B uses the BadSource with the GoodSink */
static void goodB2G()
{
    HANDLE data;
    data = INVALID_HANDLE_VALUE; /* Initialize data */
    CWE675_Duplicate_Operations_on_Resource__w32CreateFile_83_goodB2G goodB2GObject(data);
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

using namespace CWE675_Duplicate_Operations_on_Resource__w32CreateFile_83; /* so that we can use good and bad easily */

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
