#include<iostream>
#include<stack>
#include<vector>
#include<sstream>
using namespace std;
#define MaxSize 10
typedef struct {
	int data[MaxSize];
	int top;
}sqstack;
void IntStack(sqstack& s) {
	s.top = -1;
}
void testStack() {
	sqstack s; 
	IntStack(s);
}
bool stackempty(sqstack s) {
	if (s.top == -1) return true;
	else return false;
}
bool Push(sqstack& s, int x) {
	if (s.top == MaxSize - 1)
		return false;
	s.top++;
	s.data[s.top] = x;
}
bool Pop(sqstack& s, int &x) {
	if (s.top == MaxSize - 1)
		return false;
	x = s.data[s.top];
	s.top--;
}
string removeDuplicates(string s) {
	stack<char> p;
	p.push(s[0]);
	for (int i = 1; i < s.length(); i++) {
		if (p.empty()) p.push(s[i]);
		else if (p.top() == s[i]) p.pop();
		else p.push(s[i]);
	}
	string ans;
	while (!p.empty()) {
		ans += p.top();
		p.pop();
	}
	reverse(ans.begin(), ans.end());
	return ans;
}
int evalRPN(vector<string>& tokens) {
	stack<int> p;
	int ans = 0;
	for (int i = 0; i < tokens.size(); i++) {
		if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
			int num1 = p.top();
			p.pop();
			int num2 = p.top();
			p.pop();
			if (tokens[i] == "+") ans = num2 + num1;
			else if (tokens[i] == "-")ans = num2 - num1;
			else if (tokens[i] == "*")ans = num2 * num1;
			else if (tokens[i] == "/")ans = num2 / num1;
			p.push(ans);
		}
		else {
			stringstream ss;
			ss << tokens[i];
			int nums = 0;
			ss >> nums;
			p.push(nums);
		}
	}
	if (tokens.size() == 1) {
		stringstream ss;
		ss << tokens[0];
		int nums = 0;
		ss >> ans;
	}
	return ans;
}
 int main() {
	vector<string> n = { "18"};
	cout<<evalRPN(n);
	
}