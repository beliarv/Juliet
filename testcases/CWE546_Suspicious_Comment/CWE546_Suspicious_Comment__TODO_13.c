/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE546_Suspicious_Comment__TODO_13.c
Label Definition File: CWE546_Suspicious_Comment.label.xml
Template File: point-flaw-13.tmpl.c
*/
/*
 * @description
 * CWE: 546 Suspicious Comment
 * Sinks: TODO
 *    GoodSink: Comments show no indications that the code is unfinished
 *    BadSink : Comment contains the word TODO
 * Flow Variant: 13 Control flow: if(GLOBAL_CONST_FIVE==5) and if(GLOBAL_CONST_FIVE!=5)
 *
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE546_Suspicious_Comment__TODO_13_bad()
{
    if(GLOBAL_CONST_FIVE==5)
    {
        /* FLAW: The following comment has the letters 'TODO' in it*/
        /* TODO: This comment has the letters 'TODO' in it, which is certainly
         * suspicious, because it could indicate this code is not finished.
         */
        printLine("Hello");
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() uses if(GLOBAL_CONST_FIVE!=5) instead of if(GLOBAL_CONST_FIVE==5) */
static void good1()
{
    if(GLOBAL_CONST_FIVE!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* FIX: Removed the suspicious comments */
        printLine("Hello");
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(GLOBAL_CONST_FIVE==5)
    {
        /* FIX: Removed the suspicious comments */
        printLine("Hello");
    }
}

void CWE546_Suspicious_Comment__TODO_13_good()
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
    CWE546_Suspicious_Comment__TODO_13_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE546_Suspicious_Comment__TODO_13_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
