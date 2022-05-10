// void read_record()
// {

// 	// File pointer
// 	fstream fin;

// 	// Open an existing file
// 	fin.open("reportcard.csv", ios::in);

// 	// Get the roll number
// 	// of which the data is required
// 	int rollnum, roll2, count = 0;
// 	cout << "Enter the roll number "
// 		<< "of the student to display details: ";
// 	cin >> rollnum;

// 	// Read the Data from the file
// 	// as String Vector
// 	vector<string> row;
// 	string line, word, temp;

// 	while (fin >> temp) {

// 		row.clear();

// 		// read an entire row and
// 		// store it in a string variable 'line'
// 		getline(fin, line);

// 		// used for breaking words
// 		stringstream s(line);

// 		// read every column data of a row and
// 		// store it in a string variable, 'word'
// 		while (getline(s, word, ', ')) {

// 			// add all the column data
// 			// of a row to a vector
// 			row.push_back(word);
// 		}

// 		// convert string to integer for comparision
// 		roll2 = stoi(row[0]);

// 		// Compare the roll number
// 		if (roll2 == rollnum) {

// 			// Print the found data
// 			count = 1;
// 			cout << "Details of Roll " << row[0] << " : \n";
// 			cout << "Name: " << row[1] << "\n";
// 			cout << "Maths: " << row[2] << "\n";
// 			cout << "Physics: " << row[3] << "\n";
// 			cout << "Chemistry: " << row[4] << "\n";
// 			cout << "Biology: " << row[5] << "\n";
// 			break;
// 		}
// 	}
// 	if (count == 0)
// 		cout << "Record not found\n";
// }

#include <bits/stdc++.h>
using namespace std;

int main()
{
    // string s = "my name is ayush";
    string s = "Name,Age,Salary";
    // cout<<s.length();

    // string new;
    int i=0,f=0,e=0,flag=0,flag2=0;
    int count =0;
    while(i<s.length())
    {
        if(count == 2 && flag == 0)
        {
            f=i;
            flag = 1;
        }

        if((count > 2 || i==s.length()-1) && flag2 == 0)
        {
            if(count > 2)
                e = i - 2;
            if(i==s.length()-1)
                e=i;
            flag2=1;
        }

        if(s[i]==',')
            count++;

        i++;
    }
    char ch[80];
    int len = e - f + 1;
    s.copy(ch, len, f);
    // cout<<endl<<count;
    // cout<<endl<<"f: "<<f;
    // cout<<endl<<"e: "<<e;
    cout<<endl<<"ch: "<<ch;
    
}
