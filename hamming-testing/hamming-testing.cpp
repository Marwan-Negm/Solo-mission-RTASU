#include <iostream>
#include <vector>
#include <bitset>
#include <string>
using namespace std;
// any vector you see will be starting from one bec. hamming and to avoid confusions 
int main() {
    string msg;
    cout << "Enter 8-byte message: ";
    getline(cin, msg);

    vector<int> parity(72,0);//stores parity bits and arr  
    vector<int> arr; // stores message as binary
    for (unsigned char c : msg) {
        for (int b = 7; b >= 0; b--) {
            arr.push_back((c >> b) & 1);
        }
    }
    int arrindex = 0;

    for (int loc = 1; loc <= 71; loc++) {
        if ((loc & (loc - 1))) {
            parity[loc] = arr[arrindex++]; 
            
        }
        else {
            parity[loc] = 0;// leave parity bits empty
        }
    }
    for (int parity_pos = 1; parity_pos <= 64; parity_pos <<= 1) {  // 1,2,4,8,16,32,64 parity pos are parity bits (71,64)
        int v = 0;
        for (int it = 1; it <= 71; ++it) //it for the data bits 
        {
            if (it & parity_pos) { v ^= parity[it]; }
        }
        parity[parity_pos] = v;
    }
    int ERR; 
     cout << "from 1 to 71 to insert a single bit error at this bit"<<endl;
       
     cin >> ERR;
        parity[ERR] ^= 1;
        
        cout << "Injected error at position  " << ERR << endl;
    

        arr.clear(); // to clear the old correct msg
        for (int loc = 1; loc <= 71; loc++) {
            if ((loc & (loc - 1))) { arr.push_back(parity[loc]); } // corrupted msg
        }
        //  Collect into bytes 
        string corrupted;
        for (int i = 0; i < arr.size(); i += 8) {
            unsigned char c = 0;
            for (int b = 0; b < 8; b++) {
                c = (c << 1) | arr[i + b];  // build byte bit-by-bit 
            }
            corrupted.push_back(c); // add character
        }

        //  Print result 
        cout << "corrupted msg: " << corrupted << endl;


    int loc = 1; //location of 1
    int r = 0;   //to xor the locations stored in pos 
    vector<int> pos; //stores position of 1

    for (int x, i = 1; i <= 71; i++) {         // starting from one bec. hamming 
        x = parity[i];
        if (x == 1) {
            pos.push_back(loc);
        }
        loc++;
    }

    for (int o : pos) {
        r = r ^ o;
    }

    cout << "syndrome is " << bitset<8>(r) << endl;  //r the syndrome or some times the checksum

    cout << "Positions of 1s: ";  // to see what is happening
    for (int z : pos) {
        cout << z << ' ';
    }
    if (r) { parity[r] ^= 1; }
           
        
       
    for (int o : pos) {
        r = r ^ o;
    }
        
cout << endl<<"syndrome is "<< bitset<8>(r);
    

arr.clear(); // to clear the old msg
    for (int loc = 1; loc <= 71; loc++) {
        if ((loc & (loc - 1))) { arr.push_back(parity[loc]); } // corrected msg
    }
    //  Collect into bytes 
    string corrected;
    for (int i = 0; i < arr.size(); i += 8) {
        unsigned char c = 0;
        for (int b = 0; b < 8; b++) {
            c = (c << 1) | arr[i + b];  // build byte 
        }
        corrected.push_back(c); 
    }

    
    cout << endl<<"corrected msg: " << corrected << endl;

    system("pause");

}
