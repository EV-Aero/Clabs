/*
 *  TestMainTemplate.c
 *  Created on: 16 Sep 2019
 *  Author: Kjell Carlsson
 */
#include <stdio.h>

#include "../../../git/CLabs/DateCheckLab/test/SimpleCTester.h"
#include "../src/DateCheckLab.h"

SimpleTest_Initialize()					// Counters for all tests are reset here

/*********************************** Tests ***********************************/

/// supply name of your test as parameter
SimpleTest_CreateTest(test_verifydate)  	// Single test creation
{
	// define your test by calling functions from test target


    /// assert that the outcome of your call matches expected outcome
    SimpleTest_AssertInteger(<<input>>), <<input>>, "the outcome is not correct");

    //SimpleTest_AssertString(<< CALCULATED VALUE >>, << EXPECTED VALUE >>, "<< ERROR MSG >>");
}
SimpleTest_FinalizeTest()

SimpleTest_CreateTest(test_leapyear)  	// Single test creation
{
	// define your test by calling functions from test target


    /// assert that the outcome of your call matches expected outcome
    SimpleTest_AssertInteger(<<input>>), <<input>>, "the outcome is not correct");

    //SimpleTest_AssertString(<< CALCULATED VALUE >>, << EXPECTED VALUE >>, "<< ERROR MSG >>");
}
SimpleTest_FinalizeTest()				// End of test


/// Repeat the pattern above for all your tests for test target

/*********************************** Batch ***********************************/

// This is where we add up all tests to be run
static char* test_batch()
{
    /// supply info for presentation of outcome of test batch
    printf("\n Running tests for %s \n", "DateCheckLab");

    /// supply name of each test as parameter
    SimpleTest_RunTest(test_verifydate);	// One test runs
    SimpleTest_RunTest(test_leapyear);	// One test runs

    return NULL;
}

/************************** Test application main ****************************/
int main(int argc, char **argv)
{
    test_batch();						// complete batch of tests will be run

    printf("\n\n Tests completed: %d", SimpleTestCounter);	// always present total number of tests run

    if( SimpleTestFailCounter == 0){
    	printf("\n All tests passed!"); 			// if batch is successful
    }
    else{
    	printf("\n Tests failed: %d", SimpleTestFailCounter); 	// otherwise the first failed test will be presented
    }

    return 0;
}
