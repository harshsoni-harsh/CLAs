#include <iostream>
    using namespace std;
    
    int main() {
    
        // Initialize denominator
       	double k = 1;
    
        // Initialize sum
        double s = 0;
    
        for (int i = 0; i < 100000000; i++) {
    
            // even index elements are positive
            if (i % 2 == 0) {
                s += 4.0 / k;
            } else {
    
                // odd index elements are negative
                s -= 4.0 / k;
            }
    
            // denominator is odd
            k += 2;
        }
    
        cout << s << endl;
    
        return 0;
    }
