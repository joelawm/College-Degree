///////////////////////////////////////////////////
//
// Name: Joe Meyer
//
// Date: 11/12/19
//
// Function: To show memeory manangmenet with best fit and first fit
///////////////////////////////////////////////////
#include <fstream>
#include <stddef.h>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <iostream>
#include <list>
#include <queue>
#include <iostream>

//classes
class MBlock
{
	public:
		MBlock(int size, int address)
		{
			this->size = size;
			this->address = address;
		}
		int pid;
		std::string name;
		int size;
		int address;
		MBlock * previous = NULL;
		MBlock * next = NULL;
};

//constansts and constants
#define KB 1024
#define MB KB * KB
int address = 3 * MB;
std::list<MBlock> used;
std::list<MBlock> available;

//prototypesd
void print();
void runBestFit();
void runFirstFit();
void insert(MBlock);
void loadBestFit(std::string);
void loadFirstFit(std::string);
void unallocate(std::string);
void terminate(std::string);


//runs the main bit of the program, but its biggest function is to decide what to use Best fit or First Fit
int main(int argc, char *argv[])
{
	//variables
	char argtUse = '?';

	//check if there is a argument
	if(argc > 1)
	{
		argtUse = argv[1][0];
		if(!(argtUse == 'B' || argtUse == 'F'))
		{
			std::cerr << "\nUse arguments F or B\n";
			exit(-1);
		}
	}
	else
	{
		std::cerr << "\nNo arguments, please enter F or B\n";
		exit(-1);
	}
	//reset the sizes
	int sizes[5] ={MB, 2 * MB, 2 * MB, 4 * MB, 4 * MB};


	//create a new memory address
	for(int i = 0; i < 5; i++)
	{
		//push back the new block of memoery
		available.push_back(*(new MBlock(sizes[i], address)));

		//change the address input
		address = address + sizes[i];
	}

	//find which arugment is used
	if(argtUse == 'B')
	{
		//argument B start best fit
		std::cerr<<"Simulation of Memory Management using the Best-Fit algorithm\n\nBeginning of the run\n\n";
		runBestFit();
	}
	else
	{
		//start first fit
		std::cerr<<"Starting Simulation with First-Fit method\n\nBeginning of the run\n\n";
		runFirstFit();
	}
}

//run mest fit function for memeory managment
void runBestFit()
{
	//variables
	std::ifstream text;
	text.open("data.txt");
	std::string segment;
	char cmd = '?';

	//output the queue
	print();

	//search through the entire file and start the proceeeses till the end
	while(!text.eof())
	{
		//get line and find the segment
		getline(text,segment);

		//command is equal to the segment line found
		cmd = segment[0];

		//if L
		if(cmd == 'L')
		{
			loadBestFit(segment);
		}
		//if D
		else if(cmd == 'D')
		{
			unallocate(segment);
		}
		//if A
		else if(segment[0] == 'A')
		{
			loadBestFit(segment);
		}
		//if ?
		else if(cmd == '?')
		{
			break;
		}
		//if T
		else if(cmd == 'T')
		{
			terminate(segment);
		}

		//output the queue
		print();

	}
	//close the text
	text.close();

	//output section for simulation and the end results
	std::cerr<<"End of the run\n\n";
	//end results
	print();
}

//remove blocks from memeory to not take up the enire system
void unallocate(std::string segment)
{
	//variables
	std::string name;
	char cmd;
	std::istringstream str(segment);
	int id;

	//take in string
	str >> cmd >> id >> name;
	std::cerr << "Transaction:  request to unallocate block ID " << name << " for process " << id << '\n';

	//make a new list
	std::list<MBlock>::iterator iteratorf;

	//for loop ing looping through to fin the block
	for(iteratorf = used.begin(); iteratorf != used.end(); iteratorf++)
	{

		if(iteratorf->pid == id && iteratorf->name == name)
		{
			//insert a new block
			insert(*(new MBlock(iteratorf->size, iteratorf->address)));
			//earase after inserting to clear memory
			used.erase(iteratorf);
			//ouput meesage
			std::cerr<<"Success in deallocating a block\n\n";
			return;
		}
	}

	//output
	std::cerr<<"Unable to comply as the indicated block cannot be found.\n\n";
}

