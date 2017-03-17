/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE377_Insecure_Temporary_File__char_w32GetTempFileName_18.c
Label Definition File: CWE377_Insecure_Temporary_File.label.xml
Template File: point-flaw-18.tmpl.c
*/
/*
 * @description
 * CWE: 377 Insecure Temporary File
 * Sinks: w32GetTempFileName
 *    GoodSink: Create and open a temporary file, created with GetTempFileNameA(), more securely
 *    BadSink : Create and open a temporary file, created with GetTempFileNameA(), insecurely
 * Flow Variant: 18 Control flow: goto statements
 *
 * */

#include "std_testcase.h"

#include <wchar.h>
#ifndef _WIN32
#include <unistd.h>
#endif

#include <windows.h>

#define OPEN _open
#define CLOSE _close
#define O_RDWR _O_RDWR
#define O_CREAT _O_CREAT
#define O_EXCL _O_EXCL
#define S_IREAD _S_IREAD
#define S_IWRITE _S_IWRITE

#ifndef OMITBAD

void CWE377_Insecure_Temporary_File__char_w32GetTempFileName_18_bad()
{
    goto sink;
sink:
    {
        char filename[MAX_PATH] = "";
        int fileDesc;
        /* FLAW: Passing 0 in for uUnique tells GetTempFileName to create and then close the file,
        * leading to an inescapable race condition when we try to open it again. */
        if (GetTempFileNameA(".", "bad", 0, filename) == 0)
        {
            exit(1);
        }
        printLine(filename);
        /* FLAW: Open a temporary file using open() and flags that do not prevent a race condition */
        fileDesc = OPEN(filename, O_RDWR|O_CREAT, S_IREAD|S_IWRITE);
        if (fileDesc != -1)
        {
            printLine("Temporary file was opened...now closing file");
            CLOSE(fileDesc);
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() reverses the blocks on the goto statement */
static void good1()
{
    goto sink;
sink:
    {
        char filename[MAX_PATH] = "";
        int fileDesc;
        /* FIX: Passing a non-zero value in for uUnique prevents GetTempFileName from creating
         * and then closing the file, at the cost of no longer guaranteeing the name is unique. */
        /* INCIDENTAL CWE338 Weak PRNG - use of rand() as a PRNG */
        if (GetTempFileNameA(".", "good", rand() + 1, filename) == 0)
        {
            exit(1);
        }
        printLine(filename);
        /* FIX: Open a temporary file using open() and the O_CREAT and O_EXCL flags
        * NOTE: This is not a perfect solution, but it is the base case scenario */
        fileDesc = OPEN(filename, O_RDWR|O_CREAT|O_EXCL, S_IREAD|S_IWRITE);
        if (fileDesc != -1)
        {
            printLine("Temporary file was opened...now closing file");
            CLOSE(fileDesc);
        }
    }
}

void CWE377_Insecure_Temporary_File__char_w32GetTempFileName_18_good()
{
    good1();
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
    CWE377_Insecure_Temporary_File__char_w32GetTempFileName_18_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE377_Insecure_Temporary_File__char_w32GetTempFileName_18_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
