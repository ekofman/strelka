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
#ifndef __STARLING_STREAMS_BASE_HH
#define __STARLING_STREAMS_BASE_HH

#include "blt_common/blt_streams.hh"
#include "blt_util/bam_dumper.hh"
#include "starling_common/sample_info.hh"
#include "starling_common/starling_shared.hh"
#include "starling_common/starling_types.hh"

#include "boost/shared_ptr.hpp"

#include <vector>


struct starling_streams_base : public blt_streams {

    typedef blt_streams base_t;

    starling_streams_base(const starling_options& opt,
                          const prog_info& pinfo,
                          const sample_info& si);

    ~starling_streams_base();

    std::ostream*
    bindel_diploid_osptr(const unsigned sample_no) const {
        return _bindel_diploid_osptr[sample_no].get();
    }
    
    bam_dumper*
    realign_bam_ptr(const unsigned sample_no) const {
        return _realign_bam_ptr[sample_no].get();
    }

    std::ostream*
    candidate_indel_osptr() const {
        return _candidate_indel_osptr.get();
    }

    std::ostream*
    variant_window_osptr(const unsigned window_no) const {
        return _window_osptr.at(window_no).get();
    }

protected:
    static
    std::ostream*
    initialize_bindel_file(const starling_options& client_opt,
                           const prog_info& pinfo,
                           const std::string& filename,
                           const char* label=NULL);

    bam_dumper*
    initialize_realign_bam(const bool is_clobber,
                           const prog_info& pinfo,
                           const std::string& filename,
                           const char* label,
                           const bam_header_t* const header);

    static
    std::ostream*
    initialize_candidate_indel_file(const starling_options& client_opt,
                                    const prog_info& pinfo,
                                    const std::string& filename);

    static
    std::ostream*
    initialize_window_file(const starling_options& opt,
                           const prog_info& pinfo,
                           const avg_window_data& awd,
                           const sample_info& si);

    std::auto_ptr<std::ostream> _bindel_diploid_osptr[MAX_SAMPLE];
    std::auto_ptr<bam_dumper> _realign_bam_ptr[MAX_SAMPLE];
private:
    std::auto_ptr<std::ostream> _candidate_indel_osptr;
    unsigned _n_samples;

    std::vector<boost::shared_ptr<std::ostream> > _window_osptr;
};


#endif
