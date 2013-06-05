#!/usr/bin/env  python3
import math
import random
# Basic test of monte carlo

batch = 10000

incircle = 0
total = 0


for count in range (1, batch+1):
    disx, disy = random.uniform(0.0, 1.0), random.uniform(0.0,1.0)
    total += 1
    if ( disx**2 + disy**2 <= 1.0 ):
        incircle += 1
    
# Estimate PI
print ("In: " + str(incircle))
print ("Total: " + str(total))
estpi = (( float(incircle)  * 4.00 ) / float(total) )

print ("Estimation of PI based on " + str(batch) + " number of simulations")
print (estpi)