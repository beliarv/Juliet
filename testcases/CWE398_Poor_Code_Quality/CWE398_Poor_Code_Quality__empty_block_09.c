/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE398_Poor_Code_Quality__empty_block_09.c
Label Definition File: CWE398_Poor_Code_Quality.label.xml
Template File: point-flaw-09.tmpl.c
*/
/*
 * @description
 * CWE: 398 Poor Code Quality
 * Sinks: empty_block
 *    GoodSink: Code block contains code
 *    BadSink : An empty code block has no effect
 * Flow Variant: 09 Control flow: if(GLOBAL_CONST_TRUE) and if(GLOBAL_CONST_FALSE)
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE398_Poor_Code_Quality__empty_block_09_bad()
{
    if(GLOBAL_CONST_TRUE)
    {
        /* FLAW: An empty block has no effect */
        {
        }
        printLine("Hello from bad()");
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() uses if(GLOBAL_CONST_FALSE) instead of if(GLOBAL_CONST_TRUE) */
static void good1()
{
    if(GLOBAL_CONST_FALSE)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* FIX: Do not include an empty block */
        {
            printLine("Inside the block");
        }
        printLine("Hello from good()");
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(GLOBAL_CONST_TRUE)
    {
        /* FIX: Do not include an empty block */
        {
            printLine("Inside the block");
        }
        printLine("Hello from good()");
    }
}

void CWE398_Poor_Code_Quality__empty_block_09_good()
{
    good1();
    good2();
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
    CWE398_Poor_Code_Quality__empty_block_09_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE398_Poor_Code_Quality__empty_block_09_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
