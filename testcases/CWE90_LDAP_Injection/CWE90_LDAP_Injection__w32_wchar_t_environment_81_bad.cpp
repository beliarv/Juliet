/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE90_LDAP_Injection__w32_wchar_t_environment_81_bad.cpp
Label Definition File: CWE90_LDAP_Injection__w32.label.xml
Template File: sources-sink-81_bad.tmpl.cpp
*/
/*
 * @description
 * CWE: 90 LDAP Injection
 * BadSource: environment Read input from an environment variable
 * GoodSource: Use a fixed string
 * Sinks:
 *    BadSink : data concatenated into LDAP search, which could result in LDAP Injection
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */
#ifndef OMITBAD

#include "std_testcase.h"
#include "CWE90_LDAP_Injection__w32_wchar_t_environment_81.h"

#include <windows.h>
#include <Winldap.h>

#pragma comment(lib, "wldap32")

namespace CWE90_LDAP_Injection__w32_wchar_t_environment_81
{

void CWE90_LDAP_Injection__w32_wchar_t_environment_81_bad::action(wchar_t * data) const
{
    {
        LDAP* pLdapConnection = NULL;
        ULONG connectSuccess = 0L;
        ULONG searchSuccess = 0L;
        LDAPMessage *pMessage = NULL;
        wchar_t filter[256];
        /* POTENTIAL FLAW: data concatenated into LDAP search, which could result in LDAP Injection*/
        _snwprintf(filter, 256-1, L"(cn=%s)", data);
        pLdapConnection = ldap_initW(L"localhost", LDAP_PORT);
        if (pLdapConnection == NULL)
        {
            printLine("Initialization failed");
            exit(1);
        }
        connectSuccess = ldap_connect(pLdapConnection, NULL);
        if (connectSuccess != LDAP_SUCCESS)
        {
            printLine("Connection failed");
            exit(1);
        }
        searchSuccess = ldap_search_ext_sW(
                            pLdapConnection,
                            L"base",
                            LDAP_SCOPE_SUBTREE,
                            filter,
                            NULL,
                            0,
                            NULL,
                            NULL,
                            LDAP_NO_LIMIT,
                            LDAP_NO_LIMIT,
                            &pMessage);
        if (searchSuccess != LDAP_SUCCESS)
        {
            printLine("Search failed");
            if (pMessage != NULL)
            {
                ldap_msgfree(pMessage);
            }
            exit(1);
        }
        /* Typically you would do something with the search results, but this is a test case and we can ignore them */
        /* Free the results to avoid incidentals */
        if (pMessage != NULL)
        {
            ldap_msgfree(pMessage);
        }
        /* Close the connection */
        ldap_unbind(pLdapConnection);
    }
}

}
#endif /* OMITBAD */
