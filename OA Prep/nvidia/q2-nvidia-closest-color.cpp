//q2-nvidia-closest-color
#include <bits/stdc++.h>

using namespace std;

/* 
    You will be given a string of len 24, describing a pixel.
    Using Euclidean distance calc what pure color the pixel is closest to.
    Input - [000000001111111100000110]
*/
int convertFromBinary(string binary) { // O(24) = O(1)
    // int res = 0;
    // for(int i = 7, m = 0; i >= 0; i--, m++) {
    //     if(binary[i] == '1') {
    //         res += pow(2, m);
    //     }
    // }

    // return res;

    return stoi(binary, 0, 2);
}
int main() {
    vector<string> pixels = {"000000001111111100000110", "101111010110011011100100"};
    int n = pixels.size();
    int minimum_distance = 1e7;

    for(int i = 0; i < n; i++) { // TC = O(N)
        string pixel = pixels[i];

        int r = convertFromBinary(pixel.substr(0, 8));
        int g = convertFromBinary(pixel.substr(8, 8));
        int b = convertFromBinary(pixel.substr(16, 8));
        
        // with black
        int pure_black = sqrt(pow((r-0), 2) + pow((g-0), 2) + pow((b-0), 2));
        // with white
        int pure_white = sqrt(pow((r-255), 2) + pow((g-255), 2) + pow((b-255), 2));
        // with red
        int pure_red = sqrt(pow((r-255), 2) + pow((g-0), 2) + pow((b-0), 2));
        // with green
        int pure_green = sqrt(pow((r-0), 2) + pow((g-255), 2) + pow((b-0), 2));
        // with blue
        int pure_blue = sqrt(pow((r-0), 2) + pow((g-0), 2) + pow((b-255), 2));

        minimum_distance = min({pure_black, pure_blue, pure_green, pure_red, pure_white});

        cout << "Minimum Distance = " << minimum_distance << endl << "Color = ";
        if(minimum_distance == pure_black) cout << "Black";
        else if(minimum_distance == pure_blue) cout << "Blue";
        else if(minimum_distance == pure_white) cout << "White";
        else if(minimum_distance == pure_red) cout << "Red";
        else cout << "Green";
        cout << endl;
    }

    return 0;
}