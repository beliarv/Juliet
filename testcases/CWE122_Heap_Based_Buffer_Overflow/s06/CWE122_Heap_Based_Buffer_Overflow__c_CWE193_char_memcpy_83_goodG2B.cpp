/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_memcpy_83_goodG2B.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_CWE193.label.xml
Template File: sources-sink-83_goodG2B.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Allocate memory for a string, but do not allocate space for NULL terminator
 * GoodSource: Allocate enough memory for a string and the NULL terminator
 * Sinks: memcpy
 *    BadSink : Copy string to data using memcpy()
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */
#ifndef OMITGOOD

#include "std_testcase.h"
#include "CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_memcpy_83.h"

namespace CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_memcpy_83
{
CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_memcpy_83_goodG2B::CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_memcpy_83_goodG2B(char * dataCopy)
{
    data = dataCopy;
    /* FIX: Allocate space for a null terminator */
    data = (char *)malloc((10+1)*sizeof(char));
}

CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_memcpy_83_goodG2B::~CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_memcpy_83_goodG2B()
{
    {
        char source[10+1] = SRC_STRING;
        /* Copy length + 1 to include NUL terminator from source */
        /* POTENTIAL FLAW: data may not have enough space to hold source */
        memcpy(data, source, (strlen(source) + 1) * sizeof(char));
        printLine(data);
        free(data);
    }
}
}
#endif /* OMITGOOD */
