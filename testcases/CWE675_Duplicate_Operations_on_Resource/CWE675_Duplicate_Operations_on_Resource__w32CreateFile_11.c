/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE675_Duplicate_Operations_on_Resource__w32CreateFile_11.c
Label Definition File: CWE675_Duplicate_Operations_on_Resource__w32CreateFile.label.xml
Template File: sources-sinks-11.tmpl.c
*/
/*
 * @description
 * CWE: 675 Duplicate Operations on Resource
 * BadSource:  Open and close a file using CreateFile() and CloseHandle()
 * GoodSource: Open a file using CreateFile()
 * Sinks:
 *    GoodSink: Do nothing
 *    BadSink : Close the file
 * Flow Variant: 11 Control flow: if(globalReturnsTrue()) and if(globalReturnsFalse())
 *
 * */

#include "std_testcase.h"

#include <windows.h>

#ifndef OMITBAD

void CWE675_Duplicate_Operations_on_Resource__w32CreateFile_11_bad()
{
    HANDLE data;
    data = INVALID_HANDLE_VALUE; /* Initialize data */
    if(globalReturnsTrue())
    {
        data = CreateFile("BadSource_w32CreateFile.txt",
                          (GENERIC_WRITE|GENERIC_READ),
                          0,
                          NULL,
                          OPEN_ALWAYS,
                          FILE_ATTRIBUTE_NORMAL,
                          NULL);
        /* POTENTIAL FLAW: Close the file in the source */
        CloseHandle(data);
    }
    if(globalReturnsTrue())
    {
        /* POTENTIAL FLAW: Close the file in the sink (it may have been closed in the Source) */
        CloseHandle(data);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G1() - use badsource and goodsink by changing the second globalReturnsTrue() to globalReturnsFalse() */
static void goodB2G1()
{
    HANDLE data;
    data = INVALID_HANDLE_VALUE; /* Initialize data */
    if(globalReturnsTrue())
    {
        data = CreateFile("BadSource_w32CreateFile.txt",
                          (GENERIC_WRITE|GENERIC_READ),
                          0,
                          NULL,
                          OPEN_ALWAYS,
                          FILE_ATTRIBUTE_NORMAL,
                          NULL);
        /* POTENTIAL FLAW: Close the file in the source */
        CloseHandle(data);
    }
    if(globalReturnsFalse())
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* Do nothing */
        /* FIX: Don't close the file in the sink */
        ; /* empty statement needed for some flow variants */
    }
}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the second if */
static void goodB2G2()
{
    HANDLE data;
    data = INVALID_HANDLE_VALUE; /* Initialize data */
    if(globalReturnsTrue())
    {
        data = CreateFile("BadSource_w32CreateFile.txt",
                          (GENERIC_WRITE|GENERIC_READ),
                          0,
                          NULL,
                          OPEN_ALWAYS,
                          FILE_ATTRIBUTE_NORMAL,
                          NULL);
        /* POTENTIAL FLAW: Close the file in the source */
        CloseHandle(data);
    }
    if(globalReturnsTrue())
    {
        /* Do nothing */
        /* FIX: Don't close the file in the sink */
        ; /* empty statement needed for some flow variants */
    }
}

/* goodG2B1() - use goodsource and badsink by changing the first globalReturnsTrue() to globalReturnsFalse() */
static void goodG2B1()
{
    HANDLE data;
    data = INVALID_HANDLE_VALUE; /* Initialize data */
    if(globalReturnsFalse())
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* FIX: Open, but do not close the file in the source */
        data = CreateFile("GoodSource_w32CreateFile.txt",
                          (GENERIC_WRITE|GENERIC_READ),
                          0,
                          NULL,
                          OPEN_ALWAYS,
                          FILE_ATTRIBUTE_NORMAL,
                          NULL);
    }
    if(globalReturnsTrue())
    {
        /* POTENTIAL FLAW: Close the file in the sink (it may have been closed in the Source) */
        CloseHandle(data);
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the first if */
static void goodG2B2()
{
    HANDLE data;
    data = INVALID_HANDLE_VALUE; /* Initialize data */
    if(globalReturnsTrue())
    {
        /* FIX: Open, but do not close the file in the source */
        data = CreateFile("GoodSource_w32CreateFile.txt",
                          (GENERIC_WRITE|GENERIC_READ),
                          0,
                          NULL,
                          OPEN_ALWAYS,
                          FILE_ATTRIBUTE_NORMAL,
                          NULL);
    }
    if(globalReturnsTrue())
    {
        /* POTENTIAL FLAW: Close the file in the sink (it may have been closed in the Source) */
        CloseHandle(data);
    }
}

void CWE675_Duplicate_Operations_on_Resource__w32CreateFile_11_good()
{
    goodB2G1();
    goodB2G2();
    goodG2B1();
    goodG2B2();
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
    CWE675_Duplicate_Operations_on_Resource__w32CreateFile_11_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE675_Duplicate_Operations_on_Resource__w32CreateFile_11_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
