/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__short_rand_sub_84.h
Label Definition File: CWE191_Integer_Underflow.label.xml
Template File: sources-sinks-84.tmpl.h
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: rand Set data to result of rand()
 * GoodSource: Set data to a small, non-zero number (negative two)
 * Sinks: sub
 *    GoodSink: Ensure there will not be an underflow before subtracting 1 from data
 *    BadSink : Subtract 1 from data, which can cause an Underflow
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */

#include "std_testcase.h"

namespace CWE191_Integer_Underflow__short_rand_sub_84
{

#ifndef OMITBAD

class CWE191_Integer_Underflow__short_rand_sub_84_bad
{
public:
    CWE191_Integer_Underflow__short_rand_sub_84_bad(short dataCopy);
    ~CWE191_Integer_Underflow__short_rand_sub_84_bad();

private:
    short data;
};

#endif /* OMITBAD */

#ifndef OMITGOOD

class CWE191_Integer_Underflow__short_rand_sub_84_goodG2B
{
public:
    CWE191_Integer_Underflow__short_rand_sub_84_goodG2B(short dataCopy);
    ~CWE191_Integer_Underflow__short_rand_sub_84_goodG2B();

private:
    short data;
};

class CWE191_Integer_Underflow__short_rand_sub_84_goodB2G
{
public:
    CWE191_Integer_Underflow__short_rand_sub_84_goodB2G(short dataCopy);
    ~CWE191_Integer_Underflow__short_rand_sub_84_goodB2G();

private:
    short data;
};

#endif /* OMITGOOD */

}
