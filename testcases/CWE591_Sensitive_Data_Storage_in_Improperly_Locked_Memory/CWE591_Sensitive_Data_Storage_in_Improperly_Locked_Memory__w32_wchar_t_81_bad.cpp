/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_wchar_t_81_bad.cpp
Label Definition File: CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32.label.xml
Template File: sources-sink-81_bad.tmpl.cpp
*/
/*
 * @description
 * CWE: 591 Sensitive Data Storage in Improperly Locked Memory
 * BadSource:  Allocate memory for sensitive data without using VirtualLock() to lock the buffer into memory
 * GoodSource: Allocate memory for sensitive data and use VirtualLock() to lock the buffer into memory
 * Sinks:
 *    BadSink : Authenticate the user using LogonUserW()
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */
#ifndef OMITBAD

#include "std_testcase.h"
#include "CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_wchar_t_81.h"

#pragma comment(lib, "advapi32.lib")

namespace CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_wchar_t_81
{

void CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_wchar_t_81_bad::action(wchar_t * password) const
{
    {
        HANDLE pHandle;
        wchar_t * username = L"User";
        wchar_t * domain = L"Domain";
        /* Use the password in LogonUser() to establish that it is "sensitive" */
        if (LogonUserW(
                    username,
                    domain,
                    password,
                    LOGON32_LOGON_NETWORK,
                    LOGON32_PROVIDER_DEFAULT,
                    &pHandle) != 0)
        {
            printLine("User logged in successfully.");
            CloseHandle(pHandle);
        }
        else
        {
            printLine("Unable to login.");
        }
        /* POTENTIAL FLAW: Sensitive data possibly improperly locked */
        free(password);
    }
}

}
#endif /* OMITBAD */
