/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE284_Improper_Access_Control__w32_char_CreateDesktop_17.c
Label Definition File: CWE284_Improper_Access_Control__w32.label.xml
Template File: point-flaw-17.tmpl.c
*/
/*
 * @description
 * CWE: 284 Improper Access Control
 * Sinks: CreateDesktop
 *    GoodSink: Create a desktop using CreateDesktopA() without excessive privileges
 *    BadSink : Create a desktop using CreateDesktopA() with excessive privileges
 * Flow Variant: 17 Control flow: for loops
 *
 * */

#include "std_testcase.h"

#include <windows.h>
#pragma comment( lib, "user32" )

#ifndef OMITBAD

void CWE284_Improper_Access_Control__w32_char_CreateDesktop_17_bad()
{
    int j;
    for(j = 0; j < 1; j++)
    {
        {
            HDESK hDesk;
            char * desktopName = "DesktopExample";
            /* FLAW: Call CreateDesktopA() with GENERIC_ALL as the 5th parameter */
            hDesk = CreateDesktopA(
                        desktopName,
                        NULL,
                        NULL,
                        0,
                        GENERIC_ALL,
                        NULL);
            if (hDesk == NULL)
            {
                printLine("Desktop could not be created");
            }
            else
            {
                printLine("Desktop created successfully");
                CloseDesktop(hDesk);
            }
        }
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good1() uses the GoodSinkBody in the for statements */
static void good1()
{
    int k;
    for(k = 0; k < 1; k++)
    {
        {
            HDESK hDesk;
            char * desktopName = "DesktopExample";
            /* FIX: Call CreateDesktopA() without GENERIC_READ as the 5th parameter to limit access */
            hDesk = CreateDesktopA(
                        desktopName,
                        NULL,
                        NULL,
                        0,
                        GENERIC_READ,
                        NULL);
            if (hDesk == NULL)
            {
                printLine("Desktop could not be created");
            }
            else
            {
                printLine("Desktop created successfully");
                CloseDesktop(hDesk);
            }
        }
    }
}

void CWE284_Improper_Access_Control__w32_char_CreateDesktop_17_good()
{
    good1();
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
    CWE284_Improper_Access_Control__w32_char_CreateDesktop_17_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE284_Improper_Access_Control__w32_char_CreateDesktop_17_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
