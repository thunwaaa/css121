#include <vector>
#include <cmath>
#include <string>
#include <map>
#include <limits>
#include <algorithm>
#include <iostream>
#include <iomanip>

using namespace std;
struct findmbti{
    double Ne, Ni, Te, Ti, Se, Si, Fe, Fi;
    string type;
};

void higherdimension(findmbti* dt, findmbti query) {
    int size = 11;
    vector<double> distance(size);
    vector<double> temp(4, numeric_limits<double>::max()); 
    vector<string> nearest_mbti(3);

    // Calculate distances and store in buckets
    for (size_t i = 0; i < size; ++i) {
        distance[i] = sqrt(pow(dt[i].Ne - query.Ne, 2) + pow(dt[i].Ni - query.Ni, 2) + 
                              pow(dt[i].Te - query.Te, 2) + pow(dt[i].Ti - query.Ti, 2) + 
                              pow(dt[i].Se - query.Se, 2) + pow(dt[i].Si - query.Si, 2) + 
                              pow(dt[i].Fe - query.Fe, 2) + pow(dt[i].Fi - query.Fi, 2));
    }
    
    int countI=0,countE=0,countS=0,countN=0,countT=0,countF=0,countJ=0,countP=0;

    for (int i = 0; i < size; ++i) {
        if (distance[i] < 20.0){
            temp[0] = min(temp[0], distance[i]);
            nearest_mbti[0] = dt[i].type;
        }
        if (20.7 > distance[i] && distance[i]> 20.5){
            temp[1] = min(temp[1], distance[i]);
            nearest_mbti[1] = dt[i].type;
        }
        if (distance[i] > 20.6 && distance[i] < 20.9){
            temp[2] = min(temp[2], distance[i]);
            nearest_mbti[2] = dt[i].type;
        }
    } 
    for(int i=0; i<3; ++i){
        if(nearest_mbti[i][0] == 'I') countI++; else countE++;
        if(nearest_mbti[i][1] == 'S') countS++; else countN++;
        if(nearest_mbti[i][2] == 'T') countT++; else countF++;
        if(nearest_mbti[i][3] == 'J') countJ++; else countP++;
    }
    

    string myMBTI;
    if(countI >= countE) myMBTI += 'I'; else myMBTI += 'E';
    if(countS >= countN) myMBTI += 'S'; else myMBTI += 'N';
    if(countT >= countF) myMBTI += 'T'; else myMBTI += 'F';
    if(countJ >= countP) myMBTI += 'J'; else myMBTI += 'P';

    if(myMBTI.size() < 4){
        if(myMBTI.find('I') == string::npos) myMBTI += 'I'; else myMBTI += 'E';
        if(myMBTI.find('S') == string::npos) myMBTI += 'S'; else myMBTI += 'N';
        if(myMBTI.find('T') == string::npos) myMBTI += 'T'; else myMBTI += 'F';
        if(myMBTI.find('J') == string::npos) myMBTI += 'J'; else myMBTI += 'P';
    }
    cout << "my MBTI is : " << myMBTI << endl;
    
}


int main(){
    int size = 12;
    findmbti data[size];
    findmbti query;

    data[0] = {32, 32, 27, 36, 29, 31, 28, 23,"INTP"};
    data[1] = {31.8, 33, 22, 30, 35, 26, 24, 23,"INTJ"};
    data[2] = {12.8, 15.6, 14, 29, 21, 20, 17, 17,"ISTJ"};
    data[3] = {9.8, 14, 23, 23, 27, 30, 13, 25,"ISTP"};
    data[4] = {27.4, 30.4, 25, 25, 33, 28, 29, 19,"ENFJ"};
    data[5] = {41.4, 31.8, 38, 42, 25, 36, 21, 39,"INTP"};
    data[6] = {21.4, 20.4, 30, 31, 34, 30, 17, 22,"ISTP"};
    data[7] = {41, 30.4, 29, 45, 24, 42, 33, 31,"INTP"};
    data[8] = {24.8, 25, 21, 23, 25, 27, 21, 23, "INTP"};
    data[9] = {28.6, 21, 23, 24, 22, 26, 26, 13,"ENTP"};
    data[10] = {29.4, 39.4, 34, 42, 32, 31, 29, 29,"INTJ"};
    
    query = {35.8, 35.6, 18, 23, 17, 32, 26, 22};
    
    higherdimension(data, query);

    return 0;
}