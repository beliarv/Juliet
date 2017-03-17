/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE90_LDAP_Injection__w32_char_environment_54b.c
Label Definition File: CWE90_LDAP_Injection__w32.label.xml
Template File: sources-sink-54b.tmpl.c
*/
/*
 * @description
 * CWE: 90 LDAP Injection
 * BadSource: environment Read input from an environment variable
 * GoodSource: Use a fixed string
 * Sink:
 *    BadSink : data concatenated into LDAP search, which could result in LDAP Injection
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#define ENV_VARIABLE "ADD"

#ifdef _WIN32
#define GETENV getenv
#else
#define GETENV getenv
#endif

#include <windows.h>
#include <Winldap.h>

#pragma comment(lib, "wldap32")

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

/* bad function declaration */
void CWE90_LDAP_Injection__w32_char_environment_54c_badSink(char * data);

void CWE90_LDAP_Injection__w32_char_environment_54b_badSink(char * data)
{
    CWE90_LDAP_Injection__w32_char_environment_54c_badSink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declaration */
void CWE90_LDAP_Injection__w32_char_environment_54c_goodG2BSink(char * data);

/* goodG2B uses the GoodSource with the BadSink */
void CWE90_LDAP_Injection__w32_char_environment_54b_goodG2BSink(char * data)
{
    CWE90_LDAP_Injection__w32_char_environment_54c_goodG2BSink(data);
}

#endif /* OMITGOOD */
