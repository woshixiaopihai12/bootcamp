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
#include <utility/vector1.hh>


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
    
    utility::vector1< std::pair< core::Size, core::Size > >
    identify_secondary_structure_spans( std::string const & secstruct_codes ){
        utility::vector1< std::pair< core::Size, core::Size > > secondary_structure;
        core::Size start;
        for( core::Size iter = 0; iter < secstruct_codes.size()-1; ++iter){
            if (secstruct_codes[iter] =='H' || secstruct_codes[iter] == 'E'){
                start = iter;
                while (secstruct_codes[iter] == secstruct_codes[start]) {
                ++iter;
                }
        
            std::pair< core::Size, core::Size > newpair(start+1, iter);
            secondary_structure.push_back(newpair);
            --iter;
            }
        }//for
        return secondary_structure;
    }//end function

    void test_identify_secondary_structure_spans(){
        std::string str = "   EEEEE   HHHHHHHH  EEEEE   IGNOR EEEEEE   HHHHHHHHHHH  EEEEE  HHHH   ";
        utility::vector1< std::pair< core::Size, core::Size > > test_result = identify_secondary_structure_spans(str);
        std::cout<<test_result<<std::endl;
        str = "EEEEEEEEE EEEEEEEE EEEEEEEEE H EEEEE H H H EEEEEEEE";
        test_result = identify_secondary_structure_spans(str);
        std::cout<<test_result<<std::endl;
        str="HHHHHHH   HHHHHHHHHHHH      HHHHHHHHHHHHEEEEEEEEEEHHHHHHH EEEEHHH ";
        test_result = identify_secondary_structure_spans(str);
        std::cout<<test_result;
        TS_ASSERT(true);
    }
	
};





