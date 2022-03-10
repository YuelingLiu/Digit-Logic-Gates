/*******************************************************

 * Program Name: < Digital Logic Gates>

 * Author: <Yueling Liu>

 * Date: <2/21/2020>

 * Description: <program description>
   This program is using C++ which allows user to input digitial logic 
   number of 0 and 1. O represents false whereas 1 represents true.
   There's a menu that prompts user to choose the type of gate and the functions 
   will determine the output.


 ******************************************************
*/

#include<iostream>
using namespace std;

const int MAX_INPUT = 8;
int inputs[MAX_INPUT];


/*******************************************************
* 
 * Function Name: <GATE_TYPE>

 * Purpose: <It's simply a enum function which with bunch of choices, 
            by defulat the first element of enum will be 0, to make it easier
			for user, the order has been implemented by 1, so it will start with
		     NOT gate as the first choice.>

 * Parameter: <It includes 8 elements in it>

 * Return: <It is a enum function, doesn't need to return anything>
 * 
 *******************************************************/
enum GATE_TYPE {
	NOT = 1, AND, OR, NAND, NOR, HALF, FULL, EXIT
    
};


/*******************************************************
 * Function Name: <NOTGATE>

 * Purpose: <To determine NOT >

 * Parameter: <There's no parameters>

 * Return: <If it's true then return false, if it's false then return true.>
 * 
 *******************************************************/
