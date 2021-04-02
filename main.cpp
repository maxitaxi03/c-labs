#include<iostream>
#include<random>
#include<chrono>
#include<string>
#include<vector>
#include "green_monkey.h"
using namespace std;

vector<GreenMonkey> create_troop(int size);
void age_troop(vector<GreenMonkey> &mon);
void feed_troop(vector<GreenMonkey> &mon);
void engage_troop(vector<GreenMonkey> &mon);
void statistics_on_troop(vector<GreenMonkey> &mon);


int main() {
	
	vector<GreenMonkey> monkeys;
	monkeys = create_troop(50);
	
	statistics_on_troop(monkeys);
	
	for (int i = 0; i < 10; i++) {
		age_troop(monkeys);
	}
	
	for (int j = 0; j < 6; j++) {
		feed_troop(monkeys);
	}
	for (int k = 0; k < 8; k++) {
		engage_troop(monkeys);

	}//the engage is a problem, an exception is always being thrown when I uncomment out this.
	//also, check the average weight of the monkey as well as the mutants, I am always getting 0
	cout << endl;
	statistics_on_troop(monkeys);
	
	

	return 0;
}
vector<GreenMonkey> create_troop(int size) {
	vector<GreenMonkey> mon;
	for (int i = 0; i < size; i++) {
		GreenMonkey monkey;
		mon.push_back(monkey);
	}
	return mon;
}
void age_troop(vector<GreenMonkey> &mon) {
	vector<GreenMonkey>::iterator i;
	for (i = mon.begin(); i != mon.end(); i++) {
		(*i).age_me();
	}
	
	return;
}

void feed_troop(vector<GreenMonkey> &mon) {
	vector<GreenMonkey>::iterator i;
	for (i = mon.begin(); i != mon.end(); i++) {
		if ((*i).get_alive()) {
			(*i).eat();
		}
	}
	return;
}
void engage_troop(vector<GreenMonkey> &mon) {
	unsigned seed = chrono::steady_clock::now().time_since_epoch().count();
	default_random_engine ranGen(seed);
	//picking a random number between 1 and the size of the vector
	uniform_int_distribution<int>ranNum(0, mon.size() - 1);
	//assigning a random position that was generated
	int pos1 = ranNum(ranGen);
	int pos2 = ranNum(ranGen);

	while (pos1 == pos2) {
		 pos2 = ranNum(ranGen);
	}

	GreenMonkey monkey1 = mon[pos1];
	GreenMonkey monkey2 = mon[pos2];

	
		if (monkey1.get_gender() == monkey2.get_gender()) {
			if (monkey1.get_age() < monkey2.get_age()) {
				monkey1.fight(monkey2);
			}
			else if (monkey1.get_age() > monkey2.get_age()) {
				monkey2.fight(monkey1);
			}
			else {
				int choice;
				uniform_int_distribution<int>random_numb(0, 1);
				choice = random_numb(ranGen);
				(choice == 0) ?	monkey1.fight(monkey2) : monkey2.fight(monkey1);
				}
		}
		else {
			GreenMonkey baby;
			mon.push_back(baby);
		}
	}


void statistics_on_troop(vector<GreenMonkey> &mon) {
	int aliveM = 0;
	int aliveF = 0;
	int mutants = 0;
	int babies = 0;
	int deadM = 0;
	int deadF = 0;
	float avg_age = 0.0f;
	float avg_weight = 0.0f;
	float totAge = 0.0f;
	float totWeight = 0.0f;
	vector<GreenMonkey>::iterator i;

	for (i = mon.begin(); i != mon.end(); i++) {
		if ((*i).get_gender() == 'M') {
			if ((*i).get_alive()) {
				aliveM++;
			}
			else {
				deadM++;
			}
		}
		else if ((*i).get_gender() == 'F') {
			if ((*i).get_alive()) {
				aliveF++;
			}
			else {
				deadF++;
			}
		}
		if ((*i).get_mutant()) {
			mutants++;
		}
		if ((*i).get_age() <= 3) {
			babies++;
		}
		totAge += (*i).get_age();
		totWeight += (*i).get_weight();
	}
	avg_age = totAge / mon.size();
	avg_weight = totWeight / mon.size();

	cout << left << setw(45) << "Statistics" << endl;
	cout << left << setw(45) << "Total Alive Male Monkeys is: " <<aliveM << endl;
	cout << left << setw(45) << "Total Alive Female Monkeys is: " << aliveF << endl;
	cout << left << setw(45) << "Total Mutants is: " << mutants << endl;
	cout << left << setw(45) << "Total Monkeys less than or equal to 3 is: " << babies << endl;
	cout << left << setw(45) << "Total Dead Male Monkeys is: " << deadM << endl;
	cout << left << setw(45) << "Total Dead Female Monkeys is: " << deadF << endl;
	cout << left << setw(45) << "Average age is : " << avg_age << endl;
	cout << left << setw(45) << "Average weight is: " << avg_weight << endl;
	
	cout << endl;
}





































