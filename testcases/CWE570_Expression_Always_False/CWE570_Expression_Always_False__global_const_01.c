/*
 * @description Expression is always false via if (false_expression)
 * 
 * */

#include "std_testcase.h"

#ifndef OMITBAD

void CWE570_Expression_Always_False__global_const_01_bad() 
{
    /* FLAW: This expression is always false */
    if (GLOBAL_CONST_FALSE) 
    {
        printLine("Never prints");
    }
}

#endif /* OMITBAD */


#ifndef OMITGOOD

static void good1() 
{
    /* FIX: Possibly evaluate to true */
    if (globalReturnsTrueOrFalse() == GLOBAL_CONST_FALSE)
    {
        printLine("Sometimes prints");
    }
}

void CWE570_Expression_Always_False__global_const_01_good() 
{
    good1();
}

#endif /* OMITGOOD */

/* Below is the main(). It is only used when building this testcase on 
 * its own for testing or for building a binary to use in testing binary 
 * analysis tools. It is not used when compiling all the testcases as one 
 * application, which is how source code analysis tools are tested. 
 */ 

#ifdef INCLUDEMAIN

int main(int argc, char * argv[]) 
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );

#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE570_Expression_Always_False__global_const_01_good();
    printLine("Finished good()");
#endif /* OMITGOOD */

#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE570_Expression_Always_False__global_const_01_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */

    return 0;
} 

#endif
