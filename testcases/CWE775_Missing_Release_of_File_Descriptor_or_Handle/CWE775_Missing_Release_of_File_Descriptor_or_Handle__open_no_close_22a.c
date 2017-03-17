/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_22a.c
Label Definition File: CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close.label.xml
Template File: source-sinks-22a.tmpl.c
*/
/*
 * @description
 * CWE: 775 Missing Release of File Descriptor or Handle After Effective Lifetime
 * BadSource:  Open a file using open()
 * Sinks:
 *    GoodSink: Close the file using close()
 *    BadSink : Do not close file
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
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

/* The global variable below is used to drive control flow in the sink function */
int CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_22_badGlobal = 0;

void CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_22_badSink(int data);

void CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_22_bad()
{
    int data;
    /* Initialize data */
    data = -1;
    /* POTENTIAL FLAW: Open a file without closing it */
    data = OPEN("BadSource_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE);
    CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_22_badGlobal = 1; /* true */
    CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_22_badSink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* The global variables below are used to drive control flow in the sink functions. */
int CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_22_goodB2G1Global = 0;
int CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_22_goodB2G2Global = 0;

/* goodB2G1() - use badsource and goodsink by setting the static variable to false instead of true */
void CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_22_goodB2G1Sink(int data);

static void goodB2G1()
{
    int data;
    /* Initialize data */
    data = -1;
    /* POTENTIAL FLAW: Open a file without closing it */
    data = OPEN("BadSource_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE);
    CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_22_goodB2G1Global = 0; /* false */
    CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_22_goodB2G1Sink(data);
}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the if in the sink function */
void CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_22_goodB2G2Sink(int data);

static void goodB2G2()
{
    int data;
    /* Initialize data */
    data = -1;
    /* POTENTIAL FLAW: Open a file without closing it */
    data = OPEN("BadSource_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE);
    CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_22_goodB2G2Global = 1; /* true */
    CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_22_goodB2G2Sink(data);
}

void CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_22_good()
{
    goodB2G1();
    goodB2G2();
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
    CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_22_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_22_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
