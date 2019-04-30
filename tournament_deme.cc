
#include "tournament_deme.hh"

#include <algorithm>
#include <random>
#include <vector>
#include <cassert>

// tournament-selection method for choosing parent
Chromosome* TournamentDeme::select_parent()
{
    const int candidate_size = 4; // we can adjust this as necessary
    assert((candidate_size <= pop_.size()) && "population size should be > 4");

    // a vector that holds the indices of the candidates in pop_
    std::vector<int> candidates;

    std::uniform_int_distribution<int> dist(0, pop_.size() - 1);

    // add candidate parents to the vector of candidates
    for (int i = 0 ; i < candidate_size ; i++ )
    {
        candidates.push_back(dist(generator_));
    }

    // let the battles begin!
    int j = candidate_size;
    while (j > 1)
    {
        for (int k = 0; k < j / 2; k++)
        {
            if (pop_[candidates[k]]->get_fitness() < pop_[candidates[k+(j/2)]]->get_fitness())
            {
                std::swap(candidates[k], candidates[k+(j/2)]);
            }
        }
        j = j / 2; // now we ignore the ones with indices >= j /2 , since
        // we move all of the losers there
    }
    return pop_[candidates[0]];
}
