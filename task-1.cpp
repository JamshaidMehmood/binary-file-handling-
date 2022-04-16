// JAMSHAID MEHMOOD
// BITF20M032
//  IT MORNING

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    //For task 1.1 

    string name;
    int num, count = 0,totalNums=0;
    cout << "Enter the name of Binary File ::";
    getline(cin, name);
    ofstream fout(name, ios::out| ios::binary);
    if (!fout.fail())
    {
        do
        {
            cout << "Enter the integer ( 0 to terminate ) :";
            cin >> num;
            if (num != 0)
            {
                fout.write(reinterpret_cast<char*>(&num), sizeof(num));
                //count++;
                //cout<< "operation done successfully"<<endl;
            }
        } while (num != 0);
        totalNums = fout.tellp();
        count = totalNums / sizeof(num);
        cout << "There are " << count << " Numbers in the file " << name << endl;
    }
    else
    {
        cout << "Unable to open that file !!!!\n";
    }

    fout.close();
    
    cout << "---------------------------------------------------------------------------\n";
    //For task 1.2

    string name2;
    int num1,totalNumbers,totalSize;
    cin.ignore();
    cout << "Enter the name of Binary file ::";
    getline(cin, name2);
    fstream file(name2, ios::in| ios::out| ios::binary);
    if (!file.fail())
    {
        char choice1;
        do
        {
            file.seekg(0, ios::end);
            totalSize = file.tellg();
            totalNumbers = totalSize / sizeof(int);
            cout << "Enter the which number you want to read from " << totalNumbers << " :";
            cin >> num1;
            while (num1 > totalNumbers || num1 <= 0)
            {
                cout << "This file not contain as many numbers as you want ::\n";
                cout << "Enter the which number you want to read from " << totalNumbers << " :";
                cin >> num1;
            }
            file.seekg(0,ios::beg);
            file.seekg(sizeof(int) *(num1-1), ios::beg);
            int seeNum;
            file.read(reinterpret_cast<char*>(&seeNum), sizeof(seeNum));
            cout << "Integer #" << num1 << " is :" << seeNum << endl;
            char choice2;
            cout << "Do you want to modify that number:";
            cin >> choice2;               
            if(choice2 == 'y' || choice2 == 'Y')
            {
                int newNum;
                cout << "Enter new value:";
                cin >> newNum;
                //-1 is because if the number is 1 than i will be 0 which means we are at the start of the file and want to read the first integer
                file.seekp(sizeof(int) * (num1 - 1), ios::beg);
                file.write(reinterpret_cast<char*>(&newNum), sizeof(newNum));
            }

            cout << "Do you want to EXIT:";
            cin >> choice1;
        } while (choice1 == 'n' || choice1 == 'n');
    }
    else
    {
        cout << "Unable to open that file ::\n";
    }
    file.close();
    return 0;
}
