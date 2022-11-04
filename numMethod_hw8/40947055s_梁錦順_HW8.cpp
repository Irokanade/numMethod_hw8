//
//  main.cpp
//  numMethod_hw8
//
//  Created by Michael Leong on 04/11/2022.
//

#include <iostream>

using namespace std;

//lagrange equation
double L(double x, int k, double points[][2], int n) {
    double numerator = 1;
    double denominator = 1;
    
    for(int i = 0; i < n; i++) {
        if(i != k) {
            numerator *= (x-points[i][0]);
            denominator *= (points[k][0]-points[i][0]);
        }
    }
    
    return numerator/denominator;
}

//interpolation function P
double P(double x, double points[][2], int n) {
    double result = 0;
    
    for(int i = 0; i < n; i++) {
        result += points[i][1]*L(x, i, points, n);
    }
    
    return result;
}

int main(int argc, const char * argv[]) {
    int n = 4; //number of points
    
    double points[n][2];
    
    points[0][0] = 1.00;
    points[0][1] = 0.1924;
    points[1][0] = 1.05;
    points[1][1] = 0.2414;
    points[2][0] = 1.10;
    points[2][1] = 0.2933;
    points[3][0] = 1.15;
    points[3][1] = 0.3492;
    
    cout << P(1.09, points, n) << '\n';
    
    
    
    return 0;
}
