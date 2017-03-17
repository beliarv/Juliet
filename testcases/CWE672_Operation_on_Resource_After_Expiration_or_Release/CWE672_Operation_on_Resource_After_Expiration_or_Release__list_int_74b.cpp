/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_74b.cpp
Label Definition File: CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int.label.xml
Template File: sources-sinks-74b.tmpl.cpp
*/
/*
 * @description
 * CWE: 672 Operation on Resource After Expiration or Release
 * BadSource:  Add values to the list, including the number zero
 * GoodSource: Add value to the list that are not zero
 * Sinks:
 *    GoodSink: Iterate through the list without attempting to clear its contents
 *    BadSink : Iterate through the list, but clear the list if it contains a zero
 * Flow Variant: 74 Data flow: data passed in a map from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <map>

#include <wchar.h>
#include <list>
#include <iostream>

using namespace std;

using namespace std;

namespace CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_74
{

#ifndef OMITBAD

void badSink(map<int, list<int> > dataMap)
{
    /* copy data out of dataMap */
    list<int>  data = dataMap[2];
    {
        list<int> ::iterator i;
        cout << "The list contains: ";
        for( i = data.begin(); i != data.end(); i++)
        {
            if (!*i)
            {
                data.clear();
            }
            /* POTENTIAL FLAW: Dereference the iterator, which may be invalid if data is cleared */
            cout << " " << *i;
        }
        cout << endl;
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSink(map<int, list<int> > dataMap)
{
    list<int>  data = dataMap[2];
    {
        list<int> ::iterator i;
        cout << "The list contains: ";
        for( i = data.begin(); i != data.end(); i++)
        {
            if (!*i)
            {
                data.clear();
            }
            /* POTENTIAL FLAW: Dereference the iterator, which may be invalid if data is cleared */
            cout << " " << *i;
        }
        cout << endl;
    }
}

/* goodB2G uses the BadSource with the GoodSink */
void goodB2GSink(map<int, list<int> > dataMap)
{
    list<int>  data = dataMap[2];
    {
        list<int> ::iterator i;
        cout << "The list contains: ";
        for( i = data.begin(); i != data.end(); i++)
        {
            /* FIX: Do not make any attempt to clear the list */
            cout << " " << *i;
        }
        cout << endl;
    }
}

#endif /* OMITGOOD */

} /* close namespace */
