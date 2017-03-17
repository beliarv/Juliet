/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE563_Unused_Variable__unused_init_variable_int64_t_17.c
Label Definition File: CWE563_Unused_Variable__unused_init_variable.label.xml
Template File: source-sinks-17.tmpl.c
*/
/*
 * @description
 * CWE: 563 Unused Variable
 * BadSource:  Initialize data
 * Sinks:
 *    GoodSink: Use data
 *    BadSink : do nothing
 * Flow Variant: 17 Control flow: for loops
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE563_Unused_Variable__unused_init_variable_int64_t_17_bad()
{
    int j;
    int64_t data;
    /* POTENTIAL FLAW: Initialize, but do not use data */
    data = 5LL;
    for(j = 0; j < 1; j++)
    {
        /* FLAW: Do not use the variable */
        /* do nothing */
        ; /* empty statement needed for some flow variants */
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G() - use the goodsink in the for statement */
static void goodB2G()
{
    int k;
    int64_t data;
    /* POTENTIAL FLAW: Initialize, but do not use data */
    data = 5LL;
    for(k = 0; k < 1; k++)
    {
        /* FIX: Use data */
        printLongLongLine(data);
    }
}

void CWE563_Unused_Variable__unused_init_variable_int64_t_17_good()
{
    goodB2G();
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
    CWE563_Unused_Variable__unused_init_variable_int64_t_17_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE563_Unused_Variable__unused_init_variable_int64_t_17_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
