/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE338_Weak_PRNG__w32_09.c
Label Definition File: CWE338_Weak_PRNG__w32.label.xml
Template File: point-flaw-09.tmpl.c
*/
/*
 * @description
 * CWE: 338 Use of Cryptographically Weak PRNG
 * Sinks:
 *    GoodSink: Use CryptGenRandom() to generate a random number
 *    BadSink : Use rand() to generate a random number
 * Flow Variant: 09 Control flow: if(GLOBAL_CONST_TRUE) and if(GLOBAL_CONST_FALSE)
 *
 * */

#include "std_testcase.h"

#include <windows.h>
#include <wincrypt.h>
#pragma comment(lib, "advapi32.lib")

#ifndef OMITBAD

void CWE338_Weak_PRNG__w32_09_bad()
{
    if(GLOBAL_CONST_TRUE)
    {
        {
            /* FLAW: Use of rand() as a PRNG */
            int data = rand();
            printIntLine(data);
        }
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
        {
            HCRYPTPROV hCryptProv;
            int data;
            if (!CryptAcquireContextW(&hCryptProv, 0, 0, PROV_RSA_FULL, 0))
            {
                exit(1);
            }
            /* FIX: Use of CryptGenRandom() as a more secure PRNG */
            if (!CryptGenRandom(hCryptProv, sizeof(data), (BYTE *) &data))
            {
                CryptReleaseContext(hCryptProv, 0);
                exit(1);
            }
            if (hCryptProv)
            {
                CryptReleaseContext(hCryptProv, 0);
            }
            printIntLine(data);
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(GLOBAL_CONST_TRUE)
    {
        {
            HCRYPTPROV hCryptProv;
            int data;
            if (!CryptAcquireContextW(&hCryptProv, 0, 0, PROV_RSA_FULL, 0))
            {
                exit(1);
            }
            /* FIX: Use of CryptGenRandom() as a more secure PRNG */
            if (!CryptGenRandom(hCryptProv, sizeof(data), (BYTE *) &data))
            {
                CryptReleaseContext(hCryptProv, 0);
                exit(1);
            }
            if (hCryptProv)
            {
                CryptReleaseContext(hCryptProv, 0);
            }
            printIntLine(data);
        }
    }
}

void CWE338_Weak_PRNG__w32_09_good()
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
    CWE338_Weak_PRNG__w32_09_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE338_Weak_PRNG__w32_09_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
