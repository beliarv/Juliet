/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE284_Improper_Access_Control__w32_char_SHRegCreateUSKey_02.c
Label Definition File: CWE284_Improper_Access_Control__w32.label.xml
Template File: point-flaw-02.tmpl.c
*/
/*
 * @description
 * CWE: 284 Improper Access Control
 * Sinks: SHRegCreateUSKey
 *    GoodSink: Create a registry key using SHRegCreateUSKeyA() without excessive privileges
 *    BadSink : Create a registry key using SHRegCreateUSKeyA() with excessive privileges
 * Flow Variant: 02 Control flow: if(1) and if(0)
 *
 * */

#include "std_testcase.h"

#include <windows.h>
#pragma comment( lib, "shlwapi" )
#include <shlwapi.h>

#ifndef OMITBAD

void CWE284_Improper_Access_Control__w32_char_SHRegCreateUSKey_02_bad()
{
    if(1)
    {
        {
            char * keyName = "TEST\\TestKey";
            HUSKEY hKey = HKEY_CURRENT_USER;
            /* FLAW: Call SHRegCreateUSKeyA() with KEY_ALL_ACCESS as the 2nd parameter */
            if (SHRegCreateUSKeyA(
                        keyName,
                        KEY_ALL_ACCESS,
                        NULL,
                        &hKey,
                        SHREGSET_HKCU) != ERROR_SUCCESS)
            {
                printLine("Registry key could not be created");
            }
            else
            {
                printLine("Registry key created successfully");
                SHRegCloseUSKey(hKey);
            }
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() uses if(0) instead of if(1) */
static void good1()
{
    if(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        {
            char * keyName = "TEST\\TestKey";
            HUSKEY hKey = HKEY_CURRENT_USER;
            /* FIX: Call SHRegCreateUSKeyA() without KEY_ALL_ACCESS as the 2nd parameter to limit access */
            if (SHRegCreateUSKeyA(
                        keyName,
                        KEY_WRITE,
                        NULL,
                        &hKey,
                        SHREGSET_HKCU) != ERROR_SUCCESS)
            {
                printLine("Registry key could not be created");
            }
            else
            {
                printLine("Registry key created successfully");
                SHRegCloseUSKey(hKey);
            }
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(1)
    {
        {
            char * keyName = "TEST\\TestKey";
            HUSKEY hKey = HKEY_CURRENT_USER;
            /* FIX: Call SHRegCreateUSKeyA() without KEY_ALL_ACCESS as the 2nd parameter to limit access */
            if (SHRegCreateUSKeyA(
                        keyName,
                        KEY_WRITE,
                        NULL,
                        &hKey,
                        SHREGSET_HKCU) != ERROR_SUCCESS)
            {
                printLine("Registry key could not be created");
            }
            else
            {
                printLine("Registry key created successfully");
                SHRegCloseUSKey(hKey);
            }
        }
    }
}

void CWE284_Improper_Access_Control__w32_char_SHRegCreateUSKey_02_good()
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
    CWE284_Improper_Access_Control__w32_char_SHRegCreateUSKey_02_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE284_Improper_Access_Control__w32_char_SHRegCreateUSKey_02_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
