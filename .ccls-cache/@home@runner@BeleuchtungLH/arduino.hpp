#include <thread>
#include <chrono>

void setup();
void loop();

enum Mode {
	INPUT, OUTPUT, INPUT_PULLUP
};

enum State {
	LOW,HIGH
};

void delay(int millis){
	using namespace std::chrono_literals;
	std::cout << "sleeping " << millis << " milliseconds\n";
	std::this_thread::sleep_for(std::chrono::milliseconds(millis));
}

void pinMode(int p, Mode m){
	std::cout << "setting pin " << p << " to mode: " << m << "\n";
}

void digitalWrite(int p, State s){
	std::cout << "switching pin " << p << " to state: " << s << "\n";
}

int main() {
  setup();
	while (true) {
		loop();
	}
}

