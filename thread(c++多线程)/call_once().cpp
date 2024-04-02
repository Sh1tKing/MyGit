#include<iostream>
#include<thread>
#include<mutex>
#include<string>
class Log {
public:

	Log(const Log& log) = delete;//ɾ�����ƺ���
	Log& operator=(const Log& log) = delete;//ɾ�����ںŸ�ֵ
	static Log& GetInstance() {
		static Log* log = nullptr;
		if (!log) log = new Log;
		return *log;
	}
	void print(std::string msg) {
		std::cout << __TIME__ << " " << msg << std::endl;
	}
private:
	Log() {};
};
int main() {
	Log::GetInstance().print("error");
}