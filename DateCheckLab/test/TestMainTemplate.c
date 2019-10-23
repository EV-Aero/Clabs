/*
 *  TestMainTemplate.c
 *  Created on: 16 Sep 2019
 *  Author: Kjell Carlsson
 */
#include <stdio.h>

#include "SimpleCTester.h"
#include "../src/DateCheckLab.h"

SimpleTest_Initialize()					// Counters for all tests are reset here

/*********************************** Tests ***********************************/

/// supply name of your test as parameter
SimpleTest_CreateTest(test_verifydate)  	// Single test creation
{
	// define your test by calling functions from test target
	Date temp = {2019,10,19};
	_Bool ok = verifydate(temp);
    /// assert that the outcome of your call matches expected outcome
    SimpleTest_AssertTrue(ok, "the outcome is not correct");

    //SimpleTest_AssertString(<< CALCULATED VALUE >>, << EXPECTED VALUE >>, "<< ERROR MSG >>");
}
SimpleTest_FinalizeTest()

SimpleTest_CreateTest(test_verifyleap)  	// Single test creation
{
	// define your test by calling functions from test target
	Date temp = {2012,10,19};
	_Bool ok = verifydate(temp);
    /// assert that the outcome of your call matches expected outcome
    SimpleTest_AssertTrue(ok, "the outcome is not correct");

    //SimpleTest_AssertString(<< CALCULATED VALUE >>, << EXPECTED VALUE >>, "<< ERROR MSG >>");
}
SimpleTest_FinalizeTest()

SimpleTest_CreateTest(test_leapdate)  	// Single test creation
{
	// define your test by calling functions from test target
	Date temp = {2012,02,29};
	_Bool ok = verifydate(temp);
    /// assert that the outcome of your call matches expected outcome
    SimpleTest_AssertTrue(ok, "the outcome is not correct");

    //SimpleTest_AssertString(<< CALCULATED VALUE >>, << EXPECTED VALUE >>, "<< ERROR MSG >>");
}
SimpleTest_FinalizeTest()

SimpleTest_CreateTest(test_wrong)  	// Single test creation
{
	// define your test by calling functions from test target
	Date temp = {2012,02,30};
	_Bool ok = verifydate(temp);
    /// assert that the outcome of your call matches expected outcome
    SimpleTest_AssertTrue(ok, "the outcome is not correct");

    //SimpleTest_AssertString(<< CALCULATED VALUE >>, << EXPECTED VALUE >>, "<< ERROR MSG >>");
}
SimpleTest_FinalizeTest()


/// Repeat the pattern above for all your tests for test target

/*********************************** Batch ***********************************/

// This is where we add up all tests to be run
static char* test_batch()
{
    /// supply info for presentation of outcome of test batch
    printf("\n Running tests for %s \n", "DateCheckLab");

    /// supply name of each test as parameter
    SimpleTest_RunTest(test_verifydate);	// One test runs
    SimpleTest_RunTest(test_verifyleap);	// One test runs
    SimpleTest_RunTest(test_leapdate);	// One test runs
    SimpleTest_RunTest(test_wrong);	// One test runs

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
