/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE426_Untrusted_Search_Path__char_system_83.h
Label Definition File: CWE426_Untrusted_Search_Path.label.xml
Template File: sources-sink-83.tmpl.h
*/
/*
 * @description
 * CWE: 426 Untrusted Search Path
 * BadSource:  Don't specify the full path in the OS command
 * GoodSource: Specify the full path in the OS command
 * Sinks: system
 *    BadSink : Execute the system function
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */

#include "std_testcase.h"

#include <wchar.h>
#ifdef _WIN32
#define BAD_OS_COMMAND "cmd.exe /c dir"

/* REVIEWERS NOTE:
 * This hard-coded path is probably incorrect for Windows systems, as it will
 * function improperly on 9x/NT/2K, possibly on XP+ systems upgraded from 2K,
 * and could introduce code execution vulnerabilities on Windows systems that
 * have a system drive on an alternate drive letter (e.g., d:\windows)
 */
#define GOOD_OS_COMMAND "c:\\windows\\system32\\cmd.exe /c dir"
#else /* NOT _WIN32 */
#define BAD_OS_COMMAND "ls -la"
#define GOOD_OS_COMMAND "/usr/bin/ls -la"
#endif /* end NOT _WIN32 */

namespace CWE426_Untrusted_Search_Path__char_system_83
{

#ifndef OMITBAD

class CWE426_Untrusted_Search_Path__char_system_83_bad
{
public:
    CWE426_Untrusted_Search_Path__char_system_83_bad(char * dataCopy);
    ~CWE426_Untrusted_Search_Path__char_system_83_bad();

private:
    char * data;
};

#endif /* OMITBAD */

#ifndef OMITGOOD

class CWE426_Untrusted_Search_Path__char_system_83_goodG2B
{
public:
    CWE426_Untrusted_Search_Path__char_system_83_goodG2B(char * dataCopy);
    ~CWE426_Untrusted_Search_Path__char_system_83_goodG2B();

private:
    char * data;
};

#endif /* OMITGOOD */

}
