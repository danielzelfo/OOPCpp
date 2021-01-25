#pragma once
#include <iostream>
#include <fstream>
#include "GameEntry.hpp"

using namespace std;

class GameScore {
private:
	static const int MAX_ENTRIES = 5;
	//data members
	string gameName;
	GameEntry topScores[MAX_ENTRIES];
	/*
	* 0 - highest
	* 4 - lowest
	*/
	int usedEntries = 0;

public:
	//constructor using all fields
	GameScore(string newGameName, GameEntry newTopScores[MAX_ENTRIES]) {
		setGameName(newGameName);
		setTopScores(newTopScores);
	}
	//constructor with game name field
	GameScore(string newGameName) {
		setGameName(newGameName);
	}
	//constructor with file field
	GameScore(string fileName, bool isAFile) {
		//making sure the string is a date
		if (!isAFile) {
			setGameName(fileName);
			return;
		}

		//opening the file to read
		ifstream  dataFile;
		dataFile.open(fileName, ios::in);
		if (!dataFile) return;

		//declaring 3 game entry variables
		string playerName, date;
		int score;

		//getting the game name from the file
		getline(dataFile, gameName);

		//looping through all game entries in file
		while (!dataFile.eof()) {

			//reading player name
			dataFile >> playerName;

			if (dataFile.eof()) break;

			//reading player score and date
			dataFile >> score;
			dataFile >> date;

			//creating a new game entry object and adding it
			GameEntry e(playerName, score, date);
			add(e);

		}
		dataFile.close();
	}
	//default constructor
	GameScore() {
		setGameName("Unknown");
	}

	//getters and setters
	string getGameName() {
		return gameName;
	}
	GameEntry* getAllTopScores() {
		return topScores;
	}
	GameEntry getTopScoreNumber(int rank) {
		return topScores[rank - 1];
	}
	void setGameName(string newGameName) {
		gameName = newGameName;
	}
	void setTopScores(GameEntry newTopScores[MAX_ENTRIES]) {
		for (int i = 0; i < MAX_ENTRIES; i++) {
			topScores[i] = newTopScores[i];
		}
	}

	//the add function: this will find the rank of the new game entry by its score and put it there
	void add(GameEntry newScore) {
		if (usedEntries < MAX_ENTRIES && newScore.getScore() > topScores[usedEntries].getScore())
			usedEntries++;
		for (int i = 0; i < usedEntries; i++) {
			if (newScore.getScore() > topScores[i].getScore()) {
				//moving down all the scores from that index and getting rid of the lowest score
				moveDown(i);
				//setting the new score
				topScores[i] = newScore;
				break;
			}
		}

	}

	//this function will remove the lowest score and move down all the elements until the rank element is reached
	void moveDown(int rankIndex) {
		if(rankIndex < usedEntries)
			for (int i = (usedEntries - 1); i > rankIndex; i--)
				topScores[i] = topScores[i - 1];
	}

	//this function removes the given rank from the top scores (ex remove the second highest score = remove(2))
	void remove(int rank) {
		if (rank < 1 || rank > 5)
			return;
		for(int i = (rank-1); i < (usedEntries-1); i++)
			topScores[i] = topScores[i + 1];
		usedEntries--;
	}
	//this function removes all the elements in a given array of game entries from the top scores
	void remove(GameEntry newGameEntry[], int size) {
		for(int j = 0; j < size; j++) // looping through each game entry to be removed
			for (int i = 0; i < usedEntries; i++) // looping though all top scores
				if (newGameEntry[j].equals(topScores[i])) {
					remove(i + 1);
					break;
				}
	}

	//EXTRA CREDIT #2 - remove all entries on or before a given date
	void remove(string date) {
		GameEntry removedEntries[MAX_ENTRIES];
		int dateThreshold[3], size = 0;
		split(dateThreshold, date, '/');
		for (int i = 0; i < usedEntries; i++) {
			if (topScores[i].getYear() < dateThreshold[2]
				|| topScores[i].getYear() == dateThreshold[2] && topScores[i].getMonth() < dateThreshold[0]
				|| topScores[i].getYear() == dateThreshold[2] && topScores[i].getMonth() == dateThreshold[0] && topScores[i].getDay() <= dateThreshold[1]) {
				removedEntries[size] = topScores[i];
				size++;
			}
		}
		remove(removedEntries, size + 1);
	}

	//the print function
	void print() {
		cout << "Name: " << gameName << endl;
		for (int i = 0; i < usedEntries; i++)
			cout << (i + 1) << '\t' << topScores[i].toString('\t') << endl;
		cout << endl;
	}

	//function to save the game scores to a file using the file name or directory
	void save(string fileName) {
		//opening the file for writing
		ofstream dataFile;
		dataFile.open(fileName, ios::out);
		if (!dataFile) return;

		//writing the game name
		dataFile << gameName << endl;

		//writing all the game entries
		for (int i = 0; i < usedEntries; i++)
			dataFile << topScores[i].toString(' ') << endl;
		dataFile << endl;

		dataFile.close();
	}

	//this functions splits a string of a date into an array with the numbers representing the date (month, day, year)
	void split(int result[3], string data, char tar) {
		int prevEnd = 0, fillingIndex = 0;
		//looping through each character of the string
		for (int i = 0; i < data.length(); i++)
			//adding to the split array if the target key is found
			if (data[i] == tar) {
				result[fillingIndex] = stoi(data.substr(prevEnd, i));
				prevEnd = i + 1;
				fillingIndex++;
				if (fillingIndex == 2)
					break;
			}
		//adding the last part of the string to the array
		result[fillingIndex] = stoi(data.substr(prevEnd, data.length()));
	}

};

