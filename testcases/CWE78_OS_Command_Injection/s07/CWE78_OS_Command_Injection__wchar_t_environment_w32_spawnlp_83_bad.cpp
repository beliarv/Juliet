/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE78_OS_Command_Injection__wchar_t_environment_w32_spawnlp_83_bad.cpp
Label Definition File: CWE78_OS_Command_Injection.strings.label.xml
Template File: sources-sink-83_bad.tmpl.cpp
*/
/*
 * @description
 * CWE: 78 OS Command Injection
 * BadSource: environment Read input from an environment variable
 * GoodSource: Fixed string
 * Sinks: w32_spawnlp
 *    BadSink : execute command with wspawnlp
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */
#ifndef OMITBAD

#include "std_testcase.h"
#include "CWE78_OS_Command_Injection__wchar_t_environment_w32_spawnlp_83.h"

#define ENV_VARIABLE L"ADD"

#ifdef _WIN32
#define GETENV _wgetenv
#else
#define GETENV getenv
#endif

#include <process.h>

namespace CWE78_OS_Command_Injection__wchar_t_environment_w32_spawnlp_83
{
CWE78_OS_Command_Injection__wchar_t_environment_w32_spawnlp_83_bad::CWE78_OS_Command_Injection__wchar_t_environment_w32_spawnlp_83_bad(wchar_t * dataCopy)
{
    data = dataCopy;
    {
        /* Append input from an environment variable to data */
        size_t dataLen = wcslen(data);
        wchar_t * environment = GETENV(ENV_VARIABLE);
        /* If there is data in the environment variable */
        if (environment != NULL)
        {
            /* POTENTIAL FLAW: Read data from an environment variable */
            wcsncat(data+dataLen, environment, 100-dataLen-1);
        }
    }
}

CWE78_OS_Command_Injection__wchar_t_environment_w32_spawnlp_83_bad::~CWE78_OS_Command_Injection__wchar_t_environment_w32_spawnlp_83_bad()
{
    /* wspawnlp - searches for the location of the command among
     * the directories specified by the PATH environment variable */
    /* POTENTIAL FLAW: Execute command without validating input possibly leading to command injection */
    _wspawnlp(_P_WAIT, COMMAND_INT, COMMAND_INT, COMMAND_ARG1, COMMAND_ARG2, COMMAND_ARG3, NULL);
}
}
#endif /* OMITBAD */
