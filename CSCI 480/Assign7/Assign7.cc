////////////////////////////////////////////////////////////
//
//	Name: Joe Meyer
//
//	Date: 11/25/19
//
//	Function: demonstration of how the FAT table works
//////////////////////////////////////////////////////////////
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <vector>

//entry data struct
struct Entry
{
	int postion;
	std::string file;
	int size;
	Entry(int num, std::string type, int total)
	{
		postion = num;
		file = type;
		size = total;
	}
};

//constants and defines
//i talked to hutchins about HOWOFTEN, he said to use what ever number makes the output work
#define HOWOFTEN 5
#define MAXENTRIES 12
#define BLOCKSIZE 512
#define LINECOUNT 240
const char* file = "data.txt";
std::vector<Entry*> directory;
short FAT[4096];

//prototypes
bool newFile(std::string, int);
int findEmpty(int initalPos);
bool renameFile(std::string, std::string);
Entry * findAll(std::string name);
bool modifyFile(std::string, int);
void printTable();
bool deleteFile(std::string);
bool copyFile(std::string, std::string);
void check();
void printEnd();

int main(int argc, char ** argv)
{
	//variables
	FAT[0] = -1;
	FAT[4095] = -1;
	directory.push_back(new Entry(0, ".", 512));
	directory.push_back(new Entry(-1, "..", 0));

	//take input of the file
	std::ifstream inFile;

	//open the file
	inFile.open(file);

	//error checking
	if (!inFile){std::cerr << "unable to open input file";exit(-1);}

	//header
	std::cout << "Beginning of the FAT simulation\n";

	//more variables
	char inputLine[256];
	int count = 0;
	bool endCon = false;
	std::string nameHolder1;
	std::string nameHolder2;
	int sizeHolder;

	//go throught he file and check for output
	while (inFile && !endCon)
	{
		if (count % HOWOFTEN == 0){
			printEnd();
			printTable();
		}
		memset(inputLine, '\0', 256);
		inFile.getline(inputLine, 256);

		//if C then follow
		if(inputLine[0] == 'C'){
			//header
			std::cout << "Transaction:  Copy a file\n";
			strtok(inputLine, " \n\r");
			nameHolder1 = (std::string) (strtok(nullptr, " \n\r"));
			nameHolder2 = (std::string) (strtok(nullptr, " \n\r"));
			//output
			if (copyFile(nameHolder1, nameHolder2)){std::cout << "Successfully copied an existing file, " << nameHolder1 << ", to a new file, " << nameHolder2 << std::endl;}
		}
		//if D then follow
		else if(inputLine[0] == 'D'){
			//header
			std::cout << "Transaction:  Delete a file\n";
			strtok(inputLine, " \n\r");
			nameHolder1 = (std::string) (strtok(nullptr, " \n\r"));
			//Output
			if (deleteFile(nameHolder1)){std::cout << "Successfully deleted a file, " << nameHolder1 << std::endl;}
		}
		//if N then follow
		else if(inputLine[0] == 'N'){
			//header
			std::cout << "Transaction:  Add a new file\n";
			strtok(inputLine, " \n\r");
			nameHolder1 = (std::string) (strtok(nullptr, " \n\r"));
			sizeHolder = atoi(strtok(nullptr, " \n\r"));
			//output
			if (newFile(nameHolder1, sizeHolder)){std::cout << "Successfuly added a new file, " << nameHolder1 << ", of size " << sizeHolder << std::endl;}
		}
		//if M then follow
		else if(inputLine[0] == 'M'){
			//header
			std::cout << "Transaction:  Modify a file\n";
			strtok(inputLine, " \n\r");
			nameHolder1 = (std::string) (strtok(nullptr, " \n\r"));
			sizeHolder = atoi(strtok(nullptr, " \n\r"));
			//output
			if (modifyFile(nameHolder1, sizeHolder)){std::cout << "Successfully modified a file, " << nameHolder1 << std::endl;}
		}
		//if R then follows
		else if(inputLine[0] == 'R'){
			//header
			std::cout << "Transaction:  Rename a file\n";
			strtok(inputLine, " \n\r");
			nameHolder1 = (std::string) (strtok(nullptr, " \n\r"));
			nameHolder2 = (std::string) (strtok(nullptr, " \n\r"));
			//output
			if (renameFile(nameHolder1, nameHolder2)){std::cout << "Successfully changed the file name " << nameHolder1 << " to " << nameHolder2 << std::endl;}
		}
		//if ? then follow
		else if(inputLine[0] == '?'){endCon = true;}
		count++;
	}
	//header
	std::cout << "\nEnd of the FAT simulation\n";

	//print the end of the file when done
	printEnd();
	//print FAT Table
	printTable();
	return 0;
}

