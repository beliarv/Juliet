/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE400_Resource_Exhaustion__rand_sleep_84_bad.cpp
Label Definition File: CWE400_Resource_Exhaustion.label.xml
Template File: sources-sinks-84_bad.tmpl.cpp
*/
/*
 * @description
 * CWE: 400 Resource Exhaustion
 * BadSource: rand Set data to result of rand(), which may be zero
 * GoodSource: Assign count to be a relatively small number
 * Sinks: sleep
 *    GoodSink: Validate count before using it as a parameter in sleep function
 *    BadSink : Use count as the parameter for sleep withhout checking it's size first
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */
#ifndef OMITBAD

#include "std_testcase.h"
#include "CWE400_Resource_Exhaustion__rand_sleep_84.h"

#ifdef _WIN32
#include <windows.h>
#define SLEEP Sleep
#else
#include <unistd.h>
#define SLEEP usleep
#endif

namespace CWE400_Resource_Exhaustion__rand_sleep_84
{
CWE400_Resource_Exhaustion__rand_sleep_84_bad::CWE400_Resource_Exhaustion__rand_sleep_84_bad(int countCopy)
{
    count = countCopy;
    /* POTENTIAL FLAW: Set count to a random value */
    count = RAND32();
}

CWE400_Resource_Exhaustion__rand_sleep_84_bad::~CWE400_Resource_Exhaustion__rand_sleep_84_bad()
{
    /* POTENTIAL FLAW: Sleep function using count as the parameter with no validation */
    SLEEP(count);
    printLine("Sleep time possibly too long");
}
}
#endif /* OMITBAD */
