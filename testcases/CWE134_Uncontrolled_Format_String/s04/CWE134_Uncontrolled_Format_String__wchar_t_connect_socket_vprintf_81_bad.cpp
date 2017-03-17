/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__wchar_t_connect_socket_vprintf_81_bad.cpp
Label Definition File: CWE134_Uncontrolled_Format_String.vasinks.label.xml
Template File: sources-vasinks-81_bad.tmpl.cpp
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * BadSource: connect_socket Read data using a connect socket (client side)
 * GoodSource: Copy a fixed string into data
 * Sinks: vprintf
 *    GoodSink: vwprintf with a format string
 *    BadSink : vwprintf without a format string
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */
#ifndef OMITBAD

#include <stdarg.h>
#include "std_testcase.h"
#include "CWE134_Uncontrolled_Format_String__wchar_t_connect_socket_vprintf_81.h"

namespace CWE134_Uncontrolled_Format_String__wchar_t_connect_socket_vprintf_81
{

static void badVaSink(wchar_t * data, ...)
{
    {
        va_list args;
        va_start(args, data);
        /* POTENTIAL FLAW: Do not specify the format allowing a possible format string vulnerability */
        vwprintf(data, args);
        va_end(args);
    }
}

void CWE134_Uncontrolled_Format_String__wchar_t_connect_socket_vprintf_81_bad::action(wchar_t * data) const
{
    badVaSink(data, data);
}

}
#endif /* OMITBAD */
