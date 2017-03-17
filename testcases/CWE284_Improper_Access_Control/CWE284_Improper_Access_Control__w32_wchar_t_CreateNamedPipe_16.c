/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE284_Improper_Access_Control__w32_wchar_t_CreateNamedPipe_16.c
Label Definition File: CWE284_Improper_Access_Control__w32.label.xml
Template File: point-flaw-16.tmpl.c
*/
/*
 * @description
 * CWE: 284 Improper Access Control
 * Sinks: CreateNamedPipe
 *    GoodSink: Create a windows pipe using CreateNamedPipeW() ensuring that the pipe won't be created over an existing one
 *    BadSink : Create a windows pipe using CreateNamedPipeW() potentially allowing the pipe to be created over an existing one
 * Flow Variant: 16 Control flow: while(1)
 *
 * */

#include "std_testcase.h"

#include <windows.h>
#pragma comment( lib, "user32" )
#define BUFSIZE 1024
#define PIPE_NAME L"\\\\.\\pipe\\TestPipe"

#ifndef OMITBAD

void CWE284_Improper_Access_Control__w32_wchar_t_CreateNamedPipe_16_bad()
{
    while(1)
    {
        {
            HANDLE hPipe;
            wchar_t * pipeName = PIPE_NAME;
            /* FLAW: Call CreateNamedPipeW() with only PIPE_ACCESS_DUPLEX as the 2nd parameter
             * potentially allowing the pipe to be created over an existing file. */
            hPipe = CreateNamedPipeW(
                        pipeName,
                        PIPE_ACCESS_DUPLEX,
                        PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE | PIPE_WAIT,
                        PIPE_UNLIMITED_INSTANCES,
                        BUFSIZE,
                        BUFSIZE,
                        0,
                        NULL);
            if (hPipe == INVALID_HANDLE_VALUE)
            {
                printLine("Windows pipe creation failed");
            }
            else
            {
                printLine("Windows pipe created successfully");
                CloseHandle(hPipe);
            }
        }
        break;
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() uses the GoodSinkBody in the while loop */
static void good1()
{
    while(1)
    {
        {
            HANDLE hPipe;
            wchar_t * pipeName = PIPE_NAME;
            /* FIX: Call CreateNamedPipeW() with PIPE_ACCESS_DUPLEX and FILE_FLAG_FIRST_PIPE_INSTANCE as the 2nd parameter */
            hPipe = CreateNamedPipeW(
                        pipeName,
                        FILE_FLAG_FIRST_PIPE_INSTANCE | PIPE_ACCESS_DUPLEX,
                        PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE | PIPE_WAIT,
                        PIPE_UNLIMITED_INSTANCES,
                        BUFSIZE,
                        BUFSIZE,
                        0,
                        NULL);
            if (hPipe == INVALID_HANDLE_VALUE)
            {
                printLine("Windows pipe creation failed");
            }
            else
            {
                printLine("Windows pipe created successfully");
                CloseHandle(hPipe);
            }
        }
        break;
    }
}

void CWE284_Improper_Access_Control__w32_wchar_t_CreateNamedPipe_16_good()
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
    CWE284_Improper_Access_Control__w32_wchar_t_CreateNamedPipe_16_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE284_Improper_Access_Control__w32_wchar_t_CreateNamedPipe_16_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
