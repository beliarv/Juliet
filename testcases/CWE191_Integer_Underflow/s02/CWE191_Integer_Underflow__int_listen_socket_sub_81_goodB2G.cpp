/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__int_listen_socket_sub_81_goodB2G.cpp
Label Definition File: CWE191_Integer_Underflow__int.label.xml
Template File: sources-sinks-81_goodB2G.tmpl.cpp
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: listen_socket Read data using a listen socket (server side)
 * GoodSource: Set data to a small, non-zero number (negative two)
 * Sinks: sub
 *    GoodSink: Ensure there will not be an underflow before subtracting 1 from data
 *    BadSink : Subtract 1 from data, which can cause an Underflow
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */
#ifndef OMITGOOD

#include "std_testcase.h"
#include "CWE191_Integer_Underflow__int_listen_socket_sub_81.h"

namespace CWE191_Integer_Underflow__int_listen_socket_sub_81
{

void CWE191_Integer_Underflow__int_listen_socket_sub_81_goodB2G::action(int data) const
{
    /* FIX: Add a check to prevent an underflow from occurring */
    if (data > INT_MIN)
    {
        int result = data - 1;
        printIntLine(result);
    }
    else
    {
        printLine("data value is too large to perform subtraction.");
    }
}

}
#endif /* OMITGOOD */
