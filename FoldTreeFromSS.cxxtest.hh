// -*- mode:c++;tab-width:2;indent-tabs-mode:t;show-trailing-whitespace:t;rm-trailing-spaces:t -*-
// vi: set ts=2 noet:
//
// (c) Copyright Rosetta Commons Member Institutions.
// (c) This file is part of the Rosetta software suite and is made available under license.
// (c) The Rosetta software is developed by the contributing members of the Rosetta Commons.
// (c) For more information, see http://www.rosettacommons.org. Questions about this can be
// (c) addressed to University of Washington UW TechTransfer, email: license@u.washington.edu.

/// @file   test/protocols/match/ProteinSCSampler.cxxtest.hh
/// @brief
/// @author Andrew Leaver-Fay (aleaverfay@gmail.com)


// Test headers
#include <cxxtest/TestSuite.h>


#include <test/util/pose_funcs.hh>
#include <test/core/init_util.hh>

// Utility headers
#include <utility/exit.hh>

/// Project headers
#include <core/types.hh>
#include <core/chemical/ResidueType.hh>
#include <core/conformation/Residue.hh>

// C++ headers
#include <string>
#include <iostream>

//Auto Headers
#include <core/pack/dunbrack/DunbrackRotamer.hh>
#include <utility/vector1.hh>



// --------------- Test Class --------------- //

class FoldTreeFromSSTests : public CxxTest::TestSuite {

public:


	void setUp() {
		core_init();
	}
    
    void test_hello_world(){
        TS_ASSERT("true");
    }

	
};
