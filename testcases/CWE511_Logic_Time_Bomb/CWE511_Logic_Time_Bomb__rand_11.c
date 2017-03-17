/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE511_Logic_Time_Bomb__rand_11.c
Label Definition File: CWE511_Logic_Time_Bomb.label.xml
Template File: point-flaw-11.tmpl.c
*/
/*
 * @description
 * CWE: 511 Logic Time Bomb
 * Sinks: rand
 *    GoodSink: If specific random number generated, do something harmless
 *    BadSink : If specific random number generated, do something bad
 * Flow Variant: 11 Control flow: if(globalReturnsTrue()) and if(globalReturnsFalse())
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
#define UNLINK _unlink
#else
#include <unistd.h>
#define UNLINK unlink
#endif

#define NUM_CHECK 20000

#ifndef OMITBAD

void CWE511_Logic_Time_Bomb__rand_11_bad()
{
    if(globalReturnsTrue())
    {
        srand((unsigned)time(NULL));
        /* FLAW: If a certain number, delete a file */
        if (rand() == NUM_CHECK)
        {
            UNLINK("important_file.txt");
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() uses if(globalReturnsFalse()) instead of if(globalReturnsTrue()) */
static void good1()
{
    if(globalReturnsFalse())
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        srand((unsigned)time(NULL));
        /* FIX: If a certain number, print to the console */
        if (rand() == NUM_CHECK)
        {
            printLine("Happy New Year!");
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(globalReturnsTrue())
    {
        srand((unsigned)time(NULL));
        /* FIX: If a certain number, print to the console */
        if (rand() == NUM_CHECK)
        {
            printLine("Happy New Year!");
        }
    }
}

void CWE511_Logic_Time_Bomb__rand_11_good()
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
    CWE511_Logic_Time_Bomb__rand_11_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE511_Logic_Time_Bomb__rand_11_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
