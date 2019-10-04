//
//  main.cpp
//  Alth_day02
//
//  Created by 김혜진 on 28/09/2019.
//  Copyright © 2019 None. All rights reserved.
//

//17140 Array
#include <iostream>
#include <vector>
using namespace std;

#define CONTINUE -2
#define OVER -1
#define N 101

int r, c, k;
int rl, cl, T = 0;
int arr[100][100] = {0, };
int number[N];
vector<pair<int,int>> sortList;


int check()
{
    if (arr[r-1][c-1] != k)
        return CONTINUE;
    
    if (T > 100)
        T = OVER;
    
    return T;
}


void sortR()
{
    int max, index;
    for (int i = 0; i < rl; i++)
    {
        max = 0;
        fill_n(number, N, 0);
        sortList.clear();
        
        for (int j = 0; j < cl; j++)
        {
//            if (!arr[i][j])
//                break;
            
            number[arr[i][j]]++;
            
            if (max < arr[i][j])
                max = arr[i][j];
            
            arr[i][j] = 0;
        }
        
         for (int j = 1; j <= max; j++)
         {
             if (number[j] != 0)
                sortList.push_back(make_pair(number[j], j));
             
         }
        
        sort(sortList.begin(), sortList.end());
        
        index = 0;
        for (int j = 0; j < sortList.size(); j++)
        {
            arr[i][index++] = sortList[j].second;
            if (index == N)
            break;
            
            arr[i][index++] = sortList[j].first;
            if (index == N)
            break;
        }
        
        if (index > cl)
            cl = index;
    }
    T++;
}

void sortC()
{
    
       int max, index;
        for (int i = 0; i < cl; i++)
        {
            max = 0;
            fill_n(number, N, 0);
            sortList.clear();
            
            for (int j = 0; j < rl; j++)
            {
    //            if (!arr[i][j])
    //                break;
                
                number[arr[j][i]]++;
                
                if (max < arr[j][i])
                    max = arr[j][i];
                
                arr[j][i] = 0;
            }
            
             for (int j = 1; j <= max; j++)
             {
                 if (number[j] != 0)
                     sortList.push_back(make_pair(number[j], j));
             }
            
            sort(sortList.begin(), sortList.end());
            
            index = 0;
            for (int j = 0; j < sortList.size(); j++)
            {
                arr[index++][i] = sortList[j].second;
                if (index == N)
                break;
                
                arr[index++][i] = sortList[j].first;
                if (index == N)
                break;
            }
            
            if (index > rl)
                rl = index;
        }
        T++;
}

int main() {
  
    
    cin >> r >> c >> k;
    rl = 3;
    cl = 3;
    
    for (int i = 0; i < 3; i++)
    {
        for (int j =0; j < 3; j++)
        {
            cin >> arr[i][j];
        }
    }
    
    while(check() == -2)
    {
        if (rl >= cl)
            sortR();
        else
            sortC();
        
        check();
    }
    
    cout << T;
    
    return 0;
}
