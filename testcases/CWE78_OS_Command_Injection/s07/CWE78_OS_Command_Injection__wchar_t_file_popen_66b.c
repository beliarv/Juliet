/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE78_OS_Command_Injection__wchar_t_file_popen_66b.c
Label Definition File: CWE78_OS_Command_Injection.one_string.label.xml
Template File: sources-sink-66b.tmpl.c
*/
/*
 * @description
 * CWE: 78 OS Command Injection
 * BadSource: file Read input from a file
 * GoodSource: Fixed string
 * Sinks: popen
 *    BadSink : Execute command in data using popen()
 * Flow Variant: 66 Data flow: data passed in an array from one function to another in different source files
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

#ifdef _WIN32
#define FILENAME "C:\\temp\\file.txt"
#else
#define FILENAME "/tmp/file.txt"
#endif

/* define POPEN as _popen on Windows and popen otherwise */
#ifdef _WIN32
#define POPEN _wpopen
#define PCLOSE _pclose
#else /* NOT _WIN32 */
#define POPEN popen
#define PCLOSE pclose
#endif

#ifndef OMITBAD

void CWE78_OS_Command_Injection__wchar_t_file_popen_66b_badSink(wchar_t * dataArray[])
{
    /* copy data out of dataArray */
    wchar_t * data = dataArray[2];
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
void CWE78_OS_Command_Injection__wchar_t_file_popen_66b_goodG2BSink(wchar_t * dataArray[])
{
    wchar_t * data = dataArray[2];
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
