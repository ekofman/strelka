// -*- mode: c++; indent-tabs-mode: nil; -*-
//
// Copyright (c) 2009-2012 Illumina, Inc.
//
// This software is covered by the "Illumina Genome Analyzer Software
// License Agreement" and the "Illumina Source Code License Agreement",
// and certain third party copyright/licenses, and any user of this
// source file is bound by the terms therein (see accompanying files
// Illumina_Genome_Analyzer_Software_License_Agreement.pdf and
// Illumina_Source_Code_License_Agreement.pdf and third party
// copyright/license notices).
//
//

/// \file

/// \author Chris Saunders
///

#include "blt_util/bam_seq.hh"

#include <iostream>


std::ostream&
operator<<(std::ostream& os, 
           const bam_seq_base& bs) {

    const unsigned rs(bs.size());
    for(unsigned i(0);i<rs;++i){ os << bs.get_char(i); }
    return os;
}
