/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE615_Info_Exposure_by_Comment__w32_02.c
Label Definition File: CWE615_Info_Exposure_by_Comment__w32.label.xml
Template File: point-flaw-02.tmpl.c
*/
/*
 * @description
 * CWE: 615 Information Exposure by Comment
 * Sinks:
 *    GoodSink: Do not place username and password in comment
 *    BadSink : Information exposure by comment
 * Flow Variant: 02 Control flow: if(1) and if(0)
 *
 * */

#include "std_testcase.h"

#include <windows.h>
#pragma comment(lib, "advapi32.lib")

#define PASSWORD "ABCD1234!"
#define USERNAME "XXXXX Smith!"

#ifndef OMITBAD

void CWE615_Info_Exposure_by_Comment__w32_02_bad()
{
    if(1)
    {
        {
            size_t passwordLen = 0;
            HANDLE hUser;
            char * domain = "Domain";
            /* Use the password in LogonUser() to establish that it is "sensitive" */
            if (LogonUserA(
                        USERNAME,
                        domain,
                        PASSWORD,
                        LOGON32_LOGON_NETWORK,
                        LOGON32_PROVIDER_DEFAULT,
                        &hUser) != 0)
            {
                /* FLAW: expose username and password in comment*/
                /* Logged in XXXXX Smith using password ABCD1234 */
                printLine("User logged in successfully" );
                CloseHandle(hUser);
            }
            else
            {
                printLine("Unable to login.");
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
            size_t passwordLen = 0;
            HANDLE hUser;
            char * domain = "Domain";
            /* Use the password in LogonUser() to establish that it is "sensitive" */
            if (LogonUserA(
                        USERNAME,
                        domain,
                        PASSWORD,
                        LOGON32_LOGON_NETWORK,
                        LOGON32_PROVIDER_DEFAULT,
                        &hUser) != 0)
            {
                /* FIX: do not expose username or password in comment */
                /* User logged in successfully */
                printLine("User logged in successfully with password" );
                CloseHandle(hUser);
            }
            else
            {
                printLine("Unable to login.");
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
            size_t passwordLen = 0;
            HANDLE hUser;
            char * domain = "Domain";
            /* Use the password in LogonUser() to establish that it is "sensitive" */
            if (LogonUserA(
                        USERNAME,
                        domain,
                        PASSWORD,
                        LOGON32_LOGON_NETWORK,
                        LOGON32_PROVIDER_DEFAULT,
                        &hUser) != 0)
            {
                /* FIX: do not expose username or password in comment */
                /* User logged in successfully */
                printLine("User logged in successfully with password" );
                CloseHandle(hUser);
            }
            else
            {
                printLine("Unable to login.");
            }
        }
    }
}

void CWE615_Info_Exposure_by_Comment__w32_02_good()
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
    CWE615_Info_Exposure_by_Comment__w32_02_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE615_Info_Exposure_by_Comment__w32_02_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