//modify file by make a new one and copying contents, deleting old one, and renaming
bool modifyFile(std::string fileName, int size)
{
	Entry * file = findAll(fileName);

	//error checking
	if (file == nullptr){std::cout << "Error!  The file name, " << fileName << ", was not found.\n";return false;}

	//change the string temp
	std::string temp = (file->file) + "     ";

	//find the old file name
	std::string previous = file->file;

	//create anew file
	newFile(temp, size);
	//delete the old fine
	deleteFile(previous);
	//rename the file after deletion
	renameFile(temp, previous);

	//return if done correctly
	return true;
}

//find all the elements in the given set
Entry * findAll(std::string name)
{
	//variables
	bool tempBool = false;
	Entry * set = nullptr;

//iterate trought he entire stack and find all avaliabe
	for (std::vector<Entry*>::iterator it = directory.begin(); it != directory.end() && !tempBool; it++){
		//if it finds the file then change it to null
		if ((*it)->file == name){
			set = *it;
			//set to true
			tempBool = true;
		}
	}
	//return the set
	return set;
}


//print out the table being read from
void printTable(){
	//header
	std::cout << "\nContents of the File Allocation Table";
	//variables
	int lineCount = 0;
	int lineNumber = 0;

	//make sure the line count doesnt excede the table
	while (lineCount < LINECOUNT){
		if (lineCount % 12 == 0){
			//output the line numbers
			if (lineCount == 0){std::cout << "\n#" << std::setw(3) << std::setfill('0') << lineNumber;}
			//set the end
			else{std::cout << " \n#" << std::setw(3) << std::setfill('0') << lineNumber;}

			//add end bit for each number
			lineNumber += 12;
			std::cout << "-" << std::setw(3) << std::setfill('0') << lineNumber -1 << " ";
		}

		//output each line
		std::cout << std::setw(6) << std::setfill(' ') << FAT[lineCount];
		lineCount++;
	}

	//last output
	std::cout << std::setfill(' ') << " " << std::endl << std::endl;
}

//create a new file given the name and size for table
bool newFile(std::string name, int sizef){
	//variables
	bool set = true;
	int current = 0;
	int after = -1;
	Entry * temp = findAll(name);

	//write if no data is found
	if (temp == nullptr){
		if (sizef != 0){
			current = findEmpty(0);
			directory.push_back(new Entry(current, name, sizef));
			sizef -= BLOCKSIZE;

			//check the size of the file to make sure its not greater
			while (sizef > 0){

				//find the empty file
				after = findEmpty(current+1);

				//replace the contents
				FAT[current] = after;
				current = after;
				//add the block to total size
				sizef -= BLOCKSIZE;
			}
			FAT[current] = -1;
		}
		//push back the new found file
		else{directory.push_back(new Entry(-1, name, 0));}

	}
	//if data is found then dont make a new file
	else{std::cout << "File already exsists!\n";set = true;}

	//check for data integirty
	check();

	//return true
	return set;
}

//copy the file over after the deletion
bool copyFile(std::string fileName, std::string fileName_){
	//variable to change
	Entry * file = findAll(fileName);
	//error checking
	if (file == nullptr){std::cout << "Error!  The old file name, " << fileName << ", was not found.\n";return false;}

	//variable
	Entry * file_ = findAll(fileName_);
	//error checking
	if (file_ != nullptr){std::cout << "Error!  The new file name, " << fileName_ << ", already exists.\n";return false;}

	//change the file to copied
	newFile(fileName_, file->size);

	//return true if correct
	return true;
}

