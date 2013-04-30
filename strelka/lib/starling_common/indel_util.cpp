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
///
/// \author Chris Saunders
///

#include "starling_common/indel_util.hh"



bool
is_indel_conflict(const indel_key& ik1,
                  const indel_key& ik2) {

    // add one to the end_pos of all indels to prevent immediately
    // adjacent indels in the final alignments:
    pos_range pr1(ik1.open_pos_range());
    pr1.end_pos++;
    pos_range pr2(ik2.open_pos_range());
    pr2.end_pos++;

    return pr1.is_range_intersect(pr2);
}



bool
is_range_intersect_indel_breakpoints(const known_pos_range read_pr,
                                     const indel_key& ik) {

    if(read_pr.is_range_intersect(pos_range(ik.pos,ik.pos))) return true;
    const pos_t rpos(ik.right_pos());
    if(ik.pos==rpos) return false;
    return read_pr.is_range_intersect(pos_range(rpos,rpos));
}
