/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE606_Unchecked_Loop_Condition__wchar_t_connect_socket_81_bad.cpp
Label Definition File: CWE606_Unchecked_Loop_Condition.label.xml
Template File: sources-sinks-81_bad.tmpl.cpp
*/
/*
 * @description
 * CWE: 606 Unchecked Input For Loop Condition
 * BadSource: connect_socket Read data using a connect socket (client side)
 * GoodSource: Input a number less than MAX_LOOP
 * Sinks:
 *    GoodSink: Use data as the for loop variant after checking to see if it is less than MAX_LOOP
 *    BadSink : Use data as the for loop variant without checking its size
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */
#ifndef OMITBAD

#include "std_testcase.h"
#include "CWE606_Unchecked_Loop_Condition__wchar_t_connect_socket_81.h"

namespace CWE606_Unchecked_Loop_Condition__wchar_t_connect_socket_81
{

void CWE606_Unchecked_Loop_Condition__wchar_t_connect_socket_81_bad::action(wchar_t * data) const
{
    {
        int i, n, intVariable;
        if (swscanf(data, L"%d", &n) == 1)
        {
            /* POTENTIAL FLAW: user-supplied value 'n' could lead to very large loop iteration */
            intVariable = 0;
            for (i = 0; i < n; i++)
            {
                /* INCIDENTAL: CWE 561: Dead Code - non-avoidable if n <= 0 */
                intVariable++; /* avoid a dead/empty code block issue */
            }
            printIntLine(intVariable);
        }
    }
}

}
#endif /* OMITBAD */
