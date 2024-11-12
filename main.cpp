#include <iostream>

using namespace std;

int main(){
    int bulletRows, bulletColumns, bulletX, bulletY, dataIndex, sizeX, sizeY, currentTop, currentBottom;
    float bulletHitX, bulletHitY, bulletHitSize;
    cout << "Welcome, to the generator, please input the numbers as follows\nPlease input the number of bullets in your row\n";
    cin >> bulletColumns;
    cout << "Input the number of rows of bullets\n";
    cin >> bulletRows;
    cout << "Input the top left pixel X position\n";
    cin >> bulletX;
    cout << "Input the top left pixel Y position\n";
    cin >> bulletY;
    cout << "Input the width of the bullet\n";
    cin >> sizeX;
    cout << "Input the height of the bullet\n";
    cin >> sizeY;
    cout << "Input the hitbox size\n";
    cin >> bulletHitSize;
    cout << "Input the X offset of the hitbox, positive = to the right, negative = to the left, leave 0 if hitbox is in the middle\n";
    cin >> bulletHitX;
    cout << "Input the U offset of the hitbox, positive = down, negative = up, leave 0 if hitbox is in the middle\n";
    cin >> bulletHitY;
    cout << "Input the first unused index nunber in your shot data\n";
    cin >> dataIndex;

    /*bulletColumns = 5;
    bulletRows = 1;
    bulletX = 0;
    bulletY = 0;
    sizeX = 16;
    sizeY = 16;
    dataIndex = 1;*/


    currentTop = bulletY;
    currentBottom = sizeY - 1;
    for(int i = 0; i <= bulletRows - 1; i++){
        for(int i = 0;i <= bulletColumns - 1; i++){
            cout << "\n\nShotData{\n    id = " << dataIndex; dataIndex ++;
            cout << "\n    rect = (" << bulletX + (sizeX * i) << ", " << bulletY + currentTop << ", " << bulletX + (sizeX * (i + 1)) - 1 << ", " << currentBottom << " )\n";
            cout << "    collision = (" << bulletHitSize << ", " << bulletHitX << ", " << bulletHitY << ")\n";
            cout << "}";
        }
        currentTop += sizeY;
        currentBottom += sizeY;
    }
    

    return 0;
}