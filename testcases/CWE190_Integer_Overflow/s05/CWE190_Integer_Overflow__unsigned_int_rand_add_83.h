/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__unsigned_int_rand_add_83.h
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-83.tmpl.h
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: rand Set data to result of rand()
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: add
 *    GoodSink: Ensure there will not be an overflow before adding 1 to data
 *    BadSink : Add 1 to data, which can cause an overflow
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */

#include "std_testcase.h"

namespace CWE190_Integer_Overflow__unsigned_int_rand_add_83
{

#ifndef OMITBAD

class CWE190_Integer_Overflow__unsigned_int_rand_add_83_bad
{
public:
    CWE190_Integer_Overflow__unsigned_int_rand_add_83_bad(unsigned int dataCopy);
    ~CWE190_Integer_Overflow__unsigned_int_rand_add_83_bad();

private:
    unsigned int data;
};

#endif /* OMITBAD */

#ifndef OMITGOOD

class CWE190_Integer_Overflow__unsigned_int_rand_add_83_goodG2B
{
public:
    CWE190_Integer_Overflow__unsigned_int_rand_add_83_goodG2B(unsigned int dataCopy);
    ~CWE190_Integer_Overflow__unsigned_int_rand_add_83_goodG2B();

private:
    unsigned int data;
};

class CWE190_Integer_Overflow__unsigned_int_rand_add_83_goodB2G
{
public:
    CWE190_Integer_Overflow__unsigned_int_rand_add_83_goodB2G(unsigned int dataCopy);
    ~CWE190_Integer_Overflow__unsigned_int_rand_add_83_goodB2G();

private:
    unsigned int data;
};

#endif /* OMITGOOD */

}
