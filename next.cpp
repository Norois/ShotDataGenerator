#include <iostream>
#include <fstream>

class ShotDataGenerator{
	public:
		int bulletRows;
		int bulletColumns;
		int bulletX;
		int bulletY;
		int dataIndex;
		int sizeX;
		int sizeY;
		int currentTop;
		int currentBottom;

		float bulletHitX;
		float bulletHitY;
		float bulletHitSize;

		std::string fileName;

		void generate(){
			std::ofstream outputFile(fileName + ".dnh");
			
			currentTop = bulletY;
		    currentBottom = sizeY - 1;
		    for(int i = 0; i <= bulletRows - 1; i++){
		        for(int j = 0;j <= bulletColumns - 1; j++){
		            outputFile << "\n\nShotData{\n    id = " << dataIndex; dataIndex ++;
		            outputFile << "\n    rect = (" << bulletX + (sizeX * i) << ", " << bulletY + currentTop << ", " << bulletX + (sizeX * (i + 1)) - 1 << ", " << currentBottom << " )\n";
		            outputFile << "    collision = (" << bulletHitSize << ", " << bulletHitX << ", " << bulletHitY << ")\n";
		            outputFile << "}";
		        }
		        currentTop += sizeY;
		        currentBottom += sizeY;
		    }
		}
};

int main(){
	ShotDataGenerator generator;
		std::cout << "Welcome, to the generator, please input the numbers as follows\nPlease input the number of bullets in your row\n";
	   	std::cin >> generator.bulletColumns;
	    std::cout << "Input the number of rows of bullets\n";
	    std::cin >> generator.bulletRows;
	    std::cout << "Input the top left pixel X position\n";
	    std::cin >> generator.bulletX;
	    std::cout << "Input the top left pixel Y position\n";
	    std::cin >> generator.bulletY;
	    std::cout << "Input the width of the bullet\n";
	    std::cin >> generator.sizeX;
	    std::cout << "Input the height of the bullet\n";
	    std::cin >> generator.sizeY;
	    std::cout << "Input the hitbox size\n";
	    std::cin >> generator.bulletHitSize;
	    std::cout << "Input the X offset of the hitbox, positive = to the right, negative = to the left, leave 0 if hitbox is in the middle\n";
	    std::cin >> generator.bulletHitX;
	    std::cout << "Input the U offset of the hitbox, positive = down, negative = up, leave 0 if hitbox is in the middle\n";
	    std::cin >> generator.bulletHitY;
	    std::cout << "Input the first unused index nunber in your shot data\n";
	    std::cin >> generator.dataIndex;
	    std::cout << "Input the name of the file to save the output to, .dnh is added automatically\n";
	    std::cin >> generator.fileName;

	    generator.generate();
}
