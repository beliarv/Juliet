/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE78_OS_Command_Injection__wchar_t_listen_socket_execl_81_bad.cpp
Label Definition File: CWE78_OS_Command_Injection.strings.label.xml
Template File: sources-sink-81_bad.tmpl.cpp
*/
/*
 * @description
 * CWE: 78 OS Command Injection
 * BadSource: listen_socket Read data using a listen socket (server side)
 * GoodSource: Fixed string
 * Sinks: execl
 *    BadSink : execute command with wexecl
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */
#ifndef OMITBAD

#include "std_testcase.h"
#include "CWE78_OS_Command_Injection__wchar_t_listen_socket_execl_81.h"

#ifdef _WIN32
#include <process.h>
#define EXECL _wexecl
#else /* NOT _WIN32 */
#define EXECL execl
#endif

namespace CWE78_OS_Command_Injection__wchar_t_listen_socket_execl_81
{

void CWE78_OS_Command_Injection__wchar_t_listen_socket_execl_81_bad::action(wchar_t * data) const
{
    /* wexecl - specify the path where the command is located */
    /* POTENTIAL FLAW: Execute command without validating input possibly leading to command injection */
    EXECL(COMMAND_INT_PATH, COMMAND_INT_PATH, COMMAND_ARG1, COMMAND_ARG2, COMMAND_ARG3, NULL);
}

}
#endif /* OMITBAD */
