/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__open_fclose_41.c
Label Definition File: CWE404_Improper_Resource_Shutdown__open.label.xml
Template File: source-sinks-41.tmpl.c
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * BadSource:  Open a file using open()
 * Sinks: fclose
 *    GoodSink: Close the file using close()
 *    BadSink : Close the file using fclose()
 * Flow Variant: 41 Data flow: data passed as an argument from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
#define OPEN _open
#define CLOSE _close
#else
#include <unistd.h>
#define OPEN open
#define CLOSE close
#endif

#ifndef OMITBAD

static void badSink(int data)
{
    if (data != -1)
    {
        /* FLAW: Attempt to close the file using fclose() instead of close() */
        fclose((FILE *)data);
    }
}

void CWE404_Improper_Resource_Shutdown__open_fclose_41_bad()
{
    int data;
    /* Initialize data */
    data = -1;
    /* POTENTIAL FLAW: Open a file - need to make sure it is closed properly in the sink */
    data = OPEN("BadSource_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE);
    badSink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

static void goodB2GSink(int data)
{
    if (data != -1)
    {
        /* FIX: Close the file using close() */
        CLOSE(data);
    }
}

/* goodB2G uses the BadSource with the GoodSink */
static void goodB2G()
{
    int data;
    /* Initialize data */
    data = -1;
    /* POTENTIAL FLAW: Open a file - need to make sure it is closed properly in the sink */
    data = OPEN("BadSource_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE);
    goodB2GSink(data);
}

void CWE404_Improper_Resource_Shutdown__open_fclose_41_good()
{
    goodB2G();
}

#endif /* OMITGOOD */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE404_Improper_Resource_Shutdown__open_fclose_41_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE404_Improper_Resource_Shutdown__open_fclose_41_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
