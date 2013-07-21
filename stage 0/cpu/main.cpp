#include <iostream>
#include <random>
#include <chrono>
#include <thread>
#include <atomic>
#include <mutex>

using namespace std;

struct lockabletotal{
    unsigned long long int num;
    mutex m;
};


//
const int NUM_THREADS = 64;
const unsigned long int ROUNDS = 100000;

/// Globals


#include "thread.hpp"





int main(){

    lockabletotal incircle;
    incircle.num = 0;


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
        cout << "New Thread:\t" << i << endl;
        // Calls a NUM_THREADS new threads running x rounds
        t[i] = thread(dodrops, ref(incircle));
        cout << "Thread Called:\t" << i << endl;
    }

    /// Join Threads
    for (int i = 0; i < NUM_THREADS; i++){
        t[i].join();
    }

	cout << "This information would be returned to the server" << endl;
    cout << "In Cirlce: " << incircle.num << endl << "Total: " << (NUM_THREADS * ROUNDS) << endl;


    double estpi = ( double(incircle.num) * double(4.0) ) / double(NUM_THREADS * ROUNDS);

    cout << "Estimation of PI: " << estpi << endl;

    return 0;
}
