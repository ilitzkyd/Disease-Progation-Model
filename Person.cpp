#include <stdio.h>
#include <string.h>
#include <bits/stdc++.h> 
#include <iostream>
using namespace std;

enum class Status { susceptible, sick, recovered, inoculated };

class Person {

    int sick_days;
    Status status;

    public:
        Person() {
            status = Status::susceptible;
            sick_days = 0;
        }
        void update() {
            if(status==Status::sick) {
                sick_days--;
                if(sick_days==0) {
                    status = Status::recovered;
                }
            }
        }
        void infect(int days) {
            if(status==Status::susceptible) {
                sick_days = days;
                status = Status::sick;
            }
        }
        void inoculate() {
            status = Status::inoculated;
        }
        bool is_stable() {
            return status==Status::recovered;
        }

        bool is_infected() {
            return status==Status::sick;
        }
        Status get_status() {
            return status;
        }

        string status_string() {
            std::stringstream s;
            switch(status) {
                case Status::sick:
                    s << sick_days;
                    return "sick (" + s.str() + " to go)";
                    break;
                case Status::susceptible:
                    return "susceptible";
                    break;
                case Status::recovered:
                    return "recovered";
                    break;
                case Status::inoculated:
                    return "inoculated";
                    break;
                default:
                    return "An error might have occured";
                    break;
            }
        }

};

