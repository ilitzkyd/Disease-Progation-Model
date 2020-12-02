#include "People.cpp" 
#include <vector> 
#include <fstream> 
#include <string> 
#include <iostream>
int main() 
{ 
	int popvals,vaccin,randvals,ccount,inoculatedin,daysick; 
	float prob; 
	popvals=10000;
	randvals=1;
	ccount=3; 
	daysick=5;
	vaccin=0; 
	std::cout<< "Enter population: "<< std::endl;	
	std::cin>>popvals;
	std::cout<< "Enter random seed: "<< std::endl;
	std::cin>>randvals;
	std::cout<< "Enter contact count: "<< std::endl;
	std::cin>>ccount;
	std::cout<< "Enter number of days sick: "<< std::endl;
	std::cin>>daysick;
	std::cout<< "Enter number of vaccinated: "<< std::endl;
	std::cin>>inoculatedin;
	std::cout<< "Enter probability: "<< std::endl;
	std::cin>>prob;

//Healthcare Consultant Resume Samples | Velvet Jobs
	Population pop (popvals,randvals);

        pop.set_probability_of_transfer(prob);
        pop.set_contact_count(ccount);
        pop.set_days_sick(daysick);
        pop.set_inoculated(inoculatedin);
        pop.inoculate();
	
	pop.random_infection();
      	
	std::vector<int> day;
	std::vector<int> infected;
	std::vector<int> sus;
	std::vector<int> rec;
	std::vector<int> inac;
	
	while(pop.count_infected()!=0){
		day.push_back(pop.current_day());
		infected.push_back(pop.count_infected());
		sus.push_back(pop.count_susceptible());
		rec.push_back(pop.count_recovered());
		inac.push_back(pop.count_inoculated());
		pop.update();
	}
                day.push_back(pop.current_day());
                infected.push_back(pop.count_infected());
                sus.push_back(pop.count_susceptible());
                rec.push_back(pop.count_recovered());
                inac.push_back(pop.count_inoculated());
                pop.update();		
        int data[infected.size()][5];

	for (int j=0; j<infected.size();j++){
          data[j][0]=day[j];
	  data[j][1]=infected[j];
	  data[j][2]=sus[j];
	  data[j][3]=rec[j];
	  data[j][4]=inac[j];
	}
	ofstream outputfile;
	string stg, stg1, stg2, stg3, stg4, stg5;
	stg1="Statistics_SD";
	stg2="_CC";
	stg3="_prob";
	stg4="_pop";
	stg5=".txt";
	stg=stg1+std::to_string(daysick)+stg2+std::to_string(ccount)
+stg3+std::to_string(int(prob*100))+stg4+std::to_string(popvals/1000)+stg5;

	outputfile.open(stg);
        outputfile<<"day"<<","<<"infected"<<","<<"sus"<<","<<"rec"<<","<<"vac"<<endl;
        for (int b = 0;b<infected.size();b++){
	outputfile <<data[b][0]<<","<<data[b][1]<<","<<data[b][2]<<","<<data[b]
[3]<<","<<data[b][4]<<endl;
	 }
        outputfile.close();
	return 0;
};	