//Run the first fit method and then pull inthe data
void runFirstFit()
{
	//variables
	std::ifstream text;
	text.open("data.txt");
	std::string segment;
	char cmd = '?';

	//output
	print();

	//read throught the enitre file
	while(!text.eof())
	{
		//find the next line of the segment
		getline(text,segment);

		//cmd = segment
		cmd = segment[0];
		//if L
		if(cmd == 'L')
		{
			loadFirstFit(segment);
		}
		//if D
		else if(cmd == 'D')
		{
			unallocate(segment);
		}
		//if A
		else if(segment[0] == 'A')
		{
			loadFirstFit(segment);
		}
		//if ?
		else if(cmd == '?')
		{
			break;
		}
		//if T
		else if(cmd == 'T')
		{
			terminate(segment);
		}
		//output
		print();

	}
	//close the file
	text.close();

	//output for the file
	std::cerr<<"End of the run\n\n";
	print();
}

//load best fit loads the data for the best fit model
void loadBestFit(std::string segment)
{
	//variables
	int size;
	int id;
	std::string name;
	char cmd;
	bool isRight = false;
	std::istringstream str(segment);
	//take in a new segment name
	str >> cmd >> id >> size >>name;
	std::list<MBlock>::iterator iteratorf;
	std::list<MBlock>::iterator iteratorb;
	int memoryLeft = 15 * MB;

	//if command is == to L
	if(cmd == 'L')
	{
		//output the transaction request
		std::cerr << "Transaction:  request to load process " << id << ", block ID " << name << " using " << size << " bytes\n";
	}
	else
	{
		//output the transacation request
		std::cerr << "Transaction:  request to allocate " << size << " bytes for process " << id << ", block ID: " << name << "\n";
	}

	//itteartate throught
	for(iteratorf=available.begin(); iteratorf != available.end(); ++iteratorf)
	{
		//compare teh size of the element
		if((iteratorf->size - size) < memoryLeft && (iteratorf->size - size) > 0)
		{
			//find the amount of memory left
			memoryLeft = (iteratorf->size - size);
			iteratorb = iteratorf;

			//set to true
			isRight = true;
		}
	}

	//check if we can write to it
	if(isRight)
	{
		//output
		std::cerr << "Found a block of size " << iteratorb->size << '\n';

		//subtract the size
		iteratorb->size = iteratorb->size - size;
		MBlock mem(size, iteratorb->address);
		iteratorb->address = iteratorb->address + size;


		//compared the memory
		mem.pid = id;
		mem.name = name;

		//push the new memory
		used.push_back(mem);
		std::cerr << "Success in allocating a block\n\n";
	}

	//not enough size
	else
	{
		//output for error
		std::cerr << "Unable to comply as no block of adequate size is available\n\n";
	}

}

//treminate helps remove extrea list froms memory
void terminate(std::string segment)
{
	//variables
	int id;
	char cmd;
	std::istringstream str(segment);
	//create a new string id
	str >> cmd >> id;
	std::list<MBlock>::iterator iteratorf;
	bool isTerminated = false;

	//output for transaction
	std::cerr << "Transaction:  request to terminate process " << id << '\n';

	//iterate throught the queue
	for(iteratorf = used.begin(); iteratorf != used.end(); iteratorf ++)
	{

		//if put = id
		if(iteratorf->pid == id)
		{
			//insert a new block
			insert(*(new MBlock(iteratorf->size, iteratorf->address)));
			//remove extra queue
			used.erase(iteratorf);
			//deincvrent
			iteratorf--;
			//set to true
			isTerminated = true;
		}
	}

	//output for the termination
	if(!isTerminated)
	{
		//error caught
		std::cerr<<"Unable to comply as the indicated process could not be found.\n\n";
	}
	else
	{
		//end the process of success
		std::cerr<<"Success in terminating a process\n\n";
	}
}

