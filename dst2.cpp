#include<iostream>
#include<cmath>

int main() {
    int taxi,i,j;
    int cheby,euclid;
    int findme[10][10] = {
        	{0,2,0,0,0,0,0,0,0,0},
       		{0,0,0,0,0,0,0,0,0,0},
        	{0,0,0,0,0,0,0,0,0,0},
        	{0,0,0,0,0,0,0,0,0,0},
        	{0,0,0,0,0,0,0,0,0,3},
        	{0,0,0,0,0,0,0,0,0,0},
        	{0,0,0,0,0,1,0,0,0,0},
        	{0,0,0,0,0,0,0,0,0,0},
        	{0,0,0,0,0,0,0,0,0,0},
        	{0,0,0,0,0,0,0,0,0,0},
    };
    int rows = sizeof(findme) / sizeof(findme[0]);
    int cols = sizeof(findme[0]) / sizeof(findme[0][0]);
    
    std::cout << "2D Array elements:" << std::endl;
    for (i = 0; i < rows; i++){
        for ( j = 0; j < cols; j++){
            std::cout << findme[i][j] << " ";
        }
        std::cout << std::endl;
    }
    
    taxi = abs(9-1) + abs(5-9);
    euclid = sqrt(pow((9-1),2) + pow((5-9),2));
    if(abs(9-1)>abs(5-9)){cheby = abs(9-1);}
    else {cheby = abs(5-9);}
    std::cout << "Taxicab = " << taxi << std::endl;
    std::cout << "Euclidean = " << euclid << std::endl;
    std::cout << "Chebyshev = " << cheby << std::endl;
    return 0;
}