/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE426_Untrusted_Search_Path__char_popen_84_goodG2B.cpp
Label Definition File: CWE426_Untrusted_Search_Path.label.xml
Template File: sources-sink-84_goodG2B.tmpl.cpp
*/
/*
 * @description
 * CWE: 426 Untrusted Search Path
 * BadSource:  Don't specify the full path in the OS command
 * GoodSource: Specify the full path in the OS command
 * Sinks: popen
 *    BadSink : Execute the popen function
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */
#ifndef OMITGOOD

#include "std_testcase.h"
#include "CWE426_Untrusted_Search_Path__char_popen_84.h"

#ifdef _WIN32
#define POPEN _popen
#define PCLOSE _pclose
#else /* NOT _WIN32 */
#define POPEN popen
#define PCLOSE pclose
#endif

namespace CWE426_Untrusted_Search_Path__char_popen_84
{
CWE426_Untrusted_Search_Path__char_popen_84_goodG2B::CWE426_Untrusted_Search_Path__char_popen_84_goodG2B(char * dataCopy)
{
    data = dataCopy;
    /* FIX: full path is specified */
    strcpy(data, GOOD_OS_COMMAND);
}

CWE426_Untrusted_Search_Path__char_popen_84_goodG2B::~CWE426_Untrusted_Search_Path__char_popen_84_goodG2B()
{
    {
        FILE *pipe;
        /* POTENTIAL FLAW: Executing the popen() function without specifying the full path to the executable
         * can allow an attacker to run their own program */
        pipe = POPEN(data, "wb");
        if (pipe != NULL)
        {
            PCLOSE(pipe);
        }
    }
}
}
#endif /* OMITGOOD */