//load best fit loads the data in form the text file
void loadFirstFit(std::string segment)
{
	//variables
	int size;
	int id;
	std::string name;
	char cmd;
	bool isRight = false;
	std::istringstream str(segment);
	str >> cmd >> id >> size >> name;
	std::list<MBlock>::iterator iteratorf;

	//if command is == to L
	if(cmd == 'L')
	{
		//output transacation request
		std::cerr << "Transaction:  request to load process " << id << ", block ID " << name << " using " << size << " bytes\n";
	}
	else
	{
		//output Transcation reuqest
		std::cerr << "Transaction:  request to allocate " << size << " bytes for process " << id << ", block ID: " << name << "\n";
	}

	//
	for(iteratorf = available.begin(); iteratorf != available.end(); ++iteratorf)
	{
		//comparing the size to ther other
		if((iteratorf->size - size) >= 0)
		{
			//
			isRight = true;
			std::cerr << "Found a block of size " << iteratorf->size << '\n';
			break;
		}
	}

	// is ready
	if(isRight)
	{
		//find the size
		iteratorf->size = iteratorf->size - size;

		//create a new memory block
		MBlock mem(size, iteratorf->address);
		iteratorf->address = iteratorf->address + size;
		mem.pid = id;
		mem.name = name;
		//push to front of list
		used.push_front(mem);

		std::cerr << "Success in allocating a block\n\n";
	}
	else
	{
		//not enough space to print blocks
		std::cerr << "Unable to comply as no block of adequate size is available\n\n";
	}

}

//prints the final output of the program
void print()
{
	//variables and one output
	std::list<MBlock>::iterator iteratorf;
	int amount = 0;
	std::cerr << "List of available blocks\n";

	//is size of space is greater the 0
	if(available.size() > 0)
	{
		//itterate throught the entire address
		for(iteratorf=available.begin(); iteratorf != available.end(); ++iteratorf)
		{
			//output the start addresss and size
			std::cerr<<"Start Address =" << std::setw(9) << iteratorf->address;
			std::cerr<<" Size =" << std::setw(9) << iteratorf->size << '\n';

			//add the amounts together
			amount = amount + iteratorf->size;
		}
	}

	//error hadneling
	else
	{
		//output None
		std::cerr<<"(none)\n";
	}

	//ending output
	std::cerr<<"Total size of the list is = "<< amount << "\n\n";
	std::cerr<<"List of blocks in use\n";
	//reset the amount to 0
	amount = 0;
	if(used.size() > 0)
	{
		//iterator throught he used begin
		for(iteratorf=used.begin(); iteratorf != used.end(); ++iteratorf)
		{
			//output for the program
			std::cerr<<"Start Address =" << std::setw(9) << iteratorf->address;
			std::cerr<<" Size =" << std::setw(8) << iteratorf->size;
			std::cerr<<" Process ID =" << std::setw(5) << iteratorf->pid;
			std::cerr<<" Block ID =" << std::setw(6) << iteratorf->name << '\n';


			//subtrac the its sisze from amount
			amount = amount + iteratorf->size;
		}
	}
	else
	{
		std::cerr<<"(none)\n";
	}
	std::cerr<<"Total size of the list is: "<< amount << "\n\n";
}

//insert a new member into the list
void insert(MBlock mem)
{
	//variables
	std::list<MBlock>::iterator iteratorf;
	std::list<MBlock>::iterator iteratorb;
	bool isGood = false;

	//go through the looop and then ulimetlty merge the 2 data values
	for(iteratorf = available.begin(); iteratorf != available.end(); iteratorf++)
	{
		if(iteratorf->address > mem.address)
		{
			//insert one if avalaibe
			available.insert(iteratorf,mem);
			//set the avlaibel to true
			isGood = true;
			//break the if steamtne
			break;
		}
	}
	if(!isGood)
	{
		//if it isnt avaliabel push to frint
		available.push_front(mem);
	}
	//if its avalaibel go through and find the size
	for(iteratorf=available.begin(); iteratorf != --available.end(); iteratorf++)
	{
		//temp variblaes
		iteratorb = iteratorf;

		//increment variable
		iteratorb++;
		//sise + address = the second address the add the 2 sizes together
		if((iteratorf->size + iteratorf->address) == (iteratorb->address))
		{

			//add the 2 sizes together
			if((iteratorf->size + iteratorb->size) <= 4*MB)
			{
				//merger the 2 blocks by adding together
				std::cerr << "Merging two blocks at " << iteratorf->address << " and " << iteratorb->address << '\n';

				//combie the 2 sizes
				iteratorf->size = iteratorf->size + iteratorb->size;

				//clear up memory
				available.erase(iteratorb);
				//de increment
				iteratorf--;
			}
		}
	}
}
