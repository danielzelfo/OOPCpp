#pragma once
#include <iostream>
#include <string>

using namespace std;

class GameEntry {
private:
	//data members
	string playerName;
	int score;
	int date[3];

public:
	//constructor with all fields -- date is an array
	GameEntry(string newPlayerName, int newScore, int newDate[3]) {
		setPlayerName(newPlayerName);
		setScore(newScore);
		setDate(newDate);
	}
	//constructor with all fields -- date is a string
	GameEntry(string newPlayerName, int newScore, string newDate) {
		setPlayerName(newPlayerName);
		setScore(newScore);
		setDate(newDate);
	}
	//default constructor
	GameEntry() {
		playerName = "Unknown";
	}

	//getters and setters
	string getPlayerName() {
		return playerName;
	}
	int getScore() {
		return score;
	}
	int getMonth() {
		return date[0];
	}
	int getDay() {
		return date[1];
	}
	int getYear() {
		return date[2];
	}
	void setPlayerName(string newPlayerName) {
		playerName = newPlayerName;
	}
	void setScore(int newScore) {
		if (newScore >= 0 && newScore <= 1000)
			score = newScore;
		else
			score = 0;
	}
	void setDate(int newDate[3]) {
		date[0] = newDate[0];
		date[1] = newDate[1];
		date[2] = newDate[2];
	}
	void setDate(string newDate) {
		split(date, newDate, '/');
	}


	//this functions splits a string of a date into an array with the numbers representing the date (month, day, year)
	void split(int result[3], string data, char tar) {
		int prevEnd = 0, fillingIndex = 0;
		for (int i = 0; i < data.length(); i++)
			if (data[i] == tar) {
				result[fillingIndex] = stoi(data.substr(prevEnd, i));
				prevEnd = i + 1;
				fillingIndex++;
				if (fillingIndex == 2)
					break;
			}
		result[fillingIndex] = stoi(data.substr(prevEnd, data.length()));
	}

	//the game entry toString function that returns the plater name, the score, and the date
	string toString(char seperator) {
		return (playerName + seperator + to_string(score) + seperator + to_string(date[0]) + "/" + to_string(date[1]) + "/" + to_string(date[2]));
	}

	//this method is used to evaluate whether or not two game entries are equal
	bool equals(GameEntry otherGameEntry) {
		if (otherGameEntry.getPlayerName() != playerName || otherGameEntry.getScore() != score || otherGameEntry.getMonth() != date[0] || otherGameEntry.getDay() != date[1] || otherGameEntry.getYear() != date[2])
			return false;
		return true;
	}
};