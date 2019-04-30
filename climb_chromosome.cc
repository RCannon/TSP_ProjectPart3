
#include "climb_chromosome.hh"
#include "chromosome.hh"
#include <algorithm>
#include <random>
#include <cassert>



// mutates the chromosome using the local hill climbing method.

// searches for the best solution in a small neighborhood around current 
// chromosome by picking a random index and swapping the value there with
// the value at the index + 1 and with the value at intex - 1. It then
// checks which of these three permutations give the best result
// and assigns that one to be the order.
void ClimbChromosome::mutate()
{
    std::uniform_int_distribution<int> dist(0, order_.size() - 1);
    unsigned p = dist(generator_);
    double my_fitness = get_fitness();

    unsigned p_minus;
    double test_fitness_minus;

    unsigned p_plus;
    double test_fitness_plus;

    // get the fitness for p and p-1 swapped
    if (p == 0) p_minus = order_.size()-1;
    else p_minus = p - 1;
    std::swap(order_[p], order_[p_minus]);
    assert(is_valid());
    test_fitness_minus = get_fitness();
    std::swap(order_[p], order_[p_minus]);
    assert(is_valid());

    // get the fitness for p and p+1 swapped
    p_plus = (p + 1) % order_.size();
    std::swap(order_[p], order_[p_plus]);
    assert(is_valid());
    test_fitness_plus = get_fitness();
    std::swap(order_[p], order_[p_plus]);
    assert(is_valid());

    // compare the fitnesses
    double fittest = std::max({my_fitness, test_fitness_minus, test_fitness_plus});

    // select the permutation with the highest fitness
    if (fittest == my_fitness) return;
    else if (fittest == test_fitness_minus)
    {
        std::swap(order_[p], order_[p_minus]);
        assert(is_valid());
        return;
    }
    else
    {
        std::swap(order_[p], order_[p_plus]);
        assert(is_valid());
        return;
    }
}
