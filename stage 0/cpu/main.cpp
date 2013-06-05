#include <iostream>
#include <random>
#include <chrono>
#include <thread>

const unsigned long int rounds = 10000;
using namespace std;

int main(){

    unsigned long int total = 0;
    unsigned long int incircle = 0;


    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine generator (seed);
    uniform_real_distribution<double> distribution(0.0,1.0);

    for (unsigned int i = 0; i < rounds; i++){
        total++;
        // Assign random variables
        double disx = distribution(generator);
        double disy = distribution(generator);

        //cout << "( " << disx << " , " << disy << " ) " << endl;
        if(disx*disx + disy*disy <= 1.0 )
            incircle++;
    }
    // PI calculation
    cout << "In Cirlce: " << incircle << endl << "Total: " << total << endl;


    double estpi = ( double(incircle) * double(4.0) ) / double(total);

    cout << "Estimation of PI: " << estpi << endl;

    return 0;
}