//rename the files given the name
bool renameFile(std::string fileName, std::string fileName_)
{
	//variables
	Entry * file = findAll(fileName);
	//error checking
	if (file == nullptr){std::cout << "Error!  The old file name, " << fileName << ", was not found.\n";return false;}

	//chnge varibles
	Entry * file_ = findAll(fileName_);
	//error checking
	if (file_ != nullptr){std::cout << "File already exsists!\n";return false;}

	//variable to be changed
	file->file = fileName_;


	//return true
	return true;
}


//delete the file from the stack
bool deleteFile(std::string fileName){
	Entry * file = findAll(fileName);
	//error checking
	if (file == nullptr){std::cout << "Error!  The file name, " << fileName << ", was not found.\n";return false;}

	//vairbales
	int place = file->postion;
	int next;

	//error checking
	if (place != -1){

		//second error checking
		while (FAT[place] != -1){
			//change the variables around if variable
			next = FAT[place];
			FAT[place] = 0;
			place = next;
		}
		FAT[place] = 0;
	}

	//variabele
	bool tempBool = false;

	//iterate through th eentire file and remove unwanted parts
	for (std::vector<Entry*>::iterator it = directory.begin(); it != directory.end() && !tempBool; it++){
		if ((*it)->file == fileName){

			//remove the unwanted elements
			directory.erase(it);
			tempBool = true;
		}
	}

	//check for data integrity
	check();

	//return true
	return true;
}


//check to make sure the eleents are being processes correctly
void check(){
	if (((float)directory.front()->size / (float)BLOCKSIZE) > ceil((float)directory.size() / (float)MAXENTRIES)){
		//variables
		int previous = 0;
		int current = 0;

		//error checking of the entire stack
		while (FAT[current] != -1){
			previous = current;
			current = FAT[current];
		}

		//move to the next current state
		FAT[current] = 0;
		FAT[previous] = -1;
		directory.front()->size = (int) ((float)BLOCKSIZE * ceil((float)directory.size() / (float)MAXENTRIES));
	}
	else if (((float) directory[0]->size / (float) BLOCKSIZE) < ceil( (float) directory.size() / (float) MAXENTRIES)){
		//variables
		int current = 0;
		int next;
		//find if the current is in the fat table
		while (FAT[current] != -1){current = FAT[current];}

		//move to the next current state
		next = findEmpty(current);
		FAT[current] = next;
		FAT[next] = -1;

		//move the element to the front of the stack
		directory.front()->size = (int) ((float)BLOCKSIZE * ceil((float)directory.size() / (float)MAXENTRIES));
	}
}

//print the end of file for the end directory
void printEnd()
{
	//header and variables
	std::cout << "\nDirectory Listing\n";
	int count = 0;
	int cluster;

	//find the total sizes for each element
	for (std::vector<Entry*>::iterator it = directory.begin(); it != directory.end(); it++){
		count += (*it)->size;
		//output
		std::cout << "File name: " << std::setw(23) << std::left << (*it)->file;
		std::cout << "File Size: " << std::setw(5) << std::right << (*it)->size << std::endl;
		std::cout << "Cluster(s) in use:  ";

		//error cheking
		if ((*it)->postion != -1){
			cluster = 1;

			//find the poistion of the element and set to -1
			if (FAT[(*it)->postion] == -1){std::cout << std::setw(6) << (*it)->postion << std::endl;}

			//output the main fat table
			else{
				std::cout << std::setw(6) << (*it)->postion;
				for(int pos = (*it)->postion; FAT[pos] != -1; pos = FAT[pos]){

					//output structure
					if (cluster % 12 == 0){std::cout << std::endl << "                    ";}

					//output the FAT positions
					std::cout << std::setw(6) << FAT[pos];
					//add on to total
					cluster++;

				}
				std::cout << std::endl;
			}

		}
		//if none set none
		else{std::cout << "(none)\n";}
	}

	//output for the end
	std::cout << "Files:  " << directory.size();
	std::cout << "  Total Size:  " << count;
	std::cout << " bytes\n";

}

//make sure the set itself isnt empty
int findEmpty(int temp){
	//variables
	int set = -1;

	//if the file is over 4096
	for (bool found = false; !found && temp < 4096; temp++){
		//find if its dvivisble
		if (FAT[temp] == 0){
			found = true;
			set = temp;
		}
	}
	//return the set
	return set;
}
