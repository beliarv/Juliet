/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateMutex_18.c
Label Definition File: CWE253_Incorrect_Check_of_Function_Return_Value.label.xml
Template File: point-flaw-18.tmpl.c
*/
/*
 * @description
 * CWE: 253 Incorrect Check of Return Value
 * Sinks: w32CreateMutex
 *    GoodSink: Correctly check if CreateMutexW() failed
 *    BadSink : Incorrectly check if CreateMutexW() failed
 * Flow Variant: 18 Control flow: goto statements
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

#include <windows.h>
#define BUFFER_SIZE 1024

#ifndef OMITBAD

void CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateMutex_18_bad()
{
    goto sink;
sink:
    {
        HANDLE hMutex = NULL;
        hMutex = CreateMutexW(NULL, FALSE, NULL);
        /* FLAW: If CreateMutexW() failed, the return value will be NULL,
           but we are checking to see if the return value is INVALID_HANDLE_VALUE */
        if (hMutex == INVALID_HANDLE_VALUE)
        {
            exit(1);
        }
        /* We'll leave out most of the implementation since it has nothing to do with the CWE
         * and since the checkers are looking for certain function calls anyway */
        CloseHandle(hMutex);
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
        HANDLE hMutex = NULL;
        hMutex = CreateMutexW(NULL, FALSE, NULL);
        /* FIX: check for the correct return value */
        if (hMutex == NULL)
        {
            exit(1);
        }
        /* We'll leave out most of the implementation since it has nothing to do with the CWE
         * and since the checkers are looking for certain function calls anyway */
        CloseHandle(hMutex);
    }
}

void CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateMutex_18_good()
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
    CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateMutex_18_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE253_Incorrect_Check_of_Function_Return_Value__wchar_t_w32CreateMutex_18_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
