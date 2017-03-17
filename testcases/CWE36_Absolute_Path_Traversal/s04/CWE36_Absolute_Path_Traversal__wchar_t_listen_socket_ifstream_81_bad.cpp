/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE36_Absolute_Path_Traversal__wchar_t_listen_socket_ifstream_81_bad.cpp
Label Definition File: CWE36_Absolute_Path_Traversal.label.xml
Template File: sources-sink-81_bad.tmpl.cpp
*/
/*
 * @description
 * CWE: 36 Absolute Path Traversal
 * BadSource: listen_socket Read data using a listen socket (server side)
 * GoodSource: Full path and file name
 * Sinks: ifstream
 *    BadSink : Open the file named in data using ifstream::open()
 * Flow Variant: 81 Data flow: data passed in a parameter to a virtual method called via a reference
 *
 * */
#ifndef OMITBAD

#include "std_testcase.h"
#include "CWE36_Absolute_Path_Traversal__wchar_t_listen_socket_ifstream_81.h"

#include <fstream>
using namespace std;

namespace CWE36_Absolute_Path_Traversal__wchar_t_listen_socket_ifstream_81
{

void CWE36_Absolute_Path_Traversal__wchar_t_listen_socket_ifstream_81_bad::action(wchar_t * data) const
{
    {
        ifstream inputFile;
        /* POTENTIAL FLAW: Possibly opening a file without validating the file name or path */
        inputFile.open((char *)data);
        inputFile.close();
    }
}

}
#endif /* OMITBAD */
