Traveling Salesperson Problem - Part 3 - Reilly Cannon only

Please note that I used the previous week's solutions for my assignment.
Also note that running this in valgrind may take a while.

In the first part of this assignment, I created a new class called ClimbChromosome which inherited from the chromosome class from last week. The climb chromosome class overrided only two methods: the mutation method and the clone method. THe new clone method simply returns a new ClimbChromosome instead of a new Chromosome. THe mutate method is the implementation of a "local hill climbing" operator that searches a local "neighborhood" of the current chromosome to find the best permutation of cities, and mutates the chromosome accordingly. See the ClimbChromosome.cc file for more detail.

The second part of this assignment implements a tournament-selection method for determining which current-gen chromosome should reproduce to create the next generation, overriding the parent-selection method from the old Deme class. the new class is called TournamentDeme. See the TournamentDeme.cc file for more detail.

Finally, I compared the result of the genetic algorithm implemented last week (baseline-ga.tsv) with the ClimbChromosome class and regularDeme (local.tsv) and the ClimbChromesome class and the TornamentDeme class (tournament.tsv). A graph of this comparison can be seen in the comparison.gif file.
