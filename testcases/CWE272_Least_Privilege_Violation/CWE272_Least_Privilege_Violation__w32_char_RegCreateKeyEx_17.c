/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE272_Least_Privilege_Violation__w32_char_RegCreateKeyEx_17.c
Label Definition File: CWE272_Least_Privilege_Violation__w32.label.xml
Template File: point-flaw-17.tmpl.c
*/
/*
 * @description
 * CWE: 272 Least Privilege Violation
 * Sinks: RegCreateKeyEx
 *    GoodSink: Create a registry key using RegCreateKeyExA() and HKEY_CURRENT_USER
 *    BadSink : Create a registry key using RegCreateKeyExA() and HKEY_LOCAL_MACHINE
 * Flow Variant: 17 Control flow: for loops
 *
 * */

#include "std_testcase.h"

#include <windows.h>
#pragma comment( lib, "advapi32" )

#ifndef OMITBAD

void CWE272_Least_Privilege_Violation__w32_char_RegCreateKeyEx_17_bad()
{
    int j;
    for(j = 0; j < 1; j++)
    {
        {
            char * keyName = "TEST\\TestKey";
            HKEY hKey;
            /* FLAW: Call RegCreateKeyExA() with HKEY_LOCAL_MACHINE violating the least privilege principal */
            if (RegCreateKeyExA(
                        HKEY_LOCAL_MACHINE,
                        keyName,
                        0,
                        NULL,
                        REG_OPTION_NON_VOLATILE,
                        KEY_WRITE,
                        NULL,
                        &hKey,
                        NULL) != ERROR_SUCCESS)
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

/* good1() uses the GoodSinkBody in the for statements */
static void good1()
{
    int k;
    for(k = 0; k < 1; k++)
    {
        {
            char * keyName = "TEST\\TestKey";
            HKEY hKey;
            /* FIX: Call RegCreateKeyExA() with HKEY_CURRENT_USER */
            if (RegCreateKeyExA(
                        HKEY_CURRENT_USER,
                        keyName,
                        0,
                        NULL,
                        REG_OPTION_NON_VOLATILE,
                        KEY_WRITE,
                        NULL,
                        &hKey,
                        NULL) != ERROR_SUCCESS)
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

void CWE272_Least_Privilege_Violation__w32_char_RegCreateKeyEx_17_good()
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
    CWE272_Least_Privilege_Violation__w32_char_RegCreateKeyEx_17_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE272_Least_Privilege_Violation__w32_char_RegCreateKeyEx_17_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
