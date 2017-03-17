/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE126_Buffer_Overread__CWE129_fgets_81_goodB2G.cpp
Label Definition File: CWE126_Buffer_Overread__CWE129.label.xml
Template File: sources-sinks-81_goodB2G.tmpl.cpp
*/
/*
 * @description
 * CWE: 126 Buffer Overread
 * BadSource: fgets Read data from the console using fgets()
 * GoodSource: Larger than zero but less than 10
 * Sinks:
 *    GoodSink: Ensure the array index is valid
 *    BadSink : Improperly check the array index by not checking the upper bound
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */
#ifndef OMITGOOD

#include "std_testcase.h"
#include "CWE126_Buffer_Overread__CWE129_fgets_81.h"

namespace CWE126_Buffer_Overread__CWE129_fgets_81
{

void CWE126_Buffer_Overread__CWE129_fgets_81_goodB2G::action(int data) const
{
    {
        int buffer[10] = { 0 };
        /* FIX: Properly validate the array index and prevent a buffer overread */
        if (data >= 0 && data < (10))
        {
            printIntLine(buffer[data]);
        }
        else
        {
            printLine("ERROR: Array index is out-of-bounds");
        }
    }
}

}
#endif /* OMITGOOD */
