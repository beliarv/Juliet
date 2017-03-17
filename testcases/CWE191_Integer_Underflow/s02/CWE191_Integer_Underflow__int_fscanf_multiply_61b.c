/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__int_fscanf_multiply_61b.c
Label Definition File: CWE191_Integer_Underflow__int.label.xml
Template File: sources-sinks-61b.tmpl.c
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Set data to a small, non-zero number (negative two)
 * Sinks: multiply
 *    GoodSink: Ensure there will not be an underflow before multiplying data by 2
 *    BadSink : If data is negative, multiply by 2, which can cause an underflow
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

int CWE191_Integer_Underflow__int_fscanf_multiply_61b_badSource(int data)
{
    /* POTENTIAL FLAW: Read data from the console using fscanf() */
    fscanf(stdin, "%d", &data);
    return data;
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
int CWE191_Integer_Underflow__int_fscanf_multiply_61b_goodG2BSource(int data)
{
    /* FIX: Use a small, non-zero value that will not cause an integer underflow in the sinks */
    data = -2;
    return data;
}

/* goodB2G() uses the BadSource with the GoodSink */
int CWE191_Integer_Underflow__int_fscanf_multiply_61b_goodB2GSource(int data)
{
    /* POTENTIAL FLAW: Read data from the console using fscanf() */
    fscanf(stdin, "%d", &data);
    return data;
}

#endif /* OMITGOOD */
