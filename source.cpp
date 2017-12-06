#include "morse_coder.h"

using namespace std;

int main(){
  morse_coder myCoder;
  const string in("... ___ ...");
  const string out("SOS");
  cout << "Original: "
	   << in
	   <<"\nDecoded: "
	   <<myCoder.decode(in) 
	   << endl;
  cout << "Original: "
	   << out
	   <<"\nEncoded: "
	   << myCoder.encode(out)
	  << endl << endl;

const string in2("_._. ._ _");
const string out2("CAT");
 cout << "Original: "
	   << in2
	   <<"\nDecoded: "
	   <<myCoder.decode(in2) 
	   << endl;
  cout << "Original: "
	   << out2
	   <<"\nEncoded: "
	   << myCoder.encode(out2)
	  << endl;
  system("pause");
  return 0;
}
