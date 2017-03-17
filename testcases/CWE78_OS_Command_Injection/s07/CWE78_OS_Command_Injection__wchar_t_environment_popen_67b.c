/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE78_OS_Command_Injection__wchar_t_environment_popen_67b.c
Label Definition File: CWE78_OS_Command_Injection.one_string.label.xml
Template File: sources-sink-67b.tmpl.c
*/
/*
 * @description
 * CWE: 78 OS Command Injection
 * BadSource: environment Read input from an environment variable
 * GoodSource: Fixed string
 * Sinks: popen
 *    BadSink : Execute command in data using popen()
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifdef _WIN32
#define FULL_COMMAND L"%WINDIR%\\system32\\cmd.exe /c dir "
#else
#include <unistd.h>
#define FULL_COMMAND L"/bin/sh ls -la "
#endif

#define ENV_VARIABLE L"ADD"

#ifdef _WIN32
#define GETENV _wgetenv
#else
#define GETENV getenv
#endif

/* define POPEN as _popen on Windows and popen otherwise */
#ifdef _WIN32
#define POPEN _wpopen
#define PCLOSE _pclose
#else /* NOT _WIN32 */
#define POPEN popen
#define PCLOSE pclose
#endif

typedef struct _CWE78_OS_Command_Injection__wchar_t_environment_popen_67_structType
{
    wchar_t * structFirst;
} CWE78_OS_Command_Injection__wchar_t_environment_popen_67_structType;

#ifndef OMITBAD

void CWE78_OS_Command_Injection__wchar_t_environment_popen_67b_badSink(CWE78_OS_Command_Injection__wchar_t_environment_popen_67_structType myStruct)
{
    wchar_t * data = myStruct.structFirst;
    {
        FILE *pipe;
        /* POTENTIAL FLAW: Execute command in data possibly leading to command injection */
        pipe = POPEN(data, L"wb");
        if (pipe != NULL)
        {
            PCLOSE(pipe);
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE78_OS_Command_Injection__wchar_t_environment_popen_67b_goodG2BSink(CWE78_OS_Command_Injection__wchar_t_environment_popen_67_structType myStruct)
{
    wchar_t * data = myStruct.structFirst;
    {
        FILE *pipe;
        /* POTENTIAL FLAW: Execute command in data possibly leading to command injection */
        pipe = POPEN(data, L"wb");
        if (pipe != NULL)
        {
            PCLOSE(pipe);
        }
    }
}

#endif /* OMITGOOD */
