/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE78_OS_Command_Injection__wchar_t_console_w32_spawnlp_67b.c
Label Definition File: CWE78_OS_Command_Injection.strings.label.xml
Template File: sources-sink-67b.tmpl.c
*/
/*
 * @description
 * CWE: 78 OS Command Injection
 * BadSource: console Read input from the console
 * GoodSource: Fixed string
 * Sinks: w32_spawnlp
 *    BadSink : execute command with wspawnlp
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifdef _WIN32
#define COMMAND_INT_PATH L"%WINDIR%\\system32\\cmd.exe"
#define COMMAND_INT L"cmd.exe"
#define COMMAND_ARG1 L"/c"
#define COMMAND_ARG2 L"dir"
#define COMMAND_ARG3 data
#else /* NOT _WIN32 */
#include <unistd.h>
#define COMMAND_INT_PATH L"/bin/sh"
#define COMMAND_INT L"sh"
#define COMMAND_ARG1 L"ls"
#define COMMAND_ARG2 L"-la"
#define COMMAND_ARG3 data
#endif

#include <process.h>

typedef struct _CWE78_OS_Command_Injection__wchar_t_console_w32_spawnlp_67_structType
{
    wchar_t * structFirst;
} CWE78_OS_Command_Injection__wchar_t_console_w32_spawnlp_67_structType;

#ifndef OMITBAD

void CWE78_OS_Command_Injection__wchar_t_console_w32_spawnlp_67b_badSink(CWE78_OS_Command_Injection__wchar_t_console_w32_spawnlp_67_structType myStruct)
{
    wchar_t * data = myStruct.structFirst;
    /* wspawnlp - searches for the location of the command among
     * the directories specified by the PATH environment variable */
    /* POTENTIAL FLAW: Execute command without validating input possibly leading to command injection */
    _wspawnlp(_P_WAIT, COMMAND_INT, COMMAND_INT, COMMAND_ARG1, COMMAND_ARG2, COMMAND_ARG3, NULL);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE78_OS_Command_Injection__wchar_t_console_w32_spawnlp_67b_goodG2BSink(CWE78_OS_Command_Injection__wchar_t_console_w32_spawnlp_67_structType myStruct)
{
    wchar_t * data = myStruct.structFirst;
    /* wspawnlp - searches for the location of the command among
     * the directories specified by the PATH environment variable */
    /* POTENTIAL FLAW: Execute command without validating input possibly leading to command injection */
    _wspawnlp(_P_WAIT, COMMAND_INT, COMMAND_INT, COMMAND_ARG1, COMMAND_ARG2, COMMAND_ARG3, NULL);
}

#endif /* OMITGOOD */
