#include <iostream>
#include <string>
#include <random>
#include <chrono>
#include <fstream>
#include<iomanip>
#include "Classes.h"
#include<sstream>
#define minAge 1
#define maxAge 4
#define minWeight 0.5f
#define maxWeight 3.5f
#define minIncrease 0.1f
#define maxIncrease 1.0f
using namespace std;

//generating a random number with the given paramters as the limits
int GreenMonkey::getRandomNumber(int lower_limit, int upper_limit) {
	unsigned seed = chrono::steady_clock::now().time_since_epoch().count();
	default_random_engine ranGen(seed);
	uniform_int_distribution<int>random_number(lower_limit, upper_limit);
	return random_number(ranGen);
}
//generating a random number with the given paramters as the limits
float GreenMonkey::getRandomNumber(float lower_limit, float upper_limit) {
	unsigned seed = chrono::steady_clock::now().time_since_epoch().count();
	default_random_engine ranGen(seed);
	uniform_real_distribution<float>random_number_F(lower_limit, upper_limit);
	return random_number_F(ranGen);
}

GreenMonkey::GreenMonkey() {

	//when the random number is generated, check to see if the value is either 0 or 1, and assign to each the corresponding letter

	(getRandomNumber(0, 1) == 0) ? gender = 'M' : gender = 'F';

	//opening the file containing the male names, and randomly assigning a name to the object

	if (gender == 'M') {
		int totlinesM = 0;
		int countM = 0;
		string mname;
		vector<string>linesM;
		vector<string>::iterator j;


		ifstream datafileM;
		datafileM.open("M_names.txt");
		if (datafileM.fail()) {
			cerr << "There was an error opening the male file.";
			exit(1);
		}
		//if there is no error opening the file, thn add the lines to a string vector
		else {
			while (getline(datafileM, mname)) {
				totlinesM++;
				linesM.push_back(mname);
			}

			// randomly generates a number between 0 and the total number of lines in the text file


			int randlines = getRandomNumber(0, totlinesM);



			//this assigns the name found at a position in the text file to the name of the monkey
			for (j = linesM.begin(); j != linesM.end(); j++) {
				if (randlines == countM) {
					name = *j;

				}

				countM++;
			}
		}
		datafileM.close(); //closing the file
	}

	//same process did with the males is done with the females
	if (gender == 'F') {
		int totlinesF = 0;
		int count = 0;
		string fname;
		vector<string>linesF;
		vector<string>::iterator i;

		ifstream datafileF;
		datafileF.open("F_names.txt");
		if (datafileF.fail()) {
			cerr << "There was an error opening the female file.";
			exit(1);
		}
		else {
			while (getline(datafileF, fname)) {
				totlinesF++;
				linesF.push_back(fname);
			}


			int randline = getRandomNumber(0, totlinesF);
			for (i = linesF.begin(); i != linesF.end(); i++) {
				if (randline == count) {
					name = *i;

				}
				count++;
			}

		}
		datafileF.close(); //closing the file
	}

	//assigning a random weight to the monkey object using minWeight and maxWeight

	weight = getRandomNumber(minWeight, maxWeight);

	//assigning a random age to the monkey object using the minAage and maxAge 

	age = getRandomNumber(minAge, maxAge);

	//assinging some values to be set when the object is created
	alive = true;
	mutant = false;
	injured = 0;
	next = NULL;
}



//retrieving the values that are stored in the private data members
float GreenMonkey::get_weight() {
	return weight;
}
short int GreenMonkey::get_age() {
	return age;
}
string GreenMonkey::get_name() {
	return name;
}
char GreenMonkey::get_gender() {
	return gender;
}
bool GreenMonkey::get_alive() {
	return alive;
}
bool GreenMonkey::get_mutant() {
	return mutant;
}
short int GreenMonkey::get_injured() {
	return injured;
}
int GreenMonkey::get_ID() {
	return ID;
}
GreenMonkey* GreenMonkey::get_next() {
	return next;
}

