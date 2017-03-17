/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE273_Improper_Check_for_Dropped_Privileges__w32_RpcImpersonateClient_10.c
Label Definition File: CWE273_Improper_Check_for_Dropped_Privileges__w32.label.xml
Template File: point-flaw-10.tmpl.c
*/
/*
 * @description
 * CWE: 273 Improper Check for Dropped Privileges
 * Sinks: RpcImpersonateClient
 *    GoodSink: Check the return value of RpcImpersonateClient() and handle it properly
 *    BadSink : Do not check if RpcImpersonateClient() fails
 * Flow Variant: 10 Control flow: if(globalTrue) and if(globalFalse)
 *
 * */

#include "std_testcase.h"

#include <windows.h>

#include <rpcdce.h>
# pragma comment(lib, "rpcrt4")

#ifndef OMITBAD

void CWE273_Improper_Check_for_Dropped_Privileges__w32_RpcImpersonateClient_10_bad()
{
    if(globalTrue)
    {
        RpcImpersonateClient(0);
        /* FLAW: Do not check if RpcImpersonateClient() fails */
        /* We'll leave out most of the implementation since it has nothing to do with the CWE
         * and since the checkers are looking for certain function calls anyway */
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() uses if(globalFalse) instead of if(globalTrue) */
static void good1()
{
    if(globalFalse)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* FIX: Check the return value of RpcImpersonateClient() for RPC_S_OK */
        if (RpcImpersonateClient(0) != RPC_S_OK)
        {
            exit(1);
        }
        /* We'll leave out most of the implementation since it has nothing to do with the CWE
         * and since the checkers are looking for certain function calls anyway */
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(globalTrue)
    {
        /* FIX: Check the return value of RpcImpersonateClient() for RPC_S_OK */
        if (RpcImpersonateClient(0) != RPC_S_OK)
        {
            exit(1);
        }
        /* We'll leave out most of the implementation since it has nothing to do with the CWE
         * and since the checkers are looking for certain function calls anyway */
    }
}

void CWE273_Improper_Check_for_Dropped_Privileges__w32_RpcImpersonateClient_10_good()
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
    CWE273_Improper_Check_for_Dropped_Privileges__w32_RpcImpersonateClient_10_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE273_Improper_Check_for_Dropped_Privileges__w32_RpcImpersonateClient_10_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
