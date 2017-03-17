/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_68b.c
Label Definition File: CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close.label.xml
Template File: source-sinks-68b.tmpl.c
*/
/*
 * @description
 * CWE: 775 Missing Release of File Descriptor or Handle After Effective Lifetime
 * BadSource:  Open a file using open()
 * Sinks:
 *    GoodSink: Close the file using close()
 *    BadSink : Do not close file
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
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

extern int CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_68_badDataForBadSink;

extern int CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_68_badDataForGoodSink;

#ifndef OMITBAD

void CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_68b_badSink()
{
    int data = CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_68_badDataForBadSink;
    /* FLAW: No attempt to close the file */
    ; /* empty statement needed for some flow variants */
}

#endif /* OMITBAD */

#ifndef OMITGOOD

void CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_68b_goodB2GSink()
{
    int data = CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_68_badDataForGoodSink;
    /* FIX: If the file is still opened, close it */
    if (data != -1)
    {
        CLOSE(data);
    }
}

#endif /* OMITGOOD */
