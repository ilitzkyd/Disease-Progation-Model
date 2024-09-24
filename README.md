# Population Infection Simulation

This project simulates the spread of infection within a population over time, accounting for factors like vaccination, infection probability, and recovery. It models individual persons in a population and tracks their status across several days.

## Files Overview

1. **People.cpp**  
   Contains the `Population` class, which represents a population of individuals. It tracks metrics such as the number of infected, susceptible, recovered, and inoculated individuals. The simulation can be configured to handle different probabilities of infection, contact rates, and recovery times.

2. **Person.cpp**  
   Defines the `Person` class, representing an individual in the population. Each person can have one of four statuses: susceptible, sick, recovered, or inoculated. The class tracks the number of sick days and updates the person's status as the simulation progresses.

3. **main2.cpp**  
   The entry point for the simulation. It allows the user to configure parameters such as population size, contact count, infection probability, vaccination count, and the number of sick days. It simulates the spread of infection over time and outputs the results in a CSV format, showing the number of infected, susceptible, recovered, and vaccinated individuals for each day.

## Usage

To run the simulation, compile the files and run the executable. You will be prompted to enter the population size, random seed, contact count, infection probability, vaccination count, and the number of sick days.



### Output

The simulation will output a CSV file with the following columns:

- **day**: The day of the simulation.
- **infected**: The number of infected individuals on that day.
- **sus**: The number of susceptible individuals on that day.
- **rec**: The number of recovered individuals on that day.
- **vac**: The number of vaccinated individuals on that day.

The file name is generated based on the input parameters for easy identification. Example file name: Statistics_SD5_CC3_prob20_pop1.txt




