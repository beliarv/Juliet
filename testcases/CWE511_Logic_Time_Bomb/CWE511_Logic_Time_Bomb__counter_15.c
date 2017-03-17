/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE511_Logic_Time_Bomb__counter_15.c
Label Definition File: CWE511_Logic_Time_Bomb.label.xml
Template File: point-flaw-15.tmpl.c
*/
/*
 * @description
 * CWE: 511 Logic Time Bomb
 * Sinks: counter
 *    GoodSink: If counter reaches a certain value, do something harmless
 *    BadSink : If counter reaches a certain value, do something bad
 * Flow Variant: 15 Control flow: switch(6)
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
#define UNLINK _unlink
#else
#include <unistd.h>
#define UNLINK unlink
#endif

#define COUNT_CHECK 20000

#ifndef OMITBAD

void CWE511_Logic_Time_Bomb__counter_15_bad()
{
    switch(6)
    {
    case 6:
    {
        int count = 0;
        do
        {
            /* FLAW: If a counter reaches a certain value, delete a file */
            if (count == COUNT_CHECK)
            {
                UNLINK("important_file.txt");
            }
            count++;
        }
        while(1 == 1);   /* infinite loop */
    }
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
        break;
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() changes the switch to switch(5) */
static void good1()
{
    switch(5)
    {
    case 6:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
        break;
    default:
    {
        int count = 0;
        do
        {
            /* FIX: If a counter reaches a certain value, print to the console */
            if (count == COUNT_CHECK)
            {
                printLine("Happy New Year!");
            }
            count++;
        }
        while(1 == 1);   /* infinite loop */
    }
    break;
    }
}

/* good2() reverses the blocks in the switch */
static void good2()
{
    switch(6)
    {
    case 6:
    {
        int count = 0;
        do
        {
            /* FIX: If a counter reaches a certain value, print to the console */
            if (count == COUNT_CHECK)
            {
                printLine("Happy New Year!");
            }
            count++;
        }
        while(1 == 1);   /* infinite loop */
    }
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
        break;
    }
}

void CWE511_Logic_Time_Bomb__counter_15_good()
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
    CWE511_Logic_Time_Bomb__counter_15_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE511_Logic_Time_Bomb__counter_15_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
