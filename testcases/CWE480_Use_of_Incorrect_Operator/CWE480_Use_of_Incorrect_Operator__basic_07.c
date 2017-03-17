/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE480_Use_of_Incorrect_Operator__basic_07.c
Label Definition File: CWE480_Use_of_Incorrect_Operator__basic.label.xml
Template File: point-flaw-07.tmpl.c
*/
/*
 * @description
 * CWE: 480 Use of Incorrect Operator
 * Sinks:
 *    GoodSink: Include parens
 *    BadSink : Forget parens
 * Flow Variant: 07 Control flow: if(staticFive==5) and if(staticFive!=5)
 *
 * */

#include "std_testcase.h"

static char* staticStringBad = "Hello";
static char* staticStringGood = "Hello";

static char * helperBad()
{
    /* return NULL half the time and a pointer to our static string the other half */
    if(rand()%2 == 0)
    {
        return NULL;
    }
    else
    {
        return staticStringBad;
    }
}

static char * helperGood()
{
    /* return NULL half the time and a pointer to our static string the other half */
    if(rand()%2 == 0)
    {
        return NULL;
    }
    else
    {
        return staticStringGood;
    }
}

/* The variable below is not declared "const", but is never assigned
   any other value so a tool should be able to identify that reads of
   this will always give its initialized value. */
static int staticFive = 5;

#ifndef OMITBAD

void CWE480_Use_of_Incorrect_Operator__basic_07_bad()
{
    if(staticFive==5)
    {
        /* FLAW: This will never be true becuase the () was omitted.  Also INCIDENTAL CWE 570 Expression Is Always False */
        if(helperBad == NULL)
        {
            printLine("Got a NULL");
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() uses if(staticFive!=5) instead of if(staticFive==5) */
static void good1()
{
    if(staticFive!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* FIX: add () to function call */
        if(helperGood() == NULL) /* this will sometimes be true (depending on the rand() in helperGood) */
        {
            printLine("Got a NULL");
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(staticFive==5)
    {
        /* FIX: add () to function call */
        if(helperGood() == NULL) /* this will sometimes be true (depending on the rand() in helperGood) */
        {
            printLine("Got a NULL");
        }
    }
}

void CWE480_Use_of_Incorrect_Operator__basic_07_good()
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
    CWE480_Use_of_Incorrect_Operator__basic_07_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE480_Use_of_Incorrect_Operator__basic_07_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
