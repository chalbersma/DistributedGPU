#ifndef THREAD_HPP_INCLUDED
#define THREAD_HPP_INCLUDED

#include <random>
#include <chrono>

void dodrops(unsigned long int howmany, atomic<unsigned long int> &incircle){

    // Grab a new seed
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    cout << seed << endl;
    default_random_engine generator (seed);
    uniform_real_distribution<double> distribution(0.0,1.0);

    unsigned long int tempcircle = 0;

    for (unsigned int i = 0; i < howmany; i++){
        double disx = distribution(generator);
        double disy = distribution(generator);

        //cout << "( " << disx << " , " << disy << " ) " << endl;
        if(disx*disx + disy*disy <= 1.0 )
            tempcircle++;
    }

    incircle += tempcircle;

}

#endif // THREAD_HPP_INCLUDED