//assig"ning values to the private data members 
void GreenMonkey::set_weight(float w) {
	weight = w;
}
void GreenMonkey::set_age(short int a) {
	age = a;
}
void GreenMonkey::set_name(string n) {
	name = n;
}
void GreenMonkey::set_gender(char g) {
	gender = g;
}
void GreenMonkey::set_alive(bool al) {
	alive = al;
}
void GreenMonkey::set_mutant(bool m) {
	mutant = m;
}
void GreenMonkey::set_injured(short int injury) {
	injured = injury;
}
void GreenMonkey::set_ID(int id) {
	ID = id;
}
void GreenMonkey::set_next(GreenMonkey* another) {
	next = another;
}

//print function to display the data to the console
void GreenMonkey::print() {

	//conditions to determine whether the monkey is alive or dead and if the monkey is either a mutant or normal
	string isAlive = alive ? "Alive" : "Dead";
	string isMutant = mutant ? "Mutant" : "Normal"; 

	cout << endl;
	cout << left << setw(20) << name
		<< left << setw(10) << age 
		<< setw(10) << weight 
		<< left << setw(10) << gender 
		<< left << setw(15) << isAlive 
		<< left << setw(15) << isMutant 
		<< left << setw(15) << injured;
	
	return;
}
//increasing the weight of the monkey
void GreenMonkey::eat() {

	float monWeight = getRandomNumber(minIncrease, maxIncrease);
	if (!mutant) {
		weight += weight * (monWeight / 100);
	}

	return;
}
//increasing the age of the monkey
void GreenMonkey::age_me() {

	float monAge = getRandomNumber(0.02, 1);

	int monDeath = getRandomNumber(int(weight), 100);

	age++;
	//if the random number generated is 0.02, then assign mutant to true i.e, the monkey becomes a mutant
	if (monAge <= 0.02) {
		mutant = true;
	}
	//since we casted weight to integer, if the random number generated == integer value of the weight, then the monkey is dead
	if (monDeath <= int(weight)) {
		alive = false;
	}
	//if the monkey is injured more than 3 times, the monkey is also dead
	if (injured > 3) {
		alive = false;
	}
}
//engaging two monkeys in a fight
void GreenMonkey::fight(GreenMonkey* otherMonkey) {

	int monRate = getRandomNumber(1, 100);

	float fight_rate;
	fight_rate = (weight / otherMonkey->get_weight()) * 50;

	//if (monRate > fight_rate) {
		//injured++;
	//}
	//else {
		//otherMonkey.injured++;
	//}
	(monRate > fight_rate) ? injured++ : otherMonkey->injured++;
}


/************************************************************************************************************************/
								  //GreenMonkey_LinkedList class member definitions
/************************************************************************************************************************/

//default constructor of the class
GreenMonkey_LinkedList::GreenMonkey_LinkedList() {
	head = NULL;
	idCount = 0;
}
//print the contents of the list
void GreenMonkey_LinkedList::printList() {
	GreenMonkey* node = head;
	while (node != NULL) {
		node->print();
		node = node->get_next();
	}
}
//insert a node at the beginning of the linked list
void GreenMonkey_LinkedList::insert_at_start() {
	GreenMonkey* new_node = new GreenMonkey;
	new_node->set_next(head);
	head = new_node;
	
	set_idCount();
	new_node->set_ID(idCount);
}
//deletes a node 
void GreenMonkey_LinkedList::deleteNode(int node) {
	if (head == NULL) {
		return;
	}
	if (head->get_ID() == node) {
		head = head->get_next();
		return;
	}
	GreenMonkey* tmp = head;
	while (tmp != NULL) {
		if (tmp->get_next()->get_ID() == node) {
			break;
		}
		tmp = tmp->get_next();
	}
	if (tmp->get_next() == NULL) {
		return;
	}
	else
		tmp->set_next(tmp->get_next()->get_next());
	update_id();
}

//assign a value to the idCOunt data member
void GreenMonkey_LinkedList::set_idCount() {
	idCount++;
	return;
}

//retrieve the value from the data member
int GreenMonkey_LinkedList::get_idCount() {
	return idCount;
}
//update the ID data member
void GreenMonkey_LinkedList::update_id() {
	int counter = 1;
	GreenMonkey* node = head;

	while (node != NULL) {
		node->set_ID(counter);
		node = node->get_next();
		counter++;
	}
	idCount = counter;
	return;
}
//retrieve the value from the data member
GreenMonkey* GreenMonkey_LinkedList::get_Head() {
	return head;
}

