/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE90_LDAP_Injection__w32_char_connect_socket_53c.c
Label Definition File: CWE90_LDAP_Injection__w32.label.xml
Template File: sources-sink-53c.tmpl.c
*/
/*
 * @description
 * CWE: 90 LDAP Injection
 * BadSource: connect_socket Read data using a connect socket (client side)
 * GoodSource: Use a fixed string
 * Sink:
 *    BadSink : data concatenated into LDAP search, which could result in LDAP Injection
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
#include <winsock2.h>
#include <windows.h>
#include <direct.h>
#pragma comment(lib, "ws2_32") /* include ws2_32.lib when linking */
#define CLOSE_SOCKET closesocket
#else /* NOT _WIN32 */
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#define INVALID_SOCKET -1
#define SOCKET_ERROR -1
#define CLOSE_SOCKET close
#define SOCKET int
#endif

#define TCP_PORT 27015
#define IP_ADDRESS "127.0.0.1"

#include <Winldap.h>

#pragma comment(lib, "wldap32")

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */

#ifndef OMITBAD

/* bad function declaration */
void CWE90_LDAP_Injection__w32_char_connect_socket_53d_badSink(char * data);

void CWE90_LDAP_Injection__w32_char_connect_socket_53c_badSink(char * data)
{
    CWE90_LDAP_Injection__w32_char_connect_socket_53d_badSink(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declaration */
void CWE90_LDAP_Injection__w32_char_connect_socket_53d_goodG2BSink(char * data);

/* goodG2B uses the GoodSource with the BadSink */
void CWE90_LDAP_Injection__w32_char_connect_socket_53c_goodG2BSink(char * data)
{
    CWE90_LDAP_Injection__w32_char_connect_socket_53d_goodG2BSink(data);
}

#endif /* OMITGOOD */
