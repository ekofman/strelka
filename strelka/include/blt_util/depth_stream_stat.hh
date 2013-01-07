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
#ifndef __DEPTH_STREAM_STAT_HH
#define __DEPTH_STREAM_STAT_HH

#include <ciso646>
#include <cmath>

#include <iosfwd>
#include <limits>



/// \brief from the indel finder's single_pass mean/sd calculator:
///
struct depth_stream_stat {

    // Accumulate mean and standard dev using a single pass formula
    // Uses the cancellation-friendly formulae on p.26 of
    // Higham, Accuracy & Stability of Numerical Algorithms
    // Variable names follow his
    depth_stream_stat() : M_(0),Q_(0),max_(0),min_(0),k_(0),n_(0) {}

    void update (const unsigned d) {
        k_++;
        if(d!=0) n_++;
        if((k_==1) || (d>max_)) max_=d;
        if((k_==1) || (d<min_)) min_=d;

        // important to do M before Q as Q uses previous iterate of M
        const double delta(static_cast<double>(d)-M_);
        M_+=delta/static_cast<double>(k_);
        Q_+=delta*(static_cast<double>(d)-M_);
    }

    unsigned sample_size() const { return k_; }
    unsigned nonzero() const { return n_; }
    double min() const { return ((k_<1) ? std::numeric_limits<double>::quiet_NaN() : min_); }
    double max() const { return ((k_<1) ? std::numeric_limits<double>::quiet_NaN() : max_); }
    double mean() const { return ((k_<1) ? std::numeric_limits<double>::quiet_NaN() : M_); }
    double variance() const { return ((k_<2) ? std::numeric_limits<double>::quiet_NaN() : Q_/(static_cast<double>(k_-1))); }
    double sd() const { return std::sqrt(variance()); }
    double stderror() const { return sd()/std::sqrt(static_cast<double>(k_)); }

private:

    double M_;
    double Q_;
    unsigned max_;
    unsigned min_;
    unsigned k_;
    unsigned n_;
};


std::ostream& operator<<(std::ostream& os,const depth_stream_stat& ss);


#endif
