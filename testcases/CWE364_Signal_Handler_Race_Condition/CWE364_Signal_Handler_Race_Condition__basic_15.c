/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE364_Signal_Handler_Race_Condition__basic_15.c
Label Definition File: CWE364_Signal_Handler_Race_Condition__basic.label.xml
Template File: point-flaw-15.tmpl.c
*/
/*
 * @description
 * CWE: 364 Signal Handler Race Condition
 * Sinks:
 *    GoodSink: Disable the signal handler while performing non-atomic operations
 *    BadSink : Do not disable the signal handler while performing non-atomic operations
 * Flow Variant: 15 Control flow: switch(6)
 *
 * */

#include "std_testcase.h"

#include <signal.h>

typedef struct _structSigAtomic
{
    sig_atomic_t val;
}   structSigAtomic;

structSigAtomic *CWE364_Signal_Handler_Race_Condition__basic_15StructSigAtomicBad = NULL;
structSigAtomic *CWE364_Signal_Handler_Race_Condition__basic_15StructSigAtomicGood = NULL;

static void helperBad(int sig)
{
    if (CWE364_Signal_Handler_Race_Condition__basic_15StructSigAtomicBad != NULL)
    {
        CWE364_Signal_Handler_Race_Condition__basic_15StructSigAtomicBad->val = 2;
    }
}

static void helperGood(int sig)
{
    if (CWE364_Signal_Handler_Race_Condition__basic_15StructSigAtomicGood != NULL)
    {
        CWE364_Signal_Handler_Race_Condition__basic_15StructSigAtomicGood->val = 2;
    }
}

#ifndef OMITBAD

void CWE364_Signal_Handler_Race_Condition__basic_15_bad()
{
    switch(6)
    {
    case 6:
    {
        structSigAtomic *gStructSigAtomic = NULL;
        signal(SIGINT, SIG_DFL);
        if (CWE364_Signal_Handler_Race_Condition__basic_15StructSigAtomicBad != NULL)
        {
            free(CWE364_Signal_Handler_Race_Condition__basic_15StructSigAtomicBad);
            CWE364_Signal_Handler_Race_Condition__basic_15StructSigAtomicBad = NULL;
        }
        gStructSigAtomic = (structSigAtomic*)malloc(sizeof(structSigAtomic));
        /* INCIDENTAL - No check for NULL on malloc() */
        CWE364_Signal_Handler_Race_Condition__basic_15StructSigAtomicBad = gStructSigAtomic;
        CWE364_Signal_Handler_Race_Condition__basic_15StructSigAtomicBad->val = 1;
        /* Assign CWE364_Signal_Handler_Race_Condition__basic_15StructSigAtomicBad BEFORE
         * calling 'signal', because pointer types are not (according to spec), atomic
         * with respect to signals.
         *
         * In practice they are on most (all?) POSIX-y computers, but thems the
         * rules
         */
        signal(SIGINT, helperBad);
        /* FLAW: This test, free, and set operation is not atomic, so if signal
         * delivery occurs (for example) between the free and setting to NULL,
         * the signal handler could corrupt the heap, cause an access violation,
         * etc
         *
         * Technically, "CWE364_Signal_Handler_Race_Condition__basic_15StructSigAtomicBad = 0" is not atomic on certain theoretical computer
         * systems that don't actually exist, but this should trigger on
         * theoretical as well as actual computer systems.
         */
        if (CWE364_Signal_Handler_Race_Condition__basic_15StructSigAtomicBad != NULL)
        {
            free(CWE364_Signal_Handler_Race_Condition__basic_15StructSigAtomicBad);
            CWE364_Signal_Handler_Race_Condition__basic_15StructSigAtomicBad = NULL;
        }
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
        structSigAtomic *gStructSigAtomic = NULL;
        signal(SIGINT, SIG_DFL);
        if (CWE364_Signal_Handler_Race_Condition__basic_15StructSigAtomicGood != NULL)
        {
            free(CWE364_Signal_Handler_Race_Condition__basic_15StructSigAtomicGood);
            CWE364_Signal_Handler_Race_Condition__basic_15StructSigAtomicGood = 0;
        }
        gStructSigAtomic = (structSigAtomic*)malloc(sizeof(structSigAtomic));
        /* INCIDENTAL - No check for NULL on malloc() */
        CWE364_Signal_Handler_Race_Condition__basic_15StructSigAtomicGood = gStructSigAtomic;
        CWE364_Signal_Handler_Race_Condition__basic_15StructSigAtomicGood->val = 1;
        /* Assign CWE364_Signal_Handler_Race_Condition__basic_15StructSigAtomicGood BEFORE
         * calling 'signal', because pointer types are not (according to spec), atomic
         * with respect to signals.
         *
         * In practice they are on most (all?) POSIX-y computers, but thems the
         * rules
         */
        signal(SIGINT, helperGood);
        /* FIX: In this instance, the fix is to temporarily disable the signal
         * handler while performing non-atomic operations.  Another way would
         * be to use sigprocmask or sigvec, or to restructure the signal handler
         * to operate in a safe manner.
         */
        signal(SIGINT, SIG_DFL);
        if (CWE364_Signal_Handler_Race_Condition__basic_15StructSigAtomicGood != NULL)
        {
            free(CWE364_Signal_Handler_Race_Condition__basic_15StructSigAtomicGood);
            CWE364_Signal_Handler_Race_Condition__basic_15StructSigAtomicGood = NULL;
        }
        signal(SIGINT, helperGood);
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
        structSigAtomic *gStructSigAtomic = NULL;
        signal(SIGINT, SIG_DFL);
        if (CWE364_Signal_Handler_Race_Condition__basic_15StructSigAtomicGood != NULL)
        {
            free(CWE364_Signal_Handler_Race_Condition__basic_15StructSigAtomicGood);
            CWE364_Signal_Handler_Race_Condition__basic_15StructSigAtomicGood = 0;
        }
        gStructSigAtomic = (structSigAtomic*)malloc(sizeof(structSigAtomic));
        /* INCIDENTAL - No check for NULL on malloc() */
        CWE364_Signal_Handler_Race_Condition__basic_15StructSigAtomicGood = gStructSigAtomic;
        CWE364_Signal_Handler_Race_Condition__basic_15StructSigAtomicGood->val = 1;
        /* Assign CWE364_Signal_Handler_Race_Condition__basic_15StructSigAtomicGood BEFORE
         * calling 'signal', because pointer types are not (according to spec), atomic
         * with respect to signals.
         *
         * In practice they are on most (all?) POSIX-y computers, but thems the
         * rules
         */
        signal(SIGINT, helperGood);
        /* FIX: In this instance, the fix is to temporarily disable the signal
         * handler while performing non-atomic operations.  Another way would
         * be to use sigprocmask or sigvec, or to restructure the signal handler
         * to operate in a safe manner.
         */
        signal(SIGINT, SIG_DFL);
        if (CWE364_Signal_Handler_Race_Condition__basic_15StructSigAtomicGood != NULL)
        {
            free(CWE364_Signal_Handler_Race_Condition__basic_15StructSigAtomicGood);
            CWE364_Signal_Handler_Race_Condition__basic_15StructSigAtomicGood = NULL;
        }
        signal(SIGINT, helperGood);
    }
    break;
    default:
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
        break;
    }
}

void CWE364_Signal_Handler_Race_Condition__basic_15_good()
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
    CWE364_Signal_Handler_Race_Condition__basic_15_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE364_Signal_Handler_Race_Condition__basic_15_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