int NOTGATE() {
	cout << "Enter 0 or 1: ";
	cin >> inputs[0];


	if (inputs[0] == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


/*******************************************************
 * Function Name: <ANDGATE>

 * Purpose: <To determine AND >

 * Parameter: <There's no parameters>

 * Return: <All the inputs are true, then return ture, as long as one of the inputs
 is false, then return false. It follows the logic of AND>
 *
 *******************************************************/
int ANDGATE()
{
	int num;
	cout << "Enter  numbers of value:";
	cin >> num;
	cout << "Value:";
	
		for (int i = 0; i < num; i++)
		{
			cin >> inputs[i];
		}

		int r = inputs[0];
	   for (int i = 0; i < num; i++)
       {
		   
    	r &= inputs[i]; //calculate AND operatio, It does compariosn
	
	   }
	  
	   return r; //return result
}

/*******************************************************
 * Function Name: <ORGATE>

 * Purpose: <To determine OR >

 * Parameter: <There's no parameters>

 * Return: <All the inputs are true, then return ture,  if there's one or more than one 
  are flase, it still return a ture output>
 *
 *******************************************************/
int ORGATE()
{
	int num;
	cout << "Enter  numbers of value:";
	cin >> num;
	cout << "Value:";
	

	int r = inputs[0]; //r equals the first input 
	for (int i = 0; i < num; i++)
	{
		cin >> inputs[i];
	}

	
	for (int i = 0; i < num; i++)
	{
	
		r= r | inputs[i]; //calculate or operationr  = r | input[i]
		return r; //return result
	}
	}
	

/*******************************************************
 * Function Name: <NANDGATE>

 * Purpose: <To determine NOT AND >

 * Parameter: <There's no parameters>

 * Return: <If the values of output is true, then return not ture,
            othersie, return true>
 *
 *******************************************************/
int NANDGATE()
{
	int num;
	cout << "Enter  numbers of value:";
	cin >> num;
	cout << "Value:";
	

	for (int i = 0; i < num; i++)
	{
		cin >> inputs[i];
	}

	int r = inputs[0];

	for (int i = 0; i < num; i++)
	{

		r &= inputs[i]; //calculate AND operation 
	}

	if (r == 0)
	{
		return 1;
	}
	else

	{
		return 0;

	}
}

/*******************************************************
 * Function Name: <NORGATE>

 * Purpose: <To determine NOT OR GATE >

 * Parameter: <There's no parameters>

 * Return: <It returns the opposite output of ORGATE >
 *
 *******************************************************/
int NORGATE()
{
	int num;
	cout << "Enter  numbers of value:";
	cin >> num;
	cout << "Value:";

	
	for (int i = 0; i < num; i++)
	{
		cin >> inputs[i];
	}

	int r = inputs[0]; //set r equals the first input 
	for (int i = 0; i < num; i++)
	{

		r = r | inputs[i]; //calculate or operation,  = r | input[i]

		
	}
	if (r == 0)
	{
		return 1;
	}

	else
	{
		return 0;
	}
}

/*******************************************************
 * Function Name: <menuGate>

 * Purpose: <It gives user options of the logic gates >

 * Parameter: <There's no parameters>

 * Return: <It doesn't return anything>
 *
 *******************************************************/
void menuGate()
{
	cout << "MAIN MENU" << endl;
	cout << "========"<<endl;
	cout << "choice 1 - NOT gate" << endl;
	cout << "choice 2 - AND gate"<<endl;
	cout << "choice 3 - OR gate"<<endl;
	cout << "choice 4 - NAND gate" << endl;
	cout << "choice 5 - NOR gate"<<endl;
	cout << "choice 6 - Half - adder"<<endl;
	cout << "choice 7 - Full - adder"<<endl;
	cout << "choice 8 - Exit"<<endl;
	cout << endl;

}

int num; // a global value, 



/*******************************************************
 * Function Name: <HALF_ADDER Function>

 * Purpose: <To print half_adder sum and carry value >

 * Parameter: <There's no parameters>

 * Return: <It's a void function, doesn't return anything>
 *
 *******************************************************/
void HALF_ADDER() { // HalfADDER function
	int sum = 0, carry = 0; // Initializing sum and carry equal to 1
	

	sum = inputs[0] + inputs[1]; //compute sum of two inputs
	if (sum == 2) { //both inputs are 1
		sum = 0; //set sum as 0
		carry = 1; //set carry as 1
	}
	cout << "Sum : " << sum << endl; //print sum
	cout << "Carry: " << carry << endl; //print carry
}
/*******************************************************
 * Function Name: <FULL_ADDER Function>

 * Purpose: <c >

 * Parameter: <There's no parameters>

 * Return: <It's a void function, doesn't return anything>
 *
 *******************************************************/
void FULL_ADDER() { 
	int sum = 0, carry = 0; //set sum and carry as 0

	//calculate sum of inputs with carry
	sum = inputs[0] + inputs[1] + inputs[2];
	if (sum == 3) { // supposely all inputs are 1
		sum = 1; //set sum as 1
		carry = 1; //set carry as 1
	}
	else if (sum == 2) { //2 inputs are 1s and one ouput is 0
		sum = 0; //set sum as 0
		carry = 1; //set carry as 1
	}

	cout << "Sum : " << sum << endl; //print sum
	cout << "Carry: " << carry << endl; //print carry
}

/*******************************************************
 * Function Name: <main Function>

 * Purpose: < Using switch to call different functions >

 * Parameter: <There's no parameters>

 * Return: <It prints the ouput of each logic gate
 >
 *
 *******************************************************/
int main()
{
	menuGate();

	int gate;
	cout << "What gate do you want ?";
	cin >> gate;
	

	switch (gate)
	{
	case NOT:
		
		cout<<"Output is  "<< NOTGATE()<<endl;
		break;

	case AND:
		cout << "Output is  " << ANDGATE() << endl;
		break;
	case OR:
		cout << "Output is " << ORGATE() << endl;
		break;
	case NAND:
		cout << "Output is " << NANDGATE() << endl;
		break;
	case NOR:
		cout << "Output is " << NORGATE() << endl;
		break;
	case HALF:
		cout << "Enter two inputs [0 or 1]:";
		for (int i = 0; i < 2; i++)
			cin >> inputs[i];
		cout << "Output: " << endl;
		HALF_ADDER();
		break;
	case FULL:
		cout << "Enter three inputs [0 or 1]:";
		for (int i = 0; i < 3; i++)
			cin >> inputs[i];
		cout << "Output: " << endl;
      FULL_ADDER() ;
		break;
	case EXIT:
		return 0;
		break;
	}

	return 0;
}