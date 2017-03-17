/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_src_char_cat_81.h
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_src.label.xml
Template File: sources-sink-81.tmpl.h
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Initialize data as a large string
 * GoodSource: Initialize data as a small string
 * Sinks: cat
 *    BadSink : Copy data to string using strcat
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE122_Heap_Based_Buffer_Overflow__c_src_char_cat_81
{

class CWE122_Heap_Based_Buffer_Overflow__c_src_char_cat_81_base
{
public:
    /* pure virtual function */
    virtual void action(char * data) const = 0;
};

#ifndef OMITBAD

class CWE122_Heap_Based_Buffer_Overflow__c_src_char_cat_81_bad : public CWE122_Heap_Based_Buffer_Overflow__c_src_char_cat_81_base
{
public:
    void action(char * data) const;
};

#endif /* OMITBAD */

#ifndef OMITGOOD

class CWE122_Heap_Based_Buffer_Overflow__c_src_char_cat_81_goodG2B : public CWE122_Heap_Based_Buffer_Overflow__c_src_char_cat_81_base
{
public:
    void action(char * data) const;
};

#endif /* OMITGOOD */

}
