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
#ifndef __STAT_UTIL_HH
#define __STAT_UTIL_HH

bool
is_chi_sqr_reject(const double xsq,
                  const unsigned df,
                  const double alpha);

bool
is_lrt_reject_null(const double null_loghood,
                   const double alt_loghood,
                   const unsigned df,
                   const double alpha);

#endif
