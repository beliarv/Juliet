/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_81_bad.cpp
Label Definition File: CWE404_Improper_Resource_Shutdown__w32CreateFile.label.xml
Template File: source-sinks-81_bad.tmpl.cpp
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * BadSource:  Open a file using CreateFile()
 * Sinks: fclose
 *    GoodSink: Close the file using CloseHandle()
 *    BadSink : Close the file using fclose()
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */
#ifndef OMITBAD

#include "std_testcase.h"
#include "CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_81.h"

namespace CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_81
{

void CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_81_bad::action(HANDLE data) const
{
    if (data != INVALID_HANDLE_VALUE)
    {
        /* FLAW: Attempt to close the file using fclose() instead of CloseHandle() */
        fclose((FILE *)data);
    }
}

}
#endif /* OMITBAD */
