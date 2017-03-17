/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE563_Unused_Variable__unused_value_struct_09.c
Label Definition File: CWE563_Unused_Variable__unused_value.label.xml
Template File: sources-sinks-09.tmpl.c
*/
/*
 * @description
 * CWE: 563 Unused Variable
 * BadSource:  Initialize data
 * GoodSource: Initialize and use data
 * Sinks:
 *    GoodSink: Use data
 *    BadSink : Initialize and use data
 * Flow Variant: 09 Control flow: if(GLOBAL_CONST_TRUE) and if(GLOBAL_CONST_FALSE)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE563_Unused_Variable__unused_value_struct_09_bad()
{
    twoIntsStruct data;
    if(GLOBAL_CONST_TRUE)
    {
        /* POTENTIAL FLAW: Initialize, but do not use data */
        data.intOne = 0;
        data.intTwo = 0;
    }
    if(GLOBAL_CONST_TRUE)
    {
        /* POTENTIAL FLAW: Possibly over-write the initial value of data before using it */
        data.intOne = 1;
        data.intTwo = 1;
        printStructLine(&data);
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G1() - use badsource and goodsink by changing the second GLOBAL_CONST_TRUE to GLOBAL_CONST_FALSE */
static void goodB2G1()
{
    twoIntsStruct data;
    if(GLOBAL_CONST_TRUE)
    {
        /* POTENTIAL FLAW: Initialize, but do not use data */
        data.intOne = 0;
        data.intTwo = 0;
    }
    if(GLOBAL_CONST_FALSE)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* FIX: Use data without over-writing its value */
        printStructLine(&data);
    }
}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the second if */
static void goodB2G2()
{
    twoIntsStruct data;
    if(GLOBAL_CONST_TRUE)
    {
        /* POTENTIAL FLAW: Initialize, but do not use data */
        data.intOne = 0;
        data.intTwo = 0;
    }
    if(GLOBAL_CONST_TRUE)
    {
        /* FIX: Use data without over-writing its value */
        printStructLine(&data);
    }
}

/* goodG2B1() - use goodsource and badsink by changing the first GLOBAL_CONST_TRUE to GLOBAL_CONST_FALSE */
static void goodG2B1()
{
    twoIntsStruct data;
    if(GLOBAL_CONST_FALSE)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* FIX: Initialize and use data before it is overwritten */
        data.intOne = 0;
        data.intTwo = 0;
        printStructLine(&data);
    }
    if(GLOBAL_CONST_TRUE)
    {
        /* POTENTIAL FLAW: Possibly over-write the initial value of data before using it */
        data.intOne = 1;
        data.intTwo = 1;
        printStructLine(&data);
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the first if */
static void goodG2B2()
{
    twoIntsStruct data;
    if(GLOBAL_CONST_TRUE)
    {
        /* FIX: Initialize and use data before it is overwritten */
        data.intOne = 0;
        data.intTwo = 0;
        printStructLine(&data);
    }
    if(GLOBAL_CONST_TRUE)
    {
        /* POTENTIAL FLAW: Possibly over-write the initial value of data before using it */
        data.intOne = 1;
        data.intTwo = 1;
        printStructLine(&data);
    }
}

void CWE563_Unused_Variable__unused_value_struct_09_good()
{
    goodB2G1();
    goodB2G2();
    goodG2B1();
    goodG2B2();
}

#endif /* OMITGOOD */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE563_Unused_Variable__unused_value_struct_09_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE563_Unused_Variable__unused_value_struct_09_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
