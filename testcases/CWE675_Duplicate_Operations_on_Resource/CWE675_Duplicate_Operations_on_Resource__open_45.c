/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE675_Duplicate_Operations_on_Resource__open_45.c
Label Definition File: CWE675_Duplicate_Operations_on_Resource__open.label.xml
Template File: sources-sinks-45.tmpl.c
*/
/*
 * @description
 * CWE: 675 Duplicate Operations on Resource
 * BadSource:  Open and close a file using open() and close()
 * GoodSource: Open a file using open()
 * Sinks:
 *    GoodSink: Do nothing
 *    BadSink : Close the file
 * Flow Variant: 45 Data flow: data passed as a static global variable from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
# define OPEN _open
# define CLOSE _close
#else
#include <unistd.h>
# define OPEN open
# define CLOSE close
#endif

static int CWE675_Duplicate_Operations_on_Resource__open_45_badData;
static int CWE675_Duplicate_Operations_on_Resource__open_45_goodG2BData;
static int CWE675_Duplicate_Operations_on_Resource__open_45_goodB2GData;

#ifndef OMITBAD

static void badSink()
{
    int data = CWE675_Duplicate_Operations_on_Resource__open_45_badData;
    /* POTENTIAL FLAW: Close the file in the sink (it may have been closed in the Source) */
    CLOSE(data);
}

void CWE675_Duplicate_Operations_on_Resource__open_45_bad()
{
    int data;
    data = -1; /* Initialize data */
    data = OPEN("BadSource_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE);
    /* POTENTIAL FLAW: Close the file in the source */
    CLOSE(data);
    CWE675_Duplicate_Operations_on_Resource__open_45_badData = data;
    badSink();
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2BSink()
{
    int data = CWE675_Duplicate_Operations_on_Resource__open_45_goodG2BData;
    /* POTENTIAL FLAW: Close the file in the sink (it may have been closed in the Source) */
    CLOSE(data);
}

static void goodG2B()
{
    int data;
    data = -1; /* Initialize data */
    /* FIX: Open, but do not close the file in the source */
    data = OPEN("GoodSource_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE);
    CWE675_Duplicate_Operations_on_Resource__open_45_goodG2BData = data;
    goodG2BSink();
}

/* goodB2G() uses the BadSource with the GoodSink */
static void goodB2GSink()
{
    int data = CWE675_Duplicate_Operations_on_Resource__open_45_goodB2GData;
    /* Do nothing */
    /* FIX: Don't close the file in the sink */
    ; /* empty statement needed for some flow variants */
}

static void goodB2G()
{
    int data;
    data = -1; /* Initialize data */
    data = OPEN("BadSource_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE);
    /* POTENTIAL FLAW: Close the file in the source */
    CLOSE(data);
    CWE675_Duplicate_Operations_on_Resource__open_45_goodB2GData = data;
    goodB2GSink();
}

void CWE675_Duplicate_Operations_on_Resource__open_45_good()
{
    goodG2B();
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
    CWE675_Duplicate_Operations_on_Resource__open_45_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE675_Duplicate_Operations_on_Resource__open_45_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
