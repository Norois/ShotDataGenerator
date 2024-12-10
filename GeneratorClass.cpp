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
		// Delay stuff
		int delayRectTop;
		int delayRectLeft;
		int delayRectDown;
		int delayRectRight;

		float bulletHitX;
		float bulletHitY;
		float bulletHitSize;

		bool includeHead;

		std::string shotImageDirectory;
		std::string fileName;
		std::string comment;

		void generate(){
			std::ofstream outputFile(fileName + ".dnh");

			if(this -> includeHead){
				outputFile << "#UserShotData\n\n";
				outputFile << "shot_image = \"" << this -> shotImageDirectory << "\"" << std::endl;
				outputFile << "delay_rect = (" << delayRectTop << "," << delayRectLeft << ",";
				outputFile << delayRectDown << "," << delayRectDown << ")" << std::endl << std::endl;
			}

			

			if(comment.length() != 0){
				outputFile << "// " << comment << std::endl;
			}
			currentTop = bulletY;
		    currentBottom = sizeY - 1;
		    for(int j = 0; j <= bulletRows - 1; j++){
		        for(int  i = 0;i <= bulletColumns - 1; i++){
		            outputFile << "ShotData{\n    id = " << dataIndex; dataIndex ++;
		            outputFile << "\n    rect = (" << bulletX + (sizeX * i) << ", " << bulletY + currentTop << ", " << bulletX + (sizeX * (i + 1)) - 1 << ", " << currentBottom << " )\n";
					if(bulletHitX == 0 && bulletHitY == 0){
						outputFile << "    collision = " << bulletHitSize << "\n";
					} else{
		            	outputFile << "    collision = (" << bulletHitSize << ", " << bulletHitX << ", " << bulletHitY << ")\n";
					}
					outputFile << "}\n";
		        }
		        currentTop += sizeY;
		        currentBottom += sizeY;
		    }
		}

};

int main(){
	std::string yes;

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

		std::cout << "Do you wish to include the shot data header?\n";
		std::cin >> yes;
		getchar();
		if(yes == "yes"){
			generator.includeHead = true;

			std::cout << "Input the directory of the shot image";
			std::cin >> generator.shotImageDirectory;

			// Delay Rect
			std::cout << "Input the Top position of delay rect sprite";
			std::cin >> generator.delayRectTop;

			std::cout << "Input the Left position of delay rect sprite";
			std::cin >> generator.delayRectLeft;

			std::cout << "Input the Down position of delay rect sprite";
			std::cin >> generator.delayRectDown;

			std::cout << "Input the Right position of delay rect sprite";
			std::cin >> generator.delayRectRight;
		} else{generator.includeHead = false;}

		std::cout << "Optional comment to add before the shots, leave empty if no comment";
		std::cin >> generator.comment;

	    generator.generate();
}
