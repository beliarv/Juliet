/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE400_Resource_Exhaustion__fscanf_for_loop_61b.c
Label Definition File: CWE400_Resource_Exhaustion.label.xml
Template File: sources-sinks-61b.tmpl.c
*/
/*
 * @description
 * CWE: 400 Resource Exhaustion
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Assign count to be a relatively small number
 * Sinks: for_loop
 *    GoodSink: Validate count before using it as the loop variant in a for loop
 *    BadSink : Use count as the loop variant in a for loop
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

int CWE400_Resource_Exhaustion__fscanf_for_loop_61b_badSource(int count)
{
    /* POTENTIAL FLAW: Read count from the console using fscanf() */
    fscanf(stdin, "%d", &count);
    return count;
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B() uses the GoodSource with the BadSink */
int CWE400_Resource_Exhaustion__fscanf_for_loop_61b_goodG2BSource(int count)
{
    /* FIX: Use a relatively small number */
    count = 20;
    return count;
}

/* goodB2G() uses the BadSource with the GoodSink */
int CWE400_Resource_Exhaustion__fscanf_for_loop_61b_goodB2GSource(int count)
{
    /* POTENTIAL FLAW: Read count from the console using fscanf() */
    fscanf(stdin, "%d", &count);
    return count;
}

#endif /* OMITGOOD */
