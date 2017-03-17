/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE127_Buffer_Underread__CWE839_fscanf_81.h
Label Definition File: CWE127_Buffer_Underread__CWE839.label.xml
Template File: sources-sinks-81.tmpl.h
*/
/*
 * @description
 * CWE: 127 Buffer Underread
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Non-negative but less than 10
 * Sinks:
 *    GoodSink: Ensure the array index is valid
 *    BadSink : Improperly check the array index by not checking to see if the value is negative
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */

#include "std_testcase.h"

namespace CWE127_Buffer_Underread__CWE839_fscanf_81
{

class CWE127_Buffer_Underread__CWE839_fscanf_81_base
{
public:
    /* pure virtual function */
    virtual void action(int data) const = 0;
};

#ifndef OMITBAD

class CWE127_Buffer_Underread__CWE839_fscanf_81_bad : public CWE127_Buffer_Underread__CWE839_fscanf_81_base
{
public:
    void action(int data) const;
};

#endif /* OMITBAD */

#ifndef OMITGOOD

class CWE127_Buffer_Underread__CWE839_fscanf_81_goodG2B : public CWE127_Buffer_Underread__CWE839_fscanf_81_base
{
public:
    void action(int data) const;
};

class CWE127_Buffer_Underread__CWE839_fscanf_81_goodB2G : public CWE127_Buffer_Underread__CWE839_fscanf_81_base
{
public:
    void action(int data) const;
};

#endif /* OMITGOOD */

}
