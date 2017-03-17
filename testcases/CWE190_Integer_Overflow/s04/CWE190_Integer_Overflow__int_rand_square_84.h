/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__int_rand_square_84.h
Label Definition File: CWE190_Integer_Overflow__int.label.xml
Template File: sources-sinks-84.tmpl.h
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: rand Set data to result of rand(), which may be zero
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: square
 *    GoodSink: Ensure there will not be an overflow before squaring data
 *    BadSink : Square data, which can lead to overflow
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */

#include "std_testcase.h"

namespace CWE190_Integer_Overflow__int_rand_square_84
{

#ifndef OMITBAD

class CWE190_Integer_Overflow__int_rand_square_84_bad
{
public:
    CWE190_Integer_Overflow__int_rand_square_84_bad(int dataCopy);
    ~CWE190_Integer_Overflow__int_rand_square_84_bad();

private:
    int data;
};

#endif /* OMITBAD */

#ifndef OMITGOOD

class CWE190_Integer_Overflow__int_rand_square_84_goodG2B
{
public:
    CWE190_Integer_Overflow__int_rand_square_84_goodG2B(int dataCopy);
    ~CWE190_Integer_Overflow__int_rand_square_84_goodG2B();

private:
    int data;
};

class CWE190_Integer_Overflow__int_rand_square_84_goodB2G
{
public:
    CWE190_Integer_Overflow__int_rand_square_84_goodB2G(int dataCopy);
    ~CWE190_Integer_Overflow__int_rand_square_84_goodB2G();

private:
    int data;
};

#endif /* OMITGOOD */

}
