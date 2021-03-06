/*
 * Author: Daniel Zelfo
 * Class: CSCI 140
 * Program: Random Program. 
 *
 * Description: The program includes the RandDay class, the RandTime class, the RandLotto class, the RandMsgOfTheDay class, and the RandString class.
 * 				The program includes a simulation for the lottery and uses the RandLotto class to generate random lottery numbers to find the probability to win the lottery.
 *				The program includes the classroom birthday simulation. It uses the RandDay class to generate random birthdays in the same year. It runs 6 different simulations for class sizes 20-25 and finds the probability that a birthday repeats for each class size.
 * Date: 12/4/2019
 */
#include "RandDay.hpp"
#include "RandLotto.hpp"
#include "RandMsgOfTheDay.hpp"
#include "RandStr.hpp"
#include "RandTime.hpp"

#include <map>
#include <iomanip>




//prototype
void printRandom(RandDay randDay, RandTime randTime, RandLotto randLotto, RandMsgOfTheDay randMsg, RandStr randStr);

void birthdaySimulation();
void lotterySimulation();

using namespace std;

void randomClassesMain()
{
	//creating all the random objects
	RandDay randDay;
	RandTime randTime;
	RandLotto randLotto;
	RandMsgOfTheDay randMsg;
	RandStr randStr;

	//a sentinal value
	//char senti;
  char user;

	//printing the random values
	printRandom(randDay, randTime, randLotto, randMsg, randStr);

	//asking the user for input
	//cout << "Enter 'g' to generate new numbers or 'e' to exit.\n>";
	//cin >> senti;
	cout << endl;

	/*generating new values until user wants to stop
	while (senti != 'e') {

		if(senti == 'g'){
			randDay.generate();
			randTime.generate();
			randLotto.generate();
			randMsg.generate();
			randStr.generate();

			printRandom(randDay, randTime, randLotto, randMsg, randStr);
		}
		cout << "Enter 'g' to generate new numbers or 'e' to exit.\n>";
		cin >> senti;
		cout << endl;
	}
  */
  cout << "Would you like to run the birthday simulation? (y/n): ";
  cin >> user;
  if(tolower(user) == 'y') {
	  cout << "Running Birthday Simulation...\n\n";
	  birthdaySimulation();
	}
  cout << "\nWould you like to run the lottery simulation? (y/n): ";
  cin >> user;
  if(tolower(user) == 'y') {
    cout << "Running Lottery Simulation... (this will take some time)\n\n";
    lotterySimulation();
  }
}

//function to print all the random objects
void printRandom(RandDay randDay, RandTime randTime, RandLotto randLotto, RandMsgOfTheDay randMsg, RandStr randStr) {
  
	cout << "Random Day: " << endl;

	randDay.print();
	cout << "\n\n";
  

	cout << "Random Time: " << endl;

	randTime.print();
	cout << "\n\n";

	cout << "Random Lottery Numbers: " << endl;

	randLotto.print();
	cout << "\n\n";

	cout << "Random Message of The Day: " << endl;

	randMsg.print();
	cout << "\n\n";

	cout << "Random String: " << endl;

	randStr.print();
	cout << "\n\n";
}


void birthdaySimulation()
{

	//creating a random birthday objet that is in the year of 2000
	RandDay birthday(2000);

	//making a map for all the birthdays
	map<string, int> bdCounter;

	//variable for number of times a birthday was repeated within each simulation
	int birthdayRepeats;
	for(int classSize = 20; classSize <= 25; ++classSize){
		cout << "Class Size: " << classSize << endl;
		birthdayRepeats = 0;
		
		for (int j = 0; j < 10000; ++j) {
			bdCounter.clear();
			for (int i = 0; i < classSize; ++i){
				birthday.generate();
				
				//checking if the current birthday exists and handling accordingly
				if (bdCounter.find(birthday.toString()) == bdCounter.end())
					bdCounter[birthday.toString()] = 1;
				else
					goto end;
			}

			continue;
		end:
			++birthdayRepeats;
		}
		cout << "Percent of times birthdays repeated: " << birthdayRepeats/100 << "%" << endl;
	}

		
}


void lotterySimulation()
{

	/*
	
	LOTTERY SIMULATION
	
	*/
	RandLotto winner;
	RandLotto generator;

	long sum = 0;
	int reached = 1;
	const int times = 100;

	winner.generate();
	cout << "Winning Lotto Numbers: ";
	winner.print();
	cout << endl;

	
	//generating 100 winners
	for (int i = 0; i < times; ++i) {
		reached = 1;
		while (!(generator == winner)) {
			++reached;
			generator.generate();
		}
		cout << "Winner Found after " << reached << endl;
		sum += reached;
		
		winner.generate();
		generator.generate();

		cout << "New winning numbers: ";
		winner.print();
		cout << endl;
	}
	cout << "Average: " << fixed << setprecision(2) << 1.0 * sum / times << endl;
	cout << "Probability: " << fixed << setprecision(15)<< 100.0 * times / sum << '%' << endl;
}
