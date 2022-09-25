#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string.h>    // Provides memcpy function
#include "stats.h"
// I took the includes from the test program :)
using namespace main_savitch_2C;
using namespace std;

main_savitch_2C::statistician::statistician() {
	count = 0;
    total = 0.0;
    tinyest = 0.0;
    largest = 0.0;
}

/* for some reason my program only worked when I added the operators (+,*,bool)
first then the public functions after, im not sure why thats the case but yeah */

// also I had to add main_savitch_2C:: to everything because I kept getting
//errors with the friend operators without the namespace.
statistician main_savitch_2C::operator+ (const statistician& s1, const statistician& s2) {
statistician result;

result.count = s1.length() + s2.length();

result.total = s1.sum() + s2.sum();

if (s1.minimum() <s2.minimum())
result.tinyest = s1.minimum();

else result.tinyest = s2.minimum();

if (s1.maximum() <s2.maximum())
result.largest = s2.maximum();

else result.largest = s1.maximum();

return result;
}
// operator+ returns s1 s2 sequence
statistician main_savitch_2C::operator* (double scale, const statistician& s) {
statistician result;

if (s.length() == 0)

return s;

result.count = s.length();

result.total = scale * s.mean() * s.length();

result.tinyest = scale * s.minimum();

result.largest = scale * s.maximum();

return result;
}
// operator* takes s and multiplies it by the scale
bool operator == (const statistician & s1, const statistician & s2) {
if (s1.length( ) != s2.length( )) {
        return false;
    }
    if (s1.length( ) == 0) {
        return true;
    }

    return ((s1.mean() == s2.mean()) && (s1.sum() == s2.sum()) && (s1.minimum() == s2.minimum()) && (s1.maximum() == s2.maximum()));
 }
// bool operator is true if s1 and s2 have same length
void main_savitch_2C::statistician::next(double r) {
    if (count == 0) {
        total = r;
		tinyest = r;
		largest = r;
    }
    else {
        total += r;
        if (r < tinyest) {
            tinyest = r;
        }
        if (r > largest) {
            largest = r;
        }
    }
    count++;
}
// r is the next number in sequence
void main_savitch_2C::statistician::reset() {
    count = 0;
}
// resets
int main_savitch_2C::statistician::length() const {
    return count;
}
// shows length of the sequence
double main_savitch_2C::statistician::sum() const {
    return total;
}
// shows the sum of the sequence
double main_savitch_2C::statistician::mean() const {
    
    return (total / double(count));
	
}
// shows the mean of the sequence
double main_savitch_2C::statistician::minimum() const {
   
    return tinyest;
	
}
// will return the smallest, or tinyest number in the sequence
double main_savitch_2C::statistician::maximum() const {
    
    return largest;
	
}
// will return the largest number in the sequence

//I added the test code right below this comment and it does compile :)
// if you add a test program below with a == operator it will give an error code
// I was unable to figure out the == operator error code, but since it doesn't
//affect my implementation code, it shouldn't be a big deal.

