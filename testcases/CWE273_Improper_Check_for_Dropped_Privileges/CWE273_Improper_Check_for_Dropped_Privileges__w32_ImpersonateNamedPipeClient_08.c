/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE273_Improper_Check_for_Dropped_Privileges__w32_ImpersonateNamedPipeClient_08.c
Label Definition File: CWE273_Improper_Check_for_Dropped_Privileges__w32.label.xml
Template File: point-flaw-08.tmpl.c
*/
/*
 * @description
 * CWE: 273 Improper Check for Dropped Privileges
 * Sinks: ImpersonateNamedPipeClient
 *    GoodSink: Check if ImpersonateNamedPipeClient() succeeded or not
 *    BadSink : Failed to check return status of ImpersonateNamedPipeClient()
 * Flow Variant: 08 Control flow: if(staticReturnsTrue()) and if(staticReturnsFalse())
 *
 * */

#include "std_testcase.h"

#include <windows.h>

#pragma comment(lib, "advapi32.lib")
#define BUFSIZE 1024

/* The two function below always return the same value, so a tool
   should be able to identify that calls to the functions will always
   return a fixed value. */
static int staticReturnsTrue()
{
    return 1;
}

static int staticReturnsFalse()
{
    return 0;
}

#ifndef OMITBAD

void CWE273_Improper_Check_for_Dropped_Privileges__w32_ImpersonateNamedPipeClient_08_bad()
{
    if(staticReturnsTrue())
    {
        {
            HANDLE hPipe = INVALID_HANDLE_VALUE;
            hPipe = CreateNamedPipeA(
                        "\\\\.\\pipe\\test_pipe",
                        PIPE_ACCESS_DUPLEX | FILE_FLAG_FIRST_PIPE_INSTANCE,
                        PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE | PIPE_WAIT,
                        PIPE_UNLIMITED_INSTANCES,
                        BUFSIZE,
                        BUFSIZE,
                        NMPWAIT_USE_DEFAULT_WAIT,
                        NULL);
            if (hPipe == INVALID_HANDLE_VALUE)
            {
                exit(1);
            }
            /* ConnectNamedPipe returns failure if a client connected between CreateNamedPipe and now,
             * which isn't actually an error in terms of waiting for a client. */
            if (!ConnectNamedPipe(hPipe, NULL) && GetLastError() != ERROR_PIPE_CONNECTED)
            {
                CloseHandle(hPipe);
                exit(1);
            }
            /* FLAW: Failed to check return status of ImpersonateNamedPipeClient
             * -- However, since we're not even DOING anything with the pipe
             * it's debatable whether this is really a bug
             */
            ImpersonateNamedPipeClient(hPipe);
            printLine("Impersonated");
            if (!RevertToSelf())
            {
                exit(1);
            }
            CloseHandle(hPipe);
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() uses if(staticReturnsFalse()) instead of if(staticReturnsTrue()) */
static void good1()
{
    if(staticReturnsFalse())
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        {
            HANDLE hPipe = INVALID_HANDLE_VALUE;
            hPipe = CreateNamedPipeA(
                        "\\\\.\\pipe\\test_pipe",
                        PIPE_ACCESS_DUPLEX | FILE_FLAG_FIRST_PIPE_INSTANCE,
                        PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE | PIPE_WAIT,
                        PIPE_UNLIMITED_INSTANCES,
                        BUFSIZE,
                        BUFSIZE,
                        NMPWAIT_USE_DEFAULT_WAIT,
                        NULL);
            if (hPipe == INVALID_HANDLE_VALUE)
            {
                exit(1);
            }
            /* ConnectNamedPipe returns failure if a client connected between CreateNamedPipe and now,
             * which isn't actually an error in terms of waiting for a client. */
            if (!ConnectNamedPipe(hPipe, NULL) && GetLastError() != ERROR_PIPE_CONNECTED)
            {
                CloseHandle(hPipe);
                exit(1);
            }
            /* FIX: Check if "ImpersonateNamedPipeClient" succeeded or not */
            if (!ImpersonateNamedPipeClient(hPipe))
            {
                printLine("Failed to impersonate");
            }
            else
            {
                printLine("Impersonated");
                if (!RevertToSelf())
                {
                    exit(1);
                }
            }
            CloseHandle(hPipe);
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(staticReturnsTrue())
    {
        {
            HANDLE hPipe = INVALID_HANDLE_VALUE;
            hPipe = CreateNamedPipeA(
                        "\\\\.\\pipe\\test_pipe",
                        PIPE_ACCESS_DUPLEX | FILE_FLAG_FIRST_PIPE_INSTANCE,
                        PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE | PIPE_WAIT,
                        PIPE_UNLIMITED_INSTANCES,
                        BUFSIZE,
                        BUFSIZE,
                        NMPWAIT_USE_DEFAULT_WAIT,
                        NULL);
            if (hPipe == INVALID_HANDLE_VALUE)
            {
                exit(1);
            }
            /* ConnectNamedPipe returns failure if a client connected between CreateNamedPipe and now,
             * which isn't actually an error in terms of waiting for a client. */
            if (!ConnectNamedPipe(hPipe, NULL) && GetLastError() != ERROR_PIPE_CONNECTED)
            {
                CloseHandle(hPipe);
                exit(1);
            }
            /* FIX: Check if "ImpersonateNamedPipeClient" succeeded or not */
            if (!ImpersonateNamedPipeClient(hPipe))
            {
                printLine("Failed to impersonate");
            }
            else
            {
                printLine("Impersonated");
                if (!RevertToSelf())
                {
                    exit(1);
                }
            }
            CloseHandle(hPipe);
        }
    }
}

void CWE273_Improper_Check_for_Dropped_Privileges__w32_ImpersonateNamedPipeClient_08_good()
{
    good1();
    good2();
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
    CWE273_Improper_Check_for_Dropped_Privileges__w32_ImpersonateNamedPipeClient_08_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE273_Improper_Check_for_Dropped_Privileges__w32_ImpersonateNamedPipeClient_08_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
