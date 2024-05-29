#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

int timeCall(string start, string finish);
int isValid(string str);

int main(){
	unordered_map<string, int> countCall;
	unordered_map<string, long> countTotalTime;
	int totalCall = 0, countInvalid = 0;
	string tmp = "";
	cin >> tmp;
	
	while (tmp != "#"){
		totalCall++;
		
		//So goi di
		cin >> tmp;
		string forw = tmp;
		if (isValid(tmp)) countInvalid++;
		countCall[tmp]++;

		
		//So goi den
		cin >> tmp;
		
		//Ngay thang goi
		cin >> tmp;
		
		//Thoi gian bat dau va ket thuc cuoc goi
		string tmp1, tmp2;
		cin >> tmp1;
		cin >> tmp2;
		countTotalTime[forw] += timeCall(tmp1, tmp2);
		
		cin >> tmp;
	}
	
	tmp = "";
	while (tmp != "#"){
		cin >> tmp;
		
		if (tmp == "?check_phone_number"){
			if (countInvalid == 0) 
				cout << 1 << endl;
			continue;
		}
		
		if (tmp == "?number_calls_from"){
			cin >> tmp;
			cout << countCall[tmp] << endl;
			continue;
		}
		
		if (tmp == "?number_total_calls"){
			cout << totalCall << endl;
			continue;
		}
		
		if (tmp == "?count_time_calls_from"){
			cin >> tmp;
			cout << countTotalTime[tmp] << endl;
			continue;
		}

	}
	
	return 99;
}

int timeCall(string start, string finish){
	int res;
	int tmp1 = 0, tmp2 = 0, c;
	
	c = stoi(start.substr(0, 2));
	tmp1 += c*60*60;
	c = stoi(start.substr(3, 2));
	tmp1 += c*60;
	c = stoi(start.substr(6, 2));
	tmp1 += c;
	
	c = stoi(finish.substr(0, 2));
	tmp2 += c*60*60;
	c = stoi(finish.substr(3, 2));
	tmp2 += c*60;
	c = stoi(finish.substr(6, 2));
	tmp2 += c;
	
	res = tmp2 - tmp1;
	return res;
}

int isValid(string str){
	if (str.length() != 10) return 0;
	for (int i = 0; i <= 10; i++)
		if (!(str[i] <= '9' && str[i] >= '0'))
			return 0;
	return 1;
}

