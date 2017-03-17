/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE427_Uncontrolled_Search_Path_Element__wchar_t_environment_81_bad.cpp
Label Definition File: CWE427_Uncontrolled_Search_Path_Element.label.xml
Template File: sources-sink-81_bad.tmpl.cpp
*/
/*
 * @description
 * CWE: 427 Uncontrolled Search Path Element
 * BadSource: environment Read input from an environment variable
 * GoodSource: Use a hardcoded path
 * Sinks:
 *    BadSink : Set the environment variable
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */
#ifndef OMITBAD

#include "std_testcase.h"
#include "CWE427_Uncontrolled_Search_Path_Element__wchar_t_environment_81.h"

namespace CWE427_Uncontrolled_Search_Path_Element__wchar_t_environment_81
{

void CWE427_Uncontrolled_Search_Path_Element__wchar_t_environment_81_bad::action(wchar_t * data) const
{
    /* POTENTIAL FLAW: Set a new environment variable with a path that is possibly insecure */
    PUTENV(data);
}

}
#endif /* OMITBAD */