//retrieve the value from the data member
GreenMonkey* GreenMonkey_LinkedList::get_Node(int id_val) {
	GreenMonkey* node = head;
	while (node != NULL) {
		if (node->get_ID() == id_val) {
			return node;
		}
		node = node->get_next();
	}
}

/************************************************************************************************************************/
								       //Habitat class member definitions
/************************************************************************************************************************/

//create a vector to store location of the empty cells
vector<string> Habitat::getEmptyCells() {
	vector<string>loc;
	string pos1, pos2;
	for (int i = 0; i < RowCol; i++) {
		for (int j = 0; j < RowCol; j++) {
			//if head is null, then return the location of the empty cells
			if (grid[i][j].get_Head() == NULL) {
				loc.push_back(to_string(i) + ":" + to_string(j));
			}
		}
	}
	return loc;
}

//populate the empty cells of the grid with a given number of green monkey objects 
void Habitat::intialization(int num) {
	vector<string>empty = getEmptyCells();


	for (int i = 0; i < num; i++) {
		string position = empty[GreenMonkey::getRandomNumber(0, empty.size() - 1)];

		string pos = empty[stoi(position)];

		//finding the colon in order to retrieve the numbers
		string colon = ":";
		int pos2 = (int)position.find(colon);
		string row = position.substr(0, pos2);
		string col = position.substr(pos2 + 1);



		//size_t found = pos.find(colon);
		
		//string row = pos.substr(found - 1 ); //at 0
		//string col = pos.substr(found + 1); // at 2

		grid[stoi(row)][stoi(col)].insert_at_start();

		//remove position position from list
		//position.erase();

	}
}

//print the grid showwing the monkey objects by gender
void Habitat::showGrid() {
	cout << left << setw(6) <<"";
	for (int j = 0; j < RowCol; j++) { 
		cout << left << setw(5) << j;
	}
	
	cout << endl;
	for (int x = 0; x < RowCol; x++) 
	{
		cout << left << setw(5) << x;
		for (int y = 0; y < RowCol; y++) { 
			if (grid[x][y].get_Head() == NULL) 
			{
				cout << left << setw(5) << "[ ]";
				
			}
			else{
			cout << left << '[' << grid[x][y].get_Head()->get_gender() << setw(3) << ']'; 
			}
		}
		cout << endl;
		
	}
}

void Habitat::impact(GreenMonkey_LinkedList& linked_list, GreenMonkey* mon) {
	//getting a random position
	int pos = mon->getRandomNumber(1, linked_list.get_idCount());
	if (!linked_list.get_Node(pos)->get_alive()) { return; }

	//if the monkeys are the same gender, then they should fight
	if (linked_list.get_Node(pos)->get_gender() == mon->get_gender()) {
		mon->fight(linked_list.get_Node(pos));
	}
	else { linked_list.insert_at_start(); }
}

void Habitat::invasion(int num) {
	for (int i = 0; i < num; i++){

	//generating 2 random numbers
	int x = GreenMonkey::getRandomNumber(0, RowCol - 1);
	int y = GreenMonkey::getRandomNumber(0, RowCol - 1);

	//if the list is empty, then the first element will be head
	if (grid[x][y].get_Head() == NULL) {
		grid[x][y].insert_at_start();
	}
	else {
		grid[x][y].insert_at_start();
		impact(grid[x][y], grid[x][y].get_Head());
	}

	}
}


void Habitat::ageAll() {
	//aging the monkeys while the list is not empty
	for (int x = 0; x < RowCol; x++) {
		for (int y = 0; y < RowCol; y++) {
			if (grid[x][y].get_Head() != NULL) {
				for (int i = 1; i <= grid[x][y].get_idCount(); i++) {
					grid[x][y].get_Node(i)->age_me();
				}
			}
			else { return; }
		}

	}
}

