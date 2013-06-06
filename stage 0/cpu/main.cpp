#include <iostream>
#include <random>
#include <chrono>
#include <thread>
#include <atomic>

const int NUM_THREADS = 4;
const unsigned long int ROUNDS = 10000;
using namespace std;

#include "thread.hpp"


int main(){

    atomic<unsigned long int> incircle;
    incircle = 0;


    /*
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    cout << seed << endl;
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
    */

    /// Launch Threads
    thread t[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++){
        // Calls a NUM_THREADS new threads running x rounds
        t[i] = thread(dodrops, ROUNDS);
    }

    /// Join Threads
    for (int i = 0; i < NUM_THREADS; i++){
        t[i].join();
    }

    cout << "In Cirlce: " << incircle << endl << "Total: " << (NUM_THREADS * ROUNDS) << endl;


    double estpi = ( double(incircle) * double(4.0) ) / double(NUM_THREADS * ROUNDS);

    cout << "Estimation of PI: " << estpi << endl;

    return 0;
}
