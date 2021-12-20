#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

using namespace std;

int main()
{
    while(1)
    {
        setlocale (LC_ALL, "ru");
        srand (time(NULL));

        int z = 0;

        cout << "Введите действие 1 расчет, 0 выыход: ";
        cin >> z;

        if( z != 1)
            break;

        int b = 0;
        int summ = 0;

        int array_for_weight[10];
        int array_of_1and0[10] = {0};
        int array_for_solutions[10][10] = {{0}, {0}};

        bool c = true;
    
        for(int i = 0; i < 10; i++ ) 
        {
            array_for_weight[i] = rand()%10+1; 

            cout << array_for_weight[i] << "\t"; 

        }

        cout<<"\n";
        cout<< "=========================================================================" <<"\n";

        cout << "Введите вес, который требуется составить из гирь" << endl;
        int ves;
        cin >> ves;

        cout<< "=========================================================================" <<"\n";
    
        while(c)
        {
            int i=9;
            while(array_of_1and0[i] == 1)
            {
                array_of_1and0[i] = 0;
                i--;
             
                for(int j = 0; j < 10; j++)
                {
                    summ += array_for_weight[j]*array_of_1and0[j];
                }
            
                if(i<0)
                {
                    break;
                }
            }
        
            if(summ == ves)
            {
                for(int h = 0; h<10; h++)      
                {
                    array_for_solutions[b][h]=array_of_1and0[h];
                }  

                b++;
            }
        
            if (b == 10 || i < 0)
            {
                c = false;
            }
            summ = 0;
            array_of_1and0[i]++;
        }
    
        if (b == 0)
        {
            cout << "Составить вес " << ves << " из этих гирь невозможно" << endl;
        }
        else 
        {
            cout << "Можно составить вес используя следующие гири" << endl;
            for(int i = 0; i < 10; i++)
            {
                for(int j = 0; j < 10; j++)
                {
                    cout << array_for_weight[j]*array_for_solutions[i][j] << "\t";
            
                }
               
                cout << "\n";
            }
        }

    }
    system("pause");
    return 0;
}
