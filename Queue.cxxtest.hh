// -*- mode:c++;tab-width:2;indent-tabs-mode:t;show-trailing-whitespace:t;rm-trailing-spaces:t -*-
// vi: set ts=2 noet:
//
// (c) Copyright Rosetta Commons Member Institutions.
// (c) This file is part of the Rosetta software suite and is made available under license.
// (c) The Rosetta software is developed by the contributing members of the Rosetta Commons.
// (c) For more information, see http://www.rosettacommons.org. Questions about this can be
// (c) addressed to University of Washington UW TechTransfer, email: license@u.washington.edu.
/// @file		test/protocols/bootcamp/Queue.cxxtest.hh
///
/// @brief		Unit test for find neighbors code - Modified 6/3/14
/// @author	Can Li
// Test Headers
#include <cxxtest/TestSuite.h>
#include <test/core/init_util.hh>
#include <assert.h>
#include <protocols/bootcamp/Queue.hh>
#include <string>
#include <iostream>

class QueueTests : public CxxTest::TestSuite {
    
public:
    
    void setUp() {
        core_init();
    }
    
    void tearDown() {}
    
    void test_first() {
        TS_TRACE( "Running my first unit test!" );
        TS_ASSERT( true );
    }
    
    void test_enqueue() {
        std::cout<<"run test enqueue";
        std::string s;
        s="a";
        for ( core::Size i=1; i<=5; ++i) {
            new_queue.enqueue(s);
            s[0] = ++s[0];
            TS_ASSERT( new_queue.size()==i );
        }
        TS_TRACE( "Done running test_enqueue ");
        std::string b= "a";
        for ( core::Size i=1; i<=5 ; ++i ) {
            TS_ASSERT( new_queue.dequeue() == b );
            b[0]=++b[0];
        }
    }
    
    void test_dequeue(){
       
        TS_TRACE( "Done running test_dequeue" );
        
    }
private:
    protocols::bootcamp::Queue new_queue;
};