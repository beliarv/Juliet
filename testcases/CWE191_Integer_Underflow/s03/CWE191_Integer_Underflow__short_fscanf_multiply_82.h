/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__short_fscanf_multiply_82.h
Label Definition File: CWE191_Integer_Underflow.label.xml
Template File: sources-sinks-82.tmpl.h
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Set data to a small, non-zero number (negative two)
 * Sinks: multiply
 *    GoodSink: Ensure there will not be an underflow before multiplying data by 2
 *    BadSink : If data is negative, multiply by 2, which can cause an underflow
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
 *
 * */

#include "std_testcase.h"

namespace CWE191_Integer_Underflow__short_fscanf_multiply_82
{

class CWE191_Integer_Underflow__short_fscanf_multiply_82_base
{
public:
    /* pure virtual function */
    virtual void action(short data) = 0;
};

#ifndef OMITBAD

class CWE191_Integer_Underflow__short_fscanf_multiply_82_bad : public CWE191_Integer_Underflow__short_fscanf_multiply_82_base
{
public:
    void action(short data);
};

#endif /* OMITBAD */

#ifndef OMITGOOD

class CWE191_Integer_Underflow__short_fscanf_multiply_82_goodG2B : public CWE191_Integer_Underflow__short_fscanf_multiply_82_base
{
public:
    void action(short data);
};

class CWE191_Integer_Underflow__short_fscanf_multiply_82_goodB2G : public CWE191_Integer_Underflow__short_fscanf_multiply_82_base
{
public:
    void action(short data);
};

#endif /* OMITGOOD */

}
