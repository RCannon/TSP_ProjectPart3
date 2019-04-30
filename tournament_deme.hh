
#pragma once

#include "deme.hh"

class TournamentDeme : public Deme {
  public:

    TournamentDeme(const Cities* cities_ptr, unsigned pop_size, double mut_rate)
        : Deme(cities_ptr, pop_size, mut_rate) {}

    virtual ~TournamentDeme() = default; // use the standard Deme destructor

    virtual Chromosome* select_parent() override;

};
