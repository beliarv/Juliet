/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE272_Least_Privilege_Violation__w32_wchar_t_RegCreateKey_12.c
Label Definition File: CWE272_Least_Privilege_Violation__w32.label.xml
Template File: point-flaw-12.tmpl.c
*/
/*
 * @description
 * CWE: 272 Least Privilege Violation
 * Sinks: RegCreateKey
 *    GoodSink: Create a registry key using RegCreateKeyW() and HKEY_CURRENT_USER
 *    BadSink : Create a registry key using RegCreateKeyW() and HKEY_LOCAL_MACHINE
 * Flow Variant: 12 Control flow: if(globalReturnsTrueOrFalse())
 *
 * */

#include "std_testcase.h"

#include <windows.h>
#pragma comment( lib, "advapi32" )

#ifndef OMITBAD

void CWE272_Least_Privilege_Violation__w32_wchar_t_RegCreateKey_12_bad()
{
    if(globalReturnsTrueOrFalse())
    {
        {
            wchar_t * keyName = L"TEST\\TestKey";
            HKEY hKey;
            /* FLAW: Call RegCreateKeyW() with HKEY_LOCAL_MACHINE violating the least privilege principal */
            if (RegCreateKeyW(
                        HKEY_LOCAL_MACHINE,
                        keyName,
                        &hKey) != ERROR_SUCCESS)
            {
                printLine("Registry key could not be created");
            }
            else
            {
                printLine("Registry key created successfully");
                RegCloseKey(hKey);
            }
        }
    }
    else
    {
        {
            wchar_t * keyName = L"TEST\\TestKey";
            HKEY hKey;
            /* FIX: Call RegCreateKeyW() with HKEY_CURRENT_USER */
            if (RegCreateKeyW(
                        HKEY_CURRENT_USER,
                        keyName,
                        &hKey) != ERROR_SUCCESS)
            {
                printLine("Registry key could not be created");
            }
            else
            {
                printLine("Registry key created successfully");
                RegCloseKey(hKey);
            }
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() uses the GoodSink on both sides of the "if" statement */
static void good1()
{
    if(globalReturnsTrueOrFalse())
    {
        {
            wchar_t * keyName = L"TEST\\TestKey";
            HKEY hKey;
            /* FIX: Call RegCreateKeyW() with HKEY_CURRENT_USER */
            if (RegCreateKeyW(
                        HKEY_CURRENT_USER,
                        keyName,
                        &hKey) != ERROR_SUCCESS)
            {
                printLine("Registry key could not be created");
            }
            else
            {
                printLine("Registry key created successfully");
                RegCloseKey(hKey);
            }
        }
    }
    else
    {
        {
            wchar_t * keyName = L"TEST\\TestKey";
            HKEY hKey;
            /* FIX: Call RegCreateKeyW() with HKEY_CURRENT_USER */
            if (RegCreateKeyW(
                        HKEY_CURRENT_USER,
                        keyName,
                        &hKey) != ERROR_SUCCESS)
            {
                printLine("Registry key could not be created");
            }
            else
            {
                printLine("Registry key created successfully");
                RegCloseKey(hKey);
            }
        }
    }
}

void CWE272_Least_Privilege_Violation__w32_wchar_t_RegCreateKey_12_good()
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
    CWE272_Least_Privilege_Violation__w32_wchar_t_RegCreateKey_12_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE272_Least_Privilege_Violation__w32_wchar_t_RegCreateKey_12_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
