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

#ifndef __STARLING_REF_SEQ_HH
#define __STARLING_REF_SEQ_HH

#include "starling_common/starling_shared.hh"

#include <string>


void
get_starling_ref_seq(const starling_options& opt,
                     reference_contig_segment& ref);


#endif
