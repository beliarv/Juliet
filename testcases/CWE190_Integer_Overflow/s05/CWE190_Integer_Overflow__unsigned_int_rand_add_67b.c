/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__unsigned_int_rand_add_67b.c
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-67b.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: rand Set data to result of rand()
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: add
 *    GoodSink: Ensure there will not be an overflow before adding 1 to data
 *    BadSink : Add 1 to data, which can cause an overflow
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

typedef struct _CWE190_Integer_Overflow__unsigned_int_rand_add_67_structType
{
    unsigned int structFirst;
} CWE190_Integer_Overflow__unsigned_int_rand_add_67_structType;

#ifndef OMITBAD

void CWE190_Integer_Overflow__unsigned_int_rand_add_67b_badSink(CWE190_Integer_Overflow__unsigned_int_rand_add_67_structType myStruct)
{
    unsigned int data = myStruct.structFirst;
    {
        /* POTENTIAL FLAW: Adding 1 to data could cause an overflow */
        unsigned int result = data + 1;
        printUnsignedLine(result);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE190_Integer_Overflow__unsigned_int_rand_add_67b_goodG2BSink(CWE190_Integer_Overflow__unsigned_int_rand_add_67_structType myStruct)
{
    unsigned int data = myStruct.structFirst;
    {
        /* POTENTIAL FLAW: Adding 1 to data could cause an overflow */
        unsigned int result = data + 1;
        printUnsignedLine(result);
    }
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE190_Integer_Overflow__unsigned_int_rand_add_67b_goodB2GSink(CWE190_Integer_Overflow__unsigned_int_rand_add_67_structType myStruct)
{
    unsigned int data = myStruct.structFirst;
    /* FIX: Add a check to prevent an overflow from occurring */
    if (data < UINT_MAX)
    {
        unsigned int result = data + 1;
        printUnsignedLine(result);
    }
    else
    {
        printLine("data value is too large to perform arithmetic safely.");
    }
}

#endif /* OMITGOOD */
