/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__freopen_w32_close_81.h
Label Definition File: CWE404_Improper_Resource_Shutdown.label.xml
Template File: source-sinks-81.tmpl.h
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * BadSource: freopen Open a file using freopen()
 * Sinks: w32_close
 *    GoodSink: Close the file using fclose()
 *    BadSink : Close the file using close()
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */

#include "std_testcase.h"

namespace CWE404_Improper_Resource_Shutdown__freopen_w32_close_81
{

class CWE404_Improper_Resource_Shutdown__freopen_w32_close_81_base
{
public:
    /* pure virtual function */
    virtual void action(FILE * data) const = 0;
};

#ifndef OMITBAD

class CWE404_Improper_Resource_Shutdown__freopen_w32_close_81_bad : public CWE404_Improper_Resource_Shutdown__freopen_w32_close_81_base
{
public:
    void action(FILE * data) const;
};

#endif /* OMITBAD */

#ifndef OMITGOOD

class CWE404_Improper_Resource_Shutdown__freopen_w32_close_81_goodB2G : public CWE404_Improper_Resource_Shutdown__freopen_w32_close_81_base
{
public:
    void action(FILE * data) const;
};

#endif /* OMITGOOD */

}
