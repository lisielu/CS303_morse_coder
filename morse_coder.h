#ifndef morse_coder_h
#define morse_coder_h
#endif

#include <iostream> //for reporting on operations
#include <string> //for encoding from the file -> getline(istream,string)
#include <sstream> //parse the strings from morse.txt
#include <fstream> //for reading from morse.txt
#include <map>
/*
  im familiar calling it a dictionary,
  but key lookup will be very useful for encoding
*/
#include <locale> //for tolower()


//"MBTNode" stands for Morse Bin Tree
template <typename Item_Type>
struct BTNode{
  //data fields
	Item_Type data;
  	BTNode<Item_Type>* left;
  	BTNode<Item_Type>* right;
  //constructor
  BTNode(const Item_Type& the_data, BTNode<Item_Type>* left_val = NULL, 
  	BTNode<Item_Type>* right_val = NULL) : data(the_data), left(left_val), right(right_val) {}
  //destructor
  virtual ~BTNode() {}
  //to_string
  virtual std::string to_string() const {
  	std::ostringstream os;
	os << data;
	return os.str();
  }
};
//Overload ostream insertion operator
template<typename Item_Type>
std::ostream& operator<<(std::ostream& out, const BTNode<Item_Type>& node){
	return out << node.to_string();
}


class morse_coder{
  //private data fields
 private:
  std::map<char,std::string> encoder_dict;
  //encoded or decode result
  std::string result;
  BTNode<char>* Root;
public:
  //constructor
  morse_coder();
  
  //converts english to morse code
  std::string decode(const std::string& input);
    //decode helper function
    void find_in_tree(char& result, std::string& input, BTNode<char>* local_root);

  //converts morse code to english variant
  std::string encode(const std::string& input);
    
  //returns a pointer to the root
    void build_Mtree(BTNode<char>* local_root,std::ifstream& fin);
    void place_Node(const char value, BTNode<char>* local_root, std::string& input);

    std::string translate(const std::string input);
};
