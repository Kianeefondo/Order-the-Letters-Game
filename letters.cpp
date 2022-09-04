#include <iostream>
#include <chrono>
#include <ctime>
#include <string>
using namespace std;

int main() {
	srand(time(0));
	int points = 1000;
	string input;
	char comp[7];
	int q; int x; int y; int u; int a;
	int offset;
	
	
	while(true) {
		for(q = 0; q <7; ++q) {
    	    if((rand() % 2) == 0) {
                comp[q] = '@' + (rand() % 26) + 1;
    	    }
       	    else {
       	    comp[q] = 'a' + (rand() % 26);   
       	    }
	    } //Computer Input
	    
        cout << "You current points " << points << ", type in order -> " << comp << ": ";
        chrono::steady_clock::time_point begin = chrono::steady_clock::now();
    	cin >> input;
    	chrono::steady_clock::time_point end = chrono::steady_clock::now();
    	
    	int seconds = chrono::duration_cast<std::chrono::milliseconds>(end-begin).count();
    	
    	cout << seconds << " milliseconds, you ";
    	
    	if(input.size() != 7) {
    	    for(a = input.size(); a <= 7; ++a) {
    	        input.resize(7, ' ');
    	    continue;
    	    }
    	} // string fixed to 7 chars
    	
    	for(x = 0; x < 7; ++x) {		
		    for(y = x+1; y < 7; ++y) {
			    if(comp[x]>comp[y]) {
				    char temp = comp[x];
				    comp[x]= comp[y];
				    comp[y]= temp;
			    }
		    }
	    } //Swaping in asending order
    	
       	    if((seconds <= 12000) && (input == comp)){
       	        cout << "made it within the interval of 12000..." << endl;
       	        cout << endl;
       	        points = points + 500;
       	    } // correct order
       	    
       	    if((seconds > 12000) && (input == comp)){
       	        cout << "*failed* it within the interval of 12000..." << endl;
       	        cout << endl;
       	        points = points - (seconds - 12000);
       	    } //overtime
       	    
       	    if((seconds <= 12000) && (input != comp)){
       	        cout << "made it within the interval of 12000..." << endl;
       	        cout << "Answer must be \"" << comp << "\" String offset is ";
       	        
       	            for(u = 0; u < 7; ++u){
       	                if(comp[u] == input.at(u)) {
       	                    continue;
       	                }
       	                if(comp[u] != input.at(u)) {
       	                    offset = 0;
       	                    offset = offset + abs(comp[u]-input.at(u));
       	                }
       	            } // offset calculation
       	        points = points - offset;
       	        
       	        cout << offset << ", your total penalty is " << offset << "..." <<endl;
       	        cout << endl;
       	    } //incorrect input
       	    
       	    if((seconds > 12000) && (input != comp)){
       	        cout << "*failed* it within the interval of 12000..." << endl;
       	        cout << "Answer must be \"" << comp << "\" String offset is ";
       	        
       	            for(u = 0; u < 7; ++u){
       	                if(comp[u] == input.at(u)) {
       	                    continue;
       	                }
       	                if(comp[u] != input.at(u)) {
       	                    offset = 0;
       	                    offset = offset + abs(comp[u]-input.at(u));
       	                }
       	            } // offset calculation
       	        
       	        cout << offset << ", your total penalty is " << ((2*offset) + (seconds - 12000)) << "..." << endl;
       	        cout << endl;
       	    } // double jeopardy
        
        if(points < 0) {
        break;
        }
	}

    cout << "Bye..." << endl;
    
	return 0;
}