void Habitat::feedAll() {
	//feeding the monkeys while the list is not empty
	for (int x = 0; x < RowCol; x++) {
		for (int y = 0; y < RowCol; y++) {
			if (grid[x][y].get_Head() != NULL) {
				for (int i = 1; i <= grid[x][y].get_idCount(); i++) {
					grid[x][y].get_Node(i)->eat();
				}
			}
			else { return; }
		}

	}
}

void Habitat::printAll() {
	for (int x = 0; x < RowCol; x++) {
		for (int y = 0; y < RowCol; y++) {
			if (grid[x][y].get_Head() != NULL) {
				cout << endl;
				cout << endl;
				
				//if the location only has one monkey, the output should be singular, else be plural
				(grid[x][y].get_idCount() == 1) ?
				cout << "Cell->" << x << ":" << y << "has " << grid[x][y].get_idCount() << " monkey" << endl :
				cout << "Cell->" << x << ":" << y << "has " << grid[x][y].get_idCount() << " monkeys" << endl;
				
				cout << left << setw(20) << "Name"
					<< left << setw(10) << "Age"
					<< left << setw(10) << "Weight"
					<< left << setw(10) << "Gender"
					<< left << setw(15) << "Status"
					<< left << setw(15) << "Genes"
					<< left << setw(15) << "Injured";
				cout << endl;
				cout << setfill('=') << setw(88) << "";
				cout << setfill(' ');
				
				grid[x][y].printList();
			}
			else { continue; }


		}
	}
}

//retrieving the stats of the monkeys
void Habitat::getStatistics() {
	int tot_monkeys = 0, totM = 0, totF = 0, totAlive = 0, totDead = 0, tot_mutant = 0;
	int totNorm = 0;

	float total_weight = 0.0f;
	float total_age = 0.0f;
	float total_injuries = 0.0f;
	float avg_weight = 0.0f;
	float avg_age = 0.0f;
	float avg_injuries = 0.0f;


	for (int x = 0; x < RowCol; x++) {
		for (int y = 0; y < RowCol; y++) {
			if (grid[x][y].get_Head() != NULL) {
				GreenMonkey* node = grid[x][y].get_Head();
				while(node != NULL){
					tot_monkeys++;
					(node->get_gender() == 'M') ? totM++ :  totF++; 
					if (node->get_alive()) {
						total_weight += node->get_weight();
						total_age +=node->get_age();
						total_injuries += node->get_injured();
						totAlive++;
					}
					else { totDead++; }
					(node->get_mutant()) ? tot_mutant++ : totNorm++;
					node = node->get_next();
				}
			}			
		}
	}

	avg_weight = total_weight / totAlive;
	avg_age = total_age / totAlive;
	avg_injuries = total_injuries / totAlive;

	cout << endl;
	
	cout << setfill('=') << setw(70) << "" << endl;
	cout << setfill(' ');

	cout << left << setw(65) << "Description" << "Value" << endl;

	cout << setfill('=') << setw(70) << "" << endl;
	cout << setfill(' ');

	cout << left << setw(40) << "Total monkeys in the habitat" << right << setw(30) <<  tot_monkeys << endl;
	cout << left << setw(40) << "Total male monkeys in the habitat" << right << setw(30) <<totM << endl;
	cout << left << setw(40) << "Total female monkeys in the habitat" << right << setw(30) <<  totF << endl;
	cout << left << setw(40) << "Total alive monkeys in the habitat" << right << setw(30) << totAlive << endl;
	cout << left << setw(40) << "Total dead monkeys in the habitat" << right << setw(30) <<  totDead << endl;
	cout << left << setw(40) << "Total mutant monkeys in the habitat" << right << setw(30) <<  tot_mutant << endl;
	cout << left << setw(40) << "Total normal monkeys in the habitat" << right << setw(30) << totNorm << endl;
	cout << left << setw(40) << "Average weight of all alive monkeys in the habitat" << right << setw(20) << setprecision(3)<< avg_weight << endl;
	cout << left << setw(40) << "Average age of all alive monkeys in the habitat" << right << setw(23) <<  avg_age << endl;
	cout << left << setw(40) << "Average injuries of all alive monkeys in the habitat" << right << setw(18) << avg_injuries << endl;
	cout << setfill('=') << setw(70) << "" << endl;
	cout << setfill(' ');

	

	cout << endl;


}