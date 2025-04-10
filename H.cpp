#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

bool isDivisible(string M, string N) {
    int M_int = stoi(M, nullptr, 2);
    int N_int = stoi(N, nullptr, 2);
    return N_int != 0 && M_int % N_int == 0;
}

string decodeMessage(string M_prime, string N_prime) {
    int m_asterisks = (M_prime.begin(), M_prime.end(), '*');
    int n_asterisks = (N_prime.begin(), N_prime.end(), '*');

    int max_combinations = pow(2, m_asterisks + n_asterisks);
    
    for (int i = 0; i < max_combinations; i++) {
        string current_M = M_prime;
        string current_N = N_prime;
        
        int bit_index = 0;
        
        // Replace * in M_prime
        for (char &ch : current_M) {
            if (ch == '*') {
                ch = ((i >> bit_index) & 1) + '0';
                bit_index++;
            }
        }
        
        // Replace * in N_prime
        for (char &ch : current_N) {
            if (ch == '*') {
                ch = ((i >> bit_index) & 1) + '0';
                bit_index++;
            }
        }
        
        if (isDivisible(current_M, current_N)) {
            return current_M;
        }
    }
    
    return ""; // Return empty string if no valid M is found
}

int main() {
    string M_prime, N_prime;
    cin >> M_prime >> N_prime;
    
    string d ;

    string result = decodeMessage(M_prime, N_prime);
    if (!result.empty()) {
        cout << result << endl;
    }
    
    return 0;
}


