/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE400_Resource_Exhaustion__fgets_sleep_84_goodB2G.cpp
Label Definition File: CWE400_Resource_Exhaustion.label.xml
Template File: sources-sinks-84_goodB2G.tmpl.cpp
*/
/*
 * @description
 * CWE: 400 Resource Exhaustion
 * BadSource: fgets Read data from the console using fgets()
 * GoodSource: Assign count to be a relatively small number
 * Sinks: sleep
 *    GoodSink: Validate count before using it as a parameter in sleep function
 *    BadSink : Use count as the parameter for sleep withhout checking it's size first
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */
#ifndef OMITGOOD

#include "std_testcase.h"
#include "CWE400_Resource_Exhaustion__fgets_sleep_84.h"

#define CHAR_ARRAY_SIZE (3 * sizeof(count) + 2)

#ifdef _WIN32
#include <windows.h>
#define SLEEP Sleep
#else
#include <unistd.h>
#define SLEEP usleep
#endif

namespace CWE400_Resource_Exhaustion__fgets_sleep_84
{
CWE400_Resource_Exhaustion__fgets_sleep_84_goodB2G::CWE400_Resource_Exhaustion__fgets_sleep_84_goodB2G(int countCopy)
{
    count = countCopy;
    {
        char inputBuffer[CHAR_ARRAY_SIZE] = "";
        /* POTENTIAL FLAW: Read count from the console using fgets() */
        if (fgets(inputBuffer, CHAR_ARRAY_SIZE, stdin) != NULL)
        {
            /* Convert to int */
            count = atoi(inputBuffer);
        }
        else
        {
            printLine("fgets() failed.");
        }
    }
}

CWE400_Resource_Exhaustion__fgets_sleep_84_goodB2G::~CWE400_Resource_Exhaustion__fgets_sleep_84_goodB2G()
{
    /* FIX: Validate count before using it as a parameter in the sleep function */
    if (count > 0 && count <= 2000)
    {
        SLEEP(count);
        printLine("Sleep time OK");
    }
    else
    {
        printLine("Sleep time too long");
    }
}
}
#endif /* OMITGOOD */
