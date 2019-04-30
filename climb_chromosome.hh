
#pragma once

#include "chromosome.hh"
#include <cassert>

class ClimbChromosome : public Chromosome {
 public:

    // personal constructor
    ClimbChromosome(const Cities* cities_ptr)
        : Chromosome(cities_ptr) {}

    // virtual destructor
    virtual ~ClimbChromosome()
    {
        assert(is_valid());
    }

    //override Chromosome mutate - see .cc file
    virtual void mutate() override;

    // override Chromosome clone to return a new ClimbChromosome
    virtual Chromosome* clone() const override
    {
        return new ClimbChromosome(*this);
    }
};