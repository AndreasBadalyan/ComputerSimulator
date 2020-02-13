//
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::showpos;
using std::noshowpos;
using std::internal;

#include <iomanip>
using std::setw;
using std::setfill;

void printing(void);
void loader(int[], int);
void executor(int[]);
void damp(int[], int, int, int, int, int);
inline int wordTest();
const int SIZE = 100;

int main()
{
	int memory[SIZE] = { 0 };

	printing();
	loader(memory, SIZE);
	executor(memory);

	system("pause");
	return 0;
}

void printing(void)
{
   cout << "*** Welcome to Simpletron! ***\n" << "*** Please enter your program one instruction ***\n"
		  << "*** (or data word) at a time. I will type the ***\n"
		  << "*** location number and a question mark (?).  ***\n"
		  << "*** You then type the word for that location. ***\n"
		  << "*** Type the sentinel -99999 to stop entering ***\n*** your program. ***\n";
}

void loader(int memory[], int size)
{
	int instruction, i = 0;

	i / 10 ? (cout << i) : (cout << 0 << i);
	cout << "?  ";
	instruction = wordTest();

	while(instruction != -99999 && i <= 100){
		memory[i] = instruction;
		i++;
		i / 10 ? (cout << i) : (cout << 0 << i);
	   cout << "?  ";
		instruction = wordTest();
	}
	if(i > 99){
		cout << "*** Menory was overflow ***\n" << "*** Program loading completed ***";
		//
	}else
		cout << "*** Program loading completed ***\n";
}

void executor(int memory[])
{
	int accumulator = 0, instructionCounter = 0, operationCode = 0;
	int flag = 1, operand = 0, instructionRegister = 0;

	cout << "*** Program execution begins ***\n";

	while(flag){
	   instructionRegister = memory[instructionCounter];
		operationCode = instructionRegister / 100;
		operand = instructionRegister % 100;

		switch(operationCode){
		   
			case 10 :
				memory[operand] = wordTest();
				instructionCounter++;
				break;
			case 11 :
				cout << memory[operand] << endl;
				instructionCounter++;
				break;
			case 20 :
				accumulator = memory[operand];
				instructionCounter++;
				break;
			case 21 :
				memory[operand] = accumulator;
				instructionCounter++;
				break;
			case 30 :
				accumulator += memory[operand];
				instructionCounter++;
				break;
			case 31 :
				accumulator -= memory[operand];
				instructionCounter++;
				break;
			case 32 :
				if(memory[operand]){
				   accumulator /= memory[operand];
				   instructionCounter++;
				}else{
					cout << "*** Attempt to divide by zero ***\n*** Simpletron execution abnormally terminated ***\n";
					flag = 0;
				}
				break;
			case 33 :
				accumulator *= memory[operand];
				instructionCounter++;
				break;
			case 40 :
				instructionCounter = operand;
				break;
			case 41 :
				if(accumulator < 0)
					instructionCounter = operand;
				else
					instructionCounter++;
				break;
			case 42 :
				if(!accumulator)
					instructionCounter = operand;
				else
					instructionCounter++;
				break;
			case 43 :
				cout << "*** Simpletron execution terminated ***\n";
				flag = 0;
				break;
			default :
            cout << "*** Simpletron execution abnormally terminated ***\n";
				flag = 0;
		}
	}
	damp(memory, accumulator, instructionCounter, instructionRegister, operationCode, operand);
}

inline int wordTest()
{
	int number;

	cin >> number;
	while((number < -9999 || number > 9999) && number != -99999){
		cout << "imvalid word enter number betwin -9999 and 9999\n";
		cin >> number;
	}
	return number;
}

void damp(int memory[], int accumulator, int instructionCounter, int instructionRegister, int operationCode, int operand)
{
	cout << "REGISTERS:\n";
	cout << "accumulator        " << setw(7) << accumulator << endl;
	cout << "instructionCounter " << setw(7) << instructionCounter << endl;
	cout << "instructionRegister" << setw(7) << instructionRegister << endl;
	cout << "operationCode      " << setw(7) << operationCode << endl;
	cout << "operand            " << setw(7) << operand << endl;
	cout << "\nMEMORY:\n";
	cout << "  ";

	for(int j = 0; j <= 9; j++)
		cout << setw(7) << j;

	cout << internal << setfill('0');
	for(int i = 0; i <= 99; i++){
      
		if(i % 10 == 0){
			cout << endl;
			cout << noshowpos << setw(2) << i / 10 * 10;
		}
		cout << "  " << showpos << setw(5) << memory[i];
	}
	cout << endl;
		
}