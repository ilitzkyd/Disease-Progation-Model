#include <bits/stdc++.h>
#include <stdlib.h>
#include <time.h>
#include "Person.cpp"
//using namespace std;


class Population {

    int day;
    int size;

    int infected_cnt;
    int susceptible_cnt;
    int recovered_cnt;
    int inoculated_cnt;

    float probability;
    int contacts;
    int sick_days;

    vector<Person*> peoples;

    public:

        Population(int popcnt, int srandom) {
//          int popcnt=100;
//          int srandom=0;
            size = popcnt;
            day = 0;

            infected_cnt = 0;
            susceptible_cnt = popcnt;
            recovered_cnt = 0;
            inoculated_cnt = 0;


            probability = 0.0;
            contacts = 0;
            sick_days = 0;
            peoples.reserve(popcnt);
            for(int i=0; i<popcnt; i++) {
                peoples.push_back(new Person());
            }

            srand(time(NULL)+srandom);
        }

        void inoculate() {
            if(susceptible_cnt<inoculated_cnt) {
                inoculated_cnt = susceptible_cnt;
            }
            for(int i=0; i<inoculated_cnt; i++) {
                int index = rand()%peoples.size();
                Person* cured = peoples[index];
                if(cured->get_status()==Status::susceptible) {
                    cured->inoculate();
                } else {
                    i--;
                }
            }
            susceptible_cnt-=inoculated_cnt;
        }

        int current_day() {
            return day;
        }

        int count_inoculated() {
            return inoculated_cnt;
        }

        int count_infected() {
            return infected_cnt;
        }

        int count_susceptible() {
            return susceptible_cnt;
        }

        int count_recovered() {
            return recovered_cnt;
        }


        void random_infection() {
            infected_cnt = 1;
            int index =(int) rand() % size;
            Person* victim = peoples[index];
            infect_person(victim);
        }

        void update() {

            int new_infected_cnt = 0;
            int new_susceptible_cnt = 0;
            int new_recovered_cnt = 0;
            int new_inoculated_cnt = 0;

            vector<Person*> newly_infected;

            for(int i=0; i<peoples.size(); ++i) {
                Person* person = peoples.at(i);
                switch(person->get_status()) {
                    case Status::sick:
                        new_infected_cnt++;
                        interact(person, newly_infected);
                        break;
                    case Status::susceptible:
                        new_susceptible_cnt++;
                        break;
                    case Status::recovered:
                        new_recovered_cnt++;
                        break;
                    case Status::inoculated:
                        new_inoculated_cnt++;
                        break;
                    default:
                        break;
                }
                person->update();
            }

            day++;
            infected_cnt = new_infected_cnt;
            susceptible_cnt = new_susceptible_cnt;
            recovered_cnt = new_recovered_cnt;
            inoculated_cnt = new_inoculated_cnt;

            for(Person* person : newly_infected) {
                infect_person(person);
            }

        }

        string status_of_people() {

            string result = "";

            for(int i=0; i<peoples.size(); ++i) {
                Person* person = peoples[i];
                if(person->get_status()==Status::susceptible) {
                    result.append( " ?");
                } else if(person->get_status()==Status::recovered) {
                    result.append( " -");
                } else {
                    result.append( " +");
                }
            }
            return result;
        }

        void set_inoculated(int inoculated) {
            this->inoculated_cnt = inoculated;
        }

        void set_probability_of_transfer(float probability) {
            this->probability = probability;
        }

        void set_contact_count(int contacts) {
            this->contacts = contacts;
        }

        void set_days_sick(int sick_days) {
            this->sick_days = sick_days;
        }


    private:

        void infect_person(Person* person) {
            person->infect(sick_days);
        }

        void interact(Person* person, vector<Person*> &newly_infected) {
            for(int i=0; i<contacts; i++) {
                float bad_luck = (float) rand() / (float) RAND_MAX;
                if(bad_luck<=probability) {
                    int randnum = rand()%peoples.size();
                    newly_infected.push_back(peoples.at(randnum));
                }
            }
        }

};